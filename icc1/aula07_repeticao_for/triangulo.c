/* Programa que imprime um triangulo de asteriscos

	Exercicio
		1) O usuario digita o numero de linhas (ao inves de MAX)
		2) Outro formato, apos atingir MAX, 
		   imprime na ordem reversa. Ex. para MAX = 4
			*
			**
			***
			****
			***
			**
			*
		
*/
#define MAX 10

#include <stdio.h>

int main (int argc, char* argv[]) {

	int linha;

	for (linha = 1; linha <= MAX; linha++) {
		int a;
		// o numero de asteriscos deveria ser igual a 'linha'
		for (a = 1; a <= linha; a++) {
			printf("*");
		}
		
		printf("\n");
	}
	/* Ex. MAX = 3
	   FOR externo 
	    linha = 1
            if (1 <= 3) V

	    FOR interno
	     a = 1
             if (1 <= 1) V
	     printf("*")
	     a = 2
             if (2 <= 1) F

           printf("\n")

 	   linha = 2
	   if (2 <= 3) V

            FOR interno
	     a = 1
	     if (1 <= 2) V
	     printf("*")

	     a = 2
             if (2 <= 2) V
	     printf("*")

	     a = 3
	     if (3 <= 2) F
	
	   printf("\n")

	    linha = 3
	    ...

	*/

	return 0;
}



