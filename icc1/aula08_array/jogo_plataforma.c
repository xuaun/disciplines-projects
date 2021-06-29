#include <stdio.h>

int main (int argc, char* argv[]) {
	
	char fase1[10] = {'_','_','_','|','_',' ','_','_','_','*'};
	char fase2[10] = {'_','|','_','|',' ','_','_','_','_','*'};

	// 2 tipos de movimento: andar, nao gasta energia
	// 			 pular, com energia 1 por posicao

	// o personagem comeca com uma quantidade de energia X
	// cada vez que ele gasta energia, reduzo.
	// se a energia for menor que 0, o personagem morre.
	// o personagem tambem morre se cai em um buraco
	// se ele para antes de um cano, ele fica preso para sempre.	


	int E = 3;

	// inicia a fase
	int p = 0;
	char atual = fase1[p];
	while (atual != '*') {
		p++;
		atual = fase1[p]; // personagem olha para a proxima posicao
		printf("%c", atual);
		fflush(stdout); // faz com que os printfs sejam executados

		// pulo
		if (atual == '|') {
			E--;
			p++;
			atual = fase1[p];
		}

		if (E < 0) {
			printf("Game over\n");
			break;
		}

		if (atual == '|' || atual == ' ') {
			while (1);
		}
	}		
			
	printf("\n\n\n");
}
