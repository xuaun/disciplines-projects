#include <stdio.h>

int main (int argc, char* argv[]) {

	/*
	int n1, n2, n3;

	n1 = 4;
	n2 = n1	+ 1;
	n3 = n2 + n1;

	// encontrar a soma dos valores
	int soma;

	soma = n1+n2+n3;	
	*/

	// array ou arranjo -> estrutura na memoria
	// uma sequencia de valores de um mesmo tipo
	int Ns[3];

	// o identificador de um array, ex. Ns
	// corresponde a um ENDERECO na memoria e nao a um valor
	// Ns -> e' relativo ao PRIMEIRO ENDERECO do bloco alocado

	// poderia fazer isso:
	int* p;
	p = Ns;

	// portanto para armazenar algo em Ns preciso usar operador *
	*Ns = 4;
	printf("Deve aparecer o valor 4 aqui: %d\n", *Ns);
	printf("Deve aparecer um endereco aqui: %p\n", Ns);

	*(Ns+1) = 1;
	printf("Deve aparecer o valor 1 aqui: %d\n", *(Ns+1));
	printf("Deve aparecer um endereco aqui: %p\n", Ns+1);

	*(Ns+2) = 7;
	printf("Deve aparecer o valor 7 aqui: %d\n", *(Ns+2));
	printf("Deve aparecer um endereco aqui: %p\n", Ns+2);

	Ns[0] = 4;
	Ns[1] = 1;
	2[Ns] = 7;
	printf("Deve aparecer o valor 7 aqui: %d\n", 2[Ns]);

	// quero saber o endereco de Ns[2]
	// so que Ns[2] => *(Ns+2)
	// entao para pegar o endereco eu preciso usar:
	// &Ns[2] ou &(*(Ns+2))
	printf("Deve aparecer um endereco aqui: %p\n", &(Ns[2]));

	
	
	return 0;


}
