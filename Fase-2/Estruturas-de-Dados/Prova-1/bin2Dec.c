#include <stdio.h>

void convert(int x){
    if (x / 2 == 0)
        printf("%d", x % 2);
    else{
        convert(x / 2);
        printf("%d", x % 2);
    }
}

int main(){
    int x;

    scanf("%d", &x);

    convert(x);
    printf("\n");
    return 0;
}
