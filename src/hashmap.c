#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#import "../headers/hashmap.h"

HashMap *init_map() {
  setbuf(stdout, NULL);
  printf("init func start\n");

  HashMap *map = (HashMap *)malloc(sizeof(HashMap));
  map->size = 0;
  for (int i = 0; i < ARR_SIZE; i++) {
    map->backing_arr[i] = (HashObj *)malloc(sizeof(HashObj));
    map->backing_arr[i]->valid = 0;
  }
  
  printf("init func end\n");
  return map;
}

int hashCode(char *key) {
  printf("hashcode func start\n");
  int key_size = strlen(key);
  int res; 

  for (int i = 0; i < key_size; i++) {
    res += (key[i] * (i + 1));
  }
  printf("hashcode func end\n");
  return res % 1024;
}

int put(char *key, char *value, HashMap *map) {
  printf("put func start\n");
  int idx = hashCode(key);
  
  // Faulting somewhere after this point
  while(map->backing_arr[idx]->valid != 0) {
    idx++;
  }
  map->backing_arr[idx]->key = (char *)malloc(strlen(key));
  strcpy(map->backing_arr[idx]->key, key);
  
  map->backing_arr[idx]->value = (char *)malloc(strlen(value));
  strcpy(map->backing_arr[idx]->value, value);
  
  map->backing_arr[idx]->valid = 1;
  map->size = map->size + 1;

  printf("put func end\n");
  return 1;
}

char *get(char *key, HashMap *map) {
  printf("get func start\n");
  int idx = hashCode(key);

  while(map->backing_arr[idx]->valid == 1 
    && strcmp(map->backing_arr[idx]->key, key) != 0) {
    idx++;
  }

  // if(map->backing_arr[idx]->valid == 0) {
  //   printf("couldnt find val");
  //   return NULL;
  // }
  printf("get func end\n");
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
  printf("-------- HASH MAP --------\n\n");
  
  if (map->size == 0) {
    printf("MAP EMPTY\n");
  } else {
    for (int i = 0; i < ARR_SIZE; i++) {
      if (map->backing_arr[i]->valid == 1) {
        printf("Key: %s\nValue: %s\n\n", 
             map->backing_arr[i]->key,
             map->backing_arr[i]->value);
      }
    }    
  }

}
