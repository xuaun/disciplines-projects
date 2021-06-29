/*
Implementar um programa que, dadas duas matrizes, gere e imprima uma matriz 
resultado do produto das duas (deletando as matrizes origem). Para resolver 
este problema, são fornecidos os seguintes cabeçalhos:

1 ** alloc_matrix (int n, int m). Esta função fará a alocação de memória de 
uma matriz

2 int * free_matrix (int n, int m, int * matrix). Esta função liberará o 
espaço de memória de uma matriz

3 void print (int n, int m, int ** matrix). Esta função imprimirá a matriz

4 void read (int n, int m, int ** matrix). Esta função lerá uma matriz, a 
qual já tem memória alocada

5 int * prod_matrix (int n1, int m1, int n2, int m2, int * matrix1, 
int ** matrix2). Esta função executará a multiplicação das duas matrizes. 
Além disso, nela deve ser realizada a verificação da possibilidade de 
multiplicar as duas matrizes.

Alguns detalhes a seguir:

    Nota 1: Para a entrada dos dados, a primeira linha da entrada conterá o 
número as dimensões "n" e "m" da primeira matriz (onde "n" representa o 
número de linhas e "m" o número de colunas). Depois, são apresentadas "n" 
linhas com "m" elementos cada uma, representando desta maneira a primeira 
matriz. Após estes dados, é repetido o mesmo formato para a segunda matriz.
    Nota 2: Todas as matrizes deverão ser alocadas com a função allocmatrix e 
liberadas com a função freematrix.
    Nota 3: Caso dúvidas sobre multiplicação de matrizes. Pode ser consultado: 
https://pt.wikipedia.org/wiki/Produtodematrizes e um exemplo 
em https://www.infoescola.com/matematica/operacoes-com-matrizes-multiplicacao/
    Nota 4: Caso não possa ser realizada a multiplicação (por desigualdade 
entre o número de colunas da primeira matriz e o número de linhas da segunda 
matriz) deve-se mostrar a mensagem "erro nas matrizes".

Entrada

2 3
2 2 3
1 1 2
3 1 
2
3
4

Saída

22
13

*/

#include <stdio.h>
#include <stdlib.h>

int** alloc_matrix(int n, int m){
	int** matrix = (int**) malloc(sizeof(int*) * n);
	int i;
	for (i=0; i<n; i++){
		matrix[i] = (int*) malloc(sizeof(int) * m);
	}		
	
	return matrix;
}

int** free_matrix (int n, int m, int** matrix){
	free(matrix);
	
	//return ?
}

void print (int n, int m, int** matrix){
	int i, j;
	
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void read (int n, int m, int** matrix){
	int i, j;
	
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
}

int** prod_matrix (int n1, int m1, int n2, int m2, int** matrix1, int** matrix2){
	//printf("teste1: prod\n");
	
	if (m1 != n2){
		printf("erro nas matrizes\n");
	
		return (int**) 1;
	}
	
	int** mat_res = alloc_matrix(n1, m2);
	int temp = 0;
	//printf("mat_res: %p\n", *mat_res);
	
	//printf("teste2: prod\n");
	
	int i, j, k;
	for (i=0; i<n1; i++){
		for (j=0; j<m2; j++){
			for (k=0; k<m1; k++){
				//printf("teste for: prod, k = %d\n", k);
				temp += matrix1[i][k] * matrix2[k][j];
				//printf("teste1: temp%d = %d\n", k, temp);
			}
			//printf("teste2: temp%d = %d\n", j, temp);
			mat_res[i][j] = temp;
			//printf("teste3: mat_res = %d\n", mat_res[i][j]);
			temp = 0;
		}
	}
	
	//printf("teste3: prod\n");
	
	return mat_res;
} 


int main (int argc, char* argv[]){
	int n1, m1;
	scanf("%d %d", &n1, &m1);
	int** matrix1 = alloc_matrix(n1, m1);
	//printf("n1: %d; m1: %d\n", n1, m1);
	read (n1, m1, matrix1);
	
	int n2, m2;
	scanf("%d %d", &n2, &m2);
	int** matrix2 = alloc_matrix(n2, m2);
	//printf("n2: %d; m2: %d\n", n2, m2);
	//printf("matrix2: %p\n", *matrix2);
	read (n2, m2, matrix2);
	
	int** matrix_res = prod_matrix (n1, m1, n2, m2, matrix1, matrix2);
	//printf("olar\n");
	
	print (n1, m2, matrix_res);
	
	matrix1 = free_matrix (n1, m1, matrix1);
	matrix2 = free_matrix (n2, m2, matrix2);
	matrix_res = free_matrix (n1, m2, matrix_res);
	
	return 0;
}
