/*Escreva um programa que encontre o
maior número de uma matriz
bidimensional, x (linhas) por y
(colunas), e mostre as suas respectivas
posições na matriz.*/

#include<stdio.h>
#include<time.h>

int main(){
    int m[2][3];  //x = 2 e y = 3
    int i, j;
    int maior = 0;
    int imaior, jmaior;

    srand(time(NULL));  //para rodar os números de maneira "aleatoria"

    for (i=0; i<2; i++){    //iniciar a matriz com algum valor
        for (j=0; j<3; j++){
            m[i][j] = rand() % 10;  //um numero "aleatorio" entre 0 e 9
            if(m[i][j] > maior){
                maior = m[i][j];
                imaior = i;
                jmaior = j;
        }
        }
    }

    printf("O maior valor da matriz eh %d na linha %d e na coluna %d.", maior, imaior, jmaior);

    return 0;
}
