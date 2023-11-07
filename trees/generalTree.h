#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* son;
    struct node* brother;
};


typedef struct node node;

node* createTree(int value){
    node* tree = (node*)malloc(sizeof(node));
    tree->value = value;

    tree->son = tree->brother = NULL;
    return tree;
}

node* ToSon(node* tree){
    return tree->son;
}

node* ToBrht(node* tree){
    return tree->brother;
}


node* lastSon(node* tree){
    node* tmp = tree->son;
    while(ToBrht(tmp)){
        tmp = ToBrht(tmp);
    }
    return tmp;
}

node *AddNode(node**tree, const char *path, int value){
    node* tmp = *tree;
    int index = 0;
    while(path[index]!='\0'){
        if (path[index]=='r')
        {
            if (tree==NULL)
            {
                *tree = createTree(value);
                return *tree;
            }
            ++index;
            continue;
            
        }
        if (path[index] == 's') {
          if (tmp = ToSon(tmp)) {++index;continue;}
          return NULL;        
        }
          if (path[index] == 'b') {
          if (tmp = ToBrht(tmp)) {++index;continue;}
          return NULL;
        }
    if (ToSon(tmp) != NULL) {
        tmp = lastSon(tmp); 
        tmp -> brother = createTree(value);
        return tmp -> brother;


    }
    else {
      tmp -> son = createTree(value);
      return tmp -> son;

    }
    }
}

void dfs(node* root){
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->value);
    dfs(root->son);
    dfs(root->brother);
}


void bfs(node* root){
    if (root == NULL)
    {
        return;
    }
    node* a[100];
    a[0] = root;
    int start_ptr = 0;
    int end_ptr = 1;
    while(start_ptr<end_ptr){
        node* tmp = a[start_ptr];
        ++start_ptr;
        printf("%d ", tmp->value);
        if (ToSon(tmp)!=NULL)
        {
            tmp = ToSon(tmp);
            do{
                a[end_ptr] = tmp;
                end_ptr++;
            }while(tmp = ToBrht(tmp));
        }
        
    }
    return;

}