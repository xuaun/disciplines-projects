#include<stdio.h>

int main(){
    int v[5];   //v[0], v[1], v[2], v[3], v[4] == 5 vetores
    int i;
    int maior = 0;  //para achar o maior valor (a variavel tem que ter um valor muito pequeno)
    int menor = 999999;  //para achar o menor valor (a variavel tem que ter um valor muito grande)
    int maior_posicao;
    int menor_posicao;

    for(i = 0; i < 5; i++){
        printf("Digite um valor: ");
        scanf("%d", &v[i]);  //pegar os valores digitados e adicionar em cada v (v[i], ou seja, v[0], v[1] etc
        if (v[i] > maior){
            maior = v[i];  //maior vetor
            maior_posicao = i;  //posicao do maior vetor
        }
        if (v[i] < menor){
            menor = v[i];
            menor_posicao = i;
        }
    }

    printf("\n");

    for(i = 0; i < 5; i++){
        printf("O valor de v[%d] = %d.\n", i, v[i]);  //printar os valores de v
    }
    printf("O maior valor eh %d.\nO menor valor eh %d.\n", maior, menor);
    printf("A posicao do maior valor e do menor valor sao, respectivamente, %d e %d", maior_posicao, menor_posicao);

    return 0;
}
