#include <stdio.h>
#include <stdlib.h>

struct vector {
    int value;
    struct vector * previous;
    struct vector * next;
};

typedef struct vector vector;

void printMenu(){
    printf("0-Quit\n1-Insert\n2-Remove\n3-List\n4-List backwards\n5-clear\n");    
}

void insert(int value, vector** v){
    if (*v == NULL){
        *v = (vector *) malloc(sizeof(vector *));
        (*v)->value = value;
        (*v)->previous = NULL;
        (*v)->next = NULL; 
    }
    else{
        (*v)->next = (vector *) malloc(sizeof(vector *));
        (*v)->next->value = value;
        (*v)->next->next = NULL;
        (*v)->next->previous = (*v);
        (*v) = (*v)->next;
    }

}

void print(vector * head){
    int index = 0;
    while (head != NULL){
        printf("vector[%d] = %d\n", index, head->value);
        head = head->next;
        index++;
    }
}

void listBackwards(vector * tail){
    int index = 0;
    while (tail != NULL){
        printf("vector[%d] = %d\n", index, tail->value);
        tail = tail->previous;
        index++;
    }
}

void delete(int index, vector** head, vector** tail){  
    vector * aux = *head;
    if (index == 0){
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }
    else{
        int counter = 0;
        while (counter < index){
            aux = aux->next;
            counter++;
        }
        printf("%p", aux->next);
        if (aux->next != NULL){
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;
        }
        else{
            aux->previous->next = NULL;
            *tail = aux->previous;
        }
    }
}

int main(){
   vector * head = NULL;
   vector * tail = NULL;
   int operation, input;

   printMenu();
   printf("Type the operation code\n>> ");
   scanf("%d", &operation);
   while (operation != 0){
       if (operation == 1){
           printf("Type the value to insert\n>> ");
           scanf("%d", &input);
           insert(input, &tail);
           if (head == NULL)
               head = tail;
       }
       else if (operation == 2){
           printf("Type the index to remove\n>> ");
           scanf("%d", &input);
           delete(input, &head, &tail);
       }
       else if (operation == 3){
           print(head);
       }
       else if (operation == 4){
           listBackwards(tail);
       }
       printf("Type the operation code\n>> ");
       scanf("%d", &operation);
   }
   return 0;
}
