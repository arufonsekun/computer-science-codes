#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int value;
    struct Tree * left;
    struct Tree * right;
};
typedef struct Tree tree;

void insertRec(tree ** parent, int value){
    if (*parent == NULL){
        tree * new = (tree *) malloc(sizeof(tree *));
        new->value = value;
        new->right = NULL;
        new->left = NULL;
        *parent = new;
    }
    else if (value >= (*parent)->value){
        insertRec(&(*parent)->right, value);
    }
    else{
        insertRec(&(*parent)->left, value);
    }
}

void printSorted(tree * head){
    //just in case whether head is null
    if (head == NULL)
        return;
    
    if ((head->left == NULL) & (head->right == NULL))
        printf("%d ", head->value);
    
    else if ((head->left == NULL) & (head->right != NULL)){
        printf("%d ", head->value);
        printSorted(head->right);
    }
    
    else{
        printSorted(head->left);
        printf("%d ", head->value);
        printSorted(head->right);
    }

}

int main(){
    tree * tree;
    tree = NULL;
    int input;

    printf("Type a value: ");
    scanf("%d", &input);
    
    while (input != 0){
        if (tree == NULL){
            insertRec(&tree, input);
        }

        else{
            insertRec(&tree, input);
        }
        printf("Type a value: ");
        scanf("%d", &input);
    }

    printSorted(tree);
    printf("\n");
    return 0;
}
