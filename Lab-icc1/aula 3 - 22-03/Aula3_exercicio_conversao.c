/*Conversao a horas, minutos e segundos:
Possui-se uma hora expressada em segundos e deseja-se 
implementar um programa em linguagem C que calcule a 
quantidade de horas, de minutos e de segundos.
*/

#include<stdio.h>

int main(int argc, char *argv[]){
	int seg, min, hor;
	
	scanf("%d", &seg);
	
	hor = seg / (60*60);
	seg = seg % (60*60);
	
	min = seg / 60;
	seg = seg % 60;
	
	printf("%dh %dm %ds", hor, min, seg);
	
	return 0;
}
