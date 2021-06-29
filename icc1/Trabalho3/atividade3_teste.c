/*
	A distribuição de recursos e posicionamento das bases iniciais de jogadores em jogos do
gênero estratégia em tempo real -do inglês, real-time strategy (RTS)- é um problema
muito relevante para os desenvolvedores. É preciso garantir uma distribuição justa de
recursos para ambos os jogadores para que o jogo seja equilibrado e mais desafiador para
ambos.
input: map[9][9] //mapa que ocorre o jogo
0- transponivel
1- INtransponivel
(seguindo o sistema L, C): linha a linha, da esquerda para a direita: (0,0), (0,1), (0,2)...

transponível
    adjetivo de dois gêneros
    que se pode transpor.

transpor
verbo
    1.
    transitivo direto
    passar além de, deixar para trás; ultrapassar.
    "t. vales, montanhas"

input: pos1: posicao do jogador 1
input: pos2: posicao do jogador 2
input: posRec: nRec: n recursos diferentes nas posicoes posRec
* (Lembrem-se de alocar na memória heap 
* a variável para salvar as coordenadas dos recursos!.)

Calcular valor de exploracao entre a base de cada jogador e 
cada elemento de recurso no mapa:
Ei(Sn)=(1/N-1)*(somatoria      (Ei→j/P);
				N   j=1 (j!=i)
* N: número de recursos somado de 1 (a base do jogador)-(elementos de referencia)
* P: número de células transponíveis em map
* Ei→j é a cobertura do mapa quando um algoritmo de flood-fill
de quatro direções é aplicado iniciando-se do elemento i e 
parando quando o elemento j foi encontrado, ou seja, o tanto
de células visitadas pelo algoritmo durante a trajetória 
(contar a célula da base e do recurso como parte do resultado).

Calcular valor E1 e E2, respectivamente, separadamente 
partindo de ambas as bases.

Lembre-se de não colocar a base oposta no conjunto de 
elementos a serem explorados!

* O algoritmo de flood-fill mencionado é explicado no link
* do rodapé, que também contém um pseudo-código do mesmo.Lembrem-se 
* de utilizar a ordem de visita do pseudo-código do link: Sul, 
* Norte, Oeste e Leste

	Note que quanto menor o valor de E, menos o jogador terá de explorar para encontrar
recursos e, portanto, possui vantagem.

	Ao final, você deverá comparar ambos os valores e verificar se um dos jogadores possui
vantagem em relação ao outro. Para evitar erros de cálculo com ponto flutuante, você
deverá considerar que a diferença entre os valores E1 e E2 só será significativa se o valor
absoluto da diferença for maior ou igual que 0.001. Caso contrário, você deverá
considerar os valores como iguais.

	Entrada

Portanto, seu programa deverá ler 100 inteiros, com o conteúdo de cada célula da matriz,
que pode receber os valores 0 ou 1:
• map(0,0)
• map(0,1)
• map(0,2)
• ...
• map(8,7)
• map(8,8)
Em seguida, ler 4 inteiros, sendo cada par as coordenadas L e C, respectivamente, de
cada jogador
• pos1L
• pos1C
• pos2L
• pos2C
O número de recursos dever ser lido, seguido pelas coordenadas L e C de cada recurso.
• nRec
• posRec[1]L
• posRec[1]C
• posRec[2]L
• ...
• posRec[nRec-1]C
• posRec[nRec]L
• posRec[nRec]C
No exemplo a seguir, a matriz foi reduzida para 5x5, para facilitar a visualização:

3

0 0 0 0 0
0 1 1 1 1
0 0 0 0 0
0 0 0 0 0
0 1 1 1 1
0 3
3 3
2
0 0
0 4

	Saída

	Seu programa deverá imprimir como saída, separado por linhas, os valores de E1, E2
(ponto flutuante) e uma mensagem identificando se o mapa está balanceado ou algum
jogador tem vantagem. Caso seja balanceado:
	• O mapa eh balanceado \n

	Caso contrário, dizer qual dos dois jogadores (p = 1 ou p = 2) tem a vantagem:
	• O jogador p possui vantagem\n

	Exemplo:
	2.3\n
	1.25\n
	O jogador 2 possui vantagem\n

Note os símbolos \n denotando uma quebra de linha na função printf()


Exemplo
Para a entrada:
0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0
0 0
8 8
1
4 4

4

A saída será:
0.152542
0.152542
O mapa eh balanceado

*/

