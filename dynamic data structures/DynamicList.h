#include "ItarartorDoubleLinkedList.h"

typedef struct{
    item* head;
    size_t size;
}list;

void list_create(list *l){
    l->head = (item*)malloc(sizeof(item));
    l->size=0;
    l->head->prev=l->head->next=NULL;
}

bool list_is_empty(list *l){
    return l->size==0;
}

bool list_size(list *l){
    return l->size;
}

iterator last_list(list*l){
    iterator res = {l->head};
    return res;
}

iterator first_list(list*l){
    iterator res = {l->head->next};
    return res;
}


iterator list_insert(list* l, iterator* i, const int data){
    iterator res = {(item*)malloc(sizeof(item))};

    if (!res.node){
        return last_list(l);
    }
    res.node -> data = data;
    res.node->next = i->node;
    res.node->prev = i->node->prev;
    res.node->prev->next = res.node;
    i->node->prev = res.node;
    l->size++;
    return res;
}

iterator list_delete(list* l, iterator* i){
    iterator res = last_list(l);
    if (iterator_equal(&res, i))
    {
        return res;
    }
    res.node = i->node->next;
    res.node->prev = i->node->prev;
    i->node->prev->next = res.node;
    free(i->node);
    l->size--;
    i->node = NULL;
    return res;
}

void Destroy(list *l){
    item *i=l->head->next;
    while (i!=l->head)
    {
        struct item* pi=l->head;
        i=i->next;
        free(pi);
    }
    free(l->head);
    l->head=0;
    l->size = 0;
    
}

