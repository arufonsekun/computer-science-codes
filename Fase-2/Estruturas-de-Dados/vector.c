#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500000
//TODO : insertVector(int *v, size, value)
//searchVal()

void insertVector(int *v, int pos, int value){
    v[pos] = value;
}

int search(int *v, int size, int value){
    int index = 0;
    while (index <= size){
        if (v[index] == value)
            return v[index];
        index++;
    }
    return 0;
}

void print(int *v, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void sortInsertion(int *v, int index, int value){
    if(index == 0)
        v[0] = value;
    else{
        int aux;
        v[index] = value;
        while (index >= 1){
            if (v[index-1] < v[index]){
                return;
            }
            else{
                aux = v[index];
                v[index] = v[index-1];
                v[index-1] = aux;
            }
            index--;
                
        }
    }
}

int binarySearch(int * v, int index, int value){
    if (v[index] == value)
        return v[index];
    else if (v[index] < value){
        return binarySearch(v , index/2, value);
    }
    else{
        return binarySearch(v , index/2 + index/2, value);
    }
}

int main(){
    clock_t end, begin;
    int v[10], size = 0, input;
    double time_spent;

    /*begin=clock();
    for (int i=0;i<=SIZE;i++)
    {
		printf("%ld\r\r\r\r\r\r\r\r\r\r\r",i);
		insertVector(v, size, rand());
        size++;
    }
    end=clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nExecution time for insertion (in s): %5.2f\n",time_spent);
    
    printf("%d", size);
    begin = clock();
    
    printf("%d\n", search(v, size, rand()));
    
    end = clock();
    time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nExecution time for search (in s): %5.2f\n",time_spent);*/

    for (int i = 0; i < 10; i++){
        //scanf("%d", &input);
        sortInsertion(v, i, rand() % 100);
        size++;
    }
    print(v, size); 

    printf("%d\n", binarySearch(v, size / 2, rand() % 100));
    return 0;
}
