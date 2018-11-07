#include <stdio.h>
#include <stdlib.h>

#define dbSize 100

//database index
unsigned int ind = 0;

struct tcontact{
    char name[11];
    unsigned int age;
    float height;
    float weight;
};

struct tcontact dataBase[dbSize];

void add(){
    struct tcontact new;
    printf("Nome ");
    scanf("%s", new.name);
    printf("Idade ");
    scanf("%u", &new.age);
    printf("Altura ");
    scanf("%f", &new.height);
    printf("Peso ");
    scanf("%f", &new.weight);
    dataBase[ind] = new;
    ind++;

}

void list(){
    for (unsigned int i = 0; i < ind; i++){
        printf("Contato n° %u\n", i+1);
        printf("Nome: %s\n", dataBase[i].name);
        printf("Idade: %u\n", dataBase[i].age);
        printf("Altura: %.2f\n", dataBase[i].height);
        printf("Peso: %.2f\n", dataBase[i].weight);
        printf("\n");
    }
}

int main(){
    unsigned short int operation = 0;

    printf("Bem-vindo ao seu gerenciador de contatos\n");
    printf("Digite 0 para listar contatos, 1 para adicionar um novo ou 2 para sair\n");

    scanf("%hu", &operation);
    do{
        (operation == 0 ? list() : add());
        scanf("%hu", &operation);
    }while (operation != 2);

    return 0;
}
