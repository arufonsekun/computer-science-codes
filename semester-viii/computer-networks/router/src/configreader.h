#ifndef configreader
#define configreader

#define LINKS_CONFIG "../config/links.config"
#define ROUTERS_CONFIG "../config/routers.config"

char* read_link(int router_id);
char* get_port(char* link);
char* get_ip(char* link);
char* get_neighbors(int router_id);

#endif