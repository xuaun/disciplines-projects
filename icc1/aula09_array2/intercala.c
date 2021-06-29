#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
	if (argc < 2) {
		printf("Por favor informe o tamanho dos vetores\n\n");
		return 1;
	}
	int N = atoi(argv[1]); // pega o tamanho dos vetores
	int A[N];
	int B[N];
	int l;
	printf("Entre com os %d valores do vetor A:\n", N);
	for (l = 0; l < N; l++) {
		scanf("%d", A+l);
	}
	printf("Entre com os %d valores do vetor B:\n", N);
	for (l = 0; l < N; l++) {
		scanf("%d", B+l);
	}

	// intercalar A e B, gerando C
	int C[2*N];
	// comeca aqui
	l = 0;
	for (int i = 0; i < 2*N; i=i+2) {
		C[i] = A[l];
		C[i+1] = B[l];
		l++;	
	}

	// termina aqui
	for (l = 0; l < N*2; l++) {
		printf("%d ", *(C+l));
	}
	printf("\n\n");
	return 0;
}




