/* Programa que retorna a mediana de 4 numeros
	- Considere que os numeros sao distintos

	Exercicio
*/

#include <stdio.h>

int main (int argc, char* argv[]) {

	int n1, n2, n3, n4;
	int mediana;

	printf("Os numeros digitados abaixo devem ser distintos\n");
	printf("Numero 1: "); scanf("%d", &n1);
	printf("Numero 2: "); scanf("%d", &n2);
	printf("Numero 3: "); scanf("%d", &n3);
	printf("Numero 4: "); scanf("%d", &n4);

	// seu codigo
	if (n1 > n2 && n1 > n3 && n1 > n4) {
		// aqui eu sei que n1 e' o maior numero
	} 

	// media dos elementos centrais (posicao 2 e 3 dos numeros ordenados)



	printf("Mediana: \n\n", mediana);


	return 0;
}
