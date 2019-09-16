#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define OVERFLOW 10

int hashing(int value){
    return value % SIZE;
}

void print(int* vector){
    for (int i = 0; i < SIZE+OVERFLOW; i++){
        if (vector[i] != 0)
            printf("%d ", vector[i]);
    }
}

void setElements(int* vector){
    for (int i = 0; i < SIZE + OVERFLOW; i++){
        vector[i] = 0;
    }
}

int main(){
    int vector[SIZE + OVERFLOW];
    setElements(vector);
    int value, hash;
    int index = SIZE;   

    for (int i = 0; i < SIZE + OVERFLOW; i++){
        value = rand() % 100;
        hash = hashing(value);
        if (vector[hash] == 0){
            vector[hash] = value;
        }
        else if (index < SIZE + OVERFLOW){
            vector[index] = value;
            index++;
        }
        else{
            printf("Overflow!!\n");
        }
    }

    print(vector);
    return 0;
}
