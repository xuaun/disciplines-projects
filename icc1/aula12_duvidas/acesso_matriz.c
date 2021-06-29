#include <stdio.h>

int main (void) {

	// 6 inteiros no total = 4*6 = 24 bytes
	// 11, 21, 31, 41, 51, 61

	// primeira organizacao, em vetor
	// int*
	int vet[6] = {11, 21, 31, 41, 51, 61};
	
	// segunda organizacao, em matriz
	// int**
	// [11, 21]
	// [31, 41]
	// [51, 61]
	int mat[3][2] = { {11, 21}, {31, 41}, {51, 61} };

	printf("%d\n", *(vet+0) ); // valor 11
	printf("%d\n",  vet[0] );

	printf("%d\n", *(vet+2) ); // valor 31
	printf("%d\n",  vet[2] );

	printf("%d\n", **(mat+1)); // quero o valor 31
	printf("%d\n", *(mat[1]));
	
	printf("%d\n", *((*mat)+1)); // quero o valor 21
	printf("%d\n", *(mat[0]+1));


	return 0;
}
