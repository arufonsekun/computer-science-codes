#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node * left;
    struct node * right;
};

typedef struct node Node;

int max(int a, int b){
    return (a > b ? a : b);
}

void include (Node** parent, int value){
    if (*parent == NULL){
        *parent = (Node*)  malloc(sizeof(Node *));
        (*parent)->left = NULL;
        (*parent)->right = NULL;
        (*parent)->value = value;
        return;
    }
    else if (value < (*parent)->value){
        return include(&(*parent)->left, value);
    }
    else{
        return include(&(*parent)->right, value);
    }
}

void printInOrder(Node* parent){
    if (parent == NULL)
       return;
    printInOrder(parent->left);
    printf("%d ", parent->value);
    printInOrder(parent->right);
}

int height(Node * parent){
    if (parent == NULL)
        return 0;
    int left = height(parent->left) + 1;
    int right = height(parent->right) +1;
    return max(left, right);
}

int lenght(Node * tree){
    if (tree == NULL)
        return 0;
    else{
        return lenght(tree->right) + lenght(tree->left) +1;
    }
}

void BFS(Node * parent, int height){
    if (parent == NULL)
        return;
    if (height == 0)
        printf("\t%d ", parent->value);
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

int main(){
    Node * tree = NULL; Node * new = NULL;
    unsigned size;
    int value;

    //printf("Type the tree size: ");
    scanf("%u", &size);

    for (int i = 0; i < size; i++){
        //printf("Type the node value: ");
        scanf("%d", &value);
        //value = rand() % 100;
        if (new == NULL){
            include(&new, value);
            tree = new;
        }
        else{
            include(&new, value);
        }
    }
    //printInOrder(tree);
    //printf("\n");
    //printf("Tree height: %d\n", height(tree));
    //printf("Tree lenght %d\n", lenght(tree));
    BreadthFirstSearch(tree);
    //printf("\n");
    return 0;
}
