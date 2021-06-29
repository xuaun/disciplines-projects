
#include "busca_e_ordenacao.h"

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

/* Funcao de ordenacao Mergesort
*/
void mergesort (int* v, int ini, int fim) {

	if (fim <= ini) return; // caso base (vetor de 1 elemento)

	int centro = (int) ((fim+ini)/2.0);

	// 1 - passo recursivo (divisao)
	mergesort(v, ini, centro);   // divisao lista 1 (primeira metade)
	mergesort(v, centro+1, fim); // divisao lista 2 (segunda metade)

	// 2 - intercalacao, combinando solucoes parciais (conquista)

	// tamanho do vetor auxiliar:
	// 0, 1, 2, 3, 4, 5, 6, 7
	// 0, 1   aux -> tam = 2     1-0+1 = 2
	// 2, 3   aux -> tam = 2     3-2+1 = 2
	// 4, 5, 6, 7   aux -> 4     7-4+1 = 4

	// vetor auxiliar para copiar a intercalacao
	int* aux = (int*) malloc(sizeof(int) * (fim-ini+1) );
	
	int i = ini;	  // indice da lista 1 (ini ate centro)
	int j = centro+1; // indice da lista 2 (centro+1 ate fim)
 	int k = 0;	  // indice do vetor auxiliar (0 ate fim-ini)

	// comparar elementos das duas listas
	while (i <= centro && j <= fim) {
		if (v[i] <= v[j]) {
			aux[k] = v[i]; 
			i++; // proximo elemento da lista 1
		} 
		else {
			aux[k] = v[j];
			j++; // proximo elemento da lista 2
		}
		k++; // proximo elemento do aux
	}

	// copia os restantes da l1
	while (i <= centro) {
		aux[k] = v[i];
		i++; k++;
	}	
	// copia os restantes da l2
	while (j <= fim) {
		aux[k] = v[j];
		j++; k++;
	}	

	// copia aux para a posicao correta do vetor original	
	// abaixo 3 formas de fazer isso
	/*
	for (k = 0; k <= fim-ini; k++) {
		v[k+ini] = aux[k];
	}

	for (i = ini; i <= fim; i++) {
		v[i] = aux[i-ini];
	}
	*/

	for (i = ini, k = 0; i <= fim; i++, k++) {
		v[i] = aux[k];
	}

	free(aux); // libera vetor auxiliar
}

/* Funcao de ordenacao Quicksort 
   Parametros:
	int *v - vetor a ser ordenado
	int  ini - posicao inicial
	int  fim - posicao final
	int  eep - estrategia de escolha do pivo:
			0 - inicial
			1 - central
			2 - aleatorio
			3 - mediana de 3
*/
void quicksort (int* v, int ini, int fim, int (*eep)(int, int)) {

	// 0 - caso base
	//	vetor unitario ou vazio
	if (ini >= fim) return;

	// 1 - escolha do pivo
	int p = eep(ini, fim);

	// troca com o primeiro elemento
	int tmp = v[p];
	v[p] = v[ini];
	v[ini] = tmp;

	// 2 - particiona
	int i = ini+1; // percorre do inicio para o fim
	int j = fim; // percorre do fim para o inicio
	
	while (i <= j) {
		while (i <= fim && v[i] <= v[p]) i++; // encontra elemento a ser trocado na L1
		while (v[j] > v[p]) j--;  // encontra elemento a ser trocado na L2
		if (i < j) {
			tmp = v[i];
			v[i] = v[j];
			v[j] = tmp;
		}
	}

	// reposiciona o pivo na sua posicao correta (ordenado)
	tmp = v[p];
	v[p] = v[j];
	v[j] = tmp;
	p = j; // atualiza pivo

	// 3 - chamada recursiva
	quicksort(v, ini, p-1, eep);
	quicksort(v, p+1, fim, eep);

}

/* Funcao Max-Heapify
	Encontra a posicao correta de um dos elementos
	no Max-Heap
   Parametros:
	int * - vetor a ser ordenado
	int   - posicao inicial
	int   - tamanho do vetor
*/
void max_heapify(int* v, int p, int n) {

	// comeca verificando filho da esquerda
	int f = p*2;

	// caso base, no' folha
	if (f > n) return;

	// verifica se um dos filhos e' maior
	if (v[f] > v[p] || (f+1 <= n && v[f+1] > v[p])) {

		// caso o da direita seja maior, atualiza 'f'
		if (f+1 <= n && v[f+1] > v[f]) 
			f = f+1; // elemento a trocar passa a ser da dir.

		// troca
		int tmp = v[p];
		v[p] = v[f];
		v[f] = tmp;
		
		max_heapify(v, f, n);
	}
}

/* Funcao Build-MaxHeap
	Monta um Maxheap num vetor de inteiros
   Parametros:
	int * - vetor a ser ordenado
	int   - tamanho do vetor
*/
void build_maxheap(int* v, int n) {
	int m = (int) n/2.0; // ultimo no' pai
	for (int p = m; p >= 1; p--) {
		max_heapify(v, p, n);
	}
}

