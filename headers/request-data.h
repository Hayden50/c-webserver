#ifndef REQUEST_DATA
#define REQUEST_DATA

typedef struct _request_data {
  char* request_type;
  char* route;
} req_data;

// Parses client request to receive info
extern req_data * get_req_data(req_data *req, char *req_string);

#endif
