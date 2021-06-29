/*Calculo Notas:
Na disciplina de ICC a nota final de um estudante se calcula a partir de 3 notas. 
Uma primeira prova que vale o 35% do total, uma segunda prova con 35%, e uma nota 
de trabalhos que vale o 30% do total da nota final. Implemente un programa em C 
que, a partir das 3 notas anteriormente descritas, calcule a nota final da disciplina 
para um estudante.
*/

#include<stdio.h>

int main(int argc, char *argv[]){
	float prova1, prova2, trab;		//Variaveis que receberam as notas que o usuario inserir
	float notafinal;				//Variavel que sera utilizada para salvar a nota final
	
	scanf("%f", &prova1);
	scanf("%f", &prova2);
	scanf("%f", &trab);
	
	notafinal = (prova1*0.35)+(prova2*0.35)+(trab*0.30);	//calculo da media final
	
	printf("%f", notafinal);
	
	return 0;
}
