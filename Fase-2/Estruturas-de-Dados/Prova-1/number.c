#include <stdio.h>

struct number{
    int x, y;
};

int sum(struct number *num){
    return num->y + num->x;
}

int minus(struct number *num){
    return num->y - num->x;
}

float divid(struct number *num){
    return num->y / (num->x * 1.0);
}

int times(struct number *num){
    return num->y * num->x;
}

int square(int *num){
    return *num * *num;
}

int main(){

    struct number num;
    scanf("%d", &num.y);
    scanf("%d", &num.x);
    printf("%d + %d = %d\n", num.y, num.x, sum(&num));
    printf("%d - %d = %d\n", num.y, num.x, minus(&num));
    printf("%d / %d = %.2f\n", num.y, num.x, divid(&num));
    printf("%d * %d = %d\n", num.y, num.x, times(&num));
    printf("%d ^ 2 = %d\n", num.y, square(&num.y));
    printf("%d ^ 2 = %d\n", num.x, square(&num.x));


    return 0;
}
