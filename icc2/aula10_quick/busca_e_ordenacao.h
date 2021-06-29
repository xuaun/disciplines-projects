/* Biblioteca com funcoes para busca e ordenacao
	Disciplina scc0201 - Introducao a Ciencias de Computacao II
	ICMC / USP - 2018
	Moacir A. Ponti
*/

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
int* gera_vetor (int tam, int min, int max);

/* Funcao que gera um vetor de inteiros ordenados
   Parametros:
	int tam - tamanho do vetor a ser gerado
	int min - valor minimo
	int max - valor maximo
   Retorno:
	int*    - endereco do vetor na heap
*/
int* gera_vetor_ordenado(int tam, int min, int max);

/* Imprime vetor de inteiros
   Parametros
	int* - vetor
	int  - tamanho do vetor
*/
void imprime_vetor(int*, int);

/* Busca sequencial
   Parametros:
      int* - vetor de inteiros para realizar a busca
      int chave - chave a ser buscada
      int N - tamanho do vetor
   Retorno:
      int - posicao em que a chave foi encontrada, ou FAIL caso contrario
*/
int busca_sequencial(int* v, int chave, int N);

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
int busca_sequencial_recursiva(int* v, int chave, int N, int i);


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
int busca_binaria(int* v, int chave, int ini, int fim);

/* Funcao de ordenacao Insertion sort,
	ordena os elementos do vetor passado por parametro
   Parametros:
      int* v - vetor a ser ordenado
      int  n - tamanho do vetor
*/
void insertion_sort(int* v, int n);

/* Funcao de ordenacao Mergesort
   Parametros:
      int* v - vetor a ser ordenado
      int  ini - posicao inicial do vetor
      int  fim - posicao final do vetor
*/
void mergesort (int* v, int ini, int fim);

/* Funcao de ordenacao Quicksort
   Parametros:
      int* - vetor a ser ordenado
      int  - posicao inicial do vetor
      int  - posicao final do vetor
      int (*) - funcao que calcula a posicao do pivo
*/
void quicksort (int*, int, int, int (*)(int,int));


