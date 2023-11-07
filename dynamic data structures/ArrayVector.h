#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    size_t size;
    size_t cap;
    int* data;
}vector;


void vector_create(vector* v, size_t size){
    v->size = v->cap = size;
    v->data = (int*)malloc(sizeof(int)*size);
}

bool isEmpty(vector* v){
    return v->size==0;
}

size_t Size(vector* v){
    return v->size;
}


void vector_set(vector* v, size_t ind, int data){
    if (ind >=0 && ind < v->size)
    {
        v->data[ind] = data;
    }
    
}


int vector_get(vector* v, size_t ind){
    if (ind >= 0 && ind < v->size)
    {
        return v->data[ind];
    }
    
}


void vector_resize(vector* v, size_t size){
    v->size = size;
    v->cap = size;
    v->data = realloc(v->data, size*sizeof(int));
}

bool vector_equal(vector* lhs, vector* rhs){
    if (lhs->size != rhs->size)
    {
        return false;
    }
    for (int i = 0; i < lhs->size; i++)
    {
        if (lhs->data[i]!=rhs->data[i])
        {
            return false;
        }
        
    }
    return true;
    
}


void vector_destroy(vector* v){
    v->size=v->cap = 0;
    free(v->data);
}