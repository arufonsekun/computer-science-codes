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

void push_back(int val, struct list *mylist)
{

    if (mylist->size == 0)
    {
        mylist->value = val;
        mylist->next = NULL;
        mylist->size = 1;
    }

    else
    {
        struct list *new = (struct list *) malloc(sizeof(struct list));
        new->value = val;
        new->next = NULL;

        while (mylist->next != NULL)
        {
            mylist->size++;
            mylist = mylist->next;
        }

        new->size = mylist->size;
        mylist->next = new;
    }
}

void print(struct list *first){

    unsigned short int i = 0;
    while (first != NULL) {
        printf("vector [%d] = %d\n", i, first->value);
        first = first->next;
        i++;
    }


}

void get(int i, struct list *head){
    struct list *aux = head;
    int counter = 0;

    while (counter < i){
        aux = aux->next;        
        counter++;
    }
    printf("list[%d] = %d\n", counter, aux->value);
}


void clear(struct list *mylist){

    struct list *aux = mylist;

    while (aux != NULL){
        mylist = aux->next;
        free(aux);
        aux = mylist;
    }
    printf("List is clear");
    
}


int main()
{

    struct list *mylist, *first;
    mylist->next = NULL;
    first = mylist;

    push_back(4, mylist);
    push_back(5, mylist);
    push_back(6, mylist);
    push_back(7, mylist);
    push_back(8, mylist);
    push_back(9, mylist);

    //gets the element at position 3 (indexes starting in 0)
    get(3, first);
    //list the elemets
    print(first);
    clear(first);
    printf("List size: %d\n", first->size + 1);

    return 0;
}
