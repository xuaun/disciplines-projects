#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Tarefa:
	1) armazenar os maiores em um vetor alocado dinamicamente
	2) trocar o argumento 'N' para 3 argumentos:
		N_inicial
		N_final
		passo
	   de forma que o programa execute e mostre o tempo de
	   execucao para varios tamanhos de N para
	   N  = N_inicial
	   N += passo
	   ate N = N_final
*/


#define DEBUG 0

/* aloca_e_preenche_vetor
   Funcao que aloca na memoria heap um vetor de inteiros
   positivos obtidos aleatoriamente e retorna o endereco
   @Parametros
	int total : numero com o tamanho do vetor a ser alocado
   @Retorno
	int* : endereco da primeira posicao na heap contendo
		o vetor alocado
*/
int* aloca_e_preenche_vetor(int total, int debug) {

	int* aux = NULL; // variavel local

	// aloca o vetor
	aux = (int*) malloc(sizeof(int) * total);
	
	int max = (int) (total/2.0)+1;

	// preenche o vetor
	for (int i = 0; i < total; i++) {
		// *(v+i) = rand();
		// *(v+i) <=> v[i]
		aux[i] = rand()%max;
		if (debug) printf("%d ", aux[i]);
	}
	if (debug) printf("\n");
	return aux;
}


int main (int argc, char* argv[]) {

	// argv[0] - nome do programa
	// argv[1] - primeiro argumento
	// argv[2] - segundo argumento
	// printf("Quantidade de argumentos: %d\n", argc);

	if (argc < 2) {
		printf("Uso: ./maiores <N>\n N = tamanho do vetor\n");
		return 1;
	}
 
	//o tamanho do vetor no 1.o argumento na linha de comando
	// atoi() alphanumeric to integer
	int N = atoi(argv[1]);

	if (N < 1) {
		printf("Tamanho do vetor <N> deve ser > 1\n");
		return 2;
	}

	// alocar o vetor de N elementos dinamicamente
	int* vet = NULL;
	vet = aloca_e_preenche_vetor(N, DEBUG);

	// armazena clock antes e depois do algoritmo
	clock_t c1, c2;
	c1 = clock(); // antes

	// verificao e contagem dos maiores
	for (int i = 0; i < N; i++) {
		// para cada valor no vetor
		int val = vet[i];
		int maiores = 0;
		// percorre todos os elementos, contando
		for (int j = 0; j < N; j++) {
			if (vet[j] > val) {
				maiores++;
			}
		}
		if (DEBUG) printf("%d elementos > %d\n", maiores, val);
		//else printf("%d ", maiores);
	}
	c2 = clock(); // depois	

	free(vet);	

	double tempo = (c2-c1)/(double)CLOCKS_PER_SEC;
	printf("%d\t%.6lf\n", N, tempo);
	
	return 0; // finalizou sem erros
}

