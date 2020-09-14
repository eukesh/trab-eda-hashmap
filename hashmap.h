#pragma once
#include <stdbool.h>

unsigned long elf_hash(const char *);

struct node;

struct hashmap;

struct hashmap *hashmap_create(int capacity);

void hashmap_set(struct hashmap *t,const char *key,int value);
