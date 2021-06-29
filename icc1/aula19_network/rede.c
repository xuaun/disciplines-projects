/* Programa que implementa uma rede social simples
	Exemplo por: Moacir A Ponti 2018 - ICMC/USP
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_NOTFOUND -1
#define ERROR_EMPTY -2

typedef struct myprofile Profile;

struct myprofile {
	char username[16];
	char name[25];
	Profile* bff;
	Profile** following;
};

// TODO: listar aqui todas as funcoes do programa, e move-las para depois
//	 da funcao main()
int searchProfile(Profile* pnet, int size, char pusername[16]); 


int createProfile(Profile** pnet) {
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

	printf("=================================\n");
	printf("Entre com os dados do novo perfil\n");
	// agora usuario entra com os valores de seu perfil
	printf("-username: ");
	// ler a string 'username' referente ao perfil criado
	fgets((*pnet)[pos].username, 16, stdin);
	int ss = strlen((*pnet)[pos].username);
	(*pnet)[pos].username[ss-1] = '\0';	

	// TODO: se o nome do usuario ja existir, pedir um novo
	// dica: se usar a funcao searchProfile(), tenho que mudar a ordem
	// searchProfile(*pnet, network_size, "teste");

	printf("-name: ");
	// ler a string 'name' referente ao perfil criado
	fgets((*pnet)[pos].name, 25, stdin);
	ss = strlen((*pnet)[pos].name);
	(*pnet)[pos].name[ss-1] = '\0';	
	
	// inicializa bff e following com nulo
	(*pnet)[pos].bff = NULL;	
	(*pnet)[pos].following = NULL;	

	// significados do uso dos operadores * e []
	// *(pnet+pos) <==> pnet[pos]

	//  variavel	tipo
	//   pnet 	Profile**
	// *(pnet+0)	Profile* 

	// (*pnet)[0] <=> *((*pnet)+0)
	// (*pnet) -> acessa o array de Perfis
	//
	// (*pnet)[pos] acessa a struct Profile

	printf("=================================\n\n");
	return network_size;	
}

void destroyNetwork(Profile* pnet) {
	free(pnet);
}

void listNetwork(Profile* pnet, int size) {

	if (pnet == NULL || size == 0) {
		printf("Rede vazia\n");
		return;
	}

	printf("==============================\n");
	for (int j = 0; j < size; j++) {
		printf("-username: %s\n", pnet[j].username);	
		printf("-name: %s\n", pnet[j].name);	
		//printf("-bff : %p\n", pnet[j].bff); // old
	
		if (pnet[j].bff != NULL) {
			// TODO: ver se funciona e porque
			// Profile bff = *(pnet[j].bff);	
			// printf("-bff : %s\n", bff.name);
	
			printf("-bff (*) : %s\n", (*pnet[j].bff).name); 
			printf("-bff (->): %s\n", pnet[j].bff->name); 
		}

		printf("----------------------------------\n");
	}
	printf("==============================\n");
}

void menuInicial() {
	printf("1 - Cadastra Perfil\n");
	printf("2 - Lista Perfis\n");
	printf("3 - Define BFF\n");
	printf("0 - Sair\n");
	printf("Opcao: ");
}

int setBFF(Profile* pnet, int size) {
	if (pnet == NULL || size == 0) {
		printf("Rede vazia\n");
		return 1;
	}
	printf("==============================\n");
	printf("Define BFF.\nSeu usuario: ");

	// pede para o usuario digitar o primeiro perfil
	char user1[16];
	fgets(user1, 16, stdin);
	int ss = strlen(user1);
	user1[ss-1] = '\0';
	
	// verifica se existe e retorna a posicao
	int p1 = searchProfile(pnet, size, user1);
	if (p1 < 0) return p1; // caso nao tenha sucesso, retorna um erro
	
	printf("Ola' %s, digite o usuario de seu bff: ", pnet[p1].name);

	// usuario entra com o username do bff
	char user2[16];
	fgets(user2, 16, stdin);
	ss = strlen(user2);
	user2[ss-1] = '\0';
	
	// verifica se existe e retorna a posicao
	int p2 = searchProfile(pnet, size, user2);
	if (p2 < 0) return p2; // caso nao tenha sucesso, retorna um erro

	printf("Voce definiu seu bff (%s) com sucesso\n", pnet[p2].name);

	// armazena o endereco do bff no perfil
	pnet[p1].bff = &pnet[p2];

	//pnet[p1].bff = pnet+p2;

	return 1;
}


int main (int argc, char* argv[]) {

	// vetor de perfis
	Profile* net = NULL; // ninguem
	
	int current_size = 0;

	int opt = 0;
	do {
		menuInicial();
		scanf("%d", &opt);
		getchar(); 
		switch (opt) {
			// cadastra novo perfil
			case 1: current_size = createProfile(&net);
				break;

			// lista perfis
			case 2: listNetwork(net, current_size);
				break;

			// atribui BFF a um perfil
			case 3: setBFF(net, current_size);
				break;
			

		}
	} while (opt != 0);

	// TODO: salvar no disco (deixar por ultimo)

	destroyNetwork(net);
	
	return 0;
}


int searchProfile(Profile* pnet, int size, char pusername[16]) {
	if (pnet == NULL || size == 0) {
		return ERROR_EMPTY;
	}
	for (int j = 0; j < size; j++) {
		// string compare
		// strcmp retorna 0 se forem iguais em todos os caracteres
		// strcmp retorna <0 se a primeira for menor do que segunda
		// strcmp retorna >0 se a primeira for maior do que segunda
		if (!strcmp(pusername, pnet[j].username)) {
			// encontrou o username igual, retorna a posicao
			return j;
		}
	}
	return ERROR_NOTFOUND;

}

