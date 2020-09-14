#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

struct node{
    char key;
    int value;
    struct node *next;
}node;

struct hashmap{
    int capacity;
    struct node **list;
}hashmap;

struct hashmap *hashmap_create(int capacity){
    struct hashmap *t = (struct hashmap*)malloc(sizeof(struct hashmap));
    t->capacity = capacity;
    t->list = (struct node**)malloc(sizeof(struct node*)*capacity);
    int i;
    for(i=0;i<capacity;i++)
        t->list[i] = NULL;
    return t;
}

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

//inserir valores
void hashmap_set(struct hashmap *t,const char *key,int value){
    int pos = elf_hash(key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = list;

    int aux = (int)key;

    while(temp){
        if(temp->key==aux){
            temp->value = value;
            return;
        }
        temp = temp->next;
    }
    newNode->key = aux;
    newNode->value = value;
    newNode->next = list;
    t->list[pos] = newNode;
}


