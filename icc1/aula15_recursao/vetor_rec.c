#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR -1
#define MAX 100

void preenche(const int n, int v[n], int j) {
	// se j estiver dentro dos limites do vetor,
	// executa para uma posicao e realiza o passo recursivo
	if (j < n) {
		v[j] = rand()%MAX;
		preenche(n, v, j+1);
	}
}

int main(int argc, char* argv[]) {

	if (argc < 2) {
		printf("Informe tamanho do vetor\n\n");
		return ERROR;
	}

	int n = atoi(argv[1]);
	
	srand(time(NULL));

	// funcao recursiva que preenche um vetor previamente alocado
	// com valores aleatorios
	
	int vet[n]; // stack

	preenche(n, vet, 0);

	for (int i = 0; i < n; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n\n");


	return 0;
}
