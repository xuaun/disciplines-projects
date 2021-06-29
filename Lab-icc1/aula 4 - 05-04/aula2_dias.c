/*
Implemente um programa em C que receba dois n�meros inteiros que representem o m�s e o ano
em formato num�rico e imprima a quantidade de dias para esse m�s e esse ano no formato� de
teve n dias�. Na sa�da dever� aparecer o nome do m�s. Para erros na entrada dever� ser
imprimida a mensagem �Erro na entrada�. Obs. O valor das entradas � inteiro.

Entrada:2 2000
Saida:Fevereiro de 2000 teve 29 dias

Entrada:5 2014
Saida:Maio de 2014 teve 31 dias

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (int argc, char *argv[]){
	int dia, mes, ano;
	scanf("%d %d", &mes ,&ano);
	
	if(mes == 2){
		dia = 28;
		if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))){
			dia = 29;
		}
	}
	if(ano < 0){
		mes = 13;
	}
	
	setlocale(LC_ALL, "Portuguese");
	
	switch(mes){
		case 1: printf("Janeiro de %d teve 31 dias\n", ano);
		break;
		case 2: printf("Fevereiro de %d teve %d dias\n", ano, dia);
		break;
		case 3: printf("Mar�o de %d teve 31 dias\n", ano);
		break;
		case 4: printf("Abril de %d teve 30 dias\n", ano);
		break;
		case 5: printf("Maio de %d teve 31 dias\n", ano);
		break;
		case 6: printf("Junho de %d teve 30 dias\n", ano);
		break;
		case 7: printf("Julho de %d teve 31 dias\n", ano);
		break;
		case 8: printf("Agosto de %d teve 31 dias\n", ano);
		break;
		case 9: printf("Setembro de %d teve 30 dias\n", ano);
		break;
		case 10: printf("Outubro de %d teve 31 dias\n", ano);
		break;
		case 11: printf("Novembro de %d teve 30 dias\n", ano);
		break;
		case 12: printf("Dezembro de %d teve 31 dias\n", ano);
		break;
		default : printf("Erro na entrada\n");
	}
	
	return 0;
}
