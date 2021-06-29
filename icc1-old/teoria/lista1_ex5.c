/*5. Dados três números, imprimi-los em ordem crescente.*/

#include<stdio.h>

int main(){
	int x, y, z;
	
	printf("Este programa pedira o valor de tres numeros e te mostrara eles em ordem crescente.\n");
	system ("pause");
		
	printf("Digite um numero: ");
	scanf("%d", &x);
	printf("Digite outro numero: ");
	scanf("%d", &y);
	printf("Digite mais um numero: ");
	scanf("%d", &z);
	
	if ((x >= z) && (x >= y)){
		if (y > z)
		printf("A ordem crescente dos numeros digitadas e %d, %d e %d.", x, y, z);
		else
		printf("A ordem crescente dos numeros digitadas e %d, %d e %d.", x, z, y);
	}
	else if((y >= z) && (y >= x)){
		if (x > z)
		printf("A ordem crescente dos numeros digitadas e %d, %d e %d.", y, x, z);
		else
		printf("A ordem crescente dos numeros digitadas e %d, %d e %d.", y, z, x);
	}
	else if((z >= x) && (z >= y)){
		if (x > y)
		printf("A ordem crescente dos numeros digitadas e %d, %d e %d.", z, x, y);
		else
		printf("A ordem crescente dos numeros digitadas e %d, %d e %d.", z, y, x);
	}
	
	return 0;
}
