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

    pthread_create(&t0, NULL, receiver, r);
    pthread_create(&t1, NULL, sender, r);
    pthread_create(&t2, NULL, packet_handler, r);
    pthread_create(&t3, NULL, terminal, r);
    
    sem_post(&Terminal);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Todas as threads foram finalizas\n");
    exit(EXIT_SUCCESS);
}


void *receiver(void *args) {
    Router* r = args;
    struct sockaddr_in servaddr, cliaddr;

    int sockfd, recv_len, clieaddr_len;
    clieaddr_len = sizeof(cliaddr);
    
    char buffer[MESSAGE_LENGTH];
    char response[] = {"Pacote recebido!\n"};

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_CREATE_FAIL) { 
        perror("receiver: A criação do socket falhou\n");
        exit(EXIT_FAILURE); 
    }
    printf("receiver: Socket criado com sucesso\n");
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Configuração do socket
    servaddr.sin_family = AF_INET; // IPv4
    printf("receiver: A porta configurada é %d", atoi(r->port));
    servaddr.sin_port = htons(atoi(r->port));
    
    // Depois arrumar esse ==0
    if (inet_aton(r->ip, &servaddr.sin_addr) == 0) {
        printf("receiver: Deu problema no momento de converter o endereço IP\n");
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);  
    }

    if (bind(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr)) == SOCKET_BIND_FAIL) {
        perror("receiver: Bind do socket falhou\n");
        perror("receiver: É possível que a porta já esteja em uso\n");
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }

    int len, n;
    while(1) {
        printf("receiver: Esperando por mensagens...\n");
        fflush(stdout);
        memset(buffer, '\0', MESSAGE_LENGTH);

        // recvfrom é bloqueante, então não precisa se preocupar com o while(1)
        if (recv_len = recvfrom(sockfd, buffer, MESSAGE_LENGTH, 0, (struct sockaddr*) &cliaddr, &clieaddr_len) == RECEIVE_MESSAGE_ERROR) {
            printf("receiver: Houve um problema na hora de receber a mensagem\n");
        }
        // Pegar conteúdo recebido, criar um pacote e acionar o packet handler.
        printf("receiver: Pacote recebido de %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        printf("receiver: Payload: %s\n" , buffer);

        if (sendto(sockfd, response, RESPONSE_LENGTH, 0, (struct sockaddr*) &cliaddr, clieaddr_len) == RESPONSE_FAIL) {
            printf("receiver: Houve um problema no momento de responder a mensagem\n");
        }
        printf("receiver: Resposta enviada com sucesso \0/\n");

    }
    close(sockfd);
}


void *sender(void *args) {
    Router *r = args;
    // Implementar parte de enviar do Socket
    printf("sender: Instanciando o socket para envio de mensagens\n");

    struct sockaddr_in si_other;
    int s, i, slen = sizeof(si_other);
    char response[RESPONSE_LENGTH];
    char message[MESSAGE_LENGTH];

    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_CREATE_FAIL) {
        perror("sender: A criação do socket falhou\n");
        exit(EXIT_FAILURE); 
    }
    printf("sender: Socket criado com sucesso\n");
    memset((char*) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;

    while(1) {
        sem_wait(&Sender);
        printf("sender: teste\n");
        if (pthread_mutex_lock(&m_output_queue) == GET_MUTEX) {
            printf("sender: Conseguiu pegar o mutex: m_output_queue\n");
            Packet* p = output_queue_h->packet;
            print_packet(p);
            strcpy(message, p->payload);
            printf("sender: message: %s", message);
            pthread_mutex_unlock(&m_output_queue);
        
            // Configura a porta de destino da mensagem
            printf("sender: A porta configurada é %d", atoi(p->d_port));
            si_other.sin_port = htons(atoi(p->d_port));

            // Depois arrumar esse ==0
            if (inet_aton(r->ip, &si_other.sin_addr) == 0) {
                printf("sender: Deu problema no momento de converter o endereço IP\n");
                fprintf(stderr, "inet_aton() failed\n");
                exit(1);  
            }

            if (sendto(s, message, strlen(message), 0, (struct sockaddr*) &si_other, slen) == SEND_FAIL) {
                printf("sender: Houve algum problema no envio da mensagem\n");
            }

            memset(response, '\0', RESPONSE_LENGTH);
            // Lê a resposta do outro roteador
            if (recvfrom(s, response, RESPONSE_LENGTH, 0, (struct sockaddr*) &si_other, &slen) == RESPONSE_FAIL) {
                printf("sender: Roteador de destino teve algum problema ao responder a mensagem ;(\n");
            }
            printf("sender: O roteador de destino respondeu: %s\n", response);
            output_queue_h = dequeue(output_queue_h);
        }
    }
    close(s);
}


