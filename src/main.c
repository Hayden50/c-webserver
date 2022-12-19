#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include "../headers/request-data.h"
#include "../headers/socket.h"
#define PORT 8123

int main() {
  
  http_socket http_s;
  create_socket(&http_s, PORT);

  char *res = "HTTP/1.1 200 OK\r\n\r\nHello";

  while (1) {
    char buffer[1024] = "";
    int new_socket = accept(http_s.socket, NULL, NULL);
    read(new_socket, buffer, 1023);
    printf("%s\n", buffer);
    
    req_data request_data;
    get_req_data(&request_data, buffer);

    write(new_socket, res, strlen(res));
    close(new_socket);
  }

  return 0;
}
