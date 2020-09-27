#include <stdlib.h>
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
struct item{
  char* key;
  int value;
  struct item *next;
  struct item *prev;
} item;
};
//HashTable | size
struct hashmap{
  item** items;
  int capacity;
  int count;
};

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
 
    item* item_actual = map->items[hash];
     
    if (item_actual == NULL) {
        //key nao existe
        if (map->count == map->capacity) {
            //tabela cheia
            printf("Tabela cheia\n");
            return;
        }
         
        //adicionando item
        map->items[hash] = new_item; 
        map->count++;
    }else {
        //atualizar valor
        if (strcmp(item_actual->key, key) == 0) {
            strcpy(map->items[hash]->value, value);
            return;
        }else{
            //colisão tratar mais tarde
            colision(map, item);
            return;
        }
    }
}

