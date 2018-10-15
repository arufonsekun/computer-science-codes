#include <stdio.h>

int main(){
    unsigned int x = 0, y = 0, pivo = 0;
    unsigned int mult1 = 0, mult2 = 0;
    scanf("%u %u %u", &x, &y, &pivo);

    for (unsigned int i = pivo +1; mult1 == 0; i++){
        if (i % 3 == 0){
            mult1 = i;
        }
    }

    for (int j = pivo - 1; mult2 == 0; j--){
        if (j % 3 == 0){
            mult2 = j;
        }
    }

    printf("%hu\n", ((mult1 - pivo <= pivo - mult2) ? mult1 : mult2));
    return 0;
}
