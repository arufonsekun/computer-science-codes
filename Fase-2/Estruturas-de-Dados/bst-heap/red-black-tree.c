#include <stdio.h>
#include <stdlib.h>

struct node {
     int key;
     char c;
     struct node * left;
     struct node * right;
     struct node * parent;
};

typedef struct node Node;

//the following 4 functions was just coded for debugging
int max(int a, int b){
    return (a > b ? a : b);
}

int height(Node * parent){
    if (parent == NULL)
        return 0;
    int left = height(parent->left) + 1;
    int right = height(parent->right) +1;
    return max(left, right);
}

void BFS(Node * parent, int height){
    if (parent == NULL)
        return;
    if (height == 0)
        printf("%c", parent->key);
    else{
        BFS(parent->left, height-1);
        BFS(parent->right, height-1);
    }
}

void BreadthFirstSearch(Node * parent){
    int h = height(parent);
    for (int i = 0; i < h; i++){
        BFS(parent, i);
        printf("\n");
    }
}


//set node attrs
Node* setNode(Node* parent, int key){
    Node* new = (Node*) malloc(sizeof(Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->parent = parent;
    new->c = 'R';
    return new;
}

void insert(Node** root, Node* parent, int key){
    if (*root == NULL){
        *root = setNode(parent, key);
        return;
    }
    if (key < (*root)->key)
        insert(&(*root)->left, *root, key);
    else
        insert(&(*root)->right, *root, key);
}

void leftRotate(Node* root, Node* x){
    Node* y = x->right;
    x->right = y->left;

    if (y->left == NULL) y->left->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL) root = y;

    else if (x == x->parent->left) x->parent->left = y;

    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rightRotate(Node* root, Node* x){
    Node* y = x->left;
    x->left = y->right;

    if (y->right == NULL) y->right->parent = x;
    y->parent = x->parent;

    if (x->parent == NULL) root = y;

    else if (x == x->parent->right) x->parent->right = y;

    else x->parent->left = y;
    y->right = x;
    x->parent = y;
}

Node* fixUpInsertion(Node* root, Node* new){
    while (new->parent->c == 'R'){
        if (new->parent == new->parent->parent->left){
            Node* aux = new->parent->parent->right;
            if (aux->c == 'R'){
                new->parent->c = 'B';
                aux->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
            }
            else if (new == new->parent->right){
                new = new->parent;
                leftRotate(root, new);
                new->parent->c = 'B';
                new->parent->parent->c = 'R';
                rightRotate(root, new->parent->parent);
            }
        }
        else{
            Node* aux = new->parent->parent->left;
            if (aux->c == 'R'){
                new->parent->c = 'B';
                aux->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
            }
            else if(new == new->parent->left){
                new = new->parent;
                rightRotate(root, new);
            }
            new->parent->c = 'B';
            new->parent->parent->c = 'R';
            leftRotate(root, new->parent->parent);
        }
    }
    root->c = 'B';
    return root;
}

Node* getNode(Node* root, int key){
    if (root->key == key)
        return root;
    return (root->key > key ? getNode(root->left, key) : getNode(root->right, key));
}

int main(){
    Node* root = NULL;
    int value, size;

    scanf("%d", &size);
    for (int i = 0; i < size; i++){
        scanf("%d", &value);
        insert(&root, NULL, value);
        root = fixUpInsertion(root, getNode(root, value));
    }
    //BreadthFirstSearch(root);
    printf("%d", root->key);
    return 0;
}
