/* Programa que demonstra o uso de estrutura de repeticao
	especificamente, a estrutura de repeticao ENQUANTO (WHILE)

   Exemplo por: Moacir, ICMC/USP 2018
*/

#include <stdio.h>

int main (int argc, char* argv[]) {
	
	// imprime na tela numeros inteiros de 1 ate um valor N
	// digitado pelo usuario

	int N = 1;

	printf("Digite um numero inteiro (positivo, por favor)\n");
	scanf("%d", &N);

	// de 1, 2, 3, ... , N
	int atual = 1;

	// garantir que a condicao seja verdadeira para repetir o
	// bloco de codigo
	while (atual >= N) {
		printf("%d\n", atual); 
		atual  = atual+1;
	}
	// porem e' preciso que, eventualmente a condicao seja FALSA
	// do contrario temos uma repeticao infinita

	// exemplo de laco infinito
	while (1) {
		// nesse momento o programa esta aqui, e nao vai sair
		// a nao ser que seja interrompido	
	}

	return 0;
}
