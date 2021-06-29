#include <stdio.h>

#define MAX 18

int main (int argc, char* argv[]) {

	int a;

	printf("numeros pares entre 0 e %d:\n", MAX);
	// for (inicializacao; teste; modificacao)
	for (a = 0; a <= MAX; a = a+2) {
		printf("%d ", a);
	}
	printf("\n");

	int min;
	printf("Digite um numero inicial: ");
	scanf("%d", &min);

	printf("numeros pares entre %d e %d:\n", min, MAX);
	if (min % 2 != 0) {
		min = min + 1;
	}
	//min = min + (min%2);

	// for (inicializacao; teste; modificacao)
	for (a = min; a <= MAX; a = a+2) {
		printf("%d ", a);
	}
	printf("\n");



	return 0;
}
