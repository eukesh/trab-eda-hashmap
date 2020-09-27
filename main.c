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

  printf("Inserindo lorem e 12\n");
  
  hashmap_set(hash, vector[0], 12);
  printf("Verificando se a key consta");
  int aux = hashmap_get(hash,vector[0]);
  if(aux == 0){
    printf("A key não consta no hash\n");
  }else{
    printf("valor da key %d\n",aux);
  }
  

  
  return EXIT_SUCCESS;
}
