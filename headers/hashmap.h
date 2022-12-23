#ifndef HASH_MAP  
#define HASH_MAP  
#define ARR_SIZE 1024

#import <stdio.h>
#import <string.h>

typedef struct _hash_obj {
  char * key;
  char * value;
  int valid;
} HashObj;

typedef struct _hash_map {
  int size;
  HashObj * backing_arr[ARR_SIZE];
} HashMap;

// Creates the hasmap and allocates space on
// the stack
extern HashMap *init_map();

/** Finds the index for the key value pair */
extern int hashCode(char *key);

// Adds a key value pair to the map
extern void put(char *key, char *value, HashMap *map);

// Gets value when giving a key
extern char * get(char *key, HashMap *map);

// Deletes a key value pair from the map
extern void delete(char *key, HashMap *map);

// Prints the map out
extern void list_map(HashMap *map);

// Creates the routes for the websocket. Will be stored
// in the hashmap by the init function.
extern void create_routes(HashMap *map);

// Frees all malloced data
extern void free_map(HashMap *map);

#endif
