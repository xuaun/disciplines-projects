//Lista 2 ex 2

#include<stdio.h>

int main(){
	int n;
	float i;
	float s = 0;
	
	printf("Digite um valor inteiro positivo.\n");
	scanf("%d", &n);
	
	for (i = 1;i <= n; i++)
	s += 1/i;
	
	printf("O valor da soma e %f", s);
	
	return 0;
}
