#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#import "../headers/hashmap.h"

HashMap *init_map() {
  HashMap *map = (HashMap *)malloc(sizeof(HashMap));
  
  map->size = 0;
  for (int i = 0; i < ARR_SIZE; i++) {
    map->backing_arr[i] = (HashObj *)malloc(sizeof(HashObj));
    map->backing_arr[i]->valid = 0;
  }
  create_routes(map);
  return map;
}

int hashCode(char *key) {
  int key_size = strlen(key);
  int res = 0; 

  for (int i = 0; i < key_size; i++) {
    res += (key[i] * (i + 1));
  }
  return res % 1024;
}

void put(char *key, char *value, HashMap *map) {
  int idx = hashCode(key);
  
  while(map->backing_arr[idx]->valid != 0) {
    idx++;
  }
  map->backing_arr[idx]->key = (char *)malloc(strlen(key) + 1);
  strcpy(map->backing_arr[idx]->key, key);
  
  map->backing_arr[idx]->value = (char *)malloc(strlen(value) + 1);
  strcpy(map->backing_arr[idx]->value, value);
  
  map->backing_arr[idx]->valid = 1;
  map->size = map->size + 1;
}

char *get(char *key, HashMap *map) {
  int idx = hashCode(key);

  while(map->backing_arr[idx]->valid == 1 
    && strcmp(map->backing_arr[idx]->key, key) != 0) {
    idx++;
  }

  return map->backing_arr[idx]->value;
}

void delete(char *key, HashMap *map) {
  int idx = hashCode(key);

  while(map->backing_arr[idx]->valid == 1 
    && strcmp(map->backing_arr[idx]->key, key) != 0) {
    idx++;
  }

  memset(map->backing_arr[idx], 0, sizeof(HashObj));
}

void list_map(HashMap *map) {
  printf("-------- Routing Map --------\n\n");
  
  if (map->size == 0) {
    printf("MAP EMPTY\n");
  } else {
    for (int i = 0; i < ARR_SIZE; i++) {
      if (map->backing_arr[i]->valid == 1) {
        printf("Route: %s\nPage: %s\n\n", 
             map->backing_arr[i]->key,
             map->backing_arr[i]->value);
      }
    }    
  }
  printf("-----------------------------\n");
}

void create_routes(HashMap *map) {
  put("/", "index.html", map);
  put("/about", "about.html", map);
}
