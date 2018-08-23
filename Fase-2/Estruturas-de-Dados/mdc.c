#include <stdio.h>

int mdc(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    else
        return mdc(n2, n1 % n2);
}

int main(){
    int n1, n2;
    scanf("%d %d", &n1,  &n2);
    printf("%d\n", mdc(n1, n2));
    return 0;
}
