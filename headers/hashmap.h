#ifndef HASH 
#define HASH

typedef struct _hash_obj_ {
  char * key;
  char * value;
  int valid;
} HashObj;

typedef struct _hash_map {
  int size;
  HashObj * backing_arr[1024];
} HashMap;

extern void init_map(HashMap *map);

extern int hashCode(char *key);

extern int put(char *key, char *value, HashMap *map);

extern char * get(char *key, HashMap *map);

extern void delete(char *key, HashMap *map);

#endif
