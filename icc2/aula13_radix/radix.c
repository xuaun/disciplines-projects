#include <stdio.h>
#include <stdlib.h>

typedef struct rec {
	int key;
	float value1;
	char  value2;
} Rec;


void radixsort8bits(Rec *A, int n) {

	int i,j,shift;

	// 1 - alocar vetores de contagem e auxiliares
	int C[256] = {0};
	int pos[256];
	Rec *copy = (Rec *) malloc(sizeof(Rec)*n);

	// Radix sort - executa counting sort 
	// 		varias vezes usando base 2 e 8 bits por bloco
	for (shift = 0; shift <= 24; shift+=8) {
		// 2 - Counting sort : contagem + copia
		for (j = 0; j < n; j++) {
			int k = (A[j].key >>shift) & 255; // extrai 8 bits 
			C[k]++; // conta
			
			// aproveita e cria o vetor copia
			copy[j] = A[j];
		}

		// 3 - Counting sort : contagem acumulada
		//    percorre o vetor de contagem C 
		pos[0] = 0;
		for (i = 1; i < 256; i++) {
			pos[i] = pos[i-1] + C[i-1];
			C[i-1] = 0; // zera contagem para a proxima passada		
		}
		
		// 4 - Counting sort : copia elementos nas suas posicoes corretas
		for (j = 0; j < n; j++) {
			int k = (copy[j].key >>shift) & 255; // extrai 8 bits
			A[pos[k]] = copy[j]; // copia na posicao correta
			pos[k]++; // incrementa posicao
		}
	}

	free(copy);

}



int main(void) {

	Rec A[] = { {800, 4.5, 'X'}, {256, 1.1, 'A'}, {257, 4.2, 'Y'},
		  {2, 1.3, 'R'},   {4, 4.2, 'X'}, {257, 8.0, 'T'},
		  {4, 1.3, 'R'},   {256, 9.2, 'K'}, {258, 8.0, 'U'},
		  {801, 1.6, 'R'},   {255, 1.2, 'A'}, {6, 9.0, 'Y'}
		};
	int n = 12;

	for (int i = 0; i < n; i++) {
		printf("%d (%.1f, %c)\n", A[i].key, A[i].value1, A[i].value2);
	}
	printf("\n");	

	radixsort8bits(A, n);

	for (int i = 0; i < n; i++) {
		printf("%d (%.1f, %c)\n", A[i].key, A[i].value1, A[i].value2);
	}

	printf("\n");	
	return 0;
}


