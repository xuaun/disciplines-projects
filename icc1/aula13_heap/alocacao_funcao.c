#include <stdio.h>
#include <stdlib.h>

char* funcao_que_aloca_caracteres(int N) {
	char* p = malloc(N);
	return p;
}

int main (int argc, char* argv[]) {

	char* ender;

	ender = funcao_que_aloca_caracteres(1000);
	
	// quero usar a regiao de memoria aqui
	// a variavel 'end' contem o endereco do primeiro byte na heap

	ender[0] = 'z'; // heap
	ender[1] = 'o'; // heap
	ender[2] = 'm'; // heap

	// cuidado ao acessar a memoria heap (abaixo exemplos de erros)
	//ender[3000] = 'x'; // acesso indevido (escrita/write)
	//printf("%c\n", ender[3000]); // acesso indevido (leitura/read)

	// quero desalocar aqui, antes de finalizar o programa
	// free(p); // funciona? NAO
	free(ender); // funciona? SIM

	return 0;
}
