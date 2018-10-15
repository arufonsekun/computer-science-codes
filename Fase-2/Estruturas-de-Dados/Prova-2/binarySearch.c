#include <stdio.h>
#include <stdlib.h>


 void insertSortido(int *vector, int value, int index){
     vector[index] = value;
     int i = index;
     while (i >= 1){
         if (vector[i-1] > vector[i]){
             value = vector[i];
             vector[i] = vector[i-1];
             vector[i-1] = value;
         }
         i--;
     }
}

int binarySearchRec(int value, int *vector, int l, int r){
    int middle = (l + r) / 2;
    printf("%d\n", middle);
    if (vector[middle] == value){
        return vector[middle];
    }
    else{
        if (vector[middle] < value)
            return binarySearchRec(value, vector, middle +1, r);
        else
            return binarySearchRec(value, vector, l, middle -1);
    }
}

void printVector(int *vector, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main(){
    int size, input;
    printf("Type the vector size: ");
    scanf("%d", &size);
    int vector[size];

    for (int i = 0; i < size; i++){
        insertSortido(vector, rand() % 100, i);
    }
    printVector(vector, size);
    printf("Type the element to search: ");
    scanf("%d", &input);
    int search = binarySearchRec(input, vector, 0, size-1);
    printf("%d\n", search);

    return 0;
}
