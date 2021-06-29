/*Escreva um programa que gere duas
matrizes A e B quadradas 9x9 e que
realize as seguintes operações:
– transposta de A (A^t);
– produto de AxB;
• Imprima o conteúdo de A e B e o
resultados das operações de forma que
seja fácil verificar se a solução é
correta.*/

#include<stdio.h>
#include<time.h>

int main(){
    int A[9][9];
    int B[9][9];
    int i, j;

    srand(time(NULL));

    printf("Matriz A\n\n");

    for(i=0; i<9; i++){  //Valores aleatórios para a matriz A
        for(j=0; j<9; j++){
                A[i][j] = rand() % 20;
                printf("%d\t",A[i][j]);  //valores das matrizes
        }
        printf("\n");
    }

    printf("\nMatriz B\n\n");

    for(i=0; i<9; i++){  //Valores aleatórios para a matriz B
        for(j=0; j<9; j++){
            B[i][j] = rand() % 10;
            printf("%d\t", B[i][j]);  //valores das matrizes
        }
        printf("\n");
    }

    printf("\nMatriz A^t\n\n");

    for(i=0; i<9; i++){  //transposta de A
        for(j=0; j<9; j++){
                printf("%d\t", A[j][i]);
        }
        printf("\n");
    }

    printf("\nMatriz A*B\n\n");

    for(i=0; i<9; i++){  //Produto de A por B
        for(j=0; j<9; j++){
                printf("%d\t", (A[i][j]*B[i][j]));
        }
        printf("\n");
    }

    return 0;
}
