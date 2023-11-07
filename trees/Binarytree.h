#include <stdio.h>
#include <stdlib.h>

#define MAXLEN  1000

typedef int Data;
typedef struct Node Node;

void tree_print(Node *tree);
void print(Node *tree);

Node* tree_add(Node *tree, Data d);
Node* find_min_value(Node * tree);
Node* tree_delete(Node *root, Data key);

int max(Data a, Data b);
int get_width(Node *root);

struct Node{
    Data data;
    Node *left;
    Node *right;

};

Node* find_min_value(Node * tree){
    while(tree->left!=NULL)
    {
        tree = tree->left;
    }
    return tree;

}

Node * tree_add(Node * tree, Data d){

    if(tree==NULL)
    {
        Node *t = (Node*)malloc(sizeof(Node));
        t->data = d;
        t->left = t->right = NULL;
        return t;
    }

    if(d < tree->data)
    {   
        tree -> left = tree_add(tree->left,d);
    }
    if(d > tree->data)
    {   
        tree -> right = tree_add(tree->right,d);
    }
    return tree; 

}

int max(Data a, Data b){
    return (a>=b) ? a: b;
}

int get_width(Node* root){

    if (root == NULL)
    {
        return 0;
    }
    
    int max_width = 0;
    int forward = 0, back = 0;
    Node* deque[MAXLEN];

    deque[back++] = root;

    while(forward < back){

        int lvl_width = back - forward;
        max_width = max(max_width, lvl_width);

        for (int i = 0; i < lvl_width; i++)
        {
            Node* node = deque[forward++];

            if (node->left)
            {
                deque[back++] = node->left;
            }
            if (node->right)
            {
                deque[back++] = node->right;
            }
            
            
        }
        lvl_width = back - forward;


    }
    return max_width;





}

void tree_print(Node *tree)
{
    if(tree==NULL)
    {
        return;
    }
    tree_print(tree->left);
    printf("%d ",tree->data);
    tree_print(tree->right);


}


void print(Node *tree)
{
    tree_print(tree);
    printf("\n");

}


Node* tree_delete(Node *root, Data key)
{  
    if(root==NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root -> left = tree_delete(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = tree_delete(root->right, key);
    }
    else{
        // Оба NULL или один NULL
        if (root->left==NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;

        }
        if (root->right==NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;

        }
        // Имеется 2 узла
        Node *min = find_min_value(root->right);
        root->data = min->data;
        root->right=tree_delete(root->right, min->data);


    }
    return root;
    
}


int main()
{
    Node * tree = NULL;
    print(tree);

    Data test_data[] = {5,3,2,4,6,7};
    for (size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); i++)
    {
        tree = tree_add(tree, test_data[i]);
        print(tree);
    }
    /*
                      5
                     / \
                    3   6
                   / \   \
                  2   4   7
    */
    
    print(tree);
    Data x = 2;
    tree = tree_delete(tree,x);
    /*
                      5
                     / \
                    3   6
                     \   \
                      4   7
    */
    print(tree);   

    printf("%d \n",get_width(tree));


    return 0;
}