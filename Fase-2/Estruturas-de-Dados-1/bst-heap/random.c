#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("How many? ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++){
        printf("%d\n", rand() % 100);
    }
    return 0;
}
