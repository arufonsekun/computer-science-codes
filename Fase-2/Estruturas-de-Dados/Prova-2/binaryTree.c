#include <stdio.h>
#include <stdlib.h>

struct tree {
    int value;
    struct tree* left;
    struct tree* right;
};

typedef struct tree tree;

void insert(int value, tree** parent){
    if (*parent == NULL){
        (*parent) = (tree*) malloc(sizeof(tree*));
        (*parent)->value = value;
        (*parent)->left = NULL;
        (*parent)->right = NULL;
        return;
    }
    else{
        if (value >= (*parent)->value)
            insert(value, &(*parent)->right);
        else
            insert(value, &(*parent)->left);
    } 
}

void listSorted(tree* parent){
    if (parent == NULL)
        return;
    else{
        listSorted(parent->left);
        printf("%d ", parent->value);
        listSorted(parent->right);
        //printf("%d", parent->value);
    }
}

tree * search(int value, tree* parent){
    if (parent == NULL)
        return NULL;
    if (parent->value == value)
        return parent;
    else{
        if (value > parent->value)
            return search(value, parent->right);
        else
            return search(value, parent->left);
    }
}

int main(){
    tree * parent = NULL;
    int input, operation;
    
    printf("0-quit\n1-Insert\n2-Search\n3-List Sorted\nType the operation code\n>> ");
    scanf("%d", &operation);
    while (operation != 0){
        if (operation == 1){
            printf("Type the element: ");
            scanf("%d", &input);
            insert(input, &parent);
        }
        else if (operation == 2){
            printf("Type the value to search: ");
            scanf("%d", &input);
            tree* find = search(input, parent);
            (find == NULL ? printf("Value not found!\n") : printf("Value was found %d\n", find->value));
        }
        else if (operation == 3){
            listSorted(parent);
            printf("\n");
        }
        printf("Type the operation code:\n>> ");
        scanf("%d", &operation);
    }
    printf("%d\n", parent->left->value); 
    return 0;
}
