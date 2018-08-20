#include <stdio.h>

void print(unsigned int *j){
    printf("%u\n", *j);
}

int main(){
    unsigned int i = 2;
    unsigned int *j = &i;
    print(j);
}
