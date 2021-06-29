/*Faça um simulador para avaliar a movimentação de passageiros do
trem-bala de Campinas ao Rio de Janeiro. O trem realiza o trajeto
Campinas-Rio com estações em: Campinas [Estação 0], São Paulo
[Estação 1] São José dos Campos [Estação 2], Resende [Estação 3],
Rio de Janeiro [Estação 4], com um total de 5 paradas.
Em cada parada irão embarcar um certo número de
passageiros e desembarcar outra quantidade de passageiros
(controlados pelas catracas eletrônicas), podendo restar um certo
número de passageiros a bordo.
O programa deve coletar as informações de quantas pessoas
entram e saem em cada uma das estações, realizando uma
estatística final da movimentação de passageiros: total de
passageiros transportados, movimento de passageiros por
estação, e total de passageiros transportados por trecho. Os dados
de movimentação de passageiros (embarque e desembarque)
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
