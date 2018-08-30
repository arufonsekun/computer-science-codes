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

void print(int x){
    for (int i = 0; i < x; i++){
        printf("%d", output[i]);
    }
    printf("\n");
}

int main(){
    char input[9];
    scanf("%s", input);
    //printf("%s\n", input);

    not(input);
    print(strlen(input));

    return 0;
}
