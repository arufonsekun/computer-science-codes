#include <stdio.h>
#include <stdlib.h>

//"node" because a tree is made of nodes
struct node {
    int key;
    char c;
    struct node * left;
    struct node * right;
};

typedef struct node Node;

//the 4 following functions was coded just for debugging
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
        printf("%c", parent->c);
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

//given a node this function return his parent
Node* getParent(Node* root, Node* node){
    if (root == node)
        return NULL;
    else if(root->left == node || root->right == node)
        return root;
    else if (node->key < root->key)
        return getParent(root->left, node);
    else
        return getParent(root->right, node);
}

//function to set the node attrs
Node* setNode(int value){
    Node* new = (Node *) malloc(sizeof(Node*));
    new->key = value;
    new->c = 'R';
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node* getNode(Node* root, int key){
    if (root->key == key)
        return root;
    return (root->key > key ? getNode(root->left, key) : getNode(root->right, key));
}

Node* getUncle(Node* root, int key){
    Node* node = getNode(root, key);
    Node * parent = getParent(root, node);
    Node* grandParent = getParent(root, parent);
    if (grandParent == NULL)
        return NULL;
    else
        return (grandParent->left == parent ? grandParent->right : grandParent->left);
}

void insert(Node** node, int key){
    if (*node == NULL){
        *node = setNode(key);
        return;
    }
    if (key < (*node)->key)
        insert(&(*node)->left, key);
    else
        insert(&(*node)->right, key);

}

void leftRotate(Node* root, Node* x){
    Node * y = x->right;
    x->right = y->left;

    if (y->left != NULL){
        getParent(root, y->left) = x;
    }
    getParent(root, y) = getParent(root, x);
    if (getParent(root, x) == NULL){
        root = y;
    }
    else if(x == getParent(root, x)->left){
        getParent(root, x)->left = y; 
    } 
    else{
        getParent(root, x)->right = y;
    }
    y->left = x;
    getparent(root, x) = y;
}

void insertFixUp(Node* root, int value){
    Node* new = getNode(root, value);
    Node* parent = getParent(root, new);
    Node* grandParent = getParent(root, parent);

    while (parent->c == 'R'){
        if (parent == grandParent->left){
            Node * aux = grandParent->right;
            if (aux->c == 'R'){
                parent->c = 'B';
                aux->c = 'B';
                grandParent->c = 'R';
            }
            else if (grandParent == getParent(root, grandParent)->right){
                grandParent = getParent(root, grandParent);
                leftRotate(root, grandParent);
            }
            grandParent->c ='B';
            aux = getParent(root, grandParent);
            aux->c = 'V';
            rightRotate(root, aux);
        }
        else{
            Node * aux = grandParent->left;
            if (aux->c == 'R'){
                parent->c = 'B';
                aux->c = 'B';
                grandParent->c = 'R';
            }
            else if (grandParent == getParent(root, grandParent)->left){
                grandParent = getParent(root, grandParent);
                rightRotate(root, grandParent);
            }
            grandParent->c ='B';
            aux = getParent(root, grandParent);
            aux->c = 'V';
            rightRotate(root, aux);
        }
    }
    root->c = 'B';
}

int main(){
    Node* root = NULL, *new = NULL;
    int value, size;

    printf("Type the tree size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++){
        //printf("Type the value to insert: ");
        scanf("%d", &value);
        insert(&new, value);
        if(root == NULL) root = new;
        insertFixUp(root, value);
    }

    //this statement should print the root node value
    BreadthFirstSearch(root);
    /*Node * uncle = getUncle(root, 11);
    printf("%p\n", uncle);
    Node* birl = getNode(root, 7);
    printf("%d\n", birl->key);*/
    return 0;
}

//Casos da Red Black Tree
//1° O no inserido e raiz (pinta de preto);
//2° O pai do no e preto (gg easy, fica como ta)
//3° O pai e tio sao vermelhos (tio e pai tornam-se pretos e o avo vermelho)
//4º O pai(filho a esquerda) e vermelho e o tio preto(rotacionar ) alem do no
//a ser inserido ser filho a direita. Rotacionar para a esquerda o novo no e seu pai.
//Ainda ta dando merda, resolver no caso 5.
//5º Novo e filho a esquerda e o pai tmb, rotacionar para a direita (o pai vira raiz, 
//o avo vira filho do pai e torna-se vermelho) 
