#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int POOL_SIZE = 100;


typedef struct{
    size_t size;
    int* data;

}stack;

stack* stack_create(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->data = (int*)malloc(POOL_SIZE*sizeof(int));
    s->size = 0;
    return s;
}

bool isEmpty(stack* s){
    return s->size==0;
}

size_t stackSize(stack* s){
    return s->size;
}

bool stack_push(stack* s, int elem){
    if (s->size>=POOL_SIZE)
    {
        return false;
    }
    s->data[s->size++] = elem;
    return true;
    
}

bool stack_pop(stack** s){
    if ((*s)->size==0)
    {
        return false;
    }
    (*s)->size--;
    return true;
    
}

int stack_top(stack* s){
    if (s->size==0)
    {
        return false;
    }
    return s->data[s->size];
}

bool stack_destroy(stack* s){
    if (s->size==0)
    {
        return false;
    }
    s->size = 0;
    free(s);
    s = NULL;
    return true;
    
}
