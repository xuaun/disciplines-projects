//lista 2 exercicio 6

#include<stdio.h>

int main(){
	float i;  //variavel do for
	float lucro = 0;  //valor do lucro esperado, de acordo com a formula dada
	float lucromaior = 0;  //maior lucro
	float z = 0;  //valor do ingresso
	float vendaingresso;
	float x = 0;
	
	printf("lucros esperados\t\tpreco do ingreco\n");
	for (i = 0.0; i <= 8; i = i + 1.0){
		z = 5 - (i * 0.5);
		lucro = ((((26 * i) + 120) * z) - 200);
		
		printf("%.2f\t\t\t\t%.2f\n", lucro, z);
		
		if (lucro > lucromaior){
		    lucromaior = lucro;
		    vendaingresso = 120 + (26*i);
		    x = z;
	    }
	}
	printf("\nO maior lucro esperado e %.2f.\nEste lucro sera atingido com o ingresso no valor de R$%.2f.\nEspera-se que se venda %.2f ingressos.", lucromaior, x, vendaingresso);
	
	return 0;
}
