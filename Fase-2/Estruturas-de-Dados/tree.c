#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

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

int search(tree * head, int value){
    if (head == NULL)
        return -6666;
    if (head->value == value)
        return head->value;
    else{
        if (value < head->value)
            return search(head->left, value);
        else
            return search(head->right, value);
    }
}

void clear(tree * head){
   if (head == NULL)
       return;
   else{
        clear(head->left);
        clear(head->right);
        free(head);
   }
}

tree * fill(tree * head){
    clock_t begin, end;
    double time_spent;
    begin = clock();

    for (long int i = 0; i < SIZE; i++){
        printf("%ld\r\r\r\r\r\r\r", i);
        insertRec(&head, rand());
    }
    end = clock();
    time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
    printf("Time spent %lf seconds\n", time_spent);
    return head;
}

int main(){
    tree * tree, * find;
    tree = NULL;
    int input, operation;

    printf("0-leave 1-insert 2-Print Sorted 3-Search 4-clear 5-fill\n");
    printf("Type the operation code: ");
    scanf("%d", &operation);
    
    while (operation != 0){

        if (operation == 1){
            printf("Type the value to insert: ");
            scanf("%d", &input);
            if (tree == NULL){
                insertRec(&tree, input);
            }

            else{
                insertRec(&tree, input);
            }
        }
        else if (operation == 2){
            printSorted(tree);
            printf("\n");
        }
        else if (operation == 3){
            clock_t begin = clock();
            //printf("Type a value to search: ");
            //scanf("%d", &input);    
            printf("The value is %d\n", search(tree, rand() % 100));
            clock_t end = clock();
            int time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
            printf("Time spent in searching %4.3f\n", time_spent);
        }
        else if (operation == 4){
            clear(tree);
            printf("The tree is clear\n");
            tree = NULL;
        }
        else{
            tree = fill(tree);
        }
        printf("Type the operation code: ");
        scanf("%d", &operation);
    }

    return 0;
}
