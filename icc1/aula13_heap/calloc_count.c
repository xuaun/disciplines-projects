#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[]) {

	int N = 10000;

	srand(time(NULL));
	// sizeof(tipo)
	int* vet = malloc(N * sizeof(int));

	for (int i = 0; i < N; i++) { 
		// sorteia numero e comprime para intervalo 0-9
		vet[i] = rand()%10;
	}

	// qual a frequencia de cada numero (0, 1, 2, 3, ... 9)?

	// calloc - aloca a memoria e zera os bits
	// calloc(quantidade, tamanho)
	int* cont = calloc(10, sizeof(int));
	for (int i = 0; i < N; i++) { 
		int valor = vet[i];
		cont[valor]++; // importante 
	}

	// imprime vetor 'cont'
	printf("valor\tfrequencia\n");
	int soma = 0;
	for (int j = 0; j <= 9; j++) {
		printf("%d\t%d\n", j, cont[j]);
		soma += cont[j];
	}
	printf("total = %d\n", soma);

	free(cont);
	free(vet);
	return 0;
}
