/*
Ler uma tabela de notas em uma matriz, um aluno por linha, 
e usar a função desenvolvida no problema 1 (Média dos 
elementos de um vetor) para calcular e imprimir a média 
aritmética de cada aluno. ATENÇÃO: A função do problema 1 
não pode ser modificada aqui. apenas utilizada.

Nota: A primeira linha da entrada conterá o número de alunos 
"n" e o número de notas "m". As seguintes "n" linhas 
representarão a cada aluno e cada linha conterá "m" colunas 
(representando as notas do aluno).
Entrada

3 4
5.0 5.0 5.0 5.0
2.0 3.0 7.0 8.0  
1.0 0.0 3.0 5.0

Saída

5.000000
5.000000
2.250000

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

int main(int argc, char*argv[]){
	int n, m;
	
	scanf("%d %d", &n, &m);
	
	double mat[n][m];	
	int i, j;
	
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			scanf("%lf", &mat[i][j]);
		}
	}
	
	double media;
	
	for (i=0; i<n; i++){
		media = media_vet(m, mat[i]);
		printf("%lf\n", media);
	}
	
	return 0;
}
