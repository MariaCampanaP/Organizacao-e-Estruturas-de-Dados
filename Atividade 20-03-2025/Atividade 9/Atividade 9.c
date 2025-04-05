/* Fa�a um algoritmo que receba um valor x, e mostre a soma da faixa de valores de 1 a x. (utilize recursividade)*/

#include <stdio.h>
#include <stdlib.h>

int soma (int n){

    //Se n == 1 � o caso base ent�o ele retorna a 1, pois a soma � somente at� a 1
    if(n == 1){
        return 1;
    //Se n for maior que 1 a fun��o chama a si mesma com o valor n-1, acumulando a soma at� chegar no caso base parando o c�digo
    }else return (n + soma(n - 1));

}

int main(){

    int n;

    printf("Digite um numero positivo:");
    scanf("%d", &n);

    printf("Soma:%d\n", soma(n));

    return 0;
}
