/* Desenvolva um algoritmo em C que receba o peso e altura de uma pessoa e calcule o seu IMC (peso / altura�)
observa��o -> para n�meros elevados ao quadrado utilizar a biblioteca <math.h> e a f�rmula (peso / (pow(altura,2))*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float peso;
    float altura;
    float imc;

    printf("Digite o seu peso:");
    scanf("%f", &peso);

    printf("Digite a sua altura:");
    scanf("%f", &altura);

    imc = (peso / (pow(altura, 2)));

    printf("O seu IMC e:%.2f", imc);

    return 0;
}
