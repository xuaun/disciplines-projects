/*
Implementar uma função que imprima a média 
aritmética dos elementos de um vetor sendo 
que a entrada é o número de elementos e o 
vetor de elementos.
Entrada

4
2.00
3.00  
7.00
8.00  

Saída

5.000000
*/

#include <stdio.h>

double media_vet(int n, double* v){
	double media = 0.0;
	int i;
	
	for (i=0; i<n; i++){
		media += v[i];
	}
	media = media/(double)n;
	
	return media;
}

int main(int argc, char*argv[]){
	int n;
	
	scanf("%d", &n);
	
	double vet[n];
	int i;
	
	for (i=0; i<n; i++){
		scanf("%lf", &vet[i]);
	}
	
	double media = media_vet(n, vet);
	
	/*
	double vet[n];
	double media = 0.0;
	int i;
	
	for (i=0; i<n; i++){
		scanf("%lf", &vet[i]);
		media += vet[i];
	}
	media = media/(double)n;
	*/
	
	printf("%lf\n", media);
	
	return 0;
}
