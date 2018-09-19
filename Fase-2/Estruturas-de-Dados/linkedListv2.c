#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct vector{
    int value;
    struct vector* next;
    
}; 

//nickname to "struct vector"
typedef struct vector vector;

void push_back(vector **list, int value){
    if (*list == NULL){
        (*list) =  (vector *) malloc(sizeof(vector *));
        (*list)->value = value;
        (*list)->next = NULL;
    }
    else{
        (*list)->next = (vector *) malloc(sizeof(vector *));
        (*list)->next->value = value;
        (*list)->next->next = NULL;
        (*list) = (*list)->next;
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

void clear(vector * head){
    vector *aux;

    while (head != NULL){
        aux = head->next;
        free(head);
        head = aux;
    }
    printf("Vector is clear\n");
}

void in(vector *head, int value){
    int index = 0;
    char output[5] = "false";

    while (head != NULL){
        if (head->value == value){
            strncpy(output, "true", 5);
            break;
        }
        index++;
        head = head->next;
    }
    
    printf("%s\n", output);
}

int main(){
    vector *tail = NULL, *head = NULL;
    int input, first = 1;

    //inputs values
    while (scanf(" %d", &input) != EOF){
        push_back(&tail, input);
        
        if (first){
            first = 0;
            head = tail;
        }

    }

    print(head); 
    printf("Type a value to search: ");
    scanf("%d", &input);
    in(head, input);
    clear(head);
    printf("%p", head->value);

    return 0;
}
