#include <stdio.h>
#include <stdlib.h>

int size;
char find;

int counter(char input[size], int index){
    if (index == size-1){
        return (input[index] == find ? 1 : 0);
    }
    else{
        int in = (input[index] == find ? 1 : 0);
        return in + counter(input, index+1);
    }
}

int main(){

    scanf("%d", &size);
    char input[size];
    scanf("%s %c", input, &find);

    printf("%d\n", counter(input, 0));

    return 0;
}
