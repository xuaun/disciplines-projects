#include <stdio.h>

int main (int argc, char* argv[]) {

	
	int a;

	// for (inicializacao; teste; modificacao)
	for (a = 0; a <= 10; a = a+2) {
		printf("%d ", a);
	}
	printf("\n");

	a = 0;
	while (a <= 10) {
		printf("%d ", a);
	
		a = a+2;
	}
	printf("\n");

	return 0;
}
