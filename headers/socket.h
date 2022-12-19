#include <netinet/in.h>

#ifndef SOCKET 
#define SOCKET 

typedef struct _http_socket {
  int socket;
  int port;
} http_socket; 

// Inputs the socket address struct and port # and 
// created server socket
extern void create_socket(http_socket *http_s, int port);

#endif
