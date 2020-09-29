#include <stdlib.h>
#include <stdio.h>
#include "hashmap.h"
//

int main() {
  // Algumas strings para testarmos...
  const char *vector[] = {
    "lorem",
    "ipsum",
    "dolor",
    "sit",
    "amet"
  };
  const int length = sizeof vector / sizeof *vector;
  int capacity = 512;
  printf("\n");
  
  hashmap *hash = hashmap_create(capacity);
  printf("----------------------------------\n");
  for(int i=0;i<length;i++){
    const char *p = vector[i];
    int index = elf_hash(p) % capacity;
    int value = 32;
    printf("%s foi adicionado com hash %d\n",vector[i],index);
    hashmap_set(hash,vector[i],value*2);
  }
  printf("----------------------------------");
  printf("\n\tHases | keys | valor\n");
  for(int i=0;i<length;i++){
    const char *p = vector[i];
    int index = elf_hash(p) % capacity;
    printf("\t %d | %s | %d |\n",index,vector[i],hashmap_get(hash,vector[i]));
  }
  printf("----------------------------------\n");
  printf("Tamanho da tabela hash %d\n\n",hashmap_size(hash));
  if(hashmap_has(hash,vector[3]) == true)
    printf("%s esta na tabela\n",vector[3]);
  else
    printf("%s nao esta na tabela\n",vector[3]);
  printf("----------------------------------\n");
  for(int i=0;i<length;i++){
    const char *p = vector[i];
    int index = elf_hash(p) % capacity;
    printf("%s foi removido!\n",vector[i]);
    hashmap_remove(hash,vector[i]);
  }
  printf("----------------------------------\n");
  
  void hashmap_delete(hashmap *map);

  return EXIT_SUCCESS;
}