#include <stdio.h>
//#include <stdlib.h>	//para memoria heap
						//funcoes "malloc()" e "free()"

double busca(int mem, int P, int x, int y, int* real_map){
	//usar mem para acessar memoria heap
	
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
	
	while (som==0){
		if (vert == 0){
			if ((map[x+1][y]!=1)&&((x+1)<9)){
				map[x][y]=1;
				x+= 1;
				tile++;
				//Isso serve para enquanto n sei memoria heap...
				//se soubesse: x==mem*heap && y==mem*(heap+1)
				if (map[x][y] == 2){
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
				//Isso serve para enquanto n sei memoria heap...
				if (map[x][y] == 2){
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
				//Isso serve para enquanto n sei memoria heap...
				if (map[x][y] == 2){
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
				//Isso serve para enquanto n sei memoria heap...
				if (map[x][y] == 2){
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

double exploracao(int N, int P, int* pos, int* map){
	double E = 0.0;
	int i;
	
	for (i=0; i<N; i++){
		//funcao para Ei->j?
		E+= busca(i, P, *pos, *(pos+1), map);
	}
	E *= 1/(double)N;
	
	return E;
}

int main(int argc, char* argv[]){
	int map[9][9], i, j;
	int P = 0;
	
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			scanf("%d", &map[i][j]);
			//receber 0 (pode passar) e 1 (nao pode)
			if (map[i][j]==0){
				P++;
			}
		}
	}
	
	//0 - L; 1 - C;
	int pos1[2], pos2[2];
	
	scanf("%d %d %d %d", &pos1[0], &pos1[1], &pos2[0], &pos2[0]);
	
	//ver com professor se eh melhor um valor fixo para vetor
	//(Lembrem-se de alocar na memória heap 
	//a variável para salvar as coordenadas dos recursos!.)
	int nRec, posRec[nRec][2];	//pelo que vi, alocacao dinamica
	
	//parece que terei que fazer algo tipo:
	//for... posRec = (int**) malloc(nRec*2*sizeof(int));...
	//parece que seria bacana usar depois, no final, o "free(posRec);"
	scanf("%d", &nRec);
	for (i=0; i<nRec; i++){
		scanf("%d %d", &posRec[i][0], &posRec[i][1]);
	}
	
	//Calcular E(0 e 1)
	
	//Lembre-se de não colocar a base oposta no conjunto de 
	//elementos a serem explorados!
	
	//E< = vantagem
	
	/*
	Para evitar erros de cálculo com ponto flutuante, você
	deverá considerar que a diferença entre os valores E1 e E2 
	só será significativa se o valor
	absoluto da diferença for maior ou igual que 0.001. Caso
	contrário, você deverá
	considerar os valores como iguais.
	*/
	double E[2];
	for (i=0; i<2; i++){
		if (i==0){
			E[0] = exploracao(nRec, P, pos1, *map); //colocar parametros
		}else{
			E[1] = exploracao(nRec, P, pos2, *map); //colocar parametros 
		}
	}
	
	printf("%f\n%f\n", E[0], E[1]);
	
	//como margem tem que ser de 0.001:
	//if ((int)(E[0]*100))>(int)(E[1]*100))){...
	if (E[0] < E[1]){
		printf("O jogador 1 possui vantagem\n");
	}else if( E[0] > E[1]){
		printf("O jogador 2 possui vantagem\n");
	}else{
		printf("O mapa eh balanceado\n");
	}
	
	return 0;
}

//https://pt.slideshare.net/adrianots/alocao-dinmica-de-memria
