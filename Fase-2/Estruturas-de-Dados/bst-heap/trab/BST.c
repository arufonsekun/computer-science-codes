//Name: Junior Vitor Ramisch
//email: junior.ramisch@gmail.com
//code: 1811100034
//Eu ia fazer a red-black-tree mas a remoção era muito
//complicada dai eu desisti
#include <stdio.h>
#include <stdlib.h>

//constants for text-style
#define RED_STRING "\033[31;1m%s\033[0m"
#define WHITE_STRING "\033[37;1m%s\033[0m"

struct Node {
     int key;
     struct Node * left;
     struct Node * right;
     struct Node * parent;
};
typedef struct Node Node;

//Functions prototypes
void menu();
Node* generateNodes(Node* root, int treeSize);
int insert(Node** root, Node* parent, int key);
Node* setNode(Node* parent, int key);
void BFS(Node* parent, int height);
void breadthFirstSearch(Node* root);
int height(Node* root);
int treeSize(Node* root);
void inOrder(Node* root);
void preOrder(Node* root);
void posOrder(Node* root);
void descendingOrder(Node* root);
Node* deleteNode(Node* root, Node* n1);
void clearTree(Node* root);
Node* getNode(Node* root, int key);
Node* successor(Node* n);
Node* predecessor(Node* root, Node* n1);

int main(){
    Node* root = NULL;
    int operation, size;

    menu();//show menu
    printf("Type the operation: ");
    scanf("%d", &operation);
    while(operation != 14){
        if (operation == 1){
            printf("Type the tree size: ");
            scanf("%d", &size);
            if (root != NULL) {clearTree(root); root = NULL;};
            if (size != 0) {
                root = generateNodes(root, size);
                printf(WHITE_STRING, "Done!\n");
            }
        }
        else if (operation == 2){
            if (root == NULL) printf("Tree is empty!\n");
            else{
                printf("Type the node to remove: ");
                scanf("%d", &size);//reusing vars
                Node* x = getNode(root, size);
                if (x != NULL) root = deleteNode(root, x);
                else printf(WHITE_STRING, "The inputted key doesn't exists\n");
            }
        }
        else if (operation == 3){
            if (root == NULL) printf("Tree is empty!\n");
            else {
                printf(WHITE_STRING, "In-order\n → ");
                inOrder(root);
                printf("\n");
            }
        }
        else if (operation == 4){
            if (root == NULL) printf("Tree is empty!\n");
            else{
                printf(WHITE_STRING, "Pre-order\n → ");
                preOrder(root); printf("\n");}
        }
        else if (operation == 5){
            if (root == NULL) printf(WHITE_STRING, "Tree is empty!\n");
            else {
                printf(WHITE_STRING, "Pos-order\n → ");
                posOrder(root);
                printf("\n");}
        }
        else if (operation == 6){
            if (root == NULL) printf(WHITE_STRING, "Tree is empty!\n");
            else{
                printf(WHITE_STRING, "Descending-order\n → ");
                descendingOrder(root);
                printf("\n");
            }
        }
        else if (operation == 7){
            if (root == NULL) printf(WHITE_STRING, "Tree is empty!\n");
            else{
                printf("    \n");
                breadthFirstSearch(root);
            }
        }
        else if(operation == 8){
            printf(WHITE_STRING, "Tree number of nodes is ");
            printf("%d\n", treeSize(root));
        }
        else if (operation == 9){
            printf(WHITE_STRING, "Tree height is ");
            printf("%d\n", height(root));
        }
        else if (operation == 10){
            if (root == NULL) printf(WHITE_STRING, "Tree is empty!\n");
            else{
                printf("Type the node key: ");
                scanf("%d", &size);//reusing variables
                Node* s = getNode(root, size);

                if (s == NULL) printf(WHITE_STRING, "The inputted key doesn't exists\n");
                else{
                    s = successor(s);
                    if (s != NULL){
                        printf(WHITE_STRING, "\nSUCCESSSOR\n");
                        printf(" → Successor key: %d\n", s->key);
                        s->parent->parent != NULL ? printf(" → Successor's parent-key: %d\n", s->parent->key) : printf(" → Successor has no parent\n");
                        s->left != NULL ? printf(" → Successor left-child key: %d\n", s->left->key) : printf(" → Successor's left-child is null\n");
                        s->right != NULL ? printf(" → Successor's right-child key: %d\n", s->right->key) : printf(" → Successor's right-child is null\n");
                        printf("\n");
                    }
                    else{
                        printf(WHITE_STRING, "Successor doesn't exist\n");
                    }
                }
            }
        }
        else if (operation == 11){
            if (root == NULL) printf(WHITE_STRING, "Tree is empty!\n");
            else{
                printf("Type the node key: ");
                scanf("%d", &size);//reusing variables
                Node* p = getNode(root, size);
                if (p == NULL) printf(WHITE_STRING, "The inputted key doesn't exists\n");
                else{
                    p = predecessor(root, p);
                    if (p != NULL){
                        printf(WHITE_STRING, "\nPREDECESSOR\n");
                        printf(" → Predecessor key: %d\n", p->key);
                        p->parent->parent != NULL ? printf(" → Predecessor's parent-key: %d\n", p->parent->key) : printf(" → Predecessor has no parent\n");
                        p->left != NULL ? printf(" → Predecessor left-child key: %d\n", p->left->key) : printf(" → Predecessor's left-child is null\n");
                        p->right != NULL ? printf(" → Predecessor's right-child key: %d\n", p->right->key) : printf(" → Predecessor's right-child is null\n");
                        printf("\n");
                    }
                    else{
                        printf(WHITE_STRING, "Predecessor doesn't exist\n");
                    }
                }
            }
        }
        else if (operation == 12){
            clearTree(root);
            root = NULL;
            printf(WHITE_STRING, "Tree memory is clear!\n");
        }
        else if(operation == 13) {
            system("clear");
            menu();
        }
        else{
            printf(RED_STRING, "Don't get it!\n");
        }
        printf("Type the operation: ");
        scanf("%d", &operation);
        if (operation == 14){
            clearTree(root);
            printf(WHITE_STRING, "Bye!!\n");
        }
    }
    return 0;
}

