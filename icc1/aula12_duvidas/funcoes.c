#include <stdio.h>

#define size 5

int funcao(int a) {
	int b = a+2;
	return a;
}

int outra(int x) {
	x++;
	return x;
}

void endereco(int* a) {
	*a = 10;
}

void vetor(int* a) {
	for (int i=0; i< size; i++) {
		*(a+i) = 2*i;
	}
}

int main (int argc, char* argv[]) {

	int x = 5;

	printf("%d\n", funcao(x));	

	printf("%d\n", outra(x));	

	printf("%d\n", x);

	endereco(&x);
	printf("%d\n", x);

	int vet[size]; 
	vetor(vet);

	for (int i = 0; i < size; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n\n");

	return 0;
}
