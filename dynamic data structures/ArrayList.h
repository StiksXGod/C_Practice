#include "ItarartorDoubleLinkedList.h"

const int POOL_SIZE = 100;

typedef struct{
    item* head;
    size_t size;
    item* top;
    item data[POOL_SIZE];
}list;


void list_create(list* l){
    for (int i = 0; i < POOL_SIZE; i++)
    {
        l->data[i].next = &(l->data[i+1]);
    }
    l->data[POOL_SIZE-1].next = NULL;
    l->head ->prev = l->head->next = l->head;
    l->top=l->data;
    l->size = 0;    
}

bool list_is_empty(list* l){
    return l->size==0;
}

size_t list_size(list* l){
    return l->size;
}


iterator list_first(list* l){
    iterator res = {l->head->next};
    return res;
}


iterator list_last(list* l){
    iterator res = {l->head};
    return res;
}


iterator list_insert(list* l, iterator* i, const int data){
    iterator res = {l->top};
    if (!res.node)
    {
        return list_last(l);
    }
    l->top=l->top->next;
    res.node->data = data;
    res.node->next =i->node;
    res.node->prev = i->node->prev;
    res.node->prev->next = res.node;
    i->node->prev = res.node;
    l->size++;
    return res;

    

}

iterator list_delete(list* l, iterator* i){
    iterator res = list_last(l);
    if (iterator_equal(&res, i))
    {
        return res;
    }

    res.node = i->node->next;
    res.node->prev = i->node->prev;
    i->node->prev->next = res.node;
    l->size--;
    i->node->next = l->top;
    l->top=i->node;
    i->node = 0;
    return res;
}

void list_destroy(list* l){
    l->head = NULL;
    l->size = 0;
    l->top = NULL;
}