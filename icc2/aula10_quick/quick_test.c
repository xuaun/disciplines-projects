#include "busca_e_ordenacao.h"


int pivo_inicial(int i, int f) {
	return i;
}

int pivo_central(int i, int f) {
	return (int) ((i+f)/2.0);
}

int pivo_aleatorio(int i, int f) {
	return (rand()%(f-i))+i;
}

int main (int argc, char* argv[]) {

	if (argc < 2) {
		printf("Informe tamanho do vetor\n");
		return 1;
	}
	int n = atoi(argv[1]);

	clock_t c1, c2;
	double qs_time, ms_time;
	
	srand(1);
	int *vet = gera_vetor_ordenado(n, 1, 5);
		
	c1 = clock();
	quicksort(vet, 0, n-1, pivo_aleatorio);
	c2 = clock();
	qs_time = (c2-c1)/(double)CLOCKS_PER_SEC;
	
	free(vet);
	vet = NULL;

	srand(1);
	vet = gera_vetor_ordenado(n, 1, 5);
		
	c1 = clock();
	mergesort(vet, 0, n-1);
	c2 = clock();
	ms_time = (c2-c1)/(double)CLOCKS_PER_SEC;

	free(vet);

	printf("Tempo de execucao, vetor n=%d\n", n);
	printf("\tMergesort %lf\n", ms_time);
	printf("\tQuicksort %lf\n\n", qs_time);

	return 0;

}
