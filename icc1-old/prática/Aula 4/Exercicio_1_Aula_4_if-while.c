/*
Imagine que voc� deve fazer um programa para liberar notas de reais em um caixa eletr�nico.
O caixa fornece somente notas de 10 e 50 reais.
Considere que um usu�rio fa�a uma solicita��o de uma determinada quantidade.
Seu programa deve dizer quantas notas de 50 e quantas de 10 devem ser liberadas, de modo a minimizar o n�mero de notas.
Se n�o for poss�vel liberar o valor pedido, uma mensagem deve ser dada ao usu�rio.
*/
#include<stdio.h>

int main(){

    int nota50 = 0;  //Quantidade de notas de 50 reais que serao sacadas
    int nota10 = 0;  //Quantidade de notas de 10 reais que serao sacadas
    int pedido =0;   //O valor que o usuario deseja sacar
    int resto1;  //Variaveis que serao utilizadas para verificar condicao entre notas e o pedido
    printf ("Qual o valor que voce deseja sacar?\n(No momento so possuimos notas de 10 reais e 50 reais)\n");  //O programa informa as notas que estao disponiveis
    scanf("%d", &pedido);

    while (pedido != 0){
        if (pedido % 10 == 0){  //como o menor valor de notas � 10 reais, nao precisamos nos preocupar com as notas de 50 reais (pois ele � multiplo de 10)
            nota50 = pedido / 50;  //A divisao do inteiros "pedido" nos dara a quantia de notas de 50 reais que serao sacadas
            resto1 = pedido % 50;  //"resto1" e o valor que sobra pras notas de 10 reais
            nota10 = resto1 / 10;  //A divisao do inteiros "resto1" nos dara a quantia de notas de 10 reais que serao sacadas
            printf("Voce ira sacar %d notas de 50 reais, %d notas de 10 reais.\nVolte sempre!", nota50, nota10);

            pedido = 0;  //para sair do while
        }
        else{  //Caso o valor pedido nao seja possivel com notas de 50 e 10 reais, ou seja, nao � divisivel por 10
            printf("Nao e possivel sacar a quantia desejada. \nNo momento so possuimos notas de 50 e 10 reais.\nVolte sempre!");
            pedido = 0;  //para sair do while
        }
    }

    return 0;
}
