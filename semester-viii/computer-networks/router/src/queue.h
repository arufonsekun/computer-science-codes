#ifndef queue
#define queue

typedef struct packet {
    int message_type;
    char* s_address;
    char* s_port;
    char* d_port;
    char* d_address;
    char* payload;
} Packet;

typedef struct pqueue {
    Packet* packet;
    struct pqueue* next;
} Pqueue;

Pqueue* enqueue(Pqueue* q, Packet p);
Pqueue* dequeue(Pqueue* q);
void* free_queue(Pqueue* q);
void print_queue(Pqueue* q);
int isempty(Pqueue* q);

#endif