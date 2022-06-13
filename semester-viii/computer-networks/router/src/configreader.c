#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configreader.h"

char* read_link(int router_id) {
    FILE* links;
    char* link = NULL;
    char* router_config = NULL;
    size_t len = 0;
    ssize_t read;
    int read_line_counter = 0;

    links = fopen(ROUTERS_CONFIG, "r");
    if (links == NULL) {
        printf("Arquivo de configuração do roteador não encontrado.\n");
        return NULL;
    }
    while((read = getline(&link, &len, links)) != -1) {
        read_line_counter++;
        if (read_line_counter == router_id) {
            router_config = link;
            break;
        }
    }
    fclose(links);

    if (router_config == NULL) {
        printf("Configuração para o routeador %d não encontrada\n", router_id);
        return NULL;
    } 
    router_config[strcspn(router_config, "\r\n")] = 0;
    return router_config;
}

char* get_port(char* link) {
    char* port = strtok_r(link, " ", &link);
    port = strtok_r(link, " ", &link);
    return port;
}

char* get_ip(char* link) {
    char* ip = strtok_r(link, " ", &link);
    ip = strtok_r(link, " ", &link);
    ip = strtok_r(link, " ", &link);
    return ip;
}

char* get_neighbors(int router_id) {
    FILE* paths;
    char* path = NULL;
    size_t len = 0;
    ssize_t read;
    char* r1;
    char* r2;
    char* neighbors = (char*) malloc(sizeof(char) * 100);

    paths = fopen(LINKS_CONFIG, "r");
    if (paths == NULL) {
        printf("Arquivo de enlaces não encontrado.\n");
        return NULL;
    }
    while((read = getline(&path, &len, paths)) != -1) {
        path[strcspn(path, "\r\n")] = 0;

        char* r1 = strtok_r(path, " ", &path);
        char* r2 = strtok_r(path, " ", &path);

        if (atoi(r1) == router_id) {
            strcat(neighbors, r2);
            strcat(neighbors, ",");
        } else if (atoi(r2) == router_id) {
            strcat(neighbors, r1);
            strcat(neighbors, ",");
        }
    }
    neighbors[strlen(neighbors)-1] = '\0';
    fclose(paths);
    return neighbors;
}