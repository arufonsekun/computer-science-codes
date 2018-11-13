//Name: Junior Vitor Ramisch
//email: junior.ramisch@gmail.com
//code: 1811100034
#include <stdio.h>
#include <stdlib.h>

struct Node {
     int key;
     char c;
     struct Node * left;
     struct Node * right;
     struct Node * parent;
};
typedef struct Node Node;

//Functions prototypes
void menu();
Node* generateNodes(Node* root, int treeSize);
Node* insert(Node** root, Node* parent, int key);
Node* setNode(Node* parent, int key);
Node* fixUpInsertion(Node* root, Node* new);
Node* rightRotate(Node* new, Node* parent);
Node* leftRotate(Node* new, Node* parent);
void breadthFirstSearch(Node * parent);
void BFS(Node * parent, int height);
int height(Node * parent);
int max(int a, int b);
void inOrder(Node* root);

int main(){
    Node* root = NULL, *new = NULL;
    int operation, size;

    menu();//show menu
    printf("Type the operation: ");
    scanf("%d", &operation);

    while(operation != 8){
        if (operation == 1){
            printf("Type the tree size: ");
            scanf("%d", &size);
            root = generateNodes(root, size);
        }

        if (operation == 3){
            if (root == NULL) printf("Tree is empty!\n");
            inOrder(root);
        }

        printf("Type the operation: ");
        scanf("%d", &operation);
        // scanf("%d", &value);
        // new = insert(&root , NULL, value);
        // root = fixUpInsertion(root, new);
    }
    printf("\t");breadthFirstSearch(root);
    return 0;
}

//function to generate the node values
//and insert in the tree
Node* generateNodes(Node* root, int treeSize){
    Node* new;
    int newKey = 0;
    for (int i = 0; i < treeSize; i++){
        newKey  = rand() % 100;
        new = insert(&root, NULL, newKey);
        (new == NULL ? printf("é null\n") : printf("n é\n"));
        root = fixUpInsertion(root, new);
    }
    return root;
}

//set node attributes, parameters: node parent and his value
Node* setNode(Node* parent, int key){
    Node* new = (Node*) malloc(sizeof(Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->parent = parent;
    //new node is red
    new->c = 'R';
    return new;
}

Node* insert(Node** root, Node* parent, int key){
    if (*root == NULL){
        *root = setNode(parent, key);
        //parent null means that node is root
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
    parent->parent->left = new;
    parent->parent = new;

    if (new->right->left != NULL)
        new->right->left->parent = parent;

    return new;
}

Node* fixUpInsertion(Node* root, Node* new){
    while (new->parent != NULL && new->parent->c == 'R'){
        Node* grandparent = new->parent->parent;
        if (new->parent == new->parent->parent->left){
            Node* uncle = new->parent->parent->right;

            //null means a black node
            if (uncle != NULL && uncle->c == 'R'){
                //printf("Changing colors: grandparent <---> parent and uncle!\n");
                new->parent->c = 'B';
                uncle->c = 'B';
                new->parent->parent->c = 'R';
            }

            // left-right case
            else if (new->parent->right == new){
                //printf("Caso left-right!\n");
                new->parent->parent->left = new;
                new->parent->right = new->left;
                new->left = new->parent;
                new->parent->parent = new;
                new->parent = grandparent;
                //printf("%d\n", new->parent->parent->key);
                new = rightRotate(new, new->parent);
            }
            else{
                //printf("Caso left-left!\n");
                new = rightRotate(new->parent, new->parent->parent);
                new = new->parent;
                if (new->parent->parent == NULL) root = new;
            }
        }

        else{
            Node* uncle = new->parent->parent->left;
            if (uncle != NULL && uncle->c == 'R'){
                //printf("Changing colors: grandparent <---> parent and uncle!\n");
                new->parent->c = 'B';
                uncle->c = 'B';
                new->parent->parent->c = 'R';
                //new = new->parent;
            }
            else if(new->parent->left == new){
                //printf("Caso right-left!\n");
                new->parent->parent->right = new;
                new->parent->left = new->right;
                new->right = new->parent;
                new->parent->parent = new;
                new->parent = grandparent;
                new = leftRotate(new, new->parent);
                //new = leftRotate(new, new->parent);
            }
            else{
                //printf("Caso right-right!\n");
                new = leftRotate(new->parent, new->parent->parent);
                if (new->parent->parent == NULL) root = new;
                new = new->parent;
            }
            //when new become the root
        }
    }
    //root node is always black
    root->c = 'B';
    return root;
}

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

void breadthFirstSearch(Node * parent){
    int h = height(parent);
    for (int i = 0; i < h; i++){
        BFS(parent, i);
        printf("\n");
    }
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

void inOrder(Node* root){
    if (root == NULL)return;
    inOrder(root->left);
    printf("%d", root->key);
    inOrder(root->right);
}

void menu(){
    printf("\t_____________________\n");
    printf("\t| 1. Insert         |\n");
    printf("\t| 2. Delete node    |\n");
    printf("\t| 3. Print in-order |\n");
    printf("\t| 4. Print pos-order|\n");
    printf("\t| 5. Print pre-order|\n");
    printf("\t| 6. Print BFS      |\n");
    printf("\t| 7. Clear terminal |\n");
    printf("\t| 8. Exit           |\n");
    printf("\t---------------------\n");
    return;
}
