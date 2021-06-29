/* Programa que demonstra o uso de IF e SWITCH e suas diferencas

	Exemplo por: Moacir Ponti - ICMC/USP 2018
*/

#include <stdio.h>

int main (int argc, char* argv[]) {

	int x;

	printf("Digite valor de x (inteiro): ");
	scanf("%d", &x);

	printf("Demonstrando uso do IF\n");
	// A 
	/*
	if (x > 5 && x < 10) {
		printf("X e' maior que 5 e menor que 10\n");
	} else {
		if (x >= 0) {
			printf("X e' maior ou igual a 0\n");
		} else {
			printf("X e' negativo\n");
		}
	}
	*/

	// B
	if (x > 5 && x < 10) {
		printf("X e' maior que 5 e menor que 10\n");
	} 
	if (x >= 0) {
		printf("X e' maior ou igual a 0\n");
	} else {
		printf("X e' negativo\n");
	}
	

	printf("\n\nDemonstrando uso do Switch\n");
	// SWITCH
	switch (x) {
		case 0: printf("X e' igual a zero\n");
			break;

		case 5: printf("X e' igual a cinco\n");
			break;

		case 6: printf("X e' igual a seis\n");
			break;

		// case > 5 && < 10: // nao da para fazer!!!!

		default: printf("caso contrario\n");
	}


	return 0;
}


