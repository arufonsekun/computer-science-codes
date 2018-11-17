#include <stdio.h>
#include <stdlib.h>

struct node {
     int key;
     char c;
     struct node * left;
     struct node * right;
     struct node * parent;
};

#define RED "\033[31;1m%d \033[0m\t"
#define WHITE "\033[37;1m %d \033[0m\t"
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
        (parent->c == 'R' ? printf(RED, parent->key) : printf(WHITE, parent->key));
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
    if (key >= (*root)->key)
        return insert(&(*root)->right, *root, key);
    else
        return insert(&(*root)->left, *root, key);
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

    //new->right->parent = new;

    if (parent->parent->left == parent)
        parent->parent->left = new;
    else
        parent->parent->right = new;

    new->parent = parent->parent;
    parent->parent = new;

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
                new->parent->parent->right->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
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
                printf("Parent k:%d and c:%c\n", new->parent->key, new->parent->c);
                new = rightRotate(new, new->parent);
                if (new->parent->parent == NULL) root = new;
                if (new->parent->parent != NULL && new->c == 'B' && new->parent->c == 'B')
                    new = new->parent->parent;
                else
                    new = new->parent;
                //printf("Parent k:%d and c:%c\n", new->parent->key, new->parent->c);
            }
            else{
                printf("Caso left-left!\n");
                //printf("%d\n", new->key);
                new = rightRotate(new->parent, new->parent->parent);
                if (new->parent->parent == NULL) root = new;
                new = new->parent;
            }
        }

        else{
            Node* uncle = new->parent->parent->left;
            if (uncle != NULL && uncle->c == 'R'){
                printf("Changing colors\n");
                new->parent->c = 'B';
                new->parent->parent->left->c = 'B';
                new->parent->parent->c = 'R';
                new = new->parent->parent;
            }
            else if(new->parent->left == new){
                printf("Caso right-left!\n");
                //printf("%d\n", new->key);
                grandparent->right = new;
                new->parent->left = new->right;
                new->right = new->parent;
                new->parent->parent = new;
                new->parent = grandparent;
                printf("%d\n", new->parent->key);
                new = leftRotate(new, new->parent);
                if (new->parent->parent == NULL) root = new;
                if (new->parent->parent != NULL && new->c == 'B' && new->parent->c == 'B')
                    new = new->parent->parent;
                else
                    new = new->parent;
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

void padding(int n){
  for(int i = 0; i < n; i++ )
    printf("\t");
}

void print_node(Node *node, int level) {
  int h_right = height(node->right);
  int h_left = height(node->left);
  int h = (h_right > h_left ? h_right : h_left);

  char str[32];
  sprintf(str, "(\x1b[1m%d\x1b[0m|h:%d)", node->key, h);
  printf("%s", str);

  int dash = 80 - (level * 8); // 80 is the total available space, level * 8 is the tab size

  // For each caracter on string remove 1 from dash
  // Starts in 14 because str has 14 non-print characters (like \x1b[1m for coloring)
  for(int i=14; str[i] != '\0'; i++) dash--;

  for(int i=0; i < dash; i++) printf("-");
  puts("");
}

void print_tree (Node *root, int level){
  if (!root) {
    padding (level+1);
    puts("~");
  }
  else {
    print_tree (root->right, level + 1);
    padding (level + 1);
    print_node(root, level + 1);
    print_tree(root->left, level + 1);
  }
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
        //BreadthFirstSearch(root);
        root = fixUpInsertion(root, new);
    }

    print_tree(root, 1);
    printf("\t");BreadthFirstSearch(root);
    //printf("Height left: %d and height right: %d\n", height(root->left), height(root->right));
    return 0;
}
