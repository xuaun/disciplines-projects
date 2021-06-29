#include<stdio.h>

int main (){
    int A[20][10];
    int B[20][11];
    int M, N;
    int i, j;
    int temp;

    printf("Programa para trabalhar com matrizes.\nInicialmente pegaremos a quantidade de colunas e linhas que tera sua matriz A.\nLinhas (entre 0 e 20): ");
    scanf("%d", &M);
    while((M<0)||(M>20)){
        printf("Opcao invalida. Digite um numero de linhas entre 0 e 20: ");
        scanf("%d", &M);
    }

    printf("Colunas (entre 0 e 10): ");
    scanf("%d", &N);
    while((N<0)||(N>10)){
        printf("Opcao invalida. Digite um numero de colunas entre 0 e 10: ");
        scanf("%d", &N);
    }

    printf("\n");
    system("pause");
    system("cls");

    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("Digite um valor para a linha %d e coluna %d: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n");
    system("pause");
    system("cls");

    printf("A matriz A(%dx%d) lida eh:\n", M, N);

    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    system("pause");
    printf("\n");

    printf("A matriz B(%dx%d) eh:\n", M, (N+1));

    for(i=0; i<M; i++){
        temp = 1;
        for(j=0; j<(N+1); j++){
            if(j<N){
                B[i][j] = A[i][j];
                printf("%d\t", B[i][j]);
                temp *= A[i][j];
            }
            else{
                B[i][j] = temp;
                printf("%d\t", B[i][j]);
            }
        }
        printf("\n");
    }

    system("pause");

    return 0;
}
