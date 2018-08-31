#include <stdio.h>
#include <string.h>

int output[8];

void not(char input[9]){
    for (int i = 0; i < 8; i++){
        if (input[i] == '1'){
            output[i] = 0;
        }
        else
            output[i] = 1;
    }
}

void plusOne(int len){
    unsigned short int carry[8] = {0,0,0,0,0,0,0,0};
    unsigned short int operator[8] = {0,0,0,0,0,0,0,0};
    unsigned short int val = 0;
    operator[len-1] = 1;


    /*for (int j = 0; j < 8; j++){
        printf("%d", carry[j]);
    }
    printf("\n");

    for (int i = 0; i < len; i++){
        printf("%d", output[i]);
    }
    printf("\n");*/

    for (int i = len -1; i >= 0; i--){
        val = output[i] + operator[i] + carry[i];
        if (val == 2){
            output[i] = 0;
            carry[i-1] = 1;
        }
        else{
            output[i] = output[i] + operator[i] + carry[i];
        }
    }

}

void print(int x){
    for (int i = 0; i < x; i++){
        if (i == 4)
            printf(" ");
        printf("%d", output[i]);
    }
    printf("\n");
}

int main(){
    char input[9];
    memset(output, 0, 8);
    scanf("%s", input);
    if (strcmp(input, "00000000") == 0)
        print(strlen(input));
    else{
        not(input);
        plusOne(strlen(input));
        print(strlen(input));
    }

    return 0;
}
