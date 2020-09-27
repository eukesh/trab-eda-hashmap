#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashmap.h"


/**
 * Função padronizada para calcular o hash de uma string.
 */
unsigned long elf_hash(const char *s) {
  unsigned long h = 0;
  for(int i = 0; i < strlen(s); i++) {
    h = (h << 4) + s[i];
    unsigned long x = h & 0xF0000000;
    if(x != 0) {
      h ^= x >> 24;
      h &= ~x;
    }
  }

  return h;
}
//Ht_item
typedef struct item{
  char* key;
  int value;
  struct item *next;
  struct item *prev;
}item;

//HashTable | size
typedef struct hashmap{
  item **items;
  int capacity;
  int count;
}hashmap;

hashmap *hashmap_create(int capacity){
  if(capacity<1){
    return NULL;
  }else{  
    hashmap* map = (hashmap*) malloc (sizeof(hashmap));
    map->capacity = capacity;
    map->count = 0;
    map->items = (item**) calloc (map->capacity, sizeof(item*));
    for (int i=0; i<map->capacity; i++){
      map->items[i] = NULL;
    }
    return map;
    }
}

void hashmap_set(hashmap *map, const char *key, int value){
    //criar item na tabela
    item* new_item = (item*) malloc (sizeof(item));
    new_item->key = (char*) malloc(strlen(key) +1);
    new_item->value = (int) malloc(value +1);
    
    strcpy(new_item->key, key);
    new_item->value = value;
    
    int index = elf_hash(key) % map->capacity;
    
    if ((map->items[index]) == NULL) {
        //key nao existe
        
        if (map->count == map->capacity) {
            //tabela cheia
            printf("Tabela cheia\n");
            return;
        }
        
        //adicionando item
        map->items[index] = new_item; 
        map->count++;
        
    }else {
        //atualizar valor
        if (strcmp(map->items[index]->key, key) == 0) {
            map->items[index]->value = value;
            return;
        }else{
            //colisão tratar mais tarde
            
            return;
        }
    }
  
}

int hashmap_get(hashmap *map, const char *key){
  int hash = elf_hash(key) % map->capacity;

  item* item =map->items[hash];

  if(item != NULL){
    if(strcmp(item->key, key)==0){
      return item->value;
    }
  }
  return 0;

}