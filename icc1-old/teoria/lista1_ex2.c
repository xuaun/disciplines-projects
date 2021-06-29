/*2. Uma loja de discos anota diariamente durante o mês de março a quantidade de discos vendidos.
Determinar em que dia desse mês ocorreu a maior venda e qual foi a quantidade de discos vendida
nesse dia.*/

#include<stdio.h>

int main(){
	int disco = 0;
	int maiorlucro = 0;
	int lucrototal = 0;
	int x = 0;
	int i;
	
	printf("Inicio do mes de marco, anote suas vendas diarias aqui.\n");
	system ("pause");
	
	for (i = 1; i <= 31; i++){
		printf("Qual o lucro do dia %d?\n", i);
		scanf("%d", &disco);
		
		if (disco > maiorlucro){
			maiorlucro = disco;
			x = i;
		}
		lucrototal += disco;
	}
	printf("Veja em qual dia do mes de marco voce obteve maior lucro.\n");
	system ("pause");
	
	printf("O dia em que voce obteve maior lucro foi o dia foi %d e foi de %d, com um lucro total de %d", x, maiorlucro, lucrototal);
	
	return 0;
}
