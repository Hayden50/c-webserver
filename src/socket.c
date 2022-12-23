#include <stdio.h>
#include <netinet/in.h>
#include "../headers/socket.h"
#include <sys/socket.h>

void create_socket(http_socket *http_s, int port) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  http_s->port = port;

  struct sockaddr_in addr_in;
  addr_in.sin_family = AF_INET;
  addr_in.sin_addr.s_addr = INADDR_ANY;
  addr_in.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *) &addr_in, sizeof(addr_in)) < 0) {
    printf("Bind Error\n");
  }

  if (listen(sockfd, 5) < 0) {
    printf("Listen Error\n");
  } else {
    printf("Listening on port %d\n\n", port);
  }
  
  http_s->socket = sockfd;
} 
