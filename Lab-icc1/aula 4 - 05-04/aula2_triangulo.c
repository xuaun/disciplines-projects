/*
Para que possa existir um tri�ngulo � necess�rio que a medida de qualquer um dos lados seja menor
que a soma das medidas dos outros dois e maior que o valor absoluto da diferen�a entre essas
medidas. Al�m disso, os tri�ngulos podem ser classificados conforme as rela��es entre seus lados
ou entre seus �ngulos. Assim, se a medida dos tr�s lados � a mesma ent�o o tri�ngulo � chamado
de equil�tero. Caso dois lados sejam iguais � chamado de is�sceles e se os tr�s lados s�o
diferentes o tri�ngulo � chamado de escaleno. Implemente um programa em C que, a partir das
medidas dos tr�s lados, determine a (n�o) exist�ncia do tri�ngulo. Caso o tri�ngulo exista,
o programa dever� imprimir se o tri�ngulo � equil�tero, is�sceles ou escaleno. Caso n�o
exista, o programa dever� enviar uma mensagem de �O tri�ngulo n�o existe�. Para erros na
entrada (lados menores ou iguais a zero) dever� ser imprimida a mensagem �Erro na entrada�.
Obs. Naturalmente as mensagens aparecer�o sem acentos. O valor das entradas � inteiro.

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
