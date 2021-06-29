#include <stdio.h>
#include <stdlib.h>

/* Funcao que aloca uma matriz de floats com tamanho NxM
   Parametros:
	int N - numero de linhas
	int M - numero de colunas
   Retorno:
	float** - endereco para a primeira posicao da matriz na Heap
*/
float** aloca_matriz(int N, int M) {

	float** m = NULL;
	
	// aloca as 'linhas' ou seja um vetor de vetores de float

	// em outras palavras 'm' eh um vetor de ponteiros para float
	m = (float**) calloc(N, sizeof(float *));
	for (int i = 0; i < N; i++) {
		m[i] = (float *) calloc(M, sizeof(float));
	}
	return m;
}

/* Funcao que desaloca uma matriz de floats com N x M elementos
   Parametros:
	int N, int M - tamanho da matriz
	float **mat  - endereco da matriz a ser desalocada
*/
void desaloca_matriz(int N, int M, float** mat) {

	for (int i = 0; i < N; i++) {
		free(mat[i]);
	}
	free(mat);
}




/* Funcao que aloca uma vetor de strings
	cada string deve armazenar um nome com ate 10 caracteres

*/
// aloca_vetor_nomes()


int main (int argc, char* argv[]) {

	// matriz de floats com N linhas e M colunas de floats
 	float** mat;
	int N = 1000, M = 1000;
	mat = aloca_matriz(N,M);

	desaloca_matriz(N,M, mat);

	// float mat2[1000][1000]; // nao e' recomendado!!!!

	/* exercicio
	// vetor de strings com P nomes
	// (cada posicao do vetor tem um 'nome' de ate 10 chars)
	char vet;

	int P;
	vet = aloca_vetor_nomes(P);

	*/

	return 0;
}
