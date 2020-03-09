#include <stdio.h>
#include <stdlib.h>

struct vector {
    int value;
    struct vector * next;
};

typedef struct vector vector;

void push_back(vector ** array, int value)
{
    if (*array == NULL)
    {
        (*array) = (vector *) malloc(sizeof(vector *));
        (*array)->value = value;
        (*array)->next = NULL;
    }
    else
    {
        (*array)->next = (vector *) malloc(sizeof(vector *));
        (*array)->next->value = value;
        (*array)->next->next = NULL;
        (*array) = (*array)->next; 
    }
}

void insert_sort(vector ** array, int value)
{
    if (*array == NULL)
    {
        (*array) = (vector *) malloc(sizeof(vector *));
        (*array)->value = value;
        (*array)->next = NULL;
    }
}

void print(vector * head)
{
    while (head != NULL)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main()
{    
    vector * head, * tail = NULL;

    push_back(&tail, 10);
    head = tail;
    push_back(&tail, 5);
    push_back(&tail, 2);
    push_back(&tail, 4);
    push_back(&tail, 6);
    push_back(&tail, 7);
    push_back(&tail, 2);
    push_back(&tail, 1);
    push_back(&tail, 15);
    print(head);

    return 0;
}