void *packet_handler(void *args) {
    Router* r = args;
    // printf("packet_handler está pronto\n");
    while(1) {
        sem_wait(&Packet_handler);
        printf("packet_handler: Teste\n");
        if (pthread_mutex_lock(&m_general_queue) == GET_MUTEX) {
            printf("packet_handler: Conseguiu pegar o mutex\n");
            Packet p;
            p.s_address = general_queue_h->packet->s_address;
            p.d_address = general_queue_h->packet->d_address;
            p.d_port = general_queue_h->packet->d_port;
            p.payload = general_queue_h->packet->payload;
            p.message_type = general_queue_h->packet->message_type;

            printf("packet_handler: s_address %s\n", p.s_address);
            printf("packet_handler: o pacote recebido é:\n");
            printf("payload %s\n", p.payload);
            printf("d_addr %s\n", p.d_address);
            printf("port %s\n", p.d_port);
            printf("message_type %d\n", p.message_type);

            general_queue_h = dequeue(general_queue_h);

            printf("packet_handler: s_address %s\n", p.s_address);
            printf("packet_handler: o pacote recebido é:\n");
            printf("payload %s\n", p.payload);
            printf("d_addr %s\n", p.d_address);
            printf("port %s\n", p.d_port);
            printf("message_type %d\n", p.message_type);

            if (p.message_type == DATA) {
                printf("packet_handler: É uma mensagem de dados\n");
                // O pacote desenfileirado é para
                // o roteador atual, mostra ele.
                if (strcmp(p.d_address, r->ip) && strcmp(p.d_port, r->port)) {
                    printf("packet_handler: O roteador atual recebeu uma mensagem\n");
                    print_packet(p);
                } else {
                    printf("packet_handler: A mensagem não é para o roteador atual\n");
                    // O pacote desenfileirado não é para
                    // o roteador atual, então ele deve ser enviado
                    // para seu destino.
                    if (pthread_mutex_lock(&m_output_queue) == GET_MUTEX) {
                        printf("packet_handler: Conseguiu pegar o m_output_queue\n");
                        if (output_queue_h == NULL) {
                            output_queue_h = enqueue(output_queue_h, p);
                            output_queue_t = output_queue_h;
                        } else {
                            output_queue_t = enqueue(output_queue_t, p);
                        }
                        pthread_mutex_unlock(&m_output_queue);
                        sem_post(&Sender);
                    }
                }
            } else {
                // Pacote desenfileirado é de controle
                // Não fazer nada por hora
            }
            pthread_mutex_unlock(&m_general_queue);
        }
    }
}


void *terminal(void *args) {
    Router* r = args;
    sem_wait(&Terminal);
    int action, neighbor_id;
    char message[100];
    char* neighbors = get_neighbors(r->id);
    char* neighbors_cp = malloc(sizeof(char) * strlen(neighbors));
    strcpy(neighbors_cp, neighbors);

    while(1) {
        printf("BEM-VINDO AO ROTEADOR SIMULATOR\n");
        printf("1. Mandar uma mensagem algum dos seus vizinhos.\n");
        printf("2. Visualizar mensagens recebidas.\n");
        printf("Ctrl+C para encerrar.\n");
        printf("→ Digite sua ação: ");
        scanf("%d", &action);
        if (action == 1) {
            printf("Seus roteadores vizinhos são: ");
            char* n = strtok_r(neighbors, ",", &neighbors);
            while (n != 0) {
                printf("%s ", n);
                n = strtok_r(neighbors, ",", &neighbors);
            }
            printf("\n");
            printf("Digite o vizinho com quem deseja se comunicar: ");
            scanf("%d", &neighbor_id);
            printf("Digite sua mensagem: ");
            fflush (stdin);
            scanf("%s", message);

            Packet p;
            p.s_address = (char*) malloc(sizeof(char) * 100);
            p.d_address = (char*) malloc(sizeof(char) * 100);
            // p.payload = (char*) malloc(sizeof(char) * 100);
            p.d_port = (char*) malloc(sizeof(char) * 10);

            char* router = read_link(neighbor_id);
            char* router_cp = (char*) malloc(sizeof(char) * strlen(router));
            strcpy(router_cp, router);

            p.message_type = DATA;
            strcpy(p.s_address, r->ip);
            p.payload = message;
            p.d_port = get_port(router);
            p.d_address = get_ip(router_cp);

            // Manda o pacote para o packet_handler
            if (pthread_mutex_lock(&m_general_queue) == GET_MUTEX) {
                if (general_queue_h == NULL) {
                    printf("terminal: Empilhou o pacote\n");
                    general_queue_h = enqueue(general_queue_h, p);
                    general_queue_t = general_queue_h;
                } else {
                    general_queue_t = enqueue(general_queue_t, p);
                }
                pthread_mutex_unlock(&m_general_queue);
                sem_post(&Packet_handler);
            }
        } else if (action == 2) {
            printf("Suas mensagens são...\n");
        } else if (action == 3) {
            pthread_exit(NULL);
        } else {
            printf("Ação inválida, digite novamente: \n");
        }
        strcpy(neighbors, neighbors_cp);
    }
}