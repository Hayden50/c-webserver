#include <stdio.h>
#include <string.h>
#include "../headers/router.h"
#include "../headers/hashmap.h"
#include "../headers/reader.h"
#include "../headers/request-data.h"

char * handle_route(req_data *req, HashMap *map) {
  if (strcmp(req->request_type, "GET") == 0) {
    return handle_get(req, map);
  } else if (strcmp(req->request_type, "POST") == 0) {
    return handle_post(req, map);
  }
  return "SOMETHING OTHER THAN GET/POST USED";
}

char * handle_get(req_data *req, HashMap *map) {
  char *file = get(req->route, map) == NULL ? "404.html" : get(req->route, map);
  char *res = malloc(4096);
  char *file_address = malloc(100);
  char *header;
  char *start_address = "../html-templates/";

  // If the route is in the map, header is a 200, else 404
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

// TODO
char * handle_post(req_data *req, HashMap *map) {
  char *header = "HTTP/1.1 200 OK\r\n\r\n";
  char *res = malloc(4096);
  strcpy(res, header);

  char *temp = "post hello";
  strcat(res, temp);
  strcat(res, "\r\n\r\n");
  
  return res;
}
