
#include "busca_e_ordenacao.h"

int main (int argc, char* argv[]) {

	int n, min, max;
	clock_t c1, c2;
	printf("Digite minimo e maximo para o tamanho do vetor\n");
	scanf("%d %d", &min, &max);

	int passo = (int)((max-min)/10.0);

	FILE *fi, *fm;
	fi = fopen("insertion.txt", "w");

	printf("Insertion... ");
	for (n = min; n <= max; n+= passo) {
		srand(1);
		int* vet = gera_vetor(n, 0, 2*n);

		c1 = clock();
		insertion_sort(vet, n);
		c2 = clock();
		double isort_time = (c2-c1)/(float)CLOCKS_PER_SEC;
		fprintf(fi, "%d\t%lf\n", n, isort_time);
		free(vet);
	}
	fclose(fi);
	printf("\n");

	printf("Mergesort... ");
	fm = fopen("merge.txt", "w");
	for (n = min; n <= max; n+= passo) {
		srand(1);
		int* vet = gera_vetor(n, 0, 2*n);
		c1 = clock();
		mergesort(vet, 0, n-1);
		c2 = clock();
		double msort_time = (c2-c1)/(float)CLOCKS_PER_SEC;
		fprintf(fm, "%d\t%lf\n", n, msort_time);
		free(vet);
	}
	fclose(fm);
	printf("\n");

	return 0;
}

