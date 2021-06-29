#include <stdio.h>
#include <stdlib.h>

int analisaString(char *s, int imprime) {
	int i = 0;
	while (s[i] != '\n' && s[i] != '\0' && s[i] != '\r') {
		if (imprime) {
		   printf("%d - %c = %d\n", i, s[i], (int) s[i]);
		}
		i++;
	}
	s[i] = '\0';
	// retorna o tamanho da string (caracteres validos)
	return (i+1); 
}

// EXERCICIO: 1) fazer o codigo funcionar para leitura correta (opcional)
//	      2) dar opcao para cadastrar, sem perder os nomes anteriores
//	      3) fazer uma funcao que busque se um nome existe no arquivo


int main (int argc, char* argv[]) {

	FILE* fp;

	if (argc < 2) {
		printf("Informe 1 para escrever no arquivo ou 2 para ler\n");
		return -2;
	}
	int opcao = atoi(argv[1]);

 	// abre arquivo e posiciona o ponteiro no inicio
	// se nao existir, esse arquivo e' criado
	fp = fopen("nomes.txt", "r+");
	if (fp == NULL) {
		printf("Falha ao abrir o arquivo\n\n");
		return -1;
	}

	char* leitura = NULL;
	size_t bytesalocados = 0;

	if (opcao == 1) {
		getline(&leitura, &bytesalocados, stdin);
		int tam = analisaString(leitura, 0);

		fprintf(fp, "%d ", tam-1);
		fprintf(fp, "[%-50.120s]\n", leitura);

		getline(&leitura, &bytesalocados, stdin);
		tam = analisaString(leitura, 0);

		fprintf(fp, "%d ", tam-1);
		fprintf(fp, "[%-50.120s]\n", leitura);
	}

	if (opcao == 2) {
		int tamnome;
		// end of file
		while (!feof(fp)) {
			fscanf(fp, "%d", &tamnome); // le um inteiro
			fseek(fp, 0L, SEEK_CUR);
			getline(&leitura, &bytesalocados, fp); // le uma string
			printf("%d %s\n", tamnome, leitura);
		}
	}

	free(leitura);
	fclose(fp);

	return 0;
}
