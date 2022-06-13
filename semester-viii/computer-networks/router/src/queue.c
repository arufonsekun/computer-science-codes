#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int isempty(Pqueue* q) {
    return q == NULL ? 1 : 0;
}

void print_packet(Packet* p) {
    printf("--------------------------------\n");
    printf("Message type: %d\n", p->message_type);
    printf("Source address: %s\n", p->s_address);
    printf("Source port: %s\n", p->s_port);
    printf("Destination address: %s\n", p->d_address);
    printf("Destination port: %s\n", p->d_port);
    printf("Payload: %s\n", p->payload);
    printf("--------------------------------\n");
}

void print_queue(Pqueue* q) {
    if (q == NULL) {
        printf("Queue empty\n");
    }
    while(q != NULL) {
        print_packet(q->packet);
        printf("\n");
        q = q->next;
    }
}


Pqueue* enqueue(Pqueue* q, Packet p) {
    Pqueue* q1 = (Pqueue*) malloc(sizeof(Pqueue*));
    q1->packet = (Packet*) malloc(sizeof(Packet*));
    q1->packet->message_type = p.message_type;
    q1->packet->s_address = (char*) malloc(strlen(p.s_address) * sizeof(char));
    q1->packet->d_address = (char*) malloc(strlen(p.d_address) * sizeof(char));
    q1->packet->d_port = (char*) malloc(strlen(p.d_port) * sizeof(char));
    q1->packet->s_port = (char*) malloc(strlen(p.s_port) * sizeof(char));
    q1->packet->payload = (char*) malloc(strlen(p.payload) * sizeof(char));
    q1->packet->s_address = p.s_address;
    q1->packet->d_address = p.d_address;
    q1->packet->d_port = p.d_port;
    q1->packet->s_port = p.s_port;
    q1->packet->payload = p.payload;
    q1->next = NULL;

    if (!isempty(q)) {
        q->next = q1;
    }
    return q1;
}


Pqueue* dequeue(Pqueue* q) {
    if (q == NULL) return NULL;
    Pqueue* aux = q;
    q = q->next;
    free(aux->packet);
    free(aux);
    return q;
}

void* free_queue(Pqueue* q) {
    if (q == NULL) {
        printf("Queue empty\n");
    }
    while(q != NULL) {
        q = dequeue(q);
    }
    return NULL;
}

int test() {
    Packet p1, p2, p3;

    p1.message_type = 2;
    p1.s_address = "127.0.0.1";
    p1.d_address = "127.0.0.2";
    p1.d_port = "8008";
    p1.payload = "Alles gut?";

    p2.message_type = 1;
    p2.s_address = "127.0.0.2";
    p2.d_address = "127.0.0.3";
    p2.d_port = "8001";
    p2.payload = "Alles Gut!";

    p3.message_type = 3;
    p3.s_address = "127.0.0.3";
    p3.d_address = "127.0.0.4";
    p3.d_port = "8000";
    p3.payload = "Alles gut?";

    Pqueue* q = NULL;
    Pqueue* tail = NULL;
    q = enqueue(q, p1);

    Packet *p = q->packet;

    printf("payload %s\n", p->payload);
    printf("s_addr %s\n", p->s_address);
    printf("d_addr %s\n", p->d_address);
    printf("port %s\n", p->d_port);
    printf("message_type %d\n", p->message_type);

    // tail = enqueue(q, p2);
    // // tail = enqueue(tail, p3);
 
    // print_queue(q);
    
    // printf("dequeued\n");
    // q = dequeue(q);
    // // q = dequeue(q);

    // print_queue(q);
    // q = free_queue(q);
    // print_queue(q);
    return 0;
}