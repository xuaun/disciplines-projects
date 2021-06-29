#include <stdio.h>

int main (int argc, char* argv[]) {

	// array ou arranjo -> estrutura na memoria
	// uma sequencia de valores de um mesmo tipo
	float A[7] = {6.2, 8.1, -1.9, 0.0, 21.123, 13.666, -8.333};

	//float* p = A[1]; // valido? NAO.
	float* p = A+1; // valido? SIM.

	// p      e' do tipo float*

	// A[1]   e' do tipo float
	// *(A+1) e' do tipo float 

	// (A+1)  e' do tipo float*  OBS: A + 1*sizeof(float) = A+(1*4)
	//   A    e' do tipo float*

	int j;
	for (j=0; j<7; j=j+1) {
		printf("%.2f ", *(A+j));
	}	
	printf("\n\n");

	for (j=0; j<7; j=j+1) {
		printf("%.2f ", A[j]);
	}	
	printf("\n\n\n");


	// media dos numeros
	float soma = 0.0;
	/*
	soma = A[0];
	soma = soma + A[1];
	soma = soma + A[2];
	...
	soma = soma + A[6];*/
	for (j = 0; j < 7; j++) {
		soma = soma + A[j]; // soma += valor <=> soma = soma + valor
	}
	
	float media = soma/7.0;
	printf("Media = %.4f\n\n", media);
	
	return 0;


}
