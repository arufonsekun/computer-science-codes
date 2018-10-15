#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void print(int *v, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
   int size, input;
   printf("Type the vector size: ");
   scanf("%d", &size);
   int vector[size];
   clock_t begin, end;

   begin = clock();
   for (int i = 0; i < size; i++){
       //scanf("%d", &input);
       insertSortido(vector, rand()%100, i);
   }
   end = clock();
   printf("time spent on insertion sort %lf\n", (double) (end - begin) / CLOCKS_PER_SEC);
   print(vector, size);
   return 0;
}
