#include <stdio.h>
#include "array_list_int.h"

int main(){
  array_list_int a1 = ali_create();
  int i,t;
  for (i=0; i < 1000 ; ++i)
    ali_push_back(a1,i*3+1);
  t = ali_size(a1);
  printf("Tamanho de a1: %d\n",t);
  printf("a1 = { ");
  for (i=0; i < t ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");

  printf("O numero %d está no indice %d\n", 22, ali_find(a1, 22));

  ali_insert_at(a1, 5, 21);
  printf("a1 = { ");
  for(i=0; i < ali_size(a1) ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");

  ali_remove_from(a1, 5);
  printf("a1 = { ");
  for (i=0; i < ali_size(a1) ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");

  for (i=0; i < ali_size(a1) ; ++i)
    ali_pop_back(a1);
  t = ali_size(a1);
  printf("Tamanho de a1: %d\n",t);
  printf("a1 = { ");
  for (i=0; i < t ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");


  ali_destroy(a1);
  return 0;
}
