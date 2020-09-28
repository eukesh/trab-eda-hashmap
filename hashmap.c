#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashmap.h"


/**
 * Função padronizada para calcular o hash de uma string.
 */
unsigned long elf_hash(const char *s){
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

typedef struct item{
  char *key;
  int value;
}item;

typedef struct hashmap{
  lista_linkada** lista;
  int capacity;
  int count;
}hashmap;

typedef struct lista_linkada{
  item* item;
  lista_linkada* next;
}lista_linkada;

hashmap *hashmap_create(int capacity){
  if(capacity<1){
    return NULL;
  }else{  
    hashmap* map = (hashmap*) malloc (sizeof(hashmap));
    map->capacity = capacity;
    map->count = 0;
    map->lista = (lista_linkada**) calloc (map->capacity, sizeof(lista_linkada*));
    
    for (int i=0; i<map->capacity; i++){
      map->lista[i] = NULL;
    }
    return map;
    }
}

void hashmap_set(hashmap *map, const char *key, int value){
    //criar item na tabela
    lista_linkada* new_item = (lista_linkada*) malloc (sizeof(lista_linkada));
    new_item->item = (item*) malloc (sizeof(item));
    new_item->next = NULL;
    new_item->item->key = (char*) malloc(strlen(key) +1);
    new_item->item->value = (int) malloc(value +1);
    
    strcpy(new_item->item->key, key);
    new_item->item->value = value;
    
    int index = elf_hash(key) % map->capacity;
    
    if ((map->lista[index]) == NULL) {
        //key nao existe
        
        if (map->count == map->capacity) {
            //tabela cheia
            printf("Tabela cheia\n");
            return;
        }
        
        //adicionando item
        map->lista[index] = new_item; 
        map->count++;
        
    }else {
        //atualizar valor
        if (strcmp(map->lista[index]->item->key, key) == 0) {
            map->lista[index]->item->value = value;
            return;
        }else{
          //colisao, tratar lista linkada
            
          return;
        }
    }
  
}

int hashmap_get(hashmap *map, const char *key){
  int index = elf_hash(key) % map->capacity;

  lista_linkada* search = map->lista[index];

  if(search != NULL){
    if(strcmp(search->item->key, key)==0){
      return search->item->value;
    }
  }
  return 0;

}

void hashmap_remove(hashmap *map, const char *key){
  int index = elf_hash(key) % map->capacity;

  if(map->lista[index] != NULL){
    if(strcmp(map->lista[index]->item->key, key)==0){
      free(map->lista[index]->item->key);
      map->lista[index]->item->value = 0;
      free(map->lista[index]);
      map->count--;
      return;
    } 
  }else{
    printf("Item não existe\n");
    return;
  }
}

int hashmap_size(hashmap *map){
  return map->count;  
}

void hashmap_delete(hashmap *map){
    
  for(int i=0; i<map->capacity; i++){
    lista_linkada* item = map->lista[i];
    if (item != NULL){
      free(map->lista[i]->item->key);
      map->lista[i]->item->value = 0;
      free(map->lista[i]);
    }
  }

  free(map->lista);
  free(map);
}

