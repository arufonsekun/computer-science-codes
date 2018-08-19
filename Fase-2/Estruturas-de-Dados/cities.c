#include <stdio.h>
#include <stdlib.h>

#define CITIES 5

int path[CITIES] = {-1,-1,-1,-1,-1};
int find = 0, out;

struct tcity{
    int code;
    int connections[CITIES];
};

struct tcity map[CITIES];

int exists(unsigned int code){
    for (int i = 0; i < CITIES; i++){
        if (map[i].code == code){
            return i;
            break;
        }
    }
}

//return the last index of the array
int end(int index){
    for (int i = 0; i < CITIES-1; i++){
        if (map[index].connections[i] == -1){
            return i;
            break;
        }
    }
}

int endPath(){
    for (int i = 0; i < CITIES; i++){
        if (path[i] == -1){
            return i;
            break;
        }
    }
}

//Set all map structs to 'null'
void set(){

    for (unsigned int i = 0; i <= CITIES; i++)
    {
        struct tcity vertex;
        vertex.code = -1;
        for (unsigned int j = 0; j < CITIES-1; j++){
            vertex.connections[j] = -1;
        }
        map[i] = vertex;
    }
}

//print the map
void get(){
    for (int i = 0; i < CITIES; i++){
        printf("%d: ", map[i].code);
        for (int j = 0; j < CITIES-1; j++){
            printf("%d ", map[i].connections[j]);
        }
        printf("\n");
    }
}

void printPath(){
    for (unsigned short int i = 0; i < CITIES; i++)
    {
        if (path[i] != -1)
            printf("%d ", path[i]);
    }
    printf("\n");
}

 void findPath(int v1, int v2){
     path[endPath()] = v1;
     for (unsigned short int i = 0; i < CITIES-1; i++){
         if (map[v1].connections[i] == v2){
            find = 1;
            out = map[v1].connections[i];
        }
     }
     if (find != 1){
         if (v1 == CITIES-1)
             findPath(0, v2);
         else
            findPath(v1+1, v2);
     }
     else{
        printPath();
        printf("Achou o vértice %d\n", out);
    }
 }

int main(){
    int inputCode, inputConnection;
    int index1, index2 = 0, c1, c2;

    set();

    //input the map
    for (unsigned int i = 0; i < CITIES; i++){
        scanf("%d %d\n", &inputCode, &inputConnection);
        index1 = exists(inputCode);
        index2 = exists(inputConnection);

        //checks whether the first city is in the map
        if (index1 != -1){
            map[inputCode].connections[end(index1)] = inputConnection;
        }
        else{
            map[inputCode].code = inputCode;
            map[inputCode].connections[end(inputCode)] = inputConnection;
        }

        if (index2 != -1){
            map[inputConnection].connections[end(index2)] = inputCode;
        }
        else{
            map[inputConnection].code = inputConnection;
            map[inputConnection].connections[end(inputConnection)] = inputCode;
        }
    }
    scanf("%d %d\n", &c1, &c2);
    findPath(c1, c2);
    //get();
    return 0;
}
