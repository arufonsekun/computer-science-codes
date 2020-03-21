#include <stdio.h>

int array[] = {1,2,3,4,5,6};
int len = 5;

int sum(int i){
    if (i == len)
        return array[i];
    else{
        return array[i] + sum(i+1);
    }

}

int main(){

    printf("%d\n", sum(5));
    return 0;
}
