#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/request-data.h"
#include "../headers/reader.h"

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

char * handle_route(req_data *req, HashMap *map) {
  char *file = get(req->route, map);
  char *res = malloc(4096);
  
  if (file == NULL) {
    char *missing_header = "HTTP/1.1 404 OK\r\n\r\n";
    strcpy(res, missing_header);
    FILE *file = fopen("../html-templates/404.html", "r");
    char *new_buff = readfile(file);
    strcat(res, new_buff);
    strcat(res, "\r\n\r\n");
  } else {
    char *ok_header = "HTTP/1.1 200 OK\r\n\r\n";
    strcpy(res, ok_header);
    strcat(res, "Equal");
  }
  
  return res;
}

void free_request_data(req_data *req, char *res) {
  free(res);
  free((void *)req->request_type);
  free((void *)req->route);
  free((void *)req);
}
