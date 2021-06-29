/*
Implementar o seguinte:

(1) um subprograma que leia uma matriz que representa a tabela 
de notas de uma turma (um aluno por linha). 

(2) um subprograma para escrita de uma matriz, e; 

(3) um subprograma que leia uma matriz (com o subprograma 1 
acima), calcule a média das linhas da matriz com a função da 
aula passada, adicione a média de cada linha ao final da linha 
(adicionando portanto uma coluna a mais na matriz) e escreva a 
matriz resultante (com o subprograma 2)

Nota: Para a entrada dos dados, a primeira linha da entrada 
conterá o número de alunos "n" e o número de notas "m". As 
seguintes "n" linhas representarão a cada aluno e cada linha 
conterá "m" colunas (representando as notas do aluno).

Entrada

6 2
0.0 0.0
0.0 10.0
5.0 8.0
3.0 10.0
2.0 4.0
3.0 9.0

Saída

0.000000    0.000000    0.000000    
0.000000    10.000000   5.000000    
5.000000    8.000000    6.500000    
3.000000    10.000000   6.500000    
2.000000    4.000000    3.000000    
3.000000    9.000000    6.000000

*/

#include <stdio.h>

double media_vet(int n, double* v){
	double media = 0.0;
	int i;
	
	for (i=0; i<n; i++){
		media += v[i];
	}
	media = media/(double)n;
	
	return media;
}

void ler_matriz(int n, int m, double notas[][100]){
	int i, j;
	for(i = 0; i < n; i++){
		for (j = 0; j<m; j++){
			scanf("%lf", &notas[i][j]);
		}
	}
}

void escreve_matriz(int n, int m, double notas[][101]){
	int i, j;
	for(i = 0; i < n; i++){
		for (j = 0; j<=m; j++){
			printf("%lf\t", notas[i][j]);
		}
		printf("\n");
	}
}

void matriz(int n, int m, double notas[][100]){
	ler_matriz(n, m, notas);
	
	double notas_media[101][101];
	
	double media[100];
	int i, j;
	
	for(i = 0; i<n; i++){
		media[i] = media_vet(m, notas[i]);
	}
	
	for (i = 0; i<n; i++){
		for (j = 0; j<=m; j++){
			if (j<m){
				notas_media[i][j] = notas[i][j];
				//printf("matriz: %lf\n", notas[(i*m)+j]);
				//printf("\tmatriz2: %lf\n", notas_media[i][j]);
			}else{
				notas_media[i][j] = media[i];
				//printf("\tmedia2: %lf\n", notas_media[i][j]);
			}
		}
	}
	
	escreve_matriz(n, m, notas_media);
	
}

int main(int argc, char* argv[]){
	int n, m;
	scanf("%d %d", &n, &m);
	double notas[100][100];
	
	//ler_matriz(n, m, *notas);
	
	//escreve_matriz(n, m, *notas);
	
	matriz(n, m, notas);
	
	return 0;
}
