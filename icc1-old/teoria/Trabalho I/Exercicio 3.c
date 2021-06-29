#include<stdio.h>

int main (){
    int NA;
    int NB;
    int A[100];
    int B[100];
    int C[200];
    int i, j;
    int temp;

    printf("Programa criado para realizar intercalacao entre duas listas inseridas pelo usuario.\nInsira o numero de elementos que a lista A tera (entre 0 e 100): ");
    scanf("%d", &NA);
    while ((NA<0)||(NA>100)){
        printf("Valor invalido para o numero de elementos de A.\n Insira novamente o numero de elementos da lista A: ");
        scanf("%d", &NA);
    }

    printf("Insira agora os elementos, de maneira ordenada, da lista A:\n");
    for(i=0; i<NA; i++){
        printf("Elemento %d de %d: ", (i+1), NA);
        scanf("%d", &A[i]);
    }

    printf("\n");

    printf("Insira agora o numero de elementos que a lista B tera (entre 0 e 100): ");
    scanf("%d", &NB);
    while ((NB<0)||(NB>100)){
        printf("Valor invalido para o numero de elementos de B.\n Insira novamente o numero de elementos da lista B: ");
        scanf("%d", &NB);
    }

    printf("Insira agora os elementos, de maneira ordenada, da lista B:\n");
    for(i=0; i<NB; i++){
        printf("Elemento %d de %d: ", (i+1), NB);
        scanf("%d", &B[i]);
    }

    printf("\n");
    system("pause");
    system("cls");

    //g=0;

    printf("Lista C criada a partir da intercalacao da lista A com a lista C.\n");

    for(i=0; i<NA; i++){
        C[i] = A[i];
    }
    for(i=0; i<NB; i++){
        C[(NA+i)] = B[i];
    }

    for(i=0; i<(NA+NB); i++){
        for(j=i; j<(NA+NB); j++){
            if(C[j]<C[i]){
                temp=C[i];
                C[i]=C[j];
                C[j]=temp;
            }
        }
    }

    for(i=0; i<(NA+NB); i++){
        printf("%d\n", C[i]);
    }

    system("pause");

    return 0;
}
