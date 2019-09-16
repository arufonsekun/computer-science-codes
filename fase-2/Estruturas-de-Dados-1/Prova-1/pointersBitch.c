#include <stdio.h>
#include <stdlib.h>

struct vector {
    int *vetor;
    unsigned short size;
};

void init(struct vector *v){
    v->vetor = (int*) malloc(10 * sizeof(int));
    v->size = 0;
}

void push_back(struct vector *array, int val){
    if (array->size > 10)
        printf("There's no available space\n");
    else if (array->size == 0){
        *array->vetor = val;
        array->size += 1;
        array->vetor++;
    }
    else{
        *array->vetor = val;
        array->size += 1;
        array->vetor++;
    }
}

void back(struct vector *v){
    for (int i = 0; i < v->size; i++){
        v->vetor--;
    }
}

void print(struct vector *v){
    for (unsigned int i = 0; i < v->size; i++){
        printf("vetor[%d] = %d\n", i, *v->vetor);
        v->vetor++;
    }
}

int sum(struct vector *v){
    int x = 0;
    for (unsigned short i = 0; i < v->size; i++){
        x += *v->vetor;
        v->vetor++;
    }
    return x;
}

int main(){
    /*int y = 4;
    int *x = &y;
    *x = 3;
    printf("%d\n", y);*/

    /*int *vector;
    vector = (int*) malloc(5 *sizeof(int));
    for (unsigned int i = 0; i < 5; i++){
        *vector = i;
        vector++;
    }

    for (unsigned int i = 0; i < 5; i++){
        vector--;
    }

    for (unsigned int i = 0; i < 5; i++){
        printf("%d\n", *vector);
        vector++;
    }*/
    struct vector vetor;
    init(&vetor);
    push_back(&vetor, 1);
    push_back(&vetor, 2);
    push_back(&vetor, 3);
    push_back(&vetor, 4);
    push_back(&vetor, 5);
    push_back(&vetor, 6);
    push_back(&vetor, 7);
    push_back(&vetor, 8);
    push_back(&vetor, 9);
    push_back(&vetor, 10);
    back(&vetor);
    print(&vetor);
    back(&vetor);
    printf("A soma dos elementos é %d\n", sum(&vetor));


    return 0;

}
