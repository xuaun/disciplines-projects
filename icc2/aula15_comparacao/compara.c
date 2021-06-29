#include "busca_e_ordenacao.h"


int escolha_pivo(int a, int b) {
	int pos = (rand()%(b-a))+a;
	return pos;
}

int main (void) {

	int n, k;

	printf("n\tseq.\t\tbin. (ord)\n");

	// tamanho do vetor
	for (n = 10000; n <= 1000000; n+= 5000) {

		clock_t c1,c2;
		double time_ord, time_seq = 0, time_bin = 0;	
		
		int max = (int)n/5.0;

		srand(2);
		int* v1 = gera_vetor(n, 1, max);
		srand(2);
		int* v2 = gera_vetor(n, 1, max);

		// ordenacao
		c1 = clock();
		quicksort(v2, 0, n-1, escolha_pivo);
		c2 = clock();
		time_ord = (c2-c1)/(double)CLOCKS_PER_SEC;
	
		// buscas
		for (k = 1; k <= 1000; k++) {
			int chave = (rand()%(max*2))+1;

			c1 = clock();
			busca_sequencial(v1, chave, n);
			c2 = clock();
			time_seq += (c2-c1)/(double)CLOCKS_PER_SEC;

			c1 = clock();
			busca_binaria(v2, chave, 0, n-1);
			c2 = clock();
			time_bin += (c2-c1)/(double)CLOCKS_PER_SEC;
		}

		// se quiser a media, descomente abaixo
		//time_seq = time_seq / (k-1);
		//time_bin = time_bin / (k-1);

		printf("%d\t %lf\t %lf+%lf = %lf\n", n, time_seq, time_bin, time_ord, time_bin+time_ord);

		free(v1);
		free(v2);
	}

	return 0;
}
