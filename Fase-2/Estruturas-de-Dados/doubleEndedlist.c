#include <stdio.h>
#include <stdlib.h>

//insert before-> (value1, value2)
//insert index(value) -1

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
        printf("vector [%d] = %d\n", counter, list->value);
        counter++;
        list = list->next;
    }
}

void printBackwards(vector * tail){
    int index = 0;
    while (tail != NULL){
        if (tail->next != NULL)
            printf("vector[%d] = %d\n", index, tail->value);
        
        tail = tail->previous;
        index++;
       
    }
}

//delete an element given a value
void delete(int value, vector ** head){
    vector * aux = *head;
    vector * auxHead = *head;

    if ((*head)->value == value){
        (*head)->next->previous = NULL;
        *head = (*head)->next;
        free(aux);
    }

    else{
        aux = auxHead;

        while (auxHead != NULL){
            //remove the last value (gambiarra alert!!!!)
            if (auxHead->value == value & auxHead->next == NULL){
                aux->next = NULL;
                free(auxHead);
            }

            else if (auxHead->value == value){
                aux->next = auxHead->next;
                aux->next->previous = aux;
                free(auxHead);
            }

            aux = auxHead;
            auxHead = auxHead->next;
        }
    }

    
}

int main(){
    vector * list = NULL, * head;
    int input, del;
    int counter = 0;
    
    scanf("%d", &input);
    while (input != 0){
        push_back(input, &list);
        if (counter == 0){
            head = list;
            counter = 1;
        }
        scanf("%d", &input);
    }

    printf("Type a value o remove: ");
    scanf("%d", &del);
    delete(del, &head);
    
    printf("Print backwards\n");
    printBackwards(list);
    
    printf("Print normal\n");
    print(head);

    return 0;
}
