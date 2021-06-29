/*4. Dados três números naturais, verificar se eles formam os lados de um triângulo retângulo.*/

#include<stdio.h>
//#include <stdlib.h>
//#include <math.h>

int main(){
	int x, y, z;
	
	printf("Digite um primeiro valor para ser um dos lados do triangulo retangulo: ");
	scanf("%d", &x);
	printf("Digite um segundo valor para ser um dos lados do triangulo retangulo: ");
	scanf("%d", &y);
	printf("Digite um terceiro valor para ser um dos lados do triangulo retangulo: ");
	scanf("%d", &z);
	
	if ((x*x == (y*y + z*z)) || (y*y == (x*x + z*z)) || (z*z == (y*y + x*x))){
		printf("\nOs valores fornecidos formam um triangulo retangulo.");
	}
	else{
		printf("\nOs valores fornecidos nao formam um triangulo retangulo.");
	}
	
	return 0;
}
