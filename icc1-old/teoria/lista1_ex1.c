#include<stdio.h>

int main(){
	int n, x, z;
	x = 0;
	z = 0;
	
	printf("Digite um numero inteiro positivo.\n");
	scanf("%d", &n);
	
	while (x <= n){
		z += x;
		x++;
	}
	printf("O valor da soma dos primeiros %d numeros inteiros positivos e %d.", n, z);
	
	return 0;
}
