#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int a; // stack (alocacao automatica)

	int* ip; // stack (alocacao automatica)

	/* funcao malloc, tem a seguinte assinatura:
	   void* malloc(size)
		- recebe como parametro um tamanho em bytes
		- retorna um endereco (void *)
	*/
	ip = (int*) malloc(4); // alocacao dinamica (heap)
	*ip = 93;

	char* cp; // stack
	cp = (char*) malloc(1); // alocacao dinamica (heap)
	*cp = 'z';

	float* fp; // stack
	fp = (float*) malloc(4); // alocacao dinamica (heap)
	*fp = 4.5;

	printf("Imprimindo valores que estao na heap:\n");
	printf("id\t&var (stack)\tvar (heap)\t*var\n");

	printf("ip\t%p\t%p\t%d\n", &ip, ip, *ip);
	printf("cp\t%p\t%p\t%c\n", &cp, cp, *cp);
	printf("fp\t%p\t%p\t%f\n", &fp, fp, *fp);

	free(ip);
	free(cp);
	free(fp);

	return 0;
}
