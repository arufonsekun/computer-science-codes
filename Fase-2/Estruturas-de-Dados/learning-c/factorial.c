#include <stdio.h>

int factorial(int n){
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", factorial(x));
    return 0;
}
