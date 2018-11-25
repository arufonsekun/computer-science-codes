#include <stdio.h>

int array[] = {0,1,2,3,4,5,6,7,8,9};
int len = 9;

int reverse(int index){
    if (index == len/2){
        return index;
    }
    else{
        int a = reverse(index -1);
        int b = array[a];
        array[a] = array[index];
        array[index] = b;
        return a - 1;
    }

}
void print(){
    for (unsigned int i = 0; i <= len; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    reverse(len);
    print();
    return 0;
}
