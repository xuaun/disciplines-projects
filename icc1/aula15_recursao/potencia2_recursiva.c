#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int potencia_de_2_recursiva(long int x) {
	// caso base
	if (x == 0) return 1;
	// passo recursivo (envolve modificacao)
	return 2*potencia_de_2_recursiva(x-1); 
}

// outra forma, tambem funciona
long int potencia_de_2_recursiva_b(long int x) {

	// caso base
	if (x == 0) {
		return 1;
	}

	// passo recursivo (modificacao)
	x = x - 1;
	return potencia_de_2_recursiva(x)*2;
}


long int potencia_de_2_iterativa(long int x) {
	long int res = 1;
	for (int i = 0; i < x; i++) {
		res = res*2;
	}
	return res;
}


int main(int argc, char* argv[]) {

	int x = atoi(argv[1]);
	
	clock_t t1, t2;
	double tempo_rec;
	double tempo_ite;

	long int res;

	t1 = clock();
	res = potencia_de_2_recursiva(x);
	t2 = clock();
	tempo_rec = (t2-t1)/(double)CLOCKS_PER_SEC;
	printf("2^%d = %ld\n", x, res);

	t1 = clock();
	res = potencia_de_2_iterativa(x);
	t2 = clock();
	tempo_ite = (t2-t1)/(double)CLOCKS_PER_SEC;
	printf("2^%d = %ld\n", x, res);
	
	printf("Iterativa : %.5lf\n", tempo_ite);
	printf("Recursiva : %.5lf\n", tempo_rec);

	return 0;
}
