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
	int n_friends;
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

	// TODO: controlar estouro de tamanho da string
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
	// inicializa numero de amigos como 0
	(*pnet)[pos].bff = NULL;	
	(*pnet)[pos].following = NULL;	
	(*pnet)[pos].n_friends = 0;	

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

void destroyProfile(Profile* pprof) {
	// librea o vetor de ponteiros para Profile
	if (pprof->following != NULL) {
		free(pprof->following);
	}
}

void destroyNetwork(Profile* pnet, int psize) {
	
	if (pnet != NULL) {
		// percorre todos os perfis da rede
		for (int j = 0; j < psize; j++) {
			destroyProfile(&pnet[j]);
		}	
		free(pnet);
	}
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

		printf("-amigos: \n");
		for (int i = 0; i < pnet[j].n_friends; i++) {
			// pnet[j].following[i] e' do tipo Profile*
			printf("\t%s\n", pnet[j].following[i]->username);
		}
		printf("----------------------------------\n");
	}
	printf("==============================\n");
}

void menuInicial() {
	printf("1 - Cadastra Perfil\n");
	printf("2 - Lista Perfis\n");
	printf("3 - Define BFF\n");
	printf("4 - Adiciona Amigos\n");
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

	// TODO: desenvolver algum tipo de conrole para isso
	// usuario esta tentando definir ele mesmo como bff
	//if (p2 == p1) {
	//	printf("Voce tem certeza?");	
	//}

	printf("Voce definiu seu bff (%s) com sucesso\n", pnet[p2].name);

	// armazena o endereco do bff no perfil
	pnet[p1].bff = &pnet[p2];

	//pnet[p1].bff = pnet+p2;

	return 1;
}

int addFriends(Profile* pnet, int psize) {
	if (pnet == NULL) {
		printf("Rede vazia\n");
		return ERROR_EMPTY;
	}
		
	printf("\n==================================\n");
	printf("Adiciona amigos\n");
	printf("Informe usuario: ");
	char user[16];
	fgets(user, 16, stdin);
	int ss = strlen(user);
	user[ss-1] = '\0'; // adiciona \0 para garantir a condicao de string

	int u1 = searchProfile(pnet, psize, user);
	printf("%s, adicione amigos informando os usuarios abaixo, ou deixe em branco para finalizar\n", pnet[u1].name);

	char friend[16]; // busca usuario para seguir/adicionar amigo
	do {
		printf("username a adicionar: ");
		fgets(friend,16,stdin);
		ss = strlen(friend);
		friend[ss-1] = '\0';
		// retorna a posicao no vetor de perfis (rede)
		int uf = searchProfile(pnet, psize, friend);

		// TODO: verifica se usuario encontrado ja esta na lista
		//	 de amigos, i.e. o vetor 'following'

		// verifica se usuario foi encontrado
		if (uf >= 0) {
			Profile* friend_address = &pnet[uf];
			// incrementa numero de amigos e armazena na
			// variavel n_frs
			int n_frs = ++(pnet[u1].n_friends);
			pnet[u1].following = realloc(pnet[u1].following, n_frs*sizeof(Profile*));
			pnet[u1].following[n_frs-1] = friend_address;
		} else {
			printf("**usuario nao encontrado\n");
		}

	} while (ss > 1);

}

void saveNetwork(Profile* pnet, int psize) {

	// arquivo binario
	FILE* fn = fopen("network.moa", "w+");
		
	for (int j = 0; j < psize; j++) {
		printf("Salvando usuario: %s\n", pnet[j].username);
		// escreve cada campo da struct
		fwrite(&pnet[j].username, sizeof(char), 16, fn);
		fwrite(&pnet[j].name, sizeof(char), 25, fn);
		fwrite(&pnet[j].n_friends, sizeof(int), 1, fn);
		int n_frs = pnet[j].n_friends;
		if (n_frs > 0) printf("Amigos: ");
		for (int i = 0; i < n_frs; i++) {
			// pega a posicao do amigo usando subtracao
			// com relacao ao primeiro elemento do vetor
			// x0A4 posicao atual
			// x004 primeira posicao do vetor
			// pos = x0A4 - x004  sera o indice do amigo
			int pos = (pnet[j].following[i])-pnet;
			printf("pos: %d, username: %s\n", pos, pnet[j].following[i]->username);
			// salva a posicao
			fwrite(&pos, sizeof(int), 1, fn);		
		}
		printf("\n");	
	}
	fclose(fn);
}

void loadNetwork(Profile** pnet, int* psize) {

	// arquivo binario
	FILE* fn = fopen("network.moa", "r+");

	if (fn == NULL) return; // TODO: melhorar o tratamento desse erro

	while (!feof(fn)) {
		Profile p;
		// le do arquivo cada campo da struct
		fread(&p.username, sizeof(char), 16, fn);
		fread(&p.name, sizeof(char), 25, fn);
		fread(&p.n_friends, sizeof(int), 1, fn);
		printf("Usuario: %s, nome: %s\n", p.username, p.name);
		int n_frs = p.n_friends;
		if (n_frs > 0) printf("Amigos:\n");
		for (int i = 0; i < n_frs; i++) {
			int pos;
			fread(&pos, sizeof(int), 1, fn);
			printf("\t%d\n", pos);
		}
		printf("\n");	
	}
	fclose(fn);
	
	// TODO: tentem remontar a rede com base na leitura do arquivo
}


int main (int argc, char* argv[]) {

	// vetor de perfis
	Profile* net = NULL; // ninguem

	int current_size = 0;

	// tenta carregar a rede
	loadNetwork(&net, &current_size);

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

			case 4: addFriends(net, current_size);
				break;

		}
	} while (opt != 0);

	// TODO: salvar no disco (deixar por ultimo)
	saveNetwork(net, current_size);

	// libera toda a memoria principal utilizada
	destroyNetwork(net, current_size);
	
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

