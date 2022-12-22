#include <stdio.h>
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

  char *ok_header = "HTTP/1.1 200 OK\r\n\r\n";
  char *missing_header = "HTTP/1.1 200 OK\r\n\r\n";
  char res[4096];

  HashMap *map = init_map();
  put("user", "pass", map);
  put("key1", "pass1", map);
  char *temp = get("user", map);
  // printf("Value: %s", temp);
  list_map(map);

  while (1) {
    char buffer[4096] = "";
    int new_socket = accept(http_s.socket, NULL, NULL);
    read(new_socket, buffer, 4095);
    printf("%s\n", buffer);
    
    req_data request_data;
    get_req_data(&request_data, buffer);

    if (strcmp(request_data.route, "/") == 0) {
      strcpy(res, ok_header);
      strcat(res, "Equal");
    } else {
      strcpy(res, missing_header);
      FILE *file = fopen("../html-templates/404.html", "r");
      char *new_buff = readfile(file);
      strcat(res, new_buff);
      strcat(res, "\r\n\r\n");
    }

    write(new_socket, res, strlen(res));
    close(new_socket);
  }

  return 0;
}
