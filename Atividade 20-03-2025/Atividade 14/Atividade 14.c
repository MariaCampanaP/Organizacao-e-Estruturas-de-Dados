/* Fa�a um algoritmo que receba nome e pre�o de 5 carros, armazene esses dados em um vetor de structs.
Depois, o valor deve ser percorrido, e dever� mostrar o nome do carro mais caro entre todos.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct carro{

    char modelo[100];
    float preco;

};

typedef struct carro Carro;

int main(){

    int i = 0;
    int j = 0;
    float maisCaro;
    Carro carros[5];

    for(i = 0; i < 5; i++){
        printf("Insira o modelo do carro %d:\n", i + 1);
        gets(carros[i].modelo);
        fflush(stdin);
        printf("Insira o preco do carro %d:\n", i + 1);
        scanf("%f", &carros[i].preco);
        fflush(stdin);

        if(i == 1){
            maisCaro = carros[i].preco;
            j = i;
        }else if(carros[i].preco > maisCaro){
            maisCaro = carros[i].preco;
            j = i;
        }
    }

    printf("Carro mais caro:%s\nPreco:R$%.2f", carros[j].modelo, carros[j].preco);

    return 0;

}
