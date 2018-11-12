#include <stdio.h>
#include <stdlib.h>

#define MAXI 20
#define MAXJ 12

void average(float matrix[MAXI][MAXJ]){

    float average = 0;
    unsigned int denominator = 0;
    for (unsigned int i = 0; i < 20; i++){
        for (unsigned int j = 0; j < 12; j++){
            average += matrix[i][j];
            denominator++;
        }
    }

    printf("Products average: %.2f\n", average / denominator);
    printf("%f\n", average);
    printf("%u\n", denominator);
}

void printFancy(float matrix[MAXI][MAXJ]){
    char *months[12] = {
        "Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"
    };
    /*months[0] = "Janeiro";
    months[1] = "Fevereiro";
    months[2] = "Março";
    months[3] = "Abril";
    months[4] = "Maio";
    months[5] = "Junho";
    months[6] = "Julho";
    months[7] = "Agosto";
    months[8] = "Setembro";
    months[9] = "Outubro";
    months[10] = "Novembro";
    months[11] = "Dezembro";*/


    for (unsigned int i = 0; i < 12; i++){
        printf("%s  ", months[i]);
    }

    printf("\n");

    for (unsigned int i = 0; i < 20; i++){
        for (unsigned int j = 0; j < 12; j++){
            printf("  %.1f\t", matrix[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    float matrix[MAXI][MAXJ];
    float input;

    for (unsigned int i = 0; i < 20; i++){
        for (unsigned int j = 0; j < 12; j++){
            scanf("%f\n", &matrix[i][j]);
        }
    }

    // average(matrix);
    printFancy(matrix);
    return 0;
}
