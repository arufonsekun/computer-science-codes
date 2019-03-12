#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define OVERFLOW 10

int hashing(int key){
    return key % SIZE; 
}


void set(int *v){
   for (int i = 0; i < SIZE+OVERFLOW; i++){
       v[i] = 0;
   }
}

int main(){
    int vector[SIZE + OVERFLOW];
    int ignore = 0, overflow = SIZE;
    int index = 0, value;
    set(vector);

    //printf("Type the vector size: ");
    //scanf("%d", &size);
    //printf("Type the vector overflow");
    //scanf("%d", &overflow);
    
    for (int i = 0; i < SIZE + OVERFLOW; i++){
        value = (rand() % 100);
        index = hashing(value);

        if (vector[index] == 0)
            vector[index] = value;
        
        else if (overflow < SIZE + OVERFLOW){
            vector[overflow] = value;
            overflow++;
        }
        else{
            ignore++;
            printf("Overflow!!\n");
        }
    }
    
    for (int i = 0; i < SIZE+OVERFLOW; i++){
        if (vector[i] != 0)
            printf("%d ", vector[i]);
    }
    printf("%d values was ignored\n", ignore);
    return 0;
}
