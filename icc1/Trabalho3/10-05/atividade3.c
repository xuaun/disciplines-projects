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
#include <stdlib.h>	    //usado para memoria heap

/*
	Funcao que calcula quanto o jogador tera que andar para
chegar nos recursos utilizando o algoritmo de flood-fill.
*/
double busca(int mem, int P, int x, int y, int* real_map, int* posRec){
	int i, j, map[9][9];
	
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			map[i][j] = real_map[(i*9)+j];
		}
	}
	
	double som = 0.0;
	int N = 1;
	int vert = 0;
	int hor = 0;
	int tile = 1;
	
	while (som==0.0){
		if (vert == 0){
			if ((map[x+1][y]!=1)&&((x+1)<9)){
				map[x][y]=1;
				x+= 1;
				tile++;
				if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
					N--;
				}
			}else{
				vert = 1;
			}
		}else if (vert == 1){
			if ((map[x-1][y]!=1)&&((x-1)>=0)){
				map[x][y]=1;
				x-=1;
				tile++;
				if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
					N--;
				}
			}else{
				vert = -1;
			}
		}else if (hor == 0){
			if ((map[x][y-1]!=1)&&((y-1)>=0)){
				map[x][y]=1;
				y-= 1;
				tile++;
				if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
					N--;
				}
			}else{
				hor = 1;
			}
		}else{
			if ((map[x][y+1]!=1)&&((y+1)<9)){
				map[x][y]=1;
				y+= 1;
				tile++;
				if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
					N--;
				}
			}else{
				vert = 0;
				hor = 0;
			}
		}if (N==0){
			som=tile;
		}
	}
	
	som = som/P;
	
	return som;
}

/*
	Funcao que calcula E (valor de exploracao).
*/
double exploracao(int N, int P, int* pos, int* map, int* posRec){
	double E = 0.0;
	int i;
	
	//trecho que realiza a somatoria
	for (i=0; i<N; i++){
		E+= busca(i, P, *pos, *(pos+1), map, posRec);
	}
	//a multiplicacao que acompanha a somatoria
	E *= 1/(double)N;
	
	return E;
}

int main(int argc, char* argv[]){
	int map[9][9], i, j;
	int P = 0;
	
	//receber mapa do usuario
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			scanf("%d", &map[i][j]);
			//receber 0 (pode passar) e 1 (nao pode)
			if (map[i][j]==0){
				P++;
			}
		}
	}
	
	//[0] : L; [1] : C;
	int pos1[2], pos2[2];
	
	scanf("%d %d %d %d", &pos1[0], &pos1[1], &pos2[0], &pos2[0]);
	
	//salvando na memoria heap o posRec
	int nRec;
	scanf("%d", &nRec);
	int* posRec = (int*) malloc(nRec * 2 * sizeof(int));
	for (i=0; i<nRec; i++){
		scanf("%d %d", &posRec[(i*2)], &posRec[(i*2)+1]);
	}
	
	//Calcular E(0, j1, e 1, j2)
	//E< = vantagem
	
	/*
	Para evitar erros de cálculo com ponto flutuante, considerar que 
	a diferença entre os valores E1 e E2 só será significativa se o 
	valor absoluto da diferença for maior ou igual que 0.001. Caso
	contrário, você deverá considerar os valores como iguais.
	*/
	double E[2];
	for (i=0; i<2; i++){
		if (i==0){
			E[0] = exploracao(nRec, P, pos1, *map, posRec);
		}else{
			E[1] = exploracao(nRec, P, pos2, *map, posRec);
		}
	}
	
	printf("%f\n%f\n", E[0], E[1]);
	
	//como margem tem que ser de 0.001:
	//if ((int)(E[0]*100))>(int)(E[1]*100))){...
	if ((int)(E[0]*100) < (int)(E[1]*100)){
		printf("O jogador 1 possui vantagem\n");
	}else if ((int)(E[0]*100) > (int)(E[1]*100)){
		printf("O jogador 2 possui vantagem\n");
	}else{
		printf("O mapa eh balanceado\n");
	}
	
	free (posRec);
	
	return 0;
}
