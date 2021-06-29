#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// int L; // variavel global - evitar 

double simula_moeda(int N) {
	int k = 1;
	int cont_coroa = 0;
	while (k <= N) {
		// sorteia um valor e comprime para o intervalo [0,1]
		int moeda = rand()%2;
		cont_coroa = cont_coroa + moeda;
		k = k + 1;
	}
	double pc_coroa = cont_coroa/(float)N;

	return pc_coroa * 100.0;
}

int main (void) {

	srand( time(NULL)  );
	/* // exemplo de uso da funcao rand()
	int num = 0;
	num = rand();
	printf("%d\n", num);
	*/

	int L; // variavel local - escopo da funcao main()
	// usuario informa o numero de lancamentos da moeda
	scanf("%d", &L);

	// uma funcao simula 'L' lancamentos de moeda, cara=0, coroa=1
	// e retorna a porcentagem de vezes que deu coroa
	double porc_coroa, porc_cara;
	porc_coroa = simula_moeda(L);
	porc_cara  = 100-porc_coroa;
 
	printf("Caras : %.2lf%%\n", porc_cara);
	printf("Coroas: %.2lf%%\n", porc_coroa);
	// imprime na tela a porcentagem de caras e coroas obtidas

	return 0;	
}
