#include <stdio.h>

unsigned int isPrime(unsigned int number){
    unsigned int times = 0;

    if (number == 1)
        return 1;
    else{
        for (unsigned int j = 1; j <= number; j++){
            if (number % j == 0)
                times++;
        }
        return (times == 2 ? 1 : 0);
    }

}

int main(){
    int x = 0, y = 0;
    scanf("%u", &x);
    scanf("%u", &y);
    unsigned int len = x + y;
    int index = 0;
    int primes[len];

    for (unsigned int i = 1; index <= len-1; i++){
        if (isPrime(i) == 1){
            primes[index] = i;
            index++;
        }
    }

    for (unsigned int j = x -1; j < index; j++){
        printf("%hu ", primes[j]);
    }
    printf("\n");

    return 0;
}
