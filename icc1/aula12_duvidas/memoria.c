#include <stdio.h>

int main(void) {

	float mat[2][3] = {{5.1, 4.1, 3.1}, {2.1, 1.1, 0.1}};

	//int mat2[5][6] = {0}; // inicializa com zero

	float* endf;

	endf = mat;

	printf("mat = %p\n", mat);
	printf("endf= %p\n", endf);
	

	// isso gera um erro porque nao faz sentido eu 
	// acessar um 'float' como se fosse um endereco
	// printf("endf= %p\n", (**endf));
	

	return 0;
}
