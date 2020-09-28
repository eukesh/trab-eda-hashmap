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
  //teste 
  // Calcula quantidade de strings acima...
  const int length = sizeof vector / sizeof *vector;

  // Por exemplo, se tivermos 512 buckets disponíveis...
  int capacity = 512;

  //
  for(int i = 0; i < length; i++) {
    const char *s = vector[i];
    int index = elf_hash(s) % capacity;
    printf("%10s: %d\n", s, index);
  }


  
  printf("\n");

  hashmap *hash = hashmap_create(capacity);

  printf("Inserindo %s, %s na tabela\n",vector[0],vector[3]);
  
  hashmap_set(hash, vector[0], 12);
  hashmap_set(hash, vector[3], 24);
  hashmap_set(hash, vector[4], 6545);

  printf("Tamanho da tabela: %d \n",hashmap_size(hash));

  hashmap_delete(hash);
  
  printf("Tamanho da tabela: %d \n",hashmap_size(hash));

  return EXIT_SUCCESS;
}
