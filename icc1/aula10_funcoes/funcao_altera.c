#include <stdio.h>


// pode codificar daqui para baixo
void funcao_que_altera_variavel_para_5(int* ender) {
	
	// acessar o endereco e alterar o valor para 5
	(*ender) = 5;	
}
// pode codificar daqui para cima
	


int main (int argc, char* argv[]) {

	int a = 10;
	int x = 10;

	funcao_que_altera_variavel_para_5( &x ); // pode alterar essa linha
	
	//printf("x = %d\n", x);
	//printf("a = %d\n", a); // a tem que ser 10

	return 0;
}
