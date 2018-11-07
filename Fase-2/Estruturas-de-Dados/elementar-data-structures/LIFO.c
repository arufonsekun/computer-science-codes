#include <stdio.h>
#include <stdlib.h>

struct lifo{
    int value;
    struct lifo * below;
};
typedef struct lifo lifo;

void push(int value, lifo ** top){
    if (*top == NULL){
        *top = (lifo *) malloc (sizeof(lifo *));
        (*top)->value = value;
        (*top)->below = NULL;
    }
    else{
        lifo * new =  (lifo *) malloc (sizeof(lifo *));
        new->value = value;
        new->below = *top;
        *top = new;
    }
}

void print(lifo * top){
    while (top != NULL){
        printf("|%d|\n", top->value);
        top = top->below;
    }
}

void pop(lifo ** top){
    if (*top == NULL)
        printf("Stack is empty\n");
    else{
        lifo * topper = *top;
        *top = (*top)->below;
        free(topper);
    }
}

int main(){
    lifo * stack;
    int value, operation;
    stack = NULL;

    printf("0-Leave\n1-Insert\n2-Pop\n3-Print\n4-Clear terminal\n");
    printf("Type the operation code: ");
    scanf("%d", &operation);
    
    while (operation != 0){
        if (operation == 1){
            printf("Type a value: ");
            scanf("%d", &value);
            push(value, &stack);
        }
        else if (operation == 2){
            pop(&stack);
        }
        else if (operation == 3)
            print(stack);
        else
            system("clear");
        
        printf("Type the operation code: ");
        scanf("%d", &operation);
    }

    return 0;
}
