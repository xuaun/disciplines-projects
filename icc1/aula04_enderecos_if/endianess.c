#include <stdio.h>

int main  (int argc, char* argv[]) {

	int x = 258;

	// &x == endereco de x	

	// char* - armazena endereco de uma variavel CHAR
	// int*  - armazena endereco de uma variavel INT

	int* end_x = &x;

	printf("endereco armazenado: %p\n", end_x);	
	
	// vamos acessar o valor que esta no endereco armazenado
	// em end_x

	printf("valor (de 4 bytes) nesse endereco: %d\n", *end_x);
	
	//      x  -  int
	//     &x  -  int*
	//
	//  end_x  -  int*
	// *end_x  -  int

	char* p;
	p = (char*) &x; // ou p = (char*) end_x;
	
	printf("endereco armazenado (em p): %p\n", p);
	printf("valor (de 1 byte) nesse endereco: %d\n", *p);

	p = p + 1; // calcula o proximo endereco
	printf("endereco atual (em p): %p\n", p);
	printf("valor (de 1 byte) nesse endereco: %d\n", *p);

	p = p + 1; // calcula o proximo endereco
	printf("endereco atual (em p): %p\n", p);
	printf("valor (de 1 byte) nesse endereco: %d\n", *p);

	p = p + 1; // calcula o proximo endereco
	printf("endereco atual (em p): %p\n", p);
	printf("valor (de 1 byte) nesse endereco: %d\n\n\n", *p);

	// 00001001    11100100    11100101  
	// 00000001    00000001    00000001
	// AND         AND         AND
	// 00000001    00000000    00000001
	
	int y = 254; // 00000000 00000000 00000000 11111110
		     // AND
		     // 00000000 00000000 00000000 00000001

	printf("Sabemos que 254 deveria ter os bits 11111110\n");
	printf("Vamos testar fazendo operacao AND com 00000001:\n");
	printf("bit 1: %d\n", y & 1);

	// 10000000 11111110 >> 1
	// 01000000 01111111

	printf("bit 2: %d\n", (y >> 1) & 1);
	printf("bit 3: %d\n", (y >> 2) & 1);
	printf("bit 4: %d\n", (y >> 3) & 1);
	printf("bit 5: %d\n", (y >> 4) & 1);
	printf("bit 6: %d\n", (y >> 5) & 1);
	printf("bit 7: %d\n", (y >> 6) & 1);
	printf("bit 8: %d\n", (y >> 7) & 1);
	printf("bit 9: %d\n", (y >> 8) & 1);
	printf("bit10: %d\n", (y >> 9) & 1);

	
}
