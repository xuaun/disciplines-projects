/*
Marco tem vários trabalhos armazenados num arquivo. Cada trabalho possui um identificador (id), 
um título e uma descrição curta com a qual ele pode procurar o que precisa. Ele quer conseguir 
encontrar todos os trabalhos segundo uma expressão chave. Assim, ele pede para você desenvolver 
um programa em C que permita executar essa busca. O formato de saída deve conter o id, o título 
e a quantidade de ocorrências da expressão chave para cada trabalho recuperado.

Alguns detalhes técnicos são descritos a seguir:

Para a entrada dos dados, a primeira linha da entrada conterá "n", que representa o número de 
trabalhos a serem avaliados. A segunda linha conterá a expressão chave a buscar. As 3n linhas 
seguintes conterão o identificador, o título a descrição curta de cada um dos "n" trabalhos.
Use uma estrutura para representar cada trabalho.
Deve existir uma função que permita contar a quantidade de ocorrências da expressão na 
descrição do trabalho
O formato de saída deve ser < id >\t< título >\t< númerodeocorrências >
A ordem de impressão vem dada pela ordem em que cada trabalho foi lido.
Entrada
3
meio ambiente
1
mateus narra sobre o meio ambiente
no dia 5 de junho e celebrado o dia mundial do meio ambiente.
2
mateus e thire apresentam selfie em joao pessoa
os atores mateus solano e miguel thire apresentam a peca selfie em joao pessoa, neste domingo (20).
3
mateus solano e miguel thire encenam a peca selfie no teatro polytheama
a peca selfie será a atracao deste sabado (28) no teatro polytheama, as 21h, em jundiai (sp).
Saída
1    mateus narra sobre o meio ambiente  1
*/

//strcpy (recebe, passa)
//getline (var, tam, stdin)
//fgets (var, tam, stdin)
//strlen (str) -> #include<string.h>

#include <stdio.h>

char* expressao(){
	//tam 200;
	return 
}

struct trabalho_itens[
	int id = 0;
	char titulo[200];
	char descricao[200];
};

int main(int argc, char* argv[]){
	int n;
	scanf("%d", &n);
	
	char chave[200];
	fgets(chave, 200, stdin);
	
	struct trabalho_itens trabalho[20];
	int ocorrencias[20]; //--- anotar numero de ocorrencias por arquivo
	for (i=0; i<20; i++){
		ocorrencias[i] = 0;
	}
	
	int i;
	for (i=0; i<n; i++){
		scanf("%d", &trabalho[i].id);
		fgets(trabalho[i].titulo, 200, stdin);
		fgets(trabalho[i].descricao, 200, stdin);
	}
	
	//comparacao --- se tiver ocorrencia, ocorrencia[i]++
	
	for (i=0; i<n; i++){
		if (ocorrencias[i] != 0){
			printf("%d\t%s\t%s\n", trabalho[i].id, trabalho[i].titulo, trabalho[i].descricao);
		}
	}
	
	return 0;
}