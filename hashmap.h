#pragma once
#include <stdbool.h>


typedef struct item item;
typedef struct hashmap hashmap;

hashmap *hashmap_create(int capacity);

void hashmap_set(hashmap *map, const char *key, int value);

unsigned long elf_hash(const char *);

