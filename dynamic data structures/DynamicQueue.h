#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct item item;

struct item {
    int data;
    struct item* next;
};

typedef struct item item;

typedef struct {
    item* first;
    item* last;
    size_t size;
} queue;



void queue_create(queue* q){
    q->first = q->last = malloc(sizeof(item));
    q->size = 0;
}

size_t queue_size(queue* q){
    return q->size
}

bool queueIsEmpty(queue* q){
    return q->size==0;
}

bool queue_push(queue*q,int data ){
    if (!(q->last->next= malloc(sizeof(item))))
    {
        return false;
    }
    q->last->data = data;
    q->last = q->last->next;
    q->size++;
    return true;
}

bool queue_pop(queue*q ){
    if (queueIsEmpty(q))
    {
        return false;
    }
    item* temp = q->first;
    q->first=q->first->next;
    q->size--;
    free(temp);
    
}

item* queue_front(queue* q){
    if (!queueIsEmpty(q))
    {
        return q->first;
    }
    
}


void queue_destroy(queue* q){
    item* tmp = q->first;
    while(!queueIsEmpty(q)){
        tmp = q->first;
        q->first = q->first->next;
        free(tmp);
    }
    free(q->first);
    q->first = q->last =NULL;
    q->size = 0;
}

void queue_reverse(queue* q){
    if(queueIsEmpty(q)){
        return;
    }

    item* tmp = queue_front(q);
    queue_pop(q);
    queue_reverse(q);
    queue_push(q, tmp);
}
