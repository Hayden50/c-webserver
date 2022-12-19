#include <stdio.h>
#include <netinet/in.h>
#include "../headers/socket.h"
#include <sys/socket.h>

int create_socket(struct sockaddr_in * addr_in, int port) {
  // setup socket with communication off-device, TCP connection
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  addr_in->sin_family = AF_INET;
  addr_in->sin_addr.s_addr = INADDR_ANY;
  addr_in->sin_port = htons(port);

  int bind_val = bind(sockfd, (struct sockaddr *) &addr_in, sizeof(addr_in));
  int sock_listening = listen(sockfd, 5);

  return sockfd;
} 
