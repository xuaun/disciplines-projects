/*3. Dados o número n de alunos de uma turma e suas notas da primeira prova, determinar a maior e
a menor nota obtidas por essa turma (Nota máxima = 100 e nota mínima = 0).*/

#include<stdio.h>

int main(){
	int n;
	int i;
	int nota;
	int maiornota = 0;
	int menornota = 100;
	int notatotal = 0;
	
	printf("Quantos alunos existem na turma?\n");
	scanf("%d", &n);
	printf("\n");
	
	for (i = 1; i <= n; i++){
		printf("Qual a nota do aluno %d?\n", i);
		scanf("%d", &nota);
		while (nota < 0 || nota > 100){
			printf("Digite novamente a nota do aluno %d (valores aceitos: entre 0 e 100)\n", i);
			scanf("%d", &nota);
		}
		if (nota > maiornota)
		maiornota = nota;
		else if (nota < menornota)
		menornota = nota;
		
		notatotal += nota;
	}
	printf("\nA media da turma foi %d, a maior nota foi %d e a menor nota foi %d.", notatotal / n, maiornota, menornota);
	
	return 0;
}
