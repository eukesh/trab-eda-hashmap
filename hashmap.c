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
        
    }else{
        //atualizar valor
        if (strcmp(map->lista[index]->item->key, key) == 0) {
          map->lista[index]->item->value = value;
          return;
        }else{
          lista_linkada *temp = map->lista[index];
          
          do{
            if(temp->next == NULL){
              temp->next = (lista_linkada*) malloc (sizeof(lista_linkada));
              map->lista[index]->next = new_item;
              map->count++;
              return;
            }

          }while(temp->next != NULL);
            
          return;
        }
    }
  
}

bool hashmap_has(hashmap *map, const char *key) {
  int index = elf_hash(key) % map->capacity;

  lista_linkada* search = map->lista[index];

  if(search != NULL){
    if(strcmp(search->item->key, key)==0){
      return true;
    }
  }
  return false;
}
int hashmap_get(hashmap *map, const char *key){
  int index = elf_hash(key) % map->capacity;

  lista_linkada* search = map->lista[index];
  lista_linkada* temp = NULL;

  int aux = 0;
  if(search != NULL){
    do{
      if(strcmp(search->item->key, key)==0){
        return search->item->value;
        aux++;
      }else if(search->next != NULL){
        temp = search->next;
        search = temp;
      }else{
        aux++;
      }
    }while(aux == 0) ;
  }
  return 0;

}
static item* linkedlist_remove(lista_linkada* lista) {
    if (!lista)
        return NULL;
    if (!lista->next)
        return NULL;
    lista_linkada* node = lista->next;
    lista_linkada* temp = lista;
    temp->next = NULL;
    lista = node;
    item* aux = NULL;
    memcpy(temp->item, aux, sizeof(item));
    free(temp->item->key);
    free(temp->item);
    free(temp);
    return aux;
}
void hashmap_remove(hashmap *map, const char *key){
  int index = elf_hash(key) % map->capacity;
  
  lista_linkada* search = map->lista[index];
  lista_linkada* temp = NULL;
  
  int aux = 0;
  
  if(search != NULL){
    do{
      if(strcmp(search->item->key, key)==0){
        temp = search;
        search = search->next;
        temp->next = NULL;
        linkedlist_remove(temp);
        map->lista[index] = search;
        map->count--;
        aux++;
      }else if(search->next == NULL){
        aux++;
      }else{
        temp = search->next;
        search = temp;
      }
    }while(aux == 0);
  }else{
    printf("Item não existe\n");
    return;
  }
}

int hashmap_size(hashmap *map){
  return map->count;  
}

void hashmap_delete(hashmap *map){
  free(map->lista);
  free(map);
}

