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
  
  void* aux=0;
  if(i>=0){
    aux=l->data[i];
  } else {
    aux=l->data[(l->size)+1];
  }
  if(l->size==0) return NULL;
  if(i<0) i=l->size+i;
  if(i>=0){
    for(int k = i ; k<l->size-1;k++){
      l->data[k]=l->data[k+1];
    }
  }
  l->size--;
  return aux;
}

void* get(ArrayList * l, int i){
  if(i>=l->size) return NULL;
  if(i>=0) return l->data[i];
  if(i<0) return l->data[(l->size)+i];
  return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  if(l->size==0) return;
  if(l->size>0)
  {
    for(int i=0 ; i<l->size;i++){
      pop(l, i);
    }
  }
  l->size=0;
}
