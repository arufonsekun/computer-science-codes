//Name: Junior Vitor Ramisch
//email: junior.ramisch@gmail.com
//code: 1811100034
#include <stdio.h>
#include <stdlib.h>

#define RED "\033[31;1m%d \033[0m\t"
#define WHITE "\033[37;1m %d \033[0m\t"
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
void insert(Node** root, Node* parent, int key);
Node* setNode(Node* parent, int key);
Node* fixUpInsertion(Node* root, Node* new);
Node* rightRotate(Node* new, Node* parent);
Node* leftRotate(Node* new, Node* parent);
void breadthFirstSearch(Node* root);
void BFS(Node* parent, int height);
int height(Node* root);
int treeSize(Node* root);
int max(int a, int b);
void inOrder(Node* root);
void preOrder(Node* root);
void posOrder(Node* root);
void deleteNode(Node* root, int key);
void clearTree(Node* root);
Node* getNode(Node* root, int key);
Node* successor(Node* n);
Node* predecessor(Node* root, Node* pre, Node* suc, int key);
//Node* predecessor(Node* n);

int main(){
    Node* root = NULL;
    int operation, size;

    menu();//show menu
    printf("Type the operation: ");
    scanf("%d", &operation);
    while(operation != 13){
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
            printf("Type the node to remove: ");
            scanf("%d", &size);//reusing vars

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
            printf("    \n");
            breadthFirstSearch(root);
        }

        else if(operation == 7){
            printf(WHITE_STRING, "Tree number of nodes is ");
            printf("%d\n", treeSize(root));
        }

        else if (operation == 8){
            printf(WHITE_STRING, "Tree height is ");
            printf("%d\n", height(root));
        }

        else if (operation == 9){
            printf("Type the node key: ");
            scanf("%d", &size);//reusing variables
            Node* s = getNode(root, size);

            if (s == NULL) printf(WHITE_STRING, "The inputted key doesn't exists\n");
            else{
                s = successor(s);
                if (s->parent != NULL){
                    printf(WHITE_STRING, "\nSUCCESSSOR\n");
                    printf(" → Sucessor key: %d\n", s->key);
                    s->parent->parent != NULL ? printf(" → Successor's parent-key: %d\n", s->parent->key) : printf(" → Successor s no parent\n");
                    s->left != NULL ? printf(" → Successor left-child key: %d\n", s->left->key) : printf(" → Successor's left-child is null\n");
                    s->right != NULL ? printf(" → Successor's right-child key: %d\n", s->right->key) : printf(" → Successor's right-child is null\n");
                    printf("\n");
                }
                else{
                    printf(WHITE_STRING, "Successor doesn't exist\n");
                }
            }
        }

        else if (operation == 10){
            printf("Type the node key: ");
            scanf("%d", &size);//reusing variables
            Node* p = getNode(root, size);
            //printf("%d\n", p->key);
            if (p == NULL) printf(WHITE_STRING, "The inputted key doesn't exists\n");
            else{
                p = predecessor(root, NULL, NULL, size);
                printf(WHITE_STRING, "\nPREDECESSOR\n");
                printf(" → Predecessor key: %d\n", p->key);
            }
        }

        else if (operation == 11){
            clearTree(root);
            printf(WHITE_STRING, "Tree memory is clear!\n");
        }

        else if(operation == 12) {
            system("clear");
            menu();
        }

        //printf("Altura da sub arvore da esq.: %d e da direita %d\n", height(root->left), height(root->right));
        printf("Type the operation: ");
        scanf("%d", &operation);
        // scanf("%d", &value);
        // new = insert(&root , NULL, value);
        // root = fixUpInsertion(root, new);
    }
    return 0;
}

Node* generateNodes(Node* root, int treeSize){
    int newKey = 0;
    for (int i = 0; i < treeSize; i++){
        newKey = rand() % 100;
        printf("%d\n", newKey);
        insert(&root, NULL, newKey);
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

void insert(Node** root, Node* parent, int key){
    if (*root == NULL){
        *root = setNode(parent, key);
        if (parent == NULL){
            (*root)->parent = (Node*) malloc(sizeof(Node));
            (*root)->parent->left = NULL;
            (*root)->parent->right = NULL;
            (*root)->parent->parent = NULL;
        }
        return;
    }
    if (key >= (*root)->key){
        insert(&(*root)->right, *root, key);
        return;
    }
    else{
        insert(&(*root)->left, *root, key);
        return;
    }
}

void deleteNode(Node* root, int key){
    return;
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

Node* successor(Node* n){
    if (n->right != NULL){
        Node* s = n->right;
        while (s->left != NULL) s = s->left;
        return s;
    }
    else{
        Node* P = n->parent;
        while (P != NULL && n == P->right){
            P = P->parent;
        }
        return P;
    }
}


Node* predecessor(Node* root, Node* pre, Node* suc, int key){
    if (root == NULL) return NULL;
    if (root->left != NULL && root->left->key == key) {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL) {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            return tmp;
        }
        return ro
    }

    if (root->key > key) {
        return predecessor(root->left, pre, root, key) ;
    }
    else{
        return predecessor(root->right, root, suc, key) ;
    }
}


Node* getNode(Node* root, int key){
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    if (key < root->key) return getNode(root->left, key);
    else return getNode(root->right, key);
}

void menu(){
    printf("\t______________________\n");
    printf("\t| 1. Insert          |\n");
    printf("\t| 2. Delete node     |\n");
    printf("\t| 3. Print in-order  |\n");
    printf("\t| 4. Print pre-order |\n");
    printf("\t| 5. Print pos-order |\n");
    printf("\t| 6. Print BFS       |\n");
    printf("\t| 7. Number of nodes |\n");
    printf("\t| 8. Tree height     |\n");
    printf("\t| 9. Get sucessor    |\n");
    printf("\t| 10. Get Predecessor|\n");
    printf("\t| 11. Clear tree     |\n");
    printf("\t| 12. Clear terminal |\n");
    printf("\t| 13. Exit           |\n");
    printf("\t----------------------\n");
    return;
}
