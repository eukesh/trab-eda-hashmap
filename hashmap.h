#pragma once
#include <stdbool.h>


typedef struct item item;
typedef struct hashmap hashmap;

hashmap *hashmap_create(int );

void hashmap_set(hashmap *, const char *, int );

unsigned long elf_hash(const char *);

