#include <stdio.h>
#include <stdlib.h>

#define ROUTER "./src/config/router.config"
#define LINKS "./src/config/links.config"
#define CONTROL 0
#define DATA 1

typedef struct packet {
    unsigned message_type;
    char *s_address;
    char *d_address;
    char *payload;
} Packet;

void *reciever() {

}

void *sender() {

}

void *packet_handler() {

}

void *terminal() {

}

int main(int argc, char *argv[]) {
    int router_id = atoi(argv[1]);
    printf("O roteador que deve ser instanciado é %d\n", router_id);
    return 0;
}