#include<stdio.h>
#include<time.h>

int main(){
    int v[5000];   //v[0], v[1], v[2], v[3], v[4] ... v[4999] == 5000 vetores
    int i;
    int maior = 0;  //para achar o maior valor (a variavel tem que ter um valor muito pequeno)
    int menor = 100000;  //para achar o menor valor (a variavel tem que ter um valor muito grande, ou maior que o valor do "resto" (%)
    int maior_posicao;
    int menor_posicao;

    srand(time(NULL));  //para rodar os números de maneira "aleatoria"

    for(i = 0; i < 5000; i++){
        v[i] = rand() % 100000;  //um numero "aleatorio" entre 0 e 999999
        if (v[i] > maior){
            maior = v[i];  //maior vetor
            maior_posicao = i;  //posicao do maior vetor
        }
        if (v[i] < menor){
            menor = v[i];  //menor vetor
            menor_posicao = i;  //posicao do menor vetor
        }
    }

    printf("\n");

    for(i = 0; i < 5000; i++){
        printf("O valor de v[%d] = %d.\n", i, v[i]);  //printar os valores de v
    }
    printf("O maior valor eh %d.\nO menor valor eh %d.\n", maior, menor);
    printf("A posicao do maior valor e do menor valor sao, respectivamente, %d e %d", maior_posicao, menor_posicao);

    return 0;
}
