#include "array_list_int.h"

#include <stdlib.h> /* For malloc and free */

#define MAGIC 314159265

struct array_list_int{
  int *a;
  int size;
  int capacity;
  int magic;
};

/* Internal functions */

/* Check if the pointer actually points to a valid array_list_int struc */
int ali_check_type(array_list_int ali){
  if (ali->magic!=MAGIC){
    return 0;
  } else {
    return 1;
  }
}

/* Increase capacity size of the array_list_int internal storage */
int ali_realloc(array_list_int ali){
  int size_antigo = ali->size;
  int *antigo = ali->a;
  int *a = (int*)malloc(sizeof(int)*(size_antigo*2));
  int i;

  if(a == 0)
    return 0;

  for(i=0;i<size_antigo;i++)
    a[i]=ali->a[i];
  ali->a = a;
  ali->capacity=(ali->size)*2;
  free(antigo);

  return 1;
}

/* External (public) functions.
 * + Defined in array_list_int.h file
 */

/* creates new instance of a dynamic array */
array_list_int ali_create(){
  array_list_int ali = (array_list_int)malloc(sizeof(struct array_list_int));
  ali->a = (int*)malloc(sizeof(int)*4);
  ali->size=0;
  ali->capacity=4;
  ali->magic=MAGIC;
  return ali;
}

/* Gets the element at index 'index' */
int ali_get(array_list_int ali, int index){
  if (!ali_check_type(ali))
    return 0;
  if (index<0 || index>=ali->size){
    return 0;
  }
  return ali->a[index];
}

/* Adds elemento 'i' to the end of the dynamic array */
unsigned int ali_push_back(array_list_int ali, int i){
  if (!ali_check_type(ali))
    return 0;

  if(ali_percent_occuped(ali) >= 99.00)
    ali_realloc(ali);
    
  ali->a[ali->size++]=i;
  return ali->size;
}

/* Removes last element of dynamic array 'ali'
 */
unsigned int ali_pop_back(array_list_int ali){
  if (!ali_check_type(ali))
    return -1;
  if (ali->size == 0)
      return 0;
  return --(ali->size);
}


/* Gets number of int elements stored in 'ali' */
unsigned int ali_size(array_list_int ali){
  if (!ali_check_type(ali))
    return 0;
  return ali->size;
}


/*
 * Find element inside array using binary search; if it can't be found, returns -1
*/
int ali_find(array_list_int ali, int element){
  int i;
  for(i=0;i<ali->size;i++)
    if(ali->a[i] == element)
      return i;
  return -1;
}

/**
 *  returns the value that was inserted;
 */
int ali_insert_at(array_list_int ali, int index, int value){
  if (index>=0 && index<ali->size){

    if(ali_percent_occuped(ali) >= 99.00)
      ali_realloc(ali);

    int size = ali->size-1;
    while(size >= index){
      if(size == index) ali->a[size] = value;
      else ali->a[size] = ali->a[size-1];
      size--;
    }
    return value;
  }
  return -1;
}

/**
 * return the new size after the removing;
 */
int ali_remove_from(array_list_int ali, int index){
  int size = ali->size-1;
  if(index>=0 && index<=size){
    while(index < size){
      ali->a[index] = ali->a[index+1];
      index++;
    }
    ali->size = size;
  }
  if(ali_percent_occuped(ali) <= 25.00)
    ali_realloc(ali);

  return ali->size;
}

/**
 * returns array capacity;
 */
unsigned int ali_capacity(array_list_int ali){
  return ali->capacity;
}


/**
 * returns the percent occupation inside the array;
 */
double ali_percent_occuped(array_list_int ali){
  return (ali->size*100)/(ali->capacity);
}

/* Release memory used by the struct and invalidate it. */
void ali_destroy(array_list_int ali){
  free(ali->a);
  ali->size=0;
  ali->capacity=0;
  ali->magic=0;
}
