/* Fa�a um algoritmo que mostre os valores pares de 0 a 100
OBSERVA��O: numero par if (i % 2 == 0) � par */

#include <stdio.h>
#include <stdlib.h>

int main(){

    int i;

    printf("Numeros pares de 0 a 100");

    for(i >= 0; i <= 100; i++){
        if(i % 2 == 0){
            printf("%d\n", i);
        }
    }

    return 0;

}
