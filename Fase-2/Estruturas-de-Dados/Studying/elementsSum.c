#include <stdio.h>
#include <string.h>
#define size 10

int arraySum(int array[size], int i){
    if (i == size -1)
        return array[i];
    else{
        return array[i] + arraySum(array, i + 1);
    }
}

int times(int x, int y){
    if (y == 1)
        return x;
    else{
        return x + times(x, y - 1);
    }
}

int even(int x){
    if(x <= 0)
        return x;
    else{
        if (x % 2 == 0){
            printf("%d\n", x);
        }
        even(x - 1);
    }
}

int fatorial_duplo(int x){
    if (x <= 1){
        return 1;
    }
    else{
        return x * fatorial_duplo(x - 2);
    }
}

int main(){
    /*
    int array[size];
    memset(array, 0, 10);
    for (unsigned int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    printf("%d\n", sum(array, 0));*/
    //printf("%d\n", times(3,3));
    //even(20);
    printf("%d\n", fatorial_duplo(15));

}
