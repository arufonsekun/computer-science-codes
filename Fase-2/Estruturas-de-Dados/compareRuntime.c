#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

struct vector{
    int value;
    struct vector * next;
};

struct tree{
    int value;
    struct tree * left;
    struct tree * right;
};

typedef struct vector vector;
typedef struct tree tree;

//insert tree
void insertTree(tree ** head, int value){
    if (*head == NULL){
        tree * new = (tree *) malloc(sizeof (tree *));
        new->right = NULL;
        new->left = NULL;
        new->value = value;
        *head = new;
    }
    else if (value < (*head)->value)
        insertTree(&(*head)->left, value);
    else
        insertTree(&(*head)->right, value);
}

int searchTree(tree * head, int value){
    if (head == NULL)
        return -99999;
    else if (head->value == value)
        return head->value;
    else{
        if ((value < head->value) & (head->left != NULL)){
            return searchTree(head->left, value);
        }
        else{
            searchTree(head->right, value);
        }
    }
}

void clearTree(tree * head){
    if (head == NULL)
        return;
    else{
        clearTree(head->left);
        clearTree(head->right);
        free(head);
    }
}

//list insert
vector * push_back(int value, vector * tail){
    if (tail == NULL){
        tail = (vector *) malloc(sizeof(vector *));
        tail->next = NULL;
        tail->value = value;
    }
    else{
        tail->next = (vector *) malloc(sizeof(vector *));
        tail->next->value = value;
        tail->next->next = NULL;
        tail = tail->next;
    }
    return tail;
}

int getValue(int value, vector * head){
    int find;
    while (head != NULL){
        if (head->value == value){
            find = value;
            return find;
        }
        head = head->next;
    }
}

void clearVector(vector * head){
    vector * aux = head;
    clock_t end, begin;
    begin = clock();
    while (aux != NULL){
        head = aux->next;
        free(aux);
        aux = head;
    }
    end = clock();
    printf("Time spent in vector cleaning is %lf seconds\n", (double) (end - begin) / CLOCKS_PER_SEC);
}

tree * fillTree(tree * head){
    clock_t begin, end;
    double time_spent;
    begin = clock();

    for (long int i = 0; i < SIZE; i++){
        printf("%ld\r\r\r\r\r\r\r", i);
        insertTree(&head, rand());
    }
    end = clock();
    time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
    printf("Time spent in tree insertion is %lf seconds\n", time_spent);
    return head;
}

vector * fillVector(vector * head){
    clock_t begin, end;
    begin = clock();
    vector * tail = NULL;

    for (long int i = 0; i < SIZE; i++){
        printf("%ld\r\r\r\r\r\r\r", i);
        if (tail == NULL) tail = push_back(rand(), head);
        else tail = push_back(rand(), tail);
    }
    end = clock();
    printf("Time spent in vector insertion is %lf seconds\n", (double) (end - begin)/CLOCKS_PER_SEC);
    return head;
}

void treeSearch(tree * tree){
    clock_t end, begin;
    //search
    begin = clock();
    searchTree(tree, rand());
    end = clock();
    printf("Time spent in tree searching is %lf seconds\n", (double) (end - begin) / CLOCKS_PER_SEC);
}

void vectorSearch(vector * head){
    clock_t end, begin;
    begin = clock();
    getValue(rand(), head);
    end = clock();
    printf("Time spent in vector searching is %lf seconds\n", (double) (end - begin) / CLOCKS_PER_SEC);
}

int main(){
    clock_t end, begin;
    vector * head = NULL;
    tree * tree = NULL;

    //insertation
    head = fillVector(head);
    tree = fillTree(tree);
    printf("\n");

    treeSearch(tree);
    treeSearch(tree);
    printf("\n");
    vectorSearch(head);
    vectorSearch(head);
    printf("\n");

    //cleaning
    clearVector(head);
    begin = clock();
    clearTree(tree);
    end = clock();
    printf("Time spent in tree cleaning is %lf seconds\n", (double) (end - begin) / CLOCKS_PER_SEC);


    return 0;
}
