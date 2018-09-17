#include <stdio.h>
#include <stdlib.h>

//encontrar elemento na lista
//limpar a lista 

struct list
{
  int value;
  struct list *next;
  unsigned int size;
};

struct list * push_back(int val, struct list *tail)
{

    if (tail == NULL)
    {
        tail = (struct list *) malloc(sizeof(struct list));
        tail->value = val;
        tail->next = NULL;
        tail->size = 1;
    }

    else
    {
        tail->next = (struct list *) malloc(sizeof(struct list));
        tail->next->value = val;
        tail->size++;
        tail->next->size =  tail->size;
        tail->next->next = NULL;
        tail = tail->next;
    }
    return tail;
}

void print(struct list *head){

    unsigned short int i = 0;
    while (head != NULL) {
        printf("vector [%d] = %d\n", i, head->value);
        head = head->next;
        i++;
    }    
}

void get(int i, struct list *head){
    int counter = 0;
    
    while (head != NULL){
        if (i == counter)
            break;
        head = head->next;        
        counter++;
    }
    if (i == counter)
        printf("list[%d] = %d\n", counter, head->value);
    else
        printf("index %d not found\n", i);
}


void clear(struct list *head){

    struct list *aux = head;

    while (aux != NULL){
        head = aux->next;
        free(aux);
       //printf("%d", aux->value);
        aux = head;
    }
    printf("List is clear\n");
    
}

void in(int value, struct list *head){
    int are = 0;
    while (head != NULL){
        if (head->value == value)
            are = 1;
        head = head->next;
    }
    printf("%s\n", (are == 1 ? "true" : "false"));
}

int main()
{
    
    struct list *tail = NULL, *head = NULL;
    int insert;
    int index, value;

    scanf("%d", &insert);
    while (insert != 0)
    {
        tail = push_back(insert, tail);
        if (tail->size == 1)
            head = tail;
        scanf("%d", &insert);

    }
    //shows the all values
    print(head);
    printf("List size: %d\n", tail->size);

    //checks if value is in the list
    printf("Type an value to search in the list: ");
    scanf("%d", &value);
    in(value, head);

    //get a value given an index
    printf("Type an index to get his value: ");
    scanf("%d", &index);
    get(index, head);
    
    clear(head);

    return 0;
}
