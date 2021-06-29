/* Programa realizado como trabalho para a disciplina 
"SCC0221 - Introdução à Ciência da Computação I - 2018".

Programa que calcula se um mapa para jogo do gênero RTS 
(real-time strategy, estrategia em tempo real) tem uma boa
distribuicao de recursos e posicionamentos das bases iniciais
nesses jogos e aponta, caso nao esteja bem distribuido, qual
dos dois jogadores possui maior vantagem.

	Entradas:
	int map[9][9];
	int pos1 L/C;
	int pos2 L/C;
	int nRec;
	int posRec[nRec] L/C;
	
	* pos: posicao
	* L: linha
	* C: coluna
	* Rec: recursos
	* n: numero
	
	Saida:
	double E[1];
	double E[2];
	Qual dos jogadores possui vatagem/mapa balanceado
	
	* E: Valor que representa a vantagem (quanto menor, mais
	*    mais vantagem.

	João Víctor de Araujo Lima / LCE-USP 2018
*/

#include <stdio.h>
#include <stdlib.h>

/*	Funcao que calcula quanto o jogador tera que andar para
chegar nos recursos utilizando o algoritmo de flood-fill.
	Para isso, ele segue, preferencialmente, pelos caminhos na seguinte ordem: S - N - O - L, caso nenhuma dessas seja possivel, o jogador retorna uma posicao e tenta novamente.
	Variaveis_parametros:	Nx: posicao do recurso i em X
							Ny: posicao do recurso i em Y
							P: numero de blocos 0 no mapa
							x: posicao do jogador em X
							y: posicao do jogador em Y
							real_map: mapa do jogo
	
	Variaveis_locais:		i, j: para usar em lacos
							map: recebe real_map e recebe alteracoes
							som: valor que recebera a soma final
							caminho: vetor utilizado para voltar caso nao seja possivel proseguir em nenhum caminho
							aux: usado para auxiliar no vetor caminho
							dir: para saber qual direcao seguir (S, N, O, L, voltar)
							ver: verificacao para se chegou no recurso
				
*/
double busca(int Nx, int Ny, int P, int x, int y, int* real_map){
	int i, j, map[9][9];
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			map[i][j] = real_map[(i*9)+j];
		}
	}
	
	double som = 0.0;
	int caminho[81][2];
	int aux = 0;
	int tile = 1;
	int dir = 0;
	int ver = 0;
	
	//altera o valor da casa inicial para 1, assim o jogador nao pode voltar para ela "naturalmente"
	map[x][y] = 1;
	
	while (som==0.0){
		dir = 0;
		
		if (dir==0){	
			//SUL	
			if ((map[x+1][y]!=1)&&((x+1)<9)){
				caminho[aux][0] = x;
				caminho[aux][1] = y;
				aux++;
				tile++;
				x++;
				map[x][y] = 1;
				if ((Nx==x)&&(Ny==y)){
					ver = 1;
				}
			}else{
				dir++;
			}
		}if (dir==1){
			//NORTE
			if ((map[x-1][y]!=1)&&((x-1)>=0)){
				caminho[aux][0] = x;
				caminho[aux][1] = y;
				aux++;
				tile++;
				x--;
				map[x][y] = 1;
				if ((Nx==x)&&(Ny==y)){
					ver = 1;
				}
			}else{
				dir++;
			}
		}if (dir==2){
			//OESTE
			if ((map[x][y-1]!=1)&&((y-1)>=0)){
				caminho[aux][0] = x;
				caminho[aux][1] = y;
				aux++;
				tile++;
				y--;
				map[x][y] = 1;
				if ((Nx==x)&&(Ny==y)){
					ver = 1;
				}
			}else{
				dir++;
			}
		}if (dir==3){
			//LESTE
			if ((map[x][y+1]!=1)&&((y+1)<9)){
				caminho[aux][0] = x;
				caminho[aux][1] = y;
				aux++;
				tile++;
				y++;
				map[x][y] = 1;
				if ((Nx==x)&&(Ny==y)){
					ver = 1;
				}
			}else{
				dir++;
			}
		}if (dir==4){
			//voltar
			
			aux--;
			x = caminho[aux][0];
			y = caminho[aux][1];
		}
		if (ver!=0){
			som = tile/(double)P;
		}
	}
	return som;
}

