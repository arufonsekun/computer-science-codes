#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>
#include <semaphore.h>

#include <unistd.h>
#include <sys/types.h> 

#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#include "configreader.h"
#include "queue.h"

#define CONTROL 0
#define DATA 1
#define GET_MUTEX 0
#define MESSAGE_LENGTH 100
#define RESPONSE_LENGTH 16
#define SOCKET_CREATE_FAIL -1
#define SOCKET_BIND_FAIL -1
#define RECEIVE_MESSAGE_ERROR -1
#define RESPONSE_FAIL -1
#define SEND_FAIL -1

int SOCKET;
struct sockaddr_in server_addr, client_addr;

pthread_mutex_t m_input_queue = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m_output_queue = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m_general_queue = PTHREAD_MUTEX_INITIALIZER;

sem_t Sender, Terminal, Receiver, Packet_handler;

void *receiver();
void *sender();
void *packet_handler();
void *terminal();

pthread_t t0, t1, t2, t3;

Pqueue* general_queue_h = NULL;
Pqueue* input_queue_h = NULL;
Pqueue* output_queue_h = NULL;
Pqueue* general_queue_t = NULL;
Pqueue* input_queue_t = NULL;
Pqueue* output_queue_t = NULL;

typedef struct router {
    int id;
    char* ip;
    char* port;
} Router;

void create_socket(void *args) {
    Router *r = args;
    SOCKET = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (SOCKET == SOCKET_CREATE_FAIL) { 
        perror("A criação do socket falhou\n");
        exit(EXIT_FAILURE); 
    }
    
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_port = htons(atoi(r->port));
    
    if (inet_aton(r->ip, &server_addr.sin_addr) == 0) {
        printf("Deu problema no momento de converter o endereço IP\n");
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);  
    }

    if (bind(SOCKET, (const struct sockaddr *) &server_addr, sizeof(server_addr)) == SOCKET_BIND_FAIL) {
        perror("Bind do socket falhou\n");
        perror("É possível que a porta já esteja em uso\n");
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Para instanciar um roteador você precisa passar seu ID como argumento.\n");
        return 1;
    }
    Router *r = malloc(sizeof *r);
    r->id = atoi(argv[1]);
    char* link = read_link(r->id);
    char* link_cp = (char*) malloc(sizeof(char) * strlen(link));
    strcpy(link_cp, link);

    r->port = get_port(link);
    r->ip = get_ip(link_cp);

    create_socket(r);

    pthread_create(&t0, NULL, receiver, r);
    pthread_create(&t1, NULL, sender, r);
    pthread_create(&t2, NULL, packet_handler, r);
    pthread_create(&t3, NULL, terminal, r);
    
    sem_post(&Terminal);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    exit(EXIT_SUCCESS);
}

void *terminal(void *args) {
    Router* r = args;
    sem_wait(&Terminal);
    int action, neighbor_id;
    char message[100];
    char* neighbors = get_neighbors(r->id);
    char* neighbors_cp = malloc(sizeof(char) * strlen(neighbors));
    strcpy(neighbors_cp, neighbors);

    printf("\n            BEM-VINDO AO ROTEADOR SIMULATOR");
    while(1) {
        printf("\n+-----------------------------------------------------+\n");
        printf("| 1. Mandar uma mensagem para algum dos seus vizinhos.|\n");
        printf("| 2. Visualizar mensagens recebidas.                  |\n");
        printf("| 3. Desligar o roteador.                             |\n");
        printf("+-----------------------------------------------------+\n");
        printf("→ Digite sua ação: ");
        scanf("%d", &action);
        printf("\n");
        if (action == 1) {
            printf("→ Seus roteadores vizinhos são: ");
            char* n = strtok_r(neighbors, ",", &neighbors);
            while (n != 0) {
                printf("%s ", n);
                n = strtok_r(neighbors, ",", &neighbors);
            }
            printf("\n");
            printf("→ Digite o vizinho com quem deseja se comunicar: ");
            scanf("%d", &neighbor_id);
            printf("→ Digite sua mensagem: ");
            fflush (stdin);
            scanf("%s", message);

            Packet p;
            p.s_address = (char*) malloc(sizeof(char) * 100);
            p.d_address = (char*) malloc(sizeof(char) * 100);
            p.d_port = (char*) malloc(sizeof(char) * 10);
            p.s_port = (char*) malloc(sizeof(char) * 10);

            char* router = read_link(neighbor_id);
            char* router_cp = (char*) malloc(sizeof(char) * strlen(router));
            strcpy(router_cp, router);

            p.message_type = DATA;
            strcpy(p.s_address, r->ip);
            p.payload = message;
            p.d_port = get_port(router);
            p.s_port = r->port;
            p.d_address = get_ip(router_cp);

            // Manda o pacote para o packet_handler
            if (pthread_mutex_lock(&m_general_queue) == GET_MUTEX) {
                if (general_queue_h == NULL) {
                    general_queue_h = enqueue(general_queue_h, p);
                    general_queue_t = general_queue_h;
                } else {
                    general_queue_t = enqueue(general_queue_t, p);
                }
                pthread_mutex_unlock(&m_general_queue);
                sem_post(&Packet_handler);
            }
        } else if (action == 2) {
            if (pthread_mutex_lock(&m_input_queue) == GET_MUTEX) {
                if (input_queue_h == NULL) {
                    printf("→ Você não tem nenhuma mensagem ;(\n");
                } else {
                    printf("       Suas mensagens      \n");
                    printf("+--------------------------\n");
                    while (input_queue_h != NULL) {
                        printf("| Roteador %s:%s\n", input_queue_h->packet->s_address, input_queue_h->packet->s_port);
                        printf("| Disse: %s\n", input_queue_h->packet->payload);
                        input_queue_h = dequeue(input_queue_h);
                    }
                    printf("+--------------------------\n");
                }
                pthread_mutex_unlock(&m_input_queue);
            }
        } else if (action == 3) {
            exit(EXIT_SUCCESS);
        } else {
            printf("Ação inválida, digite novamente.\n");
        }
        strcpy(neighbors, neighbors_cp);
        printf("\n                 ROTEADOR SIMULATOR");
    }
}

