#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include "../headers/request-data.h"
#include "../headers/socket.h"
#include "../headers/reader.h"
#include "../headers/hashmap.h"
#define PORT 8123

int main() {
  
  http_socket http_s;
  create_socket(&http_s, PORT);

  HashMap *map = init_map();
  list_map(map);

  while (1) {
    char buffer[4096] = "";
    int new_socket = accept(http_s.socket, NULL, NULL);
    read(new_socket, buffer, 4095);
    printf("%s\n", buffer);
    
    req_data *request_data = (req_data *)malloc(sizeof(req_data));
    get_req_data(request_data, buffer);

    char *res = handle_route(request_data, map);

    write(new_socket, res, strlen(res));
    close(new_socket);
  }

  return 0;
}
