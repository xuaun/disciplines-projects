#include <stdio.h>
#include <stdlib.h>




int main (int argc, char* argv[]) {

	FILE* fp;

	// fp = fopen("meuarquivo.txt", "w"); // abre arquivo e sobrescreve se existir
	fp = fopen("meuarquivo.txt", "r+"); // abre arquivo e se existir posiciona o ponteiro no final do arquivo
	if (fp == NULL) {
		printf("Falha ao abrir o arquivo\n\n");
		return -1;
	}

	// arquivo texto - gravar strings a.k.a vetor de chars
	
	fprintf(fp, "Numeros\n");
	
	// vai para o final do arquivo (end) e move 2 bytes para tras
	fseek(fp, -5L, SEEK_END);

	// a partir da posicao atual (current), move 3 bytes para frente
	fseek(fp, 3L, SEEK_CUR);

	int num = 1;
	scanf("%d", &num);
	while (num != 0) {
		fprintf(fp, "%d\n", num);
		scanf("%d", &num);
	}

	fclose(fp);

	return 0;
}
