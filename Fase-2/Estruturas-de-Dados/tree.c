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

void printDecreasing(tree * head){
    if (head == NULL)
        return;
    else{
        printSorted(head->right);
        printf("%d ", head->value);
        printSorted(head->left);
    }
}

int search(tree * head, int value){
    if (head == NULL)
        return -999999;
    if (head->value == value)
        return head->value;
    else{
        if ((value < head->value) & (head->left != NULL))
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
    tree * tree;
    tree = NULL;
    int input, operation;

    printf("0-leave 1-insert 2-Print Increasing Order \n3- Print Decreasing Order 4-Search 5-clear 6-fill 7-clear terminal\n");
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
            printDecreasing(tree);
            printf("\n");
        }
        else if (operation == 4){
            printf("Type a value to search: ");
            scanf("%d", &input);
            clock_t begin = clock();
            int value  = search(tree, input);
            clock_t end = clock();
            printf("The value is %d (-999999 means not found)\n", value);
            double time_spent = (double) (end - begin);
            printf("Time spent in searching %4.3lf\n", time_spent);
        }
        else if (operation == 5){
            clear(tree);
            printf("The tree is clear\n");
            tree = NULL;
        }
        else if (operation == 6){
            tree = fill(tree);
        }
        else{
            system("clear");
        }
        printf("Type the operation code: ");
        scanf("%d", &operation);
    }

    return 0;
}
