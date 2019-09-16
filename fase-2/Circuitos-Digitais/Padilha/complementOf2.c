#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int output[8];
char input[9];

void fit(char binary[9]){
    int len = strlen(binary) -1;
    for (int i = 7; i >= 0; i--){
        if (len >= 0){
            input[i] = binary[len];
        }
        else{
            input[i] = '0';
        }
        len--;
    }

}

void not(){
    for (int i = 0; i < 8; i++){
        if (input[i] == '1'){
            output[i] = 0;
        }
        else
            output[i] = 1;
    }
}

void plusOne(){
    unsigned short int carry[8] = {0,0,0,0,0,0,0,0};
    unsigned short int operator[8] = {0,0,0,0,0,0,0,1};
    unsigned short int val = 0;

    for (int i = 7; i >= 0; i--){
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

void print(){
    for (int i = 0; i < strlen(input); i++){
        if (i == 4)
            printf(" ");
        printf("%d", output[i]);
    }
    printf("\n");
}

int main(){
    char binary[9];
    memset(output, 0, 8);
    memset(input, '0', 8);

    scanf("%s", binary);

    if (atoi(binary) == 0)
        printf("0000 0000\n");

    else{
        fit(binary);
        not();
        plusOne();
        print();
    }


    return 0;
}
