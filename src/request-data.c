#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/request-data.h"

void get_req_data(req_data *req, char *req_string) {
  req->request_type = (char *)malloc(10);
  req->route = (char *)malloc(2000);

  char *token = strtok(req_string, " ");
  for (int i = 0; i < 2; i++) {
    if (i == 0) {
      strcpy(req->request_type, token);
    } else {
      strcpy(req->route, token);
    }
    token = strtok(NULL, " ");
  }
}

void free_request_data(req_data *req) {
  free((void *)req->request_type);
  free((void *)req->route);
}
