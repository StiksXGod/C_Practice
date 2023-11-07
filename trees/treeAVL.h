#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int key;
    int count;
    int ball;
    struct node* left;
    struct node* right;
};

typedef struct node node;

typedef node* ptr;


void search(int x, ptr p, int*h){
    ptr p1, p2;
    if (*p==NULL)
    {
        p = (ptr)malloc(sizeof(node));
        p->key = x;
        p -> count = 1;
        p -> left = (*p) ->right = NULL;
        *h = 1;
    }else if(x<p ->key){
        search(x, p->left, h);
    }
    


}