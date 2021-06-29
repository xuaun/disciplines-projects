#include <stdio.h>

int main (int argc, char* argv[]) {

	int N;
	int i; 
	scanf("%d", &N);

	// imprimir os valores pares, de 1 ate N, 

	i = 1;
	while (i <= N) { 
		// imprimo apenas se for par
		// % e' operador de resto da divisao inteira
		// ex. 3 / 2 = 1, resto 1, entao 3%2 => 1
		//     6 / 2 = 3, resto 0, entao 6%2 => 0
	
		if ( (i % 2 == 0)) {
			printf("%d\n", i);
		}
		
		i = i + 1; // executa independente do IF acima
	}


	printf("\n\n");
	// o codigo abaixo faz o mesmo efeito do que o anterior
	i = 2;
	while (i <= N) { 
		printf("%d\n", i);
		i = i + 2; // executa independente do IF acima
	}


	return 0;	

}
