#include <stdio.h>

int main (int argc, char* argv[]) {

	float x;
	float y;
	y = 9.0; // valor inicial
	x = 3.0;     // fator de divisao

	// desvio condicional
	// se a condicao for verdadeira, executa o bloco
	// entre chaves
	
	// if (condicao) { bloco de codigo }
	if (y > 1) {
		// VERDADEIRO (y = 9) e portanto > 1
		y = y / x;		
	}
	if (y > 1) {
		// VERDADEIRO (y = 3) e portanto > 1
		y = y / x;		
	}
	if (y > 1) {
		// FALSO (y = 1) e portanto nao e' > 1
		y = y / x; // essa linha NUNCA vai ser executada
	}

	printf("valor final de y = %f\n\n", y);	

}
