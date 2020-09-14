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
  char* value;
};
//HashTable | size
struct hashmap{
  item** items;
  int capacity;
  int count;
};

hashmap *hashmap_create(int capacity){
  hashmap* table = (hashmap*) malloc (sizeof(hashmap));
  table->capacity = capacity;
  table->count = 0;
  table->items = (item**) calloc (table->capacity, sizeof(item*));
  for (int i=0; i<table->capacity; i++)
      table->items[i] = NULL;

  return table;

}

