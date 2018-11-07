#include <stdio.h>
#include <stdlib.h>

//"node" because a tree is made of nodes
struct node {
    int key;
    struct node * left;
    struct node * right;
    char c;
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
        printf("%c ", parent->c);
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
    new->left = NULL;
    new->right = NULL;
    new->c = 'R';
    return new;
}

Node* getNode(Node* root, int key){
    if (root->key == key)
        return root;
    return (root->key > key ? getNode(root->left, key) : getNode(root->right, key));
}

Node* insert(Node* node, int key){
    if(node == NULL){
        Node* new = setNode(key);
        return new;
    }
    if (key > node->key){
        if (node->right == NULL){
            Node * new = setNode(key);
            node->right = new;
            return new;
        }
        return insert(node->right, key);
    }
    else{
        if(node->left == NULL){
            Node * new = setNode(key);
            node->left = new;
            return new;
        }
        return insert(node->left, key);
    }
}

void insertFixUp(Node* root, int value){
    //if value == root->key
    if (getParent(root, getNode(root, value)) == NULL)
        return;

    if (getParent(root, getNode(root, value))->c == 'B')
        return;

    //root node always black
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
        new = insert(root, value);
        if(root == NULL) root = new;
        //insertFixUp(root, value);
    }

    //this statement should print the root node value
    BreadthFirstSearch(root);
    /*Node* birl = getNode(root, 7);
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
