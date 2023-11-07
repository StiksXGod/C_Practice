#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct item{
    int data;
    struct item* prev;
};

typedef struct item item;

typedef struct{
    item* top;
    size_t size;
}stack;


void stack_create(stack* s){
    s->top = NULL;
    s->size;
}

void stackIsEmpty(stack* s){
    return s->size==0;
}

size_t stackSize(stack* s){
    return s->size;
}

bool stack_push(stack*s, int data){
    item* elem = (item*)malloc(sizeof(item));

    if (!elem)
    {
        return false;
    }

    elem->data = data;
    elem->prev = s->top;
    s->top = elem;
    s->size++;
    return true;
    
}

int stack_top(stack*s ){
    if (s->size!=0)
    {
        return s->top->data;
    }
}

bool stack_destroy(stack* s){
    if (s->size==0)
    {
        return false;
    }
    while (s->top!=NULL)
    {
        item* temp = s->top;
        s->top = s->top->prev;
        free(temp);
    }

    s->size = 0;
    s->top = NULL;
    return true;
    
    
}