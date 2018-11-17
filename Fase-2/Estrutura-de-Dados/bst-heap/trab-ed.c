//Name: Junior Vitor Ramisch
//email: junior.ramisch@gmail.com
//code: 1811100034
#include <stdio.h>
#include <stdlib.h>

#define RED "\033[31;1m%d \033[0m\t"
#define WHITE "\033[37;1m %d \033[0m\t"

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
void breadthFirstSearch(Node* root);
void BFS(Node* parent, int height);
int height(Node* root);
int treeSize(Node* root);
int max(int a, int b);
void inOrder(Node* root);
void preOrder(Node* root);
void posOrder(Node* root);
Node* deleteNode(Node* root, int key);
void clearTree(Node* root);

int main(){
    Node* root = NULL;
    int operation, size;

    menu();//show menu
    printf("Type the operation: ");
    scanf("%d", &operation);
    while(operation != 11){
        if (operation == 1){
            printf("Type the tree size: ");
            scanf("%d", &size);
            if (root != NULL) {clearTree(root); root = NULL;};
            root = generateNodes(root, size);
        }

        else if (operation == 2){
            printf("Type the node to remove: ");
            scanf("%d", &size);//reusing vars
            deleteNode(root, size);
        }

        else if (operation == 3){
            if (root == NULL) printf("Tree is empty!\n");
            else { inOrder(root); printf("\n");}
        }

        else if (operation == 4){
            if (root == NULL) printf("Tree is empty!\n");
            else{ preOrder(root); printf("\n");}
        }

        else if (operation == 5){
            if (root == NULL) printf("Tree is empty!\n");
            else { posOrder(root); printf("\n");}
        }

        else if (operation == 6){
            printf("   ");
            breadthFirstSearch(root);
        }

        else if(operation == 7){
            printf("Tree number of nodes is %d\n", treeSize(root));
        }

        else if (operation == 8){
            printf("Tree height is %d\n", height(root));
        }

        else if (operation == 9){
            clearTree(root);
            printf("Tree memory is clear!\n");
        }

        else if(operation == 10) {
            system("clear");
            menu();
        }

        printf("Altura da sub arvore da esq.: %d e da direita %d\n", height(root->left), height(root->right));
        printf("Type the operation: ");
        scanf("%d", &operation);
        // scanf("%d", &value);
        // new = insert(&root , NULL, value);
        // root = fixUpInsertion(root, new);
    }
    return 0;
}

//function to generate the node values
//and insert in the tree
Node* generateNodes(Node* root, int treeSize){
    Node* new;
    int newKey = 0;
    for (int i = 0; i < treeSize; i++){
        newKey  = rand() % 100;
        printf("%d\n", newKey);
        new = insert(&root, NULL, newKey);
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
    if (key >= (*root)->key)
        return insert(&(*root)->right, *root, key);
    else
        return insert(&(*root)->left, *root, key);
}

Node* deleteNode(Node* root, int key){
    return root;
}

Node* leftRotate(Node* new, Node* parent){
    new->c = 'B';
    parent->c = 'R';
    parent->right = new->left;
    new->left = parent;

    if (new->left->right != NULL)
        new->left->right->parent = parent;

    if (parent->parent->left == parent)
        parent->parent->left = new;
    else
        parent->parent->right = new;

    new->parent = parent->parent;
    parent->parent = new;

    return new;
}

Node* rightRotate(Node* new, Node* parent){
    new->c = 'B';
    parent->c = 'R';
    parent->left = new->right;
    new->right = parent;

    if (new->right->left != NULL){
        new->right->left->parent = parent;
    }

    if (parent->parent->left == parent)
        parent->parent->left = new;
    else
        parent->parent->right = new;

    new->parent = parent->parent;
    parent->parent = new;

    return new;
}

Node* fixUpInsertion(Node* root, Node* new){
    while (new->parent != NULL && new->parent->c == 'R'){
        Node* grandparent = new->parent->parent;
        if (new->parent == new->parent->parent->left){
            //null means a black node
            if (new->parent->parent->right != NULL && new->parent->parent->right->c == 'R'){
                //printf("Changing colors: grandparent <---> parent and uncle!\n");
                new->parent->c = 'B';
                new->parent->parent->right->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
            }

            // left-right case
            else if (new->parent->right == new){
                //printf("Caso left-right!\n");
                grandparent->left = new;
                new->parent->right = new->left;
                new->left = new->parent;
                new->parent->parent = new;
                new->parent = grandparent;
                new = rightRotate(new, new->parent);
                if (new->parent->parent == NULL) root = new;
                if (new->parent->parent != NULL && new->c == 'B' && new->parent->c == 'B')
                    new = new->parent->parent;
                else
                    new = new->parent;
            }
            else{
                //printf("Caso left-left!\n");
                new = rightRotate(new->parent, new->parent->parent);
                if (new->parent->parent == NULL) root = new;
                new = new->parent;
            }
        }

        else{
            if (new->parent->parent->left != NULL && new->parent->parent->left->c == 'R'){
                //printf("Changing colors: grandparent <---> parent and uncle!\n");
                new->parent->c = 'B';
                new->parent->parent->left->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
            }
            else if(new->parent->left == new){
                //printf("Caso right-left!\n");
                grandparent->right = new;
                new->parent->left = new->right;
                new->right = new->parent;
                new->parent->parent = new;
                new->parent = grandparent;
                new = leftRotate(new, new->parent);
                if (new->parent->parent == NULL) root = new;
                if (new->parent->parent != NULL && new->c == 'B' && new->parent->c == 'B')
                    new = new->parent->parent;
                else
                    new = new->parent;
            }
            else{
                //printf("Caso right-right!\n");
                new = leftRotate(new->parent, new->parent->parent);
                if (new->parent->parent == NULL) root = new;
                new = new->parent;
            }
        }
    }
    //root node is always black
    root->c = 'B';
    return root;
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
        (parent->c == 'R' ? printf(RED, parent->key) : printf(WHITE, parent->key));
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

void menu(){
    printf("\t_____________________\n");
    printf("\t| 1. Insert         |\n");
    printf("\t| 2. Delete node    |\n");
    printf("\t| 3. Print in-order |\n");
    printf("\t| 4. Print pre-order|\n");
    printf("\t| 5. Print pos-order|\n");
    printf("\t| 6. Print BFS      |\n");
    printf("\t| 7. Number of nodes|\n");
    printf("\t| 8. Tree height    |\n");
    printf("\t| 9. Clear tree     |\n");
    printf("\t| 10. Clear terminal|\n");
    printf("\t| 11. Exit          |\n");
    printf("\t---------------------\n");
    return;
}
