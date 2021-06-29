//Lista 2 ex 11

#include<stdio.h>
int main (){
	char ch;
	int i;
	float compra = 0;
	float total = 0;
	float vista = 0;
	float prazo = 0;
	
	printf("Programa de compras da loja feliz.\n");
	system("pause");
	system("cls");
	
	for (i = 1; i <= 2; i++){
	printf("\nDigite o valor da compra %d: ", i);
	scanf("%f", &compra);
	
	total += compra;
		
	printf("Digite se a compra %d sera a vista (v) ou a prazo (p) para a compra: ", i);
	
	ch = getche ();
	
	if (ch == 'p')
	prazo += compra;
	
	else if (ch == 'v')
	vista += compra;
	}
	system("pause");
	system("cls");
	
	printf("\nO valor das suas compras a vista sera de %.2f, das suas compras a prazo sera de %.2f. \nO valor total das suas compras sera de %.2f e cada parcela (de tres vezes) das compras a prazo sera de %.2f", vista, prazo, total, prazo/3);
	
	return 0;
}
