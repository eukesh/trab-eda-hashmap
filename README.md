# Estrutura de Dados - Trabalho Final
  
O aluno deve implementar um tipo de dados abstrato para uma [tabela hash](https://en.wikipedia.org/wiki/Hash_table) (também conhecido como dicionário). Conforme visto em sala, tabelas hash são estruturas de dados associativas, isto é, associam uma chave a um valor, com busca, inserção e remoção eficientes (com o melhor tempo constante).

## Implementação

O código deve ser dividido em sua interface, apresentada em um cabeçalho (./hashmap.h), e sua implementação, em um arquivo fonte (./hashmap.c). Chaves serão representadas como strings, e valores como inteiros. A função de hashing usada deve ser a função ELF hash, presente nesse repositório (e nos slides).

Conforme discutido em sala, buckets podem ser implementados como listas linkadas, ou, idealmente, como árvores de busca binária (como árvores AVL ou árvores RB). As funções a serem implementadas serão descritas a seguir.

- Uma função para criar uma tabela vazia na memória. Essa função irá receber um inteiro como argumento, que será a quantidade de buckets desejados dentro da tabela hash. A função deve retornar `NULL` caso o número seja menor que um.

    ```c
    hashmap *hashmap_create(int capacity);
    ```

- Uma função para inserir valores dentro da tabela. Essa função irá receber como argumentos a tabela desejada, a chave desejada, e o valor a ser salvo. A função deverá encontrar o bucket correto para a chave, e inserir o valor (ou atualizá-lo, caso o valor já exista no bucket). O aluno é responsável por tratar possíveis colisões dentro do bucket.

    ```c
    void hashmap_set(hashmap *map, const char *key, int value);
    ```

- Uma função para procurar o valor de uma chave dentro da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. Caso a chave não exista dentro da tabela, a função deve retornar zero.

    ```c
    void hashmap_get(hashmap *map, const char *key);
    ```

- Uma função para verificar se uma chave existe dentro da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. Caso a tabela contenha um valor para a chave informada, a função deve retornar 1 (verdadeiro). Caso a tabela não contenha um valor para a chave, a função deve retornar 0 (falso).

    ```c
    bool hashmap_has(hashmap *map, const char *key);
    ```

- Uma função que remove uma chave e seu valor da tabela. Essa função irá receber como argumentos a tabela desejada e a chave desejada. Caso a tabela contenha um valor para aquela chave, o valor deve ser removido. Caso a tabela não contenha um valor para aquela chave, nada precisa ser feito.

    ```c
    void hashmap_remove(hashmap *map, const char *key);
    ```

- Uma função que retorna a quantidade de itens (pares de chave e valor) existentes em uma tabela. Seu único argumento é a tabela desejada.

    ```c
    int hashmap_size(hashmap *map);
    ```

- Finalmente, uma função para limpar a memória de uma tabela. Seu único argumento é a tabela a ser deletada. Todos os buckets dentro da tabela precisam ser liberados também.

    ```c
    void hashmap_delete(hashmap *map);
    ```


## Comparação de strings

As funções precisam comparar chaves para tratar colisões. A função `strcmp()`, presente no arquivo `string.h` na bibliteca padrão do C pode ser usada para esse fim. A função recebe duas strings como argumentos, retornando zero se forem iguais. Caso o primeiro argumento seja maior que o segundo (em ordem alfabética), um número positivo é retornado, e, caso primeiro argumento seja menor que o segundo, um número negativo é retornado.

```c
strcmp("bar", "foo"); // -1 ou outro valor negativo
strcmp("foo", "bar"); // 1 ou outro valor positivo
strcmp("bar", "bar"); // 0
strcmp("foo", "foo"); // 0
```

## Quanto à execução do trabalho:

- O trabalho pode ser feito individualmente ou em duplas.
- O trabalho deve ser entregue até o fim do mês (30/09).

## Quanto à entrega:

- Ao aceitar esse trabalho através do GitHub Classroom, o repositório é automaticamente forkado em sua conta.
- Você deve criar uma nova branch, e efetuar seu trabalho dentro dela.
- Seus arquivos devem ser devidamente adicionados à sua branch de trabalho.
- Ao término do trabalho, você deve abrir um pull request da branch contendo o trabalho para a branch master do seu próprio repositório, ao qual o professor tem acesso.
- Efetuar corretamenta a entrega fará parte da avaliação.
