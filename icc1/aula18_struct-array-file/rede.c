/* Programa que implementa uma rede social simples
	Exemplo por: Moacir A Ponti 2018 - ICMC/USP
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct myprofile Profile;

struct myprofile {
	char username[16];
	char name[25];
	Profile* bff;
};

void createProfile(Profile** pnet) {
	// static, e' inicializada so uma vez	
	// nao e' empilhada, existe uma regiao da memoria para var.static
	static int network_size = 0;

	// incrementa tamanho da rede
	network_size++;

	// realoca dinamicamente
	// se ponteiro == NULL, realloc e' igual a malloc
	*pnet = (Profile *) realloc(*pnet, sizeof(Profile)*network_size);	 
	int pos = network_size-1; // posicao do perfil criado 
		
	// getline -> aloca espaco na heap, e le string
	// fgets   -> le string ja alocada (na heap ou stack)

	// agora usuario entra com os valores de seu perfil
	printf("username: ");
	// ler a string 'username' referente ao perfil criado
	fgets((*pnet)[pos].username, 16, stdin);

	printf("name: ");
	// ler a string 'name' referente ao perfil criado
	fgets((*pnet)[pos].name, 25, stdin);
	
	// significados do uso dos operadores * e []
	// *(pnet+pos) <==> pnet[pos]

	//  variavel	tipo
	//   pnet 	Profile**
	// *(pnet+0)	Profile* 

	// (*pnet)[0] <=> *((*pnet)+0)
	// (*pnet) -> acessa o array de Perfis
	//
	// (*pnet)[pos] acessa a struct Profile
	
}

void destroyNetwork(Profile* pnet) {
	free(pnet);
}


int main (int argc, char* argv[]) {

	// vetor de perfis
	Profile* net = NULL; // ninguem

	createProfile(&net);

	printf("Username: %s\nName: %s\n", net[0].username, net[0].name);

	// TODO: altere colocando um for para cadastrar varios perfis
	// veja se funciona

	// TODO: isso vai funcionar??? 
	// checar com valgrind e com a sua consciencia
	destroyNetwork(net);
	
	return 0;
}

