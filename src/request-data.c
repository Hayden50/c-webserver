#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/request-data.h"

req_data *get_req_data(req_data *req, char *req_string) {
  char *request_type = (char *)malloc(10);
  char *route = (char *)malloc(2000);

  char *token = strtok(req_string, " ");
  for (int i = 0; i < 2; i++) {
    if (i == 0) {
      strcpy(request_type, token);
    } else {
      strcpy(route, token);
    }
    token = strtok(NULL, " ");
  }
  
  printf("Type: %s\n", request_type);
  printf("Route: %s\n", route);
  req->request_type = request_type;
  req->route = route;

  return req;
}

void free_request_data(req_data *req) {
  free((void *)req->request_type);
  free((void *)req->route);
}
