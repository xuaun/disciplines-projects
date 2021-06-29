/* Programa que executa operacoes como uma calculadora
	Exemplo por: Moacir Ponti - ICMC/USP 2018
*/

#include <stdio.h>

int main (int argc, char* argv[]) {

	float x, y;
	float res;
	int opcao;

	printf("Programa Calculadora\n\n");

	printf("Valor de x: "); scanf("%f", &x);
	printf("Valor de y: "); scanf("%f", &y);

	printf("Digite opcao (1-4)\n");
	printf("1: x+y\n");
	printf("2: x/y\n");
	printf("3: x^2\n");
	scanf("%d", &opcao);

	switch (opcao)  {
		case 1: 
			res = x + y;
			break;

		case 2:
			if (y == 0) {
				printf("Erro de divisao por zero\n");
				res = 0.0;
			} else {
				res = x / y;
			}
			break;
	
		case 3:
			res = x*x;
			break;

		default: printf("Opcao invalida\n");
	}

	// && - E    || - OU       ! - NOT
	// ex.  if (!(x > 0) && ((y == 5) || !(x ==1)))
	
	// Resultado nao pode aparecer se houver erro de divisao por zero
	//if ( (opcao != 2) || (opcao == 2 && y != 0) ) {

	// Resultado nao pode aparecer se houver divisao por zero
	// nem se a opcao for invalida
	//if ( (opcao != 2 || y != 0) && !(opcao < 1 || opcao > 3) ) {
	
	if ( (opcao != 2 || y != 0) && (opcao >= 1 && opcao <= 3) ) {
		printf("Resultado: %.2f\n", res);	
	}

	return opcao;
}