void *packet_handler(void *args) {
    Router* r = args;
    while(1) {
        sem_wait(&Packet_handler);
        if (pthread_mutex_lock(&m_general_queue) == GET_MUTEX) {
            Packet p;
            p.s_address = general_queue_h->packet->s_address;
            p.d_address = general_queue_h->packet->d_address;
            p.d_port = general_queue_h->packet->d_port;
            p.s_port = general_queue_h->packet->s_port;
            p.payload = general_queue_h->packet->payload;
            p.message_type = general_queue_h->packet->message_type;

            general_queue_h = dequeue(general_queue_h);

            if (p.message_type == DATA) {
                // O pacote desenfileirado é para
                // o roteador atual, então adiciona ele
                // na fila de entrada para ser mostrado posteriormente.
                if (strcmp(p.d_address, r->ip) == 0 && strcmp(p.d_port, r->port) == 0) {
                    if (pthread_mutex_lock(&m_input_queue) == GET_MUTEX) {
                        if (input_queue_h == NULL) {
                            input_queue_h = enqueue(input_queue_h, p);
                            input_queue_t = input_queue_h;
                        } else {
                            input_queue_t = enqueue(input_queue_t, p);
                        }
                        pthread_mutex_unlock(&m_input_queue);
                    }
                } else {
                    // O pacote desenfileirado não é para
                    // o roteador atual, então ele deve ser enviado
                    // para seu destino.
                    if (pthread_mutex_lock(&m_output_queue) == GET_MUTEX) {
                        if (output_queue_h == NULL) {
                            output_queue_h = enqueue(output_queue_h, p);
                            output_queue_t = output_queue_h;
                        } else {
                            output_queue_t = enqueue(output_queue_t, p);
                        }
                        pthread_mutex_unlock(&m_output_queue);
                        // Passa o controle para o Sender,
                        // para fazer o envio da nova mensagem.
                        sem_post(&Sender);
                    }
                }
            } else {
                // Pacote desenfileirado é de controle,
                // não fazer nada por hora
            }
            pthread_mutex_unlock(&m_general_queue);
        }
    }
}

void *receiver(void *args) {
    Router* r = args;

    struct sockaddr_in client_addr;
    int recv_len, client_addr_len;
    client_addr_len = sizeof(client_addr);
    
    char buffer[MESSAGE_LENGTH];

    memset(&client_addr, 0, client_addr_len);

    while(1) {
        fflush(stdout);
        memset(buffer, '\0', MESSAGE_LENGTH);

        // recvfrom é bloqueante, então não é preciso se preocupar com o while(1)
        if (recv_len = recvfrom(SOCKET, buffer, MESSAGE_LENGTH, 0, (struct sockaddr*) &client_addr, &client_addr_len) == RECEIVE_MESSAGE_ERROR) {
            printf("receiver: Houve um problema na hora de receber a mensagem\n");
        }

        // Cria o pacote para armazenar as informações recebidas
        Packet p;
        p.s_address = (char*) malloc(sizeof(char) * 100);
        p.d_address = (char*) malloc(sizeof(char) * 100);
        p.payload = (char*) malloc(sizeof(char) * 100);
        p.d_port = (char*) malloc(sizeof(char) * 10);
        p.s_port = (char*) malloc(sizeof(char) * 10);
        p.s_address = inet_ntoa(client_addr.sin_addr);
        p.d_address = r->ip;
        p.d_port = r->port;
        sprintf(p.s_port, "%u", ntohs(client_addr.sin_port));
        strcpy(p.payload, buffer);
        p.message_type = DATA;

        // Adiciona o pacote recebido na fila geral.
        if (pthread_mutex_lock(&m_general_queue) == GET_MUTEX) {
            if (general_queue_h == NULL) {
                general_queue_h = enqueue(general_queue_h, p);
                general_queue_t = general_queue_h;
            } else {
                general_queue_t = enqueue(general_queue_t, p);
            }
            pthread_mutex_unlock(&m_general_queue);
            // Passa o comando para o packet_handler
            // para que este trate o novo pacote de acordo com
            // o seu tipo.
            sem_post(&Packet_handler);
        }
        printf("\n→ Você tem uma nova mensagem \\0/\n");
        printf("→ Digite sua ação: ");
    }
    close(SOCKET);
}

void *sender(void *args) {
    Router *r = args;

    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    char message[MESSAGE_LENGTH];

    memset((char*) &client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;

    while(1) {
        sem_wait(&Sender);
        if (pthread_mutex_lock(&m_output_queue) == GET_MUTEX) {
            Packet* p = output_queue_h->packet;
            strcpy(message, p->payload);
        
            client_addr.sin_port = htons(atoi(p->d_port));

            if (inet_aton(p->d_address, &client_addr.sin_addr) == 0) {
                printf("sender: Deu problema no momento de converter o endereço IP\n");
                fprintf(stderr, "inet_aton() failed\n");
                exit(1);  
            }

            if (sendto(SOCKET, message, strlen(message), 0, (struct sockaddr*) &client_addr, client_addr_len) == SEND_FAIL) {
                printf("sender: Houve algum problema no envio da mensagem\n");
            }

            output_queue_h = dequeue(output_queue_h);
            pthread_mutex_unlock(&m_output_queue);
        }
    }
    close(SOCKET);
}
