#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
// #include "../headers/socket.h"
#define PORT 8123

int main() {
  
  struct sockaddr_in addr_in;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  addr_in.sin_family = AF_INET;
  addr_in.sin_addr.s_addr = INADDR_ANY;
  addr_in.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *) &addr_in, sizeof(addr_in)) < 0) {
    printf("Bind Error");
  }

  if (listen(sockfd, 5) < 0) {
    printf("Listen Error");
  }
  
  char *res = "HTTP/1.1 200 OK\r\n\r\nHello";

  while (1) {
    char buffer[1024] = "";
    int new_socket = accept(sockfd, NULL, NULL);
    read(new_socket, buffer, 1023);
    printf("Response: %s\n", buffer);
    write(new_socket, res, strlen(res));
    close(new_socket);
  }

  return 0;
}
