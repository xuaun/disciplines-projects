
#include <stdio.h>
#include <stdlib.h>	//para memoria heap
						//funcoes "malloc()" e "free()"

double busca(int mem, int P, int x, int y, int* real_map, int* posRec){
	//teste:
	//printf("\tantigo(f2):\nmem: %d\nP: %d\n(x,y): (%d,%d)\n", mem, P, x, y);
	
	//usar mem para acessar memoria heap
	
	int i, j, map[9][9];
	
	//printf("map:\n");
	
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			map[i][j] = real_map[(i*9)+j];
			//printf("%d ", map[i][j]);
		}
		//printf("\n");
	}
	
	printf("\n");
	
	double som = 0.0;
	int N = (mem+1);
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
				//if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
				//	N--;
				//}
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
				//if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
				//	N--;
				//}
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
				//if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
				//	N--;
				//}
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
				//if ((x==posRec[(mem*2)])&&(y==posRec[(mem*2)+1])){
				//	N--;
				//}
			}else{
				vert = 0;
				hor = 0;
			}
		}if (N==0){
			som=tile;
			printf("chao: %d\n", tile);
		}
	}
	
	som = som/P;
	
	return som;
}

double exploracao(int N, int P, int* pos, int* map, int* posRec){
	double E = 0.0;
	int i;
	
	//teste
	//printf("\tantigo(f1)\nE: %lf\nN: %d\nP: %d\n", E, N, P);
	
	for (i=0; i<N; i++){
		//funcao para Ei->j?
		E+= busca(i, P, *pos, *(pos+1), map, posRec);
		printf("\tfinal(f1):\nE[%d]: %lf\n", i, E);
	}
	E *= 1/(double)N;
	//printf("E: %lf\n", E);
	
	return E;
}

int main(int argc, char* argv[]){
	/*
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
	*/
	int P = 59;
	int i, j;
	int map[9][9] = {{0,1,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1},{0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1,0}};
	
	//0 - L; 1 - C;
	int pos1[2] = {0, 0};
	int pos2[2] = {8, 8};
	
	//scanf("%d %d %d %d", &pos1[0], &pos1[1], &pos2[0], &pos2[0]);
	
	//ver com professor se eh melhor um valor fixo para vetor
	//(Lembrem-se de alocar na memória heap 
	//a variável para salvar as coordenadas dos recursos!.)
	int nRec;	//pelo que vi, alocacao dinamica
	
	//parece que terei que fazer algo tipo:
	//for... posRec = (int**) malloc(nRec*2*sizeof(int));...
	//parece que seria bacana usar depois, no final, o "free(posRec);"
	nRec = 2;
	//int posRec[2] = {4, 4};
	//map[4][4] = 2;
	//map[4][0] = 2;
	int *posRec;
	posRec = (int*) malloc(2 * nRec * sizeof(int));
	for (i=0; i<nRec; i++){
		scanf("%d %d", &posRec[(i*2)], &posRec[(i*2)+1]);
	}
	//printf("a");
	map[posRec[0]][posRec[1]] = 2;
	map[posRec[2]][posRec[3]] = 2;
	//printf("b");
	
	//scanf("%d", &nRec);
	
	/*
	for (i=0; i<nRec; i++){
		scanf("%d %d", &posRec[i][0], &posRec[i][1]);
		map[posRec[i][0]][posRec[i][1]]=2;
	}
	*/
	
	//testezão:
	
	for (i=0; i<9; i++){
		for (j=0; j<9; j++){
			//printf("%d ", map[i][j]);
		}
		//printf("\n");
	}
	//printf("P: %d\nJ1: %d %d\nJ2: %d %d\nRec: %d\n", P, pos1[0], pos1[1], pos2[0], pos2[1], nRec);
	
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
			E[0] = exploracao(nRec, P, pos1, *map, posRec); //colocar parametros
		}else{
			E[1] = exploracao(nRec, P, pos2, *map, posRec); //colocar parametros 
		}
	}
	
	//teste:
	printf("\nResultados:\n");
	
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
	
	return 0;
}

//https://pt.slideshare.net/adrianots/alocao-dinmica-de-memria
