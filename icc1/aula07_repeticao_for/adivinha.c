/* Programa que sorteia um numero e pede para o usuario
	tentar adivinhar

   Exercicio :
	1) altere o codigo de forma a aceitar no maximo MAX tentativas
	   OBS:	#define permite definir uma 'macro', um simbolo
		que sera substituido em todo o codigo

	2) qual seria um 'algoritmo' para tentar adivinhar
	   com o menor numero possivel de dicas? e, por consequencia
	   qual seria o numero maximo de dicas necessarias
	   nesse seu algoritmo?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main(int argc, char* argv[]) {

	int chute = -1; // armazena o chute do usuario
	int num;  // armazena o numero a ser adivinhado

	// altera a semente da geracao pseudo-aleatoria
	// uma forma de altera-la a cada vez que o programa
	// e' executado, seria utilizar a hora do sistema
	srand( time(NULL) );

	// sorteia um numero aleatorio e mapeia para 1-128
	num = (rand()%128)+1;
	// printf("Numero sorteado: %d\n", num);

	// enquanto chute != num
	// repete a linha abaixo
	while (chute != num) {

		scanf("%d", &chute); // usuario digita chute

		if (chute > num) {
			printf("Tente um valor menor\n");
		} 
		if (chute < num) {
			printf("Tente um valor maior\n");
		}
	}
	printf("Parabains %d horas\n\n", MAX);
	
	return 0;
}
