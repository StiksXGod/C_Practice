#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node Node;

void print(Node *list);
void list_init(Node *list);
void insert_front(Node *list, Node *p);
void push_front(Node *list, Data data);

void list_remove(Node *list);
void print_it(Data d);
void foreach(Node *list, void (*func)(Data));
void print1(Node *list);

int is_empty(Node *list);

Data delete(Node *list);

struct Node{
    Data data;
    Node *next;
    Node *prev;

};

void print_it(Data d)
{
    printf("%d", d);

}

void foreach(Node *list, void (*func)(Data))
{
    for (Node *p = list->next;p!=list; p=list->next)
    {
        func(list->data);
    }
}

void print1(Node *list)
{
    foreach(list, print_it);
    printf("\n");

}

void print(Node *list)
{
    Node *p = list->next;
    while(p!=list)
    {
        printf("%d ", p->data);
        p = p->next;

    }
    printf("\n");

}

int is_empty(Node *list)
{
    return list->next == list && list -> prev == list;
}

void list_init(Node *list)
{
    list -> next = list;
    list -> prev = list;

}

void list_remove(Node *list)
{
    Node* next_node = list->next;
    Node* prev_node = list->prev;
    next_node -> prev = prev_node;
    prev_node -> next = next_node; 
}

void push_front(Node *list, Data data)
{
    Node *p=malloc(sizeof(Node));
    p->data = data;
    insert_front(list, p);
}

Data delete(Node *list)
{
    Data res = list->data;
    list_remove(list);
    free(list);
    return res;

}

void insert_front(Node *list, Node *p)
{
    Node *q = list->next;
    p->next = q;
    p->prev = list;
    list->next = p;
    q->prev = p;
} 

void insert_back(Node *list, Node *p)
{
    insert_front(list->prev,p);
}

int main()
{
    Data elem[] = {10,8,9,7,5};
    Node z;
    Node *list = &z;
    list_init(list);
    print(list);
    for (size_t i = 0; i < sizeof(elem)/sizeof(elem[0]); i++)
    {
        push_front(list,elem[i]);
        print(list);
    }
    print(list);

    Data res = delete(list->next->next);
    printf("delete: %d \n",res);
    print(list);
    Node n;
    n.data = 24;
    Node *l = &n;
    insert_back(list->next->next, l);
    printf("insert : %d\n",l->data);
    print(list);

    return 0;
}
