#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(char* vet, int n) {
	for (int p=0; p < n; p++) {
		printf("%c", *(vet+p));
	}
	printf("\n");
}

void imprime_ASCII() {
	for (int p=0; p < 256; p++) {
		printf("%d=%c | ", p, (char)p);
	}
	printf("\n");
}

/* alfabeto_vetor(char*, int)
	Altera os valores de um vetor cujo endereco e passado por parametro
	inserindo caracteres do alfabeto A, B, C, D, ate o limite do tamanho
	do vetor (n). A ultima posicao deve ser modificada para '\0'
	Caso o vetor tenha mais do que 26 posicoes, gera apenas ate 'Z'
	e insere o terminador '\0' depois de Z
   Parametros:
	char* vet: endereco da primeira posicao do vetor a ser modificado
	int   n  : numero de posicoes do vetor a modificar

*/
void alfabeto_vetor(char* vet, int n) {
	for (int p=0; p < n; p++) {
		*(vet+p) = (char) (p + 65);
	}
}


int main (int argc, char* argv[]) {

	// atoi -> alfanumeric to integer A to I
	int n = atoi(argv[1]); // pega o primeiro argumento da chamada do programa

	char X[n];
	char Y[n];

	//imprime_ASCII();

	// funcao 1 - imprime o conteudo de X
	imprime_vetor(X, n); // Y tipo? -> char*, i.e. um endereco

	// funcao 2 - altera os valores do vetor X para que sejam
	//            uma sequencia 'A', 'B', 'C', ...
	alfabeto_vetor(X, n);

	imprime_vetor(X, n);

	Y[0] = '$';
	
	imprime_vetor(Y, n);

	return 0;
}
