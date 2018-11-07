#include <stdio.h>
#include <stdlib.h>

//"node" because a tree is made of nodes
struct node {
    int key;
    struct node * left;
    struct node * right;
    struct node * parent;
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
        printf("\t%d ", parent->key);
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

//a function to set the node attrs
Node* setNode(Node* parent, int value){
    Node* new = (Node *) malloc(sizeof(16));
    new->key = value;
    new->parent = parent;
    new->left = NULL;
    new->right = NULL;
    new->c = 'R';
    return new;
}

Node* insert(Node* node, Node* parent, int key){
    //check if node is root
    if (node == NULL){
        //printf("%d\n", key);
        node = setNode(parent, key);
        //root node is always black
        //printf("%d\n", key);
        node->c = 'B';
        return node;
    }

    if (key < node->key){
        printf("entro aqui\n");
        return insert(node->left, node, key);
    }

    else
        return insert(node->right, node, key);

}

int main(){
    Node* parent = NULL;
    Node* new = NULL;
    int value, size;

    printf("Type the tree size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++){
        printf("Type the value to insert: ");
        scanf("%d", &value);
        //printf("%ld\n", sizeof(new));
        if (parent == NULL){
            //second paremeter is NULL because root node is orphan(He has no parent ;( )
            parent = insert(new, NULL, value);
            //parent = new;
        }
        else{
            //printf("%ld\n", sizeof(new));
            insert(parent, NULL, value);
        }
    }
    //this statement should print the root node value
    printf("%d\n", parent->left->parent->key);
    //BreadthFirstSearch(parent);
    return 0;
}
