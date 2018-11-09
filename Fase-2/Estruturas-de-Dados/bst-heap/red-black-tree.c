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
        printf("%d:%c  ", parent->key, parent->c);
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
        if (parent == NULL){
            (*root)->parent = (Node*) malloc(sizeof(Node));
            (*root)->parent->c = 'B';
            (*root)->parent->left = NULL;
            (*root)->parent->right = NULL;
        }
        return *root;
    }
    if (key < (*root)->key)
        return insert(&(*root)->left, *root, key);
    else
        return insert(&(*root)->right, *root, key);
}

void leftRotate(Node* new, Node* parent){
    new->parent = parent->parent;
    
    parent->right = new->left;
    
    if (new->left != NULL)
        new->left->parent = parent;

    parent->parent->left = new;
    
    parent->parent = new;
    new->left = parent;
    

}

void rightRotate(Node* new, Node* parent){
    new->parent = parent->parent;
    
    parent->left = new->right;

    parent->parent->left = new;
    parent->parent = new;
    new->right = parent;

}

Node* fixUpInsertion(Node* root, Node* new){
    //printf("%c", new->c);i
    root->c = 'B';
    while (new->parent->c == 'R'){
        //printf("%d == %d", new->parent->key, new->parent->parent->left->key);
        if (new->parent == new->parent->parent->left){
            Node* uncle = new->parent->parent->right;
            
            //null means a black node
            if (uncle != NULL && uncle->c == 'R'){
                printf("Passou a cor do avo aos pais\n");
                new->parent->c = 'B';
                uncle->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
            }
            // wheater the new node is right-child
            else if (new->parent->right == new){                
                printf("Caso left-right: parent is black and uncle is red\n");
                leftRotate(new, new->parent);
                rightRotate(new, new->parent);
            }
            else{
                printf("Caso left-left: parent is black and uncle is red\n");
                new->left = new->parent;
                new->parent = new->parent->parent;
                new->parent->parent->left = new;
                new->left->parent = new;
                //new->left->left
                rightRotate(new, new->parent);
            }
        }
        
        else{
            Node* uncle = new->parent->parent->left;
            if (uncle != NULL && uncle->c == 'R'){
                new->parent->c = 'B';
                uncle->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
            }
            else if(new->parent->right == new){
                printf("Birl do else");
                leftRotate(new, new->parent);
                rightRotate(new, new->parent);
            }
            else
                rightRotate(new, new->parent);

        }
    }
    root->c = 'B';
    return root;
}

Node* getNode(Node* root, int key){
    if (root->key == key)
        return root;
    if (key < root->key)
        return getNode(root->left, key);
    else
        return getNode(root->right, key);
}

int main(){
    Node* root = NULL, *new = NULL;
    
    int value, size;

    scanf("%d", &size);
    for (int i = 0; i < size; i++){
        scanf("%d", &value);
        new = insert(&root , NULL, value);
        //printf("%d\n", new->key);
        fixUpInsertion(root, new);
    }
    //Node* c = getNode(root, 5);
    //printf("%d\n", c->parent->key);
    BreadthFirstSearch(root);
    return 0;
}
