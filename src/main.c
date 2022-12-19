#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include "socket.c"
#define PORT 8123

int main() {
  
  struct sockaddr_in addr_in;
  int sockfd = create_socket(&addr_in, PORT);
  int addr_size = sizeof(addr_in);
  char *res = "Hello World!";

  while (1) {
    char buffer[1024] = { 0 };
    int new_socket = accept(sockfd, (struct sockaddr*)&addr_in, (socklen_t*)&addr_size);
    read(new_socket, buffer, 1023);
    printf("%s\n", buffer);
    send(new_socket, res, strlen(res), 0);
  }
  return 0;
}
