/* Fa�a um algoritmo que preencha um vetor de 10 posi��es e mostre apenas os n�meros pares presentes nele*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor[10];
    int par;

    for(int i = 0; i <= 10; i++){
        scanf("%d\n", &vetor[i]);
    }

    for(int i = 0; i<= 10; i++){
        if(vetor[i] % 2 == 0){
            printf("%d e par\n", vetor[i]);
        }
    }
}
