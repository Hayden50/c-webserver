#include <netinet/in.h>

#ifndef socket 
#define socket 

// Inputs the socket address struct and port # and 
// created server socket
int create_socket(struct sockaddr_in * addr_in, int port);

#endif
