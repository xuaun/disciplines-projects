/* Programa que imprime os numeros primos de 1 ate N

*/


#include <stdio.h>

int main (int argc, char* argv[]) {

	int N;
	scanf("%d", &N); // usuario informa N


	int i = 2; // primeiro numero a ser testado

	// primeiro caso N == 3	
	while (i <= N) {
		// ja sei que qualquer inteiro e divisivel
		// por ele mesmo e por um e portanto, posso comecar
		// com variavel valendo 2
		int divisores = 2;

		// testo os numeros anteriores
		// comeco com o imediatamente anterior (i-1)
		int j = i-1;
		while (j > 1) {
			// se encontrar resto == 0
			if (i % j == 0) {
				divisores = divisores + 1;
			}
			j = j - 1; // atualizo j para o numero anterior
		}
		if (divisores == 2) {
			printf("%d - primo\n", i);
		} 
		else {
			printf("%d - nao e' primo, possui %d divisores\n", i, divisores);
		}
		i = i + 1; // agora vou testar o proximo numero
	}

	return 0;
}
