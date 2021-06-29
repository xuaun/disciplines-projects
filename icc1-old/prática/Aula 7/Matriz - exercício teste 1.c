/*Inicialize uma matriz de inteiros de duas
dimensões 2x3x4 com valores quaisquer. Faça
um programa que imprima os valores da matriz*/

#include<stdio.h>

int main(){
    int m[2][3];
    int i, j;

    for (i=0; i<2; i++){    //iniciar a matriz com algum valor
        for (j=0; j<3; j++){
            m[i][j] = i + j;
        }
    }

    for (i=0; i<2; i++){    //printar valores da matriz
        for (j=0; j<3; j++){
            printf("m[%d][%d] = %d; \n", i, j, m[i][j]);
        }
    }

    return 0;
}
