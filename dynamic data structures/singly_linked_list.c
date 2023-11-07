#include <stdio.h>
#include <stdlib.h>




typedef struct Node Node;
typedef int Data;
void push(Node **node,Data data );
void print(Node *list);
int is_empty(Node *list);
Data pop(Node **plist);

struct Node{
    Data data;
    Node * next;

};




void push(Node **node,Data data )
{
    Node *p = malloc(sizeof(Node));
    p->data = data;
    p->next = *node;
    *node = p;
}

void print(Node *list)
{
    for (Node *p=list;p!=NULL ; p=p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");

}


int is_empty(Node *list)
{
    return list == NULL;

}



Data pop(Node **plist)
{
    Node *p = *plist;
    Data res = p->data;
    *plist = p -> next;
    free(p);
    return res;



}



int main(void)
{
    Data mass[] = {10, 4, 6, 7, 8, 9};
    Node *list = NULL;
    print(list);
    for (size_t i = 0; i < sizeof(mass)/sizeof(mass[0]); i++)
    {
        push(&list,mass[i]);
    }
    print(list);
    while(!is_empty(list))
    {
        Data pop_elem = pop(&list);
        printf("pop : %d ",pop_elem);

    }
    print(list);
    return 0;





}