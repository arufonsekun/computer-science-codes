#include <stdio.h>

int mod(int x, int y){
    if (x < y)
        return x;
    else
        mod(x - y, y);
}

int main(){
    int x, y;
    
    scanf("%d %d", &x, &y);
    printf("%d\n", mod(x, y));

    return 0;
}
