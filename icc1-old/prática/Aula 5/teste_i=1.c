#include<stdio.h>

int main(){
    int v[5];   //v[0], v[1], v[2], v[3], v[4] == 5 vetores
    int i;
    int maior = 0;  //para achar o maior valor (a variavel tem que ter um valor muito pequeno)

    for(i = 1; i <= 5; i++){  //para colocar i=1...
        printf("Digite um valor: ");
        scanf("%d", &v[i - 1]);  //pegar os valores digitados e adicionar em cada v [i-1] (ou seja, v[0], v[1] etc
        if (v[i-1] > maior)
            maior = v[i - 1];  //maior vetor
    }

    printf("\n");

    for(i = 1; i <= 5; i++){
        printf("O valor de v[%d] = %d.\n", i, v[i - 1]);  //printar os valores de v
    }
    printf("O maior valor eh %d.", maior);

    return 0;
}
