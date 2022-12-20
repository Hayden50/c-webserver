#ifndef REQUEST_DATA
#define REQUEST_DATA

typedef struct _request_data {
  char* request_type;
  char* route;
} req_data;

// Parses client request to receive info
extern void get_req_data(req_data *req, char *req_string);

// Free all of the data malloced in get req data
extern void free_request_data(req_data *req);

#endif
