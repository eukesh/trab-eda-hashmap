#pragma once
#include <stdbool.h>
#include <stdlib.h>

unsigned long elf_hash(const char *);


typedef struct item item;
typedef struct hashmap hashmap;
typedef struct lista_linkada lista_linkada;

hashmap *hashmap_create(int );
void hashmap_set(hashmap *map, const char *key, int value);

int hashmap_get(hashmap *map, const char *key);

bool hashmap_has(hashmap *map, const char *key);

static item* linkedlist_remove(lista_linkada* lista);

void hashmap_remove(hashmap *map, const char *key);

int hashmap_size(hashmap *map);

void hashmap_delete(hashmap *map);