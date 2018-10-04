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

/*void push(tree ** parent, int value){
     if (*parent == NULL){
         (*parent) = (tree *) malloc(sizeof(tree *));
         (*parent)->value = value;
         (*parent)->left = NULL;
         (*parent)->right = NULL;
     }
     else{
         printf("opa\n");
         tree * aux = *parent;
         tree * behind;
         while (aux != NULL){
             behind = aux;
             if (aux->value <= value){
                 aux = aux->right;
             }
             else{
                 aux = aux->left;
             }
         }
 
         tree * new = (tree *) malloc(sizeof(tree *));
         new->value = value;
         new->right = NULL;
         new->left = NULL;
         
         if (value >= behind->value){
             behind->right = new;
         }
         else{
             behind->left = new;
         }
     }
 }
 */


int main(){
    tree * treee, * parent;
    parent = NULL;
    int input;

    printf("Type a value: ");
    scanf("%d", &input);
    
    while (input != 0){
        if (parent == NULL){
            printf("entro\n");
            insertRec(&parent, input);
        }

        else{
            insertRec(&parent, input);
        }
        printf("Type a value: ");
        scanf("%d", &input);
    }

    printf("%d\n", parent->right->value);
    return 0;
}
