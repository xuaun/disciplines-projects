#include <stdio.h>

long int potencia_de_2(int y) {
	int j;
	long int pot;
	// ex. y = 4, quero calcular pot = 2^4 = 2*2*2*2 
	pot = 1; // garante que 2^0 = 1
	for (j = 0; j < y; j++) {
		pot = 2*pot;
	}
	// ex. y = 4
	// j = 0
	// pot = 2*1 = 2
	// j = 1
	// pot = 2*2 = 4
	// j = 2
	// pot = 2*4 = 8
	// j = 3
	// pot = 2*8 = 16
	return pot;
}

void imprime_mais_potencia_de_2_vezes(int y) {
	int k;
	// se y = 0, imprimir 2^0= 1 vez +
	// se y = 1, imprimri 2^1= 2 vezes +
	// se y = 2, imprimri 2^2= 4 vezes +
	// se y = 3, imprimri 2^3= 8 vezes +
	for (k = 0; k < potencia_de_2(y); k++) {
		printf("+");
	}
	printf("\n");
}


int main (int argc, char* argv[]) {

	int x = 4;
	long int resultado;

	scanf("%d", &x);
	resultado = potencia_de_2(x);

	printf("2^%d = %ld\n", x, resultado);		

	imprime_mais_potencia_de_2_vezes(x);

	return 0;

}
