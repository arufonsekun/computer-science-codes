#include <stdio.h>
#include <stdlib.h>

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
        printf("%s\n", "birl");
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
    while (1) {
        printf("vector [%d] = %d\n", i, first->value);
        if (first->next == NULL)
            break;
        first = first->next;
        i++;
    }
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

    print(first);
    printf("%d\n", first->value);

    return 0;
}
