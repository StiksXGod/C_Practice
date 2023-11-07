#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item{
    int data;
    struct item* next;
    struct item* prev;
}item;

typedef struct{
    item *node;
}iterator;

bool iterator_equal(const iterator* lhs, const iterator* rhs){
    return lhs->node==rhs->node;
}

bool iterator_not_equal(const iterator* lhs, const iterator* rhs){
    return !iterator_equal(lhs, rhs);
}

void iterator_next(iterator* elem){
    elem->node=elem->node->next;
}

void iterator_prev(iterator* elem){
    elem->node=elem->node->prev;
}

int iterator_get(iterator* elem){
    return elem->node->data;
}

void iterator_set(const iterator* elem, const int data){
    elem->node->data=data;
}