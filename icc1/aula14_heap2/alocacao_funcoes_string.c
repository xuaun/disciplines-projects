#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca_A_errada(int N) {
	char* p = malloc(N);
}

void aloca_B_errada(char* p, int N) {
	p = malloc(N);
}


/* receber uma quantidade de bytes por parametro
	e retornar um endereco para um bloco na
	heap contendo esses N bytes alocados
   Parametros:
	int N - quantidade de bytes
   Retorno:
	char* - endereco da primeira posicao
		do bloco de N bytes na heap	

*/
char* aloca_A(int N) {
	char* p = (char*) malloc(N*sizeof(char));
	return p;
}

void aloca_B(char** p, int N) {
	*p = (char*) malloc(N*sizeof(char));
}


int main (int argc, char* argv[]) {

	/* bloco de codigo abaixo nao funciona
	aloca_A_errada(500);
	char* vet = NULL;
	aloca_B_errada(vet, 500);
	free(vet);
	*/
	// funcao aloca e retorna o endereco da regiao na Heap
	char* string1 = aloca_A(500);	
	
	string1[0] = 'M';
	string1[1] = 'o';
	string1[2] = 'a';
	string1[3] = 'c';
	string1[4] = 'i';
	string1[5] = 'r';
	string1[6] = '\0';

	printf("%s\n", string1);

	// funcao aloca memoria via parametro
	char* string2 = NULL;
	aloca_B(&string2, 500);

	strcpy(string2, "Moacir");
	
	printf("%s\n", string2);
	
	free(string1);
	free(string2);

	return 0;
}
