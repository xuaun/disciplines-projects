#include <stdio.h>

int main (int argc, char* argv[]) {

	float x;
	float y;

	printf("Programa que executa ate 3 divisoes do\nprimeiro numero pelo segundo numero digitado.\n\n");

	// pedir para o usuario digitar um valor float
	// e armazenar no endereco de y
	printf("Digite o valor de y: ");
	scanf("%f", &y);

	printf("Digite o valor de x: ");
	scanf("%f", &x);

	//y = o que o usuario digitar primeiro;
	//x = o que o usuario digitar em segundo;

	// desvio condicional
	// se a condicao for verdadeira, executa o bloco
	// entre chaves
	
	// if (condicao) { bloco de codigo }
	if (y > 1) {
		// VERDADEIRO (y = 9) e portanto > 1
		y = y / x;		
		printf("primeira divisao\n");
		printf("y = %f\n", y);
	}
	if (y > 1) {
		// VERDADEIRO (y = 3) e portanto > 1
		y = y / x;		
		printf("segunda divisao\n");
		printf("y = %f\n", y);
	}
	if (y > 1) {
		// FALSO (y = 1) e portanto nao e' > 1
		y = y / x; // essa linha NUNCA vai ser executada
		printf("terceira divisao\n");
		printf("y = %f\n", y);
	}

	printf("valor final de y = %f\n\n", y);	

}
