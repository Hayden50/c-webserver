#import <stdio.h>
#import <string.h>
#import "../headers/hashmap.h"

void init_map(HashMap *map) {
  map->size = 0;
  memset(map->backing_arr, 0, sizeof(map->backing_arr));
  for (int i = 0; i < 1024; i++) {
    map->backing_arr[i]->valid = 0;
  }
}

int hashCode(char *key) {
  int key_size = strlen(key);
  int res; 

  for (int i = 0; i < key_size; i++) {
    res += (key[i] * (i + 1));
  }
  return res % 1024;
}

int put(char *key, char *value, HashMap *map) {
  int idx = hashCode(key);
  
  while(map->backing_arr[idx] != 0) {
    idx++;
  }
  map->backing_arr[idx]->key = key;
  map->backing_arr[idx]->value = value;
  map->backing_arr[idx]->valid = 1;

  map->size = map->size + 1;
  return 1;
}

char *get(char *key, HashMap *map) {
  int idx = hashCode(key);

  while(map->backing_arr[idx]->valid == 1 
    && strcmp(map->backing_arr[idx]->key, key) != 0) {
    idx++;
  }

  if(map->backing_arr[idx]->valid == 0) {
    return NULL;
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
  for (int i = 0; i < 1024; i++) {
    if (map->backing_arr[i]->valid == 1) {
      printf("Key: %s\nValue: %s\n\n", 
             map->backing_arr[i]->key,
             map->backing_arr[i]->value);
    }
  }
}
