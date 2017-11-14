#include <stdio.h>
#include "array_list_int.h"


int main(){
  array_list_int a1 = ali_create();
  int i;
  for (i=0; i < 10000000; ++i)
    ali_push_back(a1,i+1);
  printf("Tamanho de a1: %d\n",ali_size(a1));
  /*printf("a1 = { ");
  for (i=0; i < ali_size(a1) ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n"); */
  printf("porcento ocupado: %lf\n" ,ali_percent_occuped(a1));
  /*printf("O numero %d está no indice %d\n", 1, ali_find(a1, 1));
  ali_insert_at(a1, 5, 21);
  printf("a1 = { ");
  for (i=0; i < ali_size(a1) ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");
  printf("porcento ocupado: %lf\n" ,ali_percent_occuped(a1));
  ali_remove_from(a1, 5);
  printf("a1 = { ");
  for (i=0; i < ali_size(a1) ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");
  printf("porcento ocupado: %lf\n" ,ali_percent_occuped(a1));*/

  ali_destroy(a1);
  return 0;
}
