/*
Desafio:
– O valor do seno de x pode ser calculado pela série
de Taylor, dada por:
sin(x) = x - x^3/3! + x^5/5! – x^7/7! ....
Faça um programa que leia o valor de x e compute o valor
do seno(x) usando os 5 primeiros termos da série de Taylor.
*/

#include<stdio.h>

int main(){
	float y = 0;
	float sin;
	float x = 0;
	
	printf("Digite um valor em graus e descubra seu seno: ");
	scanf("%f", &y);
	
	x = (y*3.14)/180;
	
	sin = (x) - (x*x*x)/(3*2*1) + (x*x*x*x*x)/(5*4*3*2*1) - (x*x*x*x*x*x*x)/(7*6*5*4*3*2*1) + (x*x*x*x*x*x*x*x*x)/(9*8*7*6*5*4*3*2*1);
	
	printf("O valor de seno de %.0f e %.3f.", y, sin);
	
	printf("\n");
	system("pause");
	
	return 0;
}
