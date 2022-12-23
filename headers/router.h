#ifndef ROUTER
#define ROUTER

#include "./request-data.h"
#include "./hashmap.h"

extern char * handle_route(req_data *req, HashMap *map);

extern char * handle_get(req_data *req, HashMap *map);

extern char * handle_post(req_data *req, HashMap *map);

#endif 
