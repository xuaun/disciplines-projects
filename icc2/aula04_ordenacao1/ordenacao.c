#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FAIL -404
#define DEBUG 0

/* Funcao que gera um vetor de inteiros aleatorios
	em um determinado intervalo de valores
   Parametros:
	int tam - tamanho do vetor a ser gerado
	int min - valor minimo
	int max - valor maximo
   Retorno:
	int*    - endereco do vetor na heap
*/
int* gera_vetor (int tam, int min, int max) {

	// verifica problemas
	if (tam < 1 || min > max) return NULL;

	int* vet = (int *) malloc(sizeof(int)*tam);

	// verifica se houve problema na alocacao
	if (vet == NULL) return NULL;

	for (int i = 0; i < tam; i++) {
		// ex. min = 0, max = 5, [0, 4] = [0,4+1] = [0, 5]
		//     min = 3, max = 8, [0, 5] + 3 = [3, 8]
		int val = (rand()%(max-min+1)) + min;
		vet[i] = val;
	}
	return vet;
}

/* Funcao que gera um vetor de inteiros ordenados
   Parametros:
	int tam - tamanho do vetor a ser gerado
	int min - valor minimo
	int max - valor maximo
   Retorno:
	int*    - endereco do vetor na heap
*/
int* gera_vetor_ordenado(int tam, int min, int max) {

	// verifica problemas
	if (tam < 1 || min > max) return NULL;

	int* vet = (int *) malloc(sizeof(int)*tam);

	// verifica se houve problema na alocacao
	if (vet == NULL) return NULL;

	// TODO: melhorar isso pra ficar uniformemente distribuido
	int val = min;
	vet[0] = 0;
	for (int i = 0; i < tam; i++) {
		vet[i] = val;
		val = vet[i]+rand()%3;
		if (val > max) val = max;
	}
	return vet;
}


/* Imprime vetor de inteiros
   Parametros
	int* v - vetor
	int  N - tamanho do vetor
*/
void imprime_vetor(int*v, int N) {
	for (int i = 0; i < N; i++)
		printf("%d ", v[i]);
	printf("\n");
}

/* Busca sequencial
   Parametros:
      int* - vetor de inteiros para realizar a busca
      int chave - chave a ser buscada
      int N - tamanho do vetor
   Retorno:
      int - posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_sequencial(int* v, int chave, int N) {
	for (int i = 0; i < N; i++) {
		if (v[i] == chave)
			return i;
	}	
	return FAIL;
}


/* Busca sequencial (recursiva)
	OBS: NAO UTILIZAR NA PRATICA, apenas para fins didaticos
   Parametros:
      int* - vetor de inteiros para realizar a busca
      int chave - chave a ser buscada
      int N - tamanho do vetor
      int i - posicao a ser verificada (inicializada com 0)
   Retorno:
      int - posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_sequencial_recursiva(int* v, int chave, int N, int i) {

	// caso base (1)
	if (i > N) return FAIL;
	// caso base (2)
	if (v[i] == chave) return i;

	// passo recursivo
	return busca_sequencial_recursiva(v, chave, N, i+1);

	// TODO: verificar o que acontece
	// return busca_sequencial_recursiva(v, chave, N, i++); n.funciona
	// return busca_sequencial_recursiva(v, chave, N, ++i); ok
	// i sera modificado
}


/* Busca binaria
	OBS: assume que o vetor esta ordenado
	TODO: analisar o algoritmo usando f(n) = c + f(n/2)
   Parametros:
      int* - vetor de inteiros para realizar a busca
      int chave - chave a ser buscada
      int ini   - posicao inicial do espaco de busca
      int fim   - posicao final do espaco de busca
   Retorno:
      int - posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_binaria(int* v, int chave, int ini, int fim) {

	// 0 - caso base (busca sem sucesso)
	if (ini > fim) return FAIL;

	// 1 - calcula ponto central e verifica se chave foi encontrada
	int centro = (int)((ini+fim)/2.0);
	if (v[centro] == chave)
		return centro;

	// 2 - chamada recursiva para metade do espaco de busca
	if (chave < v[centro])
		// se chave eh menor, fim passa ser o centro-1
		return busca_binaria(v, chave, ini, centro-1);

	if (chave > v[centro])
		// se a chave eh maior, inicio passa ser centro+1
		return busca_binaria(v, chave, centro+1, fim);
	
}

/* Funcao de ordenacao Insertion sort,
	ordena os elementos do vetor passado por parametro
   Parametros:
      int* v - vetor a ser ordenado
      int  n - tamanho do vetor
*/
void insertion_sort(int* v, int n) {

	int i = 1; 

	while (i < n) {
		int chave = v[i]; // fixa chave i e compara com os anteriores
		int j = i-1; // inspeciona elemento anterior
		while (j >= 0 && chave < v[j]) {
			v[j+1] = v[j]; // movimenta elemento
			j--;
		}
		v[j+1] = chave; // copia chave para a posicao correta

		i++; // vai para a proxima chave
	}

}


int main (int argc, char* argv[]) {


	int N, min, max;
	scanf("%d", &N);
	scanf("%d %d", &min, &max);

	int* vet = gera_vetor(N, min, max);
	if (DEBUG) imprime_vetor(vet, N);

	// ordenacao
	clock_t c1, c2;

	c1 = clock();
	insertion_sort(vet, N);
	c2 = clock();
	double sorting_time = (c2-c1)/(float)CLOCKS_PER_SEC;

	if (DEBUG) imprime_vetor(vet, N);

	// busca binaria
	int chave;
	scanf("%d", &chave);

	c1 = clock();
	int pos = busca_binaria(vet, chave, 0, N-1);
	c2 = clock();
	double searching_time = (c2-c1)/(float)CLOCKS_PER_SEC;

	if (pos != FAIL) printf("Elemento encontrado na pos %d\n", pos);

	printf("Tempo de ordenacao (insertion): %lf\n", sorting_time);
	printf("Tempo de busca (binaria)      : %lf\n", searching_time);

	free(vet);
	return 0;
}