/*	Funcao que calcula E (valor de exploracao).
	Variaveis_parametros:	N: numero de recursos
							posN: matriz que leva o endereco na memoria heap das posicoes dos recursos
							P: numero de blocos 0 no mapa
							pos: vetor que contem a posicao do jogador
							map: mapa do jogo
	
	Variaveis_locais:		E: para armazenar o valor de exploracao E
							i: para ser utilizada num laco
*/
double exploracao(int N, int** posN, int P, int* pos, int* map){
	double E = 0.0;
	int i;
	
	//Este for faz o papel da somatoria na formula
	for (i=0; i<N; i++){
		E += busca(posN[i][0], posN[i][1], P, *pos, *(pos+1), map);
	}
	E *= 1/(double)N;
	
	return E;
}

/*	Funcao que realiza a alocacao dinamica da matriz "posRec"
	Variaveis_parametros:	N: numero de recursos
	
	Variaveis_locais:		mat: matriz que recebera a alocacao dinamica
							i: usada em lacos
*/
int** aloca_matriz(int N){
	
	int** mat = NULL;
	int i;
	
	mat = (int**) calloc(N, sizeof(int*));
	for (i=0; i<N; i++){
		mat[i] = (int*) calloc(2, sizeof(int));
	}
	
	return mat;
}

/*	Funcao que realiza a liberacao da matriz "posRec" alocada dinamicamente
	Variaveis_parametros:	N: numero de recursos
							mat: matriz que sera deslocada
*/
void desloca_matriz(int N, int** mat){
	int i;
	for (i=0; i<N; i++){
		free(mat[i]);
	}
	free(mat);
}

/*	Funcao principal:

	Recebe os valores do mapa, as posicoes dos jogadores, o numero de recursos, as posicoes dos recursos e printa, no final, os valores de E e comenta se o mapa esta ou nao balanceado, caso sim, para qual jogador.
	
	Variaveis_locais:	map: matriz mapa do jogo, recebida pelo usuario
						i, j: variaveis usadas em lacos de repeticao
						P: variavel que lera o numero de 0 no mapa
						pos1, pos2: vetores que recebem as posicoes dos jogadores 1 e 2
						nRec: recebe o numero de recursos
						posRec: matriz que recebe as posicoes dos n recursos
						E: vetor que aponta os valores de exploracao dos jogadores 1 e 2
*/
int main (int agrc, char* argv[]){
	int map[9][9], i, j;
	int P = 0;
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			scanf("%d", &map[i][j]);
			if (map[i][j]==0){
				P++;
			}
		}
	}
	
	int pos1[2], pos2[2];
	scanf("%d %d %d %d", &pos1[0], &pos1[1], &pos2[0], &pos2[1]);
	
	int nRec;
	scanf("%d", &nRec);
	
	int** posRec = aloca_matriz(nRec);
	
	for (i=0; i<nRec; i++){
		scanf("%d %d", &posRec[i][0], &posRec[i][1]);
	}
	
	double E[2];
	for (i=0; i<2; i++){
		if (i==0){
			E[i] = exploracao(nRec, posRec, P, pos1, *map);
		}else{
			E[i] = exploracao(nRec, posRec, P, pos2, *map);
		}
	}
	
	desloca_matriz(nRec, posRec);
	
	printf("%f\n%f\n", E[0], E[1]);
	
	if (((int)(E[0]*100))<((int)(E[1]*100))){
		printf("O jogador 1 possui vantagem\n");
	}else if (((int)(E[0]*100))>((int)(E[1]*100))){
		printf("O jogador 2 possui vantagem\n");
	}else{
		printf("O mapa eh balanceado\n");
	}
	
	return 0;
}
