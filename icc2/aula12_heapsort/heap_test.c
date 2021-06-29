#include "busca_e_ordenacao.h"

int main(void) {

	int* A = gera_vetor(11, 0, 9);
	A[0] = -1; // desconsiderando a primeira posicao

	imprime_vetor(A, 11);

	max_heapify(A, 1, 11);

	imprime_vetor(A, 11);

	build_maxheap(A, 11);

	imprime_vetor(A, 11);

	return 0;
}
