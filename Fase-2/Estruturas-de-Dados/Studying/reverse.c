#include <stdio.h>

int array[] = {5,4,1,0};
int len = 3;

int reverse(int index){
    if ((index == len / 2) & (len % 2 == 0)){
        return index - 1;
    }
    if ((index == len/2)){
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
