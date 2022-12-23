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
  char *file = get(req->route, map) == NULL ? "404.html" : get(req->route, map);
  char *res = malloc(4096);
  char *file_address = malloc(100);
  char *header;
  char *start_address = "../html-templates/";

  header = file != NULL ? "HTTP/1.1 200 OK\r\n\r\n" : "HTTP/1.1 404 NOT FOUND\r\n\r\n";
  strcpy(res, header);
  strcpy(file_address, start_address);
  strcat(file_address, file);

  FILE *new_file = fopen(file_address, "r");
  char *new_buff = readfile(new_file);
    
  strcat(res, new_buff);
  free(file_address);
  strcat(res, "\r\n\r\n");
  
  return res;
}

void free_request_data(req_data *req, char *res) {
  free(res);
  free((void *)req->request_type);
  free((void *)req->route);
  free((void *)req);
}