Node* generateNodes(Node* root, int treeSize){
    int newKey = 0;
    int generate;
    for (int i = 0; i < treeSize; i++){
        newKey = rand();
        generate = insert(&root, NULL, newKey);
        if (generate == 0){
            i--;
        }
    }
    return root;
}

Node* setNode(Node* parent, int key){
    Node* new = (Node*) malloc(sizeof(Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->parent = parent;
    return new;
}

int insert(Node** root, Node* parent, int key){
    if (*root == NULL){
        *root = setNode(parent, key);
        if (parent == NULL){
            (*root)->parent = (Node*) malloc(sizeof(Node));
            (*root)->parent = NULL;
        }
        return 1;
    }
    if (key > (*root)->key) return insert(&(*root)->right, *root, key);
    else if (key == (*root)->key) return 0; //ignore repeated key
    else return insert(&(*root)->left, *root, key);
}

int max(int a, int b){
    return (a > b ? a : b);
}

int treeSize(Node* root){
    if (root == NULL) return 0;
    return treeSize(root->left) + treeSize(root->right) + 1;
}

int height(Node * parent){
    if (parent == NULL)
    return 0;
    int left = height(parent->left) + 1;
    int right = height(parent->right) +1;
    return max(left, right);
}

void printSpaces(int spaces, int height){
    for (int i = 0; i < height - spaces; i++){
        printf("   ");
    }
}

void breadthFirstSearch(Node * parent){
    int h = height(parent);
    for (int i = 1; i <= h; i++){
        printSpaces(i, h);
        BFS(parent, i);
        printf("\n");
    }
}

void BFS(Node * parent, int h){
    if (parent == NULL){
        printf("  ");
        return;
    }
    if (h == 1){
        printf("%d ", parent->key);
        printSpaces(1, height(parent));
    }
    else{
        BFS(parent->left, h-1);
        BFS(parent->right, h-1);
    }
}

void inOrder(Node* root){
    if (root == NULL)return;
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}

void preOrder(Node* root){
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void posOrder(Node* root){
    if (root == NULL)
        return;
    posOrder(root->left);
    posOrder(root->right);
    printf("%d ", root->key);
}

void clearTree(Node* root){
    if (root == NULL) return;
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}

void descendingOrder(Node* root){
    if (root == NULL) return;
    descendingOrder(root->right);
    printf("%d ", root->key);
    descendingOrder(root->left);
}

Node* successor(Node* n){
    if (n->right != NULL){
        Node* n1 = n->right;
        while (n1->left != NULL) n1 = n1->left;
        return n1;
    }
    else{
        Node* n2 = n->parent;
        while (n2 != NULL && n == n2->right){
            n2 = n2->parent;
        }
        return n2;
    }
}

Node* predecessor(Node* root, Node* n1){
    if (n1->left != NULL){
        n1 = n1->left;
        while (n1->right != NULL)
            n1 = n1->right;
        return n1;
    }
    else{
        Node* n2 = n1->parent;
        while (n2 != NULL && n1 == n2->left){
            n1 = n2;
            n2 = n2->parent;
        }
        return n2;
    }
}

Node* getNode(Node* root, int key){
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    if (key < root->key) return getNode(root->left, key);
    else return getNode(root->right, key);
}

//return the node that will replace the remove-node
Node* treeMin(Node* x){
    while (x->left != NULL)
        x = x->left;
    return x;
}

Node* moveNode(Node* root, Node* n1, Node* n2){
    //Node n1 is root
    if (n1->parent == NULL){
        n2->parent = NULL;
        root = n2;
    }
    //whether n1 is left-child
    else if (n1 == n1->parent->left) n1->parent->left = n2;
    else n1->parent->right = n2;
    if (n2 != NULL ) n2->parent = n1->parent;

    return root;
}

Node* deleteNode(Node* root, Node* z){
    if (z->left == NULL) root = moveNode(root, z, z->right);
    else if (z->right == NULL) root = moveNode(root, z, z->left);

    else{
        Node* y = treeMin(z->right);
        if (y->parent != z){
            root = moveNode(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        else{
            root = moveNode(root, z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }
    return root;
}

void menu(){
    printf("\t______________________\n");
    printf("\t| 1. Insert          |\n");
    printf("\t| 2. Delete node     |\n");
    printf("\t| 3. Print in-order  |\n");
    printf("\t| 4. Print pre-order |\n");
    printf("\t| 5. Print pos-order |\n");
    printf("\t| 6. Print downward  |\n");
    printf("\t| 7. Print BFS       |\n");
    printf("\t| 8. Number of nodes |\n");
    printf("\t| 9. Tree height     |\n");
    printf("\t| 10. Get successor  |\n");
    printf("\t| 11. Get predecessor|\n");
    printf("\t| 12. Clear tree     |\n");
    printf("\t| 13. Clear terminal |\n");
    printf("\t| 14. Exit           |\n");
    printf("\t----------------------\n");
    return;
}
