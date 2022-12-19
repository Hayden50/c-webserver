#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
  
  // setup socket with communication off-device, TCP connection
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  struct sockaddr_in addr_in;
  addr_in.sin_family = AF_INET;
  addr_in.sin_addr.s_addr = INADDR_ANY;
  addr_in.sin_port = htons(8123);
  
  int bind_val = bind(sockfd, (struct sockaddr *) &addr_in, sizeof(addr_in));
  int sock_listening = listen(sockfd, 5);

  return 0;
}
