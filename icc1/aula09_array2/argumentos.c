#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* argv[]) {

	printf("Numero de argumentos (argc): %d\n", argc);	

	int i = 0;
	while (i < argc) {
		printf("argv %d = %s (%p)\n", i, argv[i], argv+i);
		i++;
	}

	// argv[0] -> e' um vetor/array de char

	// tenho que converter para outros tipos se for preciso	
	// ex: alfanumerico para inteiro (a to i)
	int inteiro = atoi(argv[1]);
	// ex: alfanumerico para float (a to f)
	float ponto_flutuante = atof(argv[2]);

	// a partir do momento que acesso e converto, tenho que ter
	// 'certeza' de que eles existem e podem ser convertidos
	printf("%d, %.4f\n\n", inteiro, ponto_flutuante);


}
