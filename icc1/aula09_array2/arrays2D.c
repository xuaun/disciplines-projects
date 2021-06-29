/* Programa que demonstra o uso de arrays com mais de um indice
	1 indice  - vetor
	2 indices - matriz
   Exemplo por: Moacir Ponti / ICMC-USP 2018
*/


#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {

	// cria uma matriz 2x3, inicializada com 1,2,3,4,5,6
	int mat1[2][3] = { {1,2,3}, {4,5,6} };
	
	// cria uma matriz 3x2, inicializada com zeros
	int mat2[3][2] = {0};

	// matriz 1
	int i,j;
	for (i = 0; i < 2; i++) {
	    for (j = 0; j < 3; j++) {
		printf("[%d,%d] %d (%p)\n", i, j, mat1[i][j], &mat1[i][j]);
	    }
	}
	printf("\n");


	// cada operacao em mat1 e' multiplicada por 12 bytes
	// pois cada posicao mat1[i] possui um vetor com 3 ints (3x4=12)
	// abaixo, exemplo de uso de apenas um indice (i), sendo j=0 fixo
	// preciso usar **(mat1) pois e' preciso acessar dois niveis de
	// endereco, um para a linha (que leva em um vetor), e outro
	// para a coluna (que finalmente leva em um valor inteiro
	printf("Acessando e percorrendo apenas as linhas\n");
	for (i = 0; i < 2; i++) {
	    printf("[%d,0] %d (%p)\n", i, *(*(mat1+i)), (mat1+i));
	}

	// exemplo usando colchetes
	//for (i = 0; i < 2; i++) {
	//    printf("[%d,0] %d (%p)\n", i, *mat1[i], mat1[i]);
	//}


	printf("\nAcessando e percorrendo linhas e colunas\n");

	// exemplo acessando todos os elementos da matriz
	for (i = 0; i < 2; i++) {
	    for (j = 0; j < 3; j++) {
		printf("[%d,%d] %d (%p)\n", i, j, *(*(mat1+i)+j), *(mat1+i)+j);
	    }
	}


	return 0;
}


