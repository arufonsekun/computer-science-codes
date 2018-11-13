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
        printf("%d:%c \t", parent->key, parent->c);
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

Node* insert(Node** root, Node* parent, int key){
    if (*root == NULL){
        *root = setNode(parent, key);
        if (parent== NULL){
            (*root)->parent = (Node*) malloc(sizeof(Node));
            (*root)->parent->c = 'B';
            (*root)->parent->left = NULL;
            (*root)->parent->right = NULL;
            (*root)->parent->parent = NULL;
        }
        return *root;
    }
    if (key < (*root)->key)
        return insert(&(*root)->left, *root, key);
    else
        return insert(&(*root)->right, *root, key);
}

Node* leftRotate(Node* new, Node* parent){
    new->c = 'B';
    parent->c = 'R';
    new->parent = parent->parent;
    parent->right = new->left;
    new->left = parent;

    if (parent->parent->left == parent)
        parent->parent->left = new;
    else
        parent->parent->right = new;

    parent->parent = new;

    if (new->left->right != NULL)
        new->left->right->parent = parent;

    return new;
}

Node* rightRotate(Node* new, Node* parent){
    new->c = 'B';
    parent->c = 'R';
    new->parent = parent->parent;
    parent->left = new->right;

    new->right = parent;

    if (parent->parent->left == parent)
        parent->parent->left = new;
    else
        parent->parent->right = new;

    parent->parent = new;

    if (new->right->left != NULL){
        printf("Entro naquele IF");
        new->right->left->parent = parent;
    }

    return new;
}

Node* fixUpInsertion(Node* root, Node* new){
    //printf("Key: %d Parent: %d\n", new->key, new->parent->key);
    while (new->parent != NULL && new->parent->c == 'R'){
        //printf("%d == %d", new->parent->key, new->parent->parent->left->key);
        Node* grandparent = new->parent->parent;
        if (new->parent == new->parent->parent->left){
            Node* uncle = new->parent->parent->right;

            //null means a black node
            if (uncle != NULL && uncle->c == 'R'){
                printf("Changing colors\n");
                new->parent->c = 'B';
                uncle->c = 'B';
                new->parent->parent->c = 'R';
            }

            // left-right case
            else if (new->parent->right == new){
                printf("Caso left-right!\n");
                //printf("%d\n", new->key);
                grandparent->left = new;
                new->parent->right = new->left;
                new->left = new->parent;
                new->parent->parent = new;
                new->parent = grandparent;
                //printf("%d\n", new->parent->parent->key);
                new = rightRotate(new, new->parent);
            }
            else{
                printf("Caso left-left!\n");
                //printf("%d\n", new->key);
                new = rightRotate(new->parent, new->parent->parent);
                new = new->parent;
                if (new->parent->parent == NULL) root = new;
            }
        }

        else{
            Node* uncle = new->parent->parent->left;
            if (uncle != NULL && uncle->c == 'R'){
                printf("Changing colors\n");
                new->parent->c = 'B';
                uncle->c = 'B';
                new->parent->parent->c = 'R';
                //new = new->parent;
            }
            else if(new->parent->left == new){
                printf("Caso right-left!\n");
                //printf("%d\n", new->key);
                grandparent->right = new;
                new->parent->left = new->right;
                new->right = new->parent;
                new->parent->parent = new;
                new->parent = grandparent;
                new = leftRotate(new, new->parent);
                //new = leftRotate(new, new->parent);
            }
            else{
                printf("Caso right-right!\n");
                //printf("%d\n", new->key);
                new = leftRotate(new->parent, new->parent->parent);
                if (new->parent->parent == NULL) root = new;
                new = new->parent;
            }
            //when new become the root
        }
    }
    root->c = 'B';
    return root;
}

int main(){
    Node* root = NULL, *new = NULL;
    int value, size;

    scanf("%d", &size);
    for (int i = 0; i < size; i++){
        printf("Type the new value: ");
        scanf("%d", &value);
        new = insert(&root , NULL, value);
        //printf("%d\n", new->key);
        root = fixUpInsertion(root, new);
    }

    printf("\t");BreadthFirstSearch(root);
    return 0;
}
