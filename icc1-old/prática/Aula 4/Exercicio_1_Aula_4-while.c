/*
Imagine que você deve fazer um programa para liberar notas de reais em um caixa eletrônico.
O caixa fornece somente notas de 10 e 50 reais.
Considere que um usuário faça uma solicitação de uma determinada quantidade.
Seu programa deve dizer quantas notas de 50 e quantas de 10 devem ser liberadas, de modo a minimizar o número de notas.
Se não for possível liberar o valor pedido, uma mensagem deve ser dada ao usuário.
*/
#include<stdio.h>

int main(){

    int nota50 = 0;  //Quantidade de notas de 50 reais que serao sacadas
    int nota10 = 0;  //Quantidade de notas de 10 reais que serao sacadas
    int pedido = 0;  //O valor que o usuario deseja sacar
    printf ("Qual o valor que voce deseja sacar?\n(No momento so possuimos notas de 10 reais e 50 reais)\n");  //O programa informa as notas que estao disponiveis
    scanf("%d", &pedido);
                       // Para minimizar o numero de notas, devemos começar com as notas de 50 reais

    while (pedido >= 50){  //O laço se repete enquanto o pedido for maior ou igual que 50 reais
        pedido = pedido - 50;  //retira 50 reais do pedido
        nota50++;  //Uma nota de 50 reais a mais por volta
    }
    while (pedido >= 10){  //O laço se repete enquanto o pedido for maior ou igual que 10 reais
        pedido = pedido - 10;  //retira 10 reais do pedido
        nota10++;  //Uma nota de 10 reais a mais por volta
    }
    if (pedido == 0){  //Se, no final das contas, nao sobrar resto, aparecera a mensagem da quantia que sera sacada
        printf("Voce ira sacar %d notas de 50 reais, %d notas de 10 reais.\nVolte sempre!", nota50, nota10);
    }
    else{  //Caso sobre resto, aparecera a mensagem de erro
        printf("Nao e possivel sacar a quantia desejada. \nNo momento so possuimos notas de 50 e 10 reais.\nVolte sempre!");
    }

    return 0;
    }
