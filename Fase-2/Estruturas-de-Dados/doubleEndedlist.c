#include <stdio.h>
#include <stdlib.h>

struct vector{
    int value;
    struct vector * next;
    struct vector * previous;
};

typedef struct vector vector;

void push_back(int value, vector ** list){
    if (*list == NULL){
        (*list) = (vector *) malloc(sizeof(vector *));
        (*list)->value = value;
        (*list)->next = NULL;
        (*list)->previous = NULL;
    }
    else{
        (*list)->next = (vector *) malloc(sizeof(vector *));
        (*list)->next->value = value;
        (*list)->next->next = NULL;
        (*list)->next->previous = *list;
        (*list) = (*list)->next;
    }

}

void print(vector * list){
    int counter = 0;
    while (list != NULL){
        printf("vector[%d] = %d\n", counter, list->value);
        counter++;
        list = list->next;
    }
}

void printBackwards(vector * tail){

    int index = 0;
    while (tail != NULL){
        printf("vector[%d] = %d\n", index, tail->value);
        tail = tail->previous;
        index++;
       
    }

}

//delete an element given a value
//return a pointer to the last value
vector * delete(int value, vector ** head){
    vector * aux = *head;
    vector * auxHead = *head;

    if ((*head)->value == value){
        (*head)->next->previous = NULL;
        *head = (*head)->next;
        free(aux);
        while (auxHead->next != NULL)
            auxHead = auxHead->next;
        return auxHead;
    }

    else{

        while (auxHead->next != NULL){

            if (auxHead->value == value){
                aux->next = auxHead->next;
                aux->next->previous = aux;
                free(auxHead);
            }

            aux = auxHead;
            auxHead = auxHead->next;
        }

        if ((auxHead->value == value) & (auxHead->next == NULL)){
            aux->next = NULL;
            free(auxHead);
            return aux;
        }
        else{
            return auxHead;
        }
    }
    
}

void insertBefore(int new, int before, vector ** head){
    vector * newValue = (vector *) malloc (sizeof(vector *));
    newValue->value = new;

    if ((*head)->value == before){
        newValue->previous = NULL;
        newValue->next = *head;
        (*head)->previous = newValue;
        *head = newValue;
    }
    else{
        vector * behind = *head;
        vector * front = (*head)->next;
        while (front != NULL){
            if (front->value == before){
                newValue->next = front;
                newValue->previous = behind;
                behind->next = newValue;
                front->previous = newValue;
            }
            behind = front;
            front = front->next;
        }
    }
}

int main(){
    //tail era pra ser list mas como list apontava pro fim agora vai ser tail o nome e fodasse
    vector * tail = NULL, * head;
    int operation = 1, input, before;
    int counter = 0;
   
    printf("\n0-Leave \n1-Insert \n2-Remove \n3-List Normal \n4-List Backwards \n5-Insert Before \n6-Clear terminal\n");
    while (operation != 0){
        
        printf("Type the operation code: ");
        scanf("%d", &operation);

        if (operation == 1){
            printf("Type the value to insert: ");
            scanf("%d", &input);
            push_back(input, &tail);
           
            if (counter == 0){
                head = tail;
                counter = 1;
            }
        }

        else if (operation == 2){
            printf("Type the value to remove: ");
            scanf("%d", &input);
            tail=delete(input, &head);
        }

        else if (operation == 3)
            print(head);

        else if (operation == 4)
            printBackwards(tail);

        else if (operation == 5){
            printf("Type the value to insert followed by the existing value: ");
            scanf("%d %d", &input, &before);
            insertBefore(input, before, &head);
        }

        else{
            system("clear");
            printf("\n0-Leave \n1-Insert \n2-Remove \n3-List Normal \n4-List Backwards \n5-Insert Before \n6-Clear terminal\n");
        }
    }

    return 0;
}
