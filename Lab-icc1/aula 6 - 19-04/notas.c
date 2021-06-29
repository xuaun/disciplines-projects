/*
Um professor quer conhecer qual é a distribuição das notas
em cada sede de uma escola. Para isto, ele pede ao Jorge que 
desenvolva um programa em C que, dado o número “n” de alunos 
de uma turma e as notas dos “n” alunos, e imprima a quantidade 
de alunos que obtiveram cada nota. As notas variam de 0 a 10, 
sempre em valores inteiros. Como você já aprendeu bastante na 
matéria, você fala para o Jorge que pode ajudar com esta tarefa.
Entrada

10
2
3
4
1
6
2
0
2
10
3

Saída

Nota 0: 1
Nota 1: 1
Nota 2: 3
Nota 3: 2
Nota 4: 1
Nota 5: 0
Nota 6: 1
Nota 7: 0
Nota 8: 0
Nota 9: 0
Nota 10: 1
 
*/
#include <stdio.h>

int main (int argc, char *argv[]){
	int alunos;
	int i;
	
	scanf("%d", &alunos);
	
	int notas[11] = {0};
	int temp;
	
	for(i=0; i<alunos; i++){
		scanf("%d", &temp);
		
		if((temp>=0)&&(temp<11)){
			if(temp == 0){
				notas[0]+=1;
			}else if(temp == 1){
				notas[1]+=1;
			}else if(temp == 2){
				notas[2]+=1;
			}else if(temp == 3){
				notas[3]+=1;
			}else if(temp == 4){
				notas[4]+=1;
			}else if(temp == 5){
				notas[5]+=1;
			}else if(temp == 6){
				notas[6]+=1;
			}else if(temp == 7){
				notas[7]+=1;
			}else if(temp == 8){
				notas[8]+=1;
			}else if(temp == 9){
				notas[9]+=1;
			}else if(temp == 10){
				notas[10]+=1;
			}
		}
	}
	
	for(i=0; i<11; i++){
		printf("Nota %d: %d\n", i, notas[i]);
	}
	
	return 0;
}
