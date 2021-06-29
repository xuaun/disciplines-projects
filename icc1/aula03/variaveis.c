/* Programa que demonstra o uso de variaveis, seu conteudo
	e endereco na memoria pilha (stack)
   Autor: Moacir A. Ponti (ICMC/USP)
   2018 
*/

#include <stdio.h>

int main(int argc, char* argv[]) {

	// declaracao de variaveis

	char a;  // tipo caracter, 1 byte

	float x; // tipo ponto flutuante, 4 bytes

	int y;	 // tipo inteiro, 4 bytes

	// imprimir o conteudo das variaveis
	printf("%c, %f, %d \n\n", a, x, y);

	// inicializar as variaveis

	a = 'V';
	x = 1.99;
	y = 7;

	printf("Valores: %c, %.2f, %d \n\n", a, x, y);
	printf("Enderecos: %p, %p, %p \n\n", &a, &x, &y);

	printf("Para imprimir uma barra: \\ \n");
	printf("Para imprimir um simbolo de porcentagem: %% \n");
	printf("Fim do programa\n\n");

}
