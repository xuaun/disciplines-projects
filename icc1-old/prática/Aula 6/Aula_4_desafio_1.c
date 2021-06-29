/*Fa�a um simulador para avaliar a movimenta��o de passageiros do
trem-bala de Campinas ao Rio de Janeiro. O trem realiza o trajeto
Campinas-Rio com esta��es em: Campinas [Esta��o 0], S�o Paulo
[Esta��o 1] S�o Jos� dos Campos [Esta��o 2], Resende [Esta��o 3],
Rio de Janeiro [Esta��o 4], com um total de 5 paradas.
Em cada parada ir�o embarcar um certo n�mero de
passageiros e desembarcar outra quantidade de passageiros
(controlados pelas catracas eletr�nicas), podendo restar um certo
n�mero de passageiros a bordo.
O programa deve coletar as informa��es de quantas pessoas
entram e saem em cada uma das esta��es, realizando uma
estat�stica final da movimenta��o de passageiros: total de
passageiros transportados, movimento de passageiros por
esta��o, e total de passageiros transportados por trecho. Os dados
de movimenta��o de passageiros (embarque e desembarque)
devem ser armazenados em vetores.*/

#include<stdio.h>

int main(){
    int circulacao[5], embarque[5], desembarque[5], embarcados[5];
    int i, temp1, temp2, total;

    total = 0;  //total de passageiros
    temp1 = 0;  //ira ajudar em circulacao
    temp2 = 0;  //guardara o valor antigo de embarcados

    printf("Bem-vindo a plataforma de ajuda de embarque e desembarque do tem bala.\n\nIremos coletar quantos passageiros entraram e subiram em cada uma das estacoes da viagem.\n\n");
    system("pause");

    for (i=0; i<=4; i++){
        printf("\nQuantos passageiros subiram na estacao %d? ", i);
        scanf("%d", &embarque[i]);
        printf("\nQuantos passageiros desceram na estacao %d? ", i);
        scanf("%d", &desembarque[i]);
        temp1 = embarque[i] + desembarque[i];  //movimentacao por estacao
        circulacao[i] = temp1;
        embarcados[i] = temp2 + embarque[i] - desembarque[i];  //quantos ainda estao no trem
        temp2 = embarcados[i];  //para usar no proximo i
        total = total + embarque[i];  //total de passageiros
    }

    system("cls");

    printf("O numero total de passageiros que viajaram conosco foi %d.\n\n", total);
    printf("estacao\tcirculacao\tpor estacao\n");
    for (i=0; i<=4; i++){
        printf("%d\t%d\t\t%d\n", i, circulacao[i], embarcados[i]);
    }
    printf("\nObrigado por utilizar nossos servicos!\n");

    return 0;
}
