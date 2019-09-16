#include <stdio.h>
#include <stdlib.h>

struct vector {
    int value;
    struct vector * next;
};

typedef struct vector vector;

void printMenu(){
    printf("0-Quit\n1-Insert\n2-Remove\n3-List\n4-Clear\n5-clear\n>> ");
    return;
}

void insert(int value, vector** tail){
    if (*tail == NULL){
        *tail = (vector *) malloc(sizeof (vector *));
        (*tail)->value = value;
        (*tail)->next = NULL;
    }   
    else{
        (*tail)->next = (vector *) malloc(sizeof(vector *));
        (*tail)->next->value = value;
        (*tail)->next->next = NULL;
        *tail = (*tail)->next;
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

void delete(int index, vector ** head){
    if (*head == NULL) printf("List is empty\n");
    else if (index == 0){
        *head = (*head)->next;
    }
    else{
        vector * Head = (*head);
        int pos = 0;

        while (pos < index -1){
            Head = Head->next;
            pos++;
        }
        vector * aux = Head->next;
        Head->next = Head->next->next;
        free(aux);
    }
}

void clear(vector * head){
    vector * aux = head;
    while (head != NULL){
        aux = head->next;
        free(head);
        head = aux;
    }
}

int main(){
    vector * head = NULL;
    vector * tail= NULL;    
    int operation, input;
    
    printMenu();
    scanf("%d", &operation);
    while (operation != 0){
        if (operation == 1){
            printf("Type the element to add\n>> ");
            scanf("%d", &input);
            insert(input, &tail);
            if (head == NULL){
                head = tail;
            }
        }
        else if (operation == 2){
            printf("Type de index to remove\n>> ");
            scanf("%d", &input);
            delete(input, &head);
        }
        else if (operation == 3){
            print(head);
        }
        else if(operation == 4){
            system("clear");
            printMenu();
        }else{
            clear(head);
            tail = NULL;
            head = tail;
        }

        printf("Type the operation code:\n>> ");
        scanf("%d", &operation);
    }
}
