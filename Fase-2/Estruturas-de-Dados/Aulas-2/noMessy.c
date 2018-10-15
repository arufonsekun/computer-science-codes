//implementar o bagulho sem gambiarra
#include <stdio.h>

#define MAXJ 20
#define MAXI 12

struct sales{
    char code[4];
    float months[MAXI];
};

struct sales control[MAXJ];

void print(){
    printf("Cod\tJan\tFev\tMar\tAbr\tMai\tJun\tJul\tAgo\tSet\tOut\tNov\tDez\n");
    for (unsigned int i = 0; i < MAXJ; i++)
    {
        printf("%s\t", control[i].code);
        for (unsigned int j = 0; j < MAXI; j++)
        {
            printf("%.1f\t", control[i].months[j]);
        }
        printf("\n");
    }
}

int main(){

    struct sales product;
    for(unsigned int i = 0; i < MAXJ; i++){

        scanf("%s\n", product.code);

        for (unsigned int j = 0; j < MAXI; j++){
            scanf("%f\n", &product.months[j]);
        }
        control[i] = product;
    }
    print();
    return 0;
}
