#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList * l= (ArrayList*)malloc(sizeof(ArrayList));

  l->data= malloc(sizeof(void*)*2);

  l->capacity=2;
  l->size=0;
  
  return l;
  
}

void append(ArrayList * l, void * data){

  if(l->size==l->capacity)
  {
    l->capacity*=2;
    l->data=realloc(l->data, sizeof(void*)*l->capacity);
  }
  l->data[l->size]=data;
  l->size++;
}

void push(ArrayList * l, void * data, int i){
  if(i>l->size) return;

  if(l->size==l->capacity)
  {
    l->capacity*=2;
    l->data=realloc(l->data, sizeof(void*)*l->capacity);
  }

  for(int k = l->size ; k>i;k--){
    l->data[k]=l->data[k-1];
  }
  l->data[i]=data;
  l->size++;

}

void* pop(ArrayList * l, int i){
  void* aux=l->data[i];
  for(int k = i ; k>l->size;k++){
    
    l->data[k]=l->data[k+1];
  }
  return aux;
}

void* get(ArrayList * l, int i){
  if(i>l->size || i<0) return NULL;
  if(i>=0 && i< l->size) return l->data[i];
  int pos = l->size-1-i;
    if(pos>=0) return l->data[pos];
    return NULL;
  
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
