#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//update (int old, int new)
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

vector * get(vector * head, int value){
    vector * find = NULL;
    while (head != NULL){
        if (head->value == value)
            return head;
        head = head->next;
    }
}

void update(vector * head, int old, int new){
    vector * find = get(head, old);
    (find != NULL ? find->value = new : printf("Value not find\n"));
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

void delete(vector **head, int value){
    vector * aux;
    vector *head1 = *head;

    if ((*head)->value == value){
        aux = *head;
        *head = (*head)->next;
        free(aux);
    }
    else{
        aux = head1;
        while (head1 != NULL){
            if (head1->value == value){
                aux->next = head1->next; 
                free(head1);
            }

            aux = head1;
            head1 = head1->next;
        }

    }

}

int main(){
    vector *tail = NULL, *head = NULL;
    int input, first = 1;
    int old, new, del;

    //inputs values
    scanf(" %d", &input);
    while (input != 0){
        push_back(&tail, input);
        
        if (first){
            first = 0;
            head = tail;
        }
        scanf(" %d", &input);

    }

   /* printf("Type a value to search: ");
    scanf("%d", &input);
    in(head, input);
    
    printf("Type a value to change and the new value: ");
    scanf("%d %d", &old, &new);
    update(head, old, new);*/
    print(head);
   
    printf("Type a value to remove: ");
    scanf("%d", &del);
    delete(&head, del);
    print(head);

    clear(head);
    //printf("%p", head->value);

    return 0;
}
