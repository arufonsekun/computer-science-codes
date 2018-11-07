//author Junior Vitor Ramisch
//e-mail: junior.ramisch@gmail.com
//student code: 1811100034
#include <stdio.h>
#include <stdlib.h>

struct queue{
    int value;
    struct queue * next;
};
typedef struct queue queue;

//prototypes
queue * enqueue (queue * last, int value);
void dequeue (queue ** first);
void print (queue * first);
int isEmpty(queue * queue);

int main(){
    //queue points to the first element
    queue * queue = NULL, * tail = NULL;
    int operation, input;
    
    printf("0-leave 1-enqueue 2-dequeue 3-print\n");
    printf("Type the operation code : ");
    scanf("%d", &operation);
    while(operation != 0){
        if(operation == 1){
            printf("Type de value to enqueue (just ints): ");
            scanf("%d", &input);
            //stores the first value enqueued
            if (isEmpty(queue)){
                tail = enqueue(queue, input);
                queue = tail;
            }
            else
                tail = enqueue(tail, input);
        }
        else if (operation == 2)
            dequeue(&queue);
        else if (operation == 3)
            print(queue);
        else
            printf("What you mean with %d?\n", operation);
        printf("Type the operation code%s: ", ((operation > 3) | (operation < 0) ? " again, please" : " "));
        scanf("%d", &operation);  
    }
    return 0;
}

queue * enqueue(queue * last, int value){
    if (isEmpty(last)){
        last = (queue *) malloc(sizeof(queue *));
        last->value = value;
        last->next = NULL;
        return last;
    }
    else{
        queue * new = (queue *) malloc(sizeof(queue *));
        new->value = value;
        new->next = NULL;
        last->next = new;
        return new;
    }
}

void dequeue(queue ** first){
    if (isEmpty(*first))
        printf("Queue is empty!\n");
    else{
        queue * aux = *first;
        (*first) = (*first)->next;
        free(aux);
    }
}

void print(queue * first){
    if (isEmpty(first))
        printf("Queue is empty!\n");
    else{
        while (first != NULL){
            printf("|%d", first->value);
            first = first->next;
        }
        printf("|\n");
    }
}

int isEmpty(queue * first){
    return (first == NULL ? 1 : 0);
}
