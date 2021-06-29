#include <stdio.h>

int main (int argc, char*argv[]) {

	// primeira variavel
	char a;
	a = 'X';

	// variavel que armazena um ENDERECO de char
	// (char*)
	char* p; 

	// armazeno o endereco da primeira variavel
	p = &a;
	
	printf("Endereco inicial: %p\n", p);

	printf("Conteudo no endereco: %c\n", *p); 

	int x = 1;
	// for, while
	while (x <= 10000) {
		p = p + 1;
		printf("%p : %c\n", p, *p); 
		x = x + 1;
	}
}
