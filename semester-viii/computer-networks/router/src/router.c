#include <stdio.h>
#include <stdlib.h>

#define ROUTER "./src/config/router.config"
#define LINKS "./src/config/links.config"

void reciever() {

}

void sender() {

}

void packet_handler() {

}

void terminal() {

}

int main(int argc, char *argv[]) {
    int router_id = atoi(argv[1]);
    printf("O roteador que deve ser instanciado é %d\n", router_id);
    return 0;
}