#include <stdio.h>
#include <stdlib.h>

struct list
{
  int value;
  struct list *next;
};

void push_back(int val, struct list *lista)
{
    struct list *new;
    new = (struct list *) malloc(sizeof(struct list));
    new->value = val;
    new->next = NULL;

    if (lista->next == NULL)
    {
        lista->next = new;
    }

    else
    {
        while (lista->next != NULL)
        {
            lista = lista->next;
        }
        lista = new;
    }
}

void __init__(struct list* mylist){
    mylist->value = 0;
    mylist->next = NULL;
}

int main()
{

    struct list mylist* = __init__();
    struct list mylist;
    push_back(4, &mylist);
    push_back(3, &mylist);

    printf("%d\n", mylist.value);
    printf("%d\n", mylist.next->value);

    //push_back(2, &mylist);


    return 0;
}
