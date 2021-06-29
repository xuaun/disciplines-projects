/*
Para que possa existir um triângulo é necessário que a medida de qualquer um dos lados seja menor
que a soma das medidas dos outros dois e maior que o valor absoluto da diferença entre essas
medidas. Além disso, os triângulos podem ser classificados conforme as relações entre seus lados
ou entre seus ângulos. Assim, se a medida dos três lados é a mesma então o triângulo é chamado
de equilátero. Caso dois lados sejam iguais é chamado de isósceles e se os três lados são
diferentes o triângulo é chamado de escaleno. Implemente um programa em C que, a partir das
medidas dos três lados, determine a (não) existência do triângulo. Caso o triângulo exista,
o programa deverá imprimir se o triângulo é equilátero, isósceles ou escaleno. Caso não
exista, o programa deverá enviar uma mensagem de “O triângulo não existe”. Para erros na
entrada (lados menores ou iguais a zero) deverá ser imprimida a mensagem “Erro na entrada”.
Obs. Naturalmente as mensagens aparecerão sem acentos. O valor das entradas é inteiro.

Entrada: 1
8
10
Saida:O triangulo nao existe

Entrada:2
2
3
Saida:Isosceles
*/

#include <stdio.h>

int main (int argc, char *argv[]){
	int l1, l2, l3;
	
	scanf("%d", &l1);
	scanf("%d", &l2);
	scanf("%d", &l3);
	
	if((l1<=0)||(l2<=0)||(l3<=0)){
		printf("Erro na entrada");
	}else{
		if(((l1>=l2+l3)||(l2>=l1+l3)||(l3>=l1+l2))&&((l1<=l2-l3)||(l2<=l1-l3)||(l3<=l1-l2)||(l1<=l3-l2)||(l2<=l3-l2)||(l3<=l2-l3))){
			printf("O triangulo nao existe");
		}else{
			if((l1==l2)&&(l1==l3)){
				printf("Equilatero");
			}else if((l1==l2)||(l1==l3)||(l2==l3)){
				printf("Isosceles");
			}else{
				printf("Escaleno");
			}
		}
	}
	
	return 0;
}
