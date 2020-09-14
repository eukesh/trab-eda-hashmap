#pragma once
#include <stdbool.h>

typedef struct item item;
typedef struct hashmap hashmap;

hashmap *hashmap_create(int capacity);

unsigned long elf_hash(const char *);

