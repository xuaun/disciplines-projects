#include <stdio.h>

int main (int argc, char* argv[]) {

	// Memoria: espaco reservado p/ um inteiro de 32 bits
	int x;
	x = 40000;

	// Memoria: espaco reservado p/ um ponto flutuante
	//		de 32 bits (numero "real")
	float y;
	y = 1.33333333;
	
	// Memoria: espaco reservado para um caracter ASCII
	//		de 8 bits
	char c;	
	c = 'A';

	// Operadores aritmeticos
	// soma +
	// subtracao -
	// produto *
	// divisao /
	x*y;

	// Impressao na tela -> printf("exibido", valores)
	printf("Primeiro numero = %d\n", x);
	printf("Segundo numero  = %f\n", y);
	printf("Multiplicacao   = %f\n", x*y);

	// para recuperar o endereco da memoria usar &
	printf("Endereco de x = %p\n", &x);

}
