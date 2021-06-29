/* Programa realizado como trabalho para a disciplina 
"SCC0221 - Introdução à Ciência da Computação I - 2018".

					--ARRUMAR--

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

/*	Roteiro para comentar structs/funcoes:

	Primeiro, breve comentario sobre a funcao, seu objetivo e principais passos;
	Segundo, listar "Variaveis_parametros" e "Variaveis_locais" e suas funcoes;
	
	!Alem disso, comentar pontos importantes das funcoes dentro das mesmas!

*/

#include <stdio.h>
#include <stdlib.h>

typedef
struct racionais {
	int n;
	int d;
} rac;

rac** aloca_matriz(int l, int c, rac** mat){
	mat = (rac**) calloc (l, sizeof(rac*));
	
	int i;
	for (i=0; i<l; i++){
		mat[i] = (rac*) calloc(c, sizeof(rac));
	}
	
	return mat;
}

void desaloca_matriz(int l, rac** mat){
	int i;
	for (i=0; i<l; i++) {
		free(mat[i]);
	}
	free(mat);
}

void recebe_matriz(rac** matriz, rac** temp_mat){
	int i, j, k=0, l;
	char tipo;
	
	for (l=0; l<2; l++){
		scanf(" %c", &tipo);
		
		if (tipo == 'p'){
			for (i=0; i<4; i++){
				scanf("%d %d", &temp_mat[0][i].n, &temp_mat[0][i].d);
			}
			for (i=0; i<4; i++){
				matriz[k][i].n = temp_mat[0][i].n;
				matriz[k][i].d = temp_mat[0][i].d;
			}
			k++;
		}else if (tipo == 'r'){
			for (i=0; i<2; i++){
				for (j=0; j<4; j++){
					scanf("%d %d", &temp_mat[i][j].n, &temp_mat[i][j].d);
				}
			}
			for (i=0; i<2; i++){
				for (j=0; j<4; j++){
					matriz[i][j].n = temp_mat[i][j].n;
					matriz[i][j].d = temp_mat[i][j].d;
				}
				k++;
			}
		}		
	}
}

void troca_vetor(rac** mat, int index, int c){
	rac** temp_mat = aloca_matriz(1, 4, temp_mat);
	int i;
	for (i=0; i<4; i++){
		temp_mat[0][i].n = mat[c][i].n;
		temp_mat[0][i].d = mat[c][i].d;
		mat[c][i].n = mat[index][i].n;
		mat[c][i].d = mat[index][i].d;
		mat[index][i].n = temp_mat[0][i].n;
		mat[index][i].d = temp_mat[0][i].d;
	}
	
	desaloca_matriz(1, temp_mat);
}

rac** corrigir_matriz(int l, int c, rac** mat, int index){
	if (mat[index][index].n != 0){
		return mat;
	}else {
		int i;
		for (i=(index+1); i<l; i++){
			if (mat[i][index].n != 0){
				troca_vetor(mat, index, i);
				return mat;
			}
		}
	}
}

rac mmc(rac x, rac y){
	int k = 2;
	int mmc = 1;
	int temp = x.d;
	
	while ((x.d!=1)||(y.d!=1)){
		if ((x.d%k==0)||(y.d%k==0)){
			mmc *= k;
			if ((x.d % k) == 0){
				x.d = x.d/k;
			}
			if ((y.d % k) == 0){
				y.d = y.d/k;
			}
		}else{
			k++;
		}
	}
	
	x.d = mmc;
	x.n *= mmc/temp;
	
	return x;
}

rac conta_struct(rac p, rac x, rac y, rac x1){
	y.n = p.d*y.n*x1.n;
	y.d = p.n*y.d*x1.d;
	
	if ((x.n!=0)||(y.n!=0)){
		x = mmc(x, y);
		y.n *= x.d/y.d;
	}
	
	x.n -= y.n;
	
	return x;
}

void modifica_matriz(rac** mat, int index, int l, int c){
	int i, j;
	rac pivo;
	pivo.n = mat[index][index].n;
	pivo.d = mat[index][index].d;
	printf("p.n=%d\np.d=%d\n", pivo.n, pivo.d);
	
	for (i=(index+1); i<l; i++){
		for (j=index; j<c; j++){
			mat[i][j] = conta_struct(pivo, mat[i][j], mat[index][j], mat[i][index]);
		}
	}
}

rac** escalonamento(rac** mat, int index, int l, int c){
	rac** mat_cor = mat;
	if (index != (l-1)){
		mat_cor = corrigir_matriz(l, c, mat_cor, index);

		modifica_matriz(mat_cor, index, l, c);
		
		return escalonamento(mat, (index+1), l, c);
		
	}else{
		return mat_cor;
	}
}

int main(int argc, char* argv[]){
	int l, c;
	scanf("%d %d", &l, &c);
	
	rac** matriz = aloca_matriz(l, c, matriz);
	
	rac** temp_mat = aloca_matriz(2, 4, temp_mat);
	
	recebe_matriz(matriz, temp_mat);

	desaloca_matriz(2, temp_mat);

	matriz = escalonamento(matriz, 0, l, c);
	
	if (matriz[(l-1)][(c-1)].n != 0){
		printf("nao\n");
	}else if ((matriz[(l-1)][(c-2)].n == 0)&&(matriz[(l-1)][(c-3)].n == 0)){
		printf("sim\n");
	}else{
		printf("nao\n");
	}
	
	int i, j;
	for (i=0; i<l; i++){
		printf("%d", matriz[i][0].n);
		if (matriz[i][0].d != 1){
			printf("/%d", matriz[i][0].d);
		}
		for (j=1; j<c; j++){
			printf("\t%d", matriz[i][j].n);
			if ((matriz[i][j].d != 1)&&(matriz[i][j].n!=0)){
				printf("/%d", matriz[i][j].d);
			}
		}
		printf("\n");
	}
	
	desaloca_matriz(l, matriz);
	
	return 0;
}
