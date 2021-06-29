#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

long int fibonacci(int x) {
	// cenario indefinido
	if (x <= 0) return ERROR;

	printf("\t%d\n", x);
	// caso base
	if (x > 0 && x <= 2) return 1;

	// passo recursivo
	return fibonacci(x-1) + fibonacci(x-2);
}


int main(int argc, char* argv[]) {

	int n = atoi(argv[1]);

	n = 4;
	long int fib_n = fibonacci(n);

	printf("Fibonacci %d = %ld\n", n, fib_n);

	return 0;
}
