/*
Crie um programa que consegue
adivinhar um número no raio de 1 a 15
em no máximo 4 tentativas
(assuma que o jogador diga se o número
é maior ou menor a cada tentativa
incorreta).
USE APENAS (SE-ENTAO)
*/

#include<stdio.h>
//#include<time.h>  //Passos para caso o numero seja dado pelo computador, e nao pelo usuario
//#include<stdlib.h>

int main (){
	//srand(time(NULL));
	//int r = 1 + rand() % 15;  //resto por 15 para que o numero seja entre 0 e 14
	char ch;
	
	printf("Vamos tentar adivinhar um numero que voce esteja pensando de 1 a 15 em quatro tentativas.\n");
	system("pause");  //introducao
	
	printf("\nO numero que voce pensou e 8? (Digite > se for maior, < se for menor e = se for igual)\n");
	ch = getche();  //1 tentativa
	printf("\n");
	system("pause");
	
	if (ch == '<'){
		printf("\nO numero que voce pensou e 4? (Digite > se for maior, < se for menor e = se for igual)\n");
	    ch = getche();  //2 tentativa
		printf("\n");
	    system("pause");
		if (ch == '<'){
			printf("\nO numero que voce pensou e 2? (Digite > se for maior, < se for menor e = se for igual)\n");
	        ch = getche();  //3 tentativa
			printf("\n");
	        system("pause");
			if (ch == '<'){
				printf("\nO numero que voce pensou e 1?\n");  //4 tentativa
				printf("\n");
			}
			else if (ch == '>'){
				printf("\nO numero que voce pensou e 3?\n");  //4 tentativa
				printf("\n");
			}
		}
		else if (ch == '>'){
			printf("\nO numero que voce pensou e 6? (Digite > se for maior, < se for menor e = se for igual)\n");
	        ch = getche();  //3 tentativa
			printf("\n");
	        system("pause");
			if (ch == '<'){
				printf("\nO numero que voce pensou e 5?\n");  //4 tentativa
				printf("\n");
			}
			else if (ch == '>'){
				printf("\nO numero que voce pensou e 7?\n");  //4 tentativa
				printf("\n");
			}
		}
	}
    else if (ch == '>'){
		printf("\nO numero que voce pensou e 12? (Digite > se for maior, < se for menor e = se for igual)\n");
	    ch = getche();  //2 tentativa
		printf("\n");
	    system("pause");
		if (ch == '<'){
			printf("\nO numero que voce pensou e 10? (Digite > se for maior, < se for menor e = se for igual)\n");
	        ch = getche();  //3 tentativa
			printf("\n");
	        system("pause");
			if (ch == '<'){
				printf("\nO numero que voce pensou e 9?\n");  //4 tentativa
				printf("\n");
			}
			else if (ch == '>'){
				printf("\nO numero que voce pensou e 11?\n");  //4 tentativa
				printf("\n");
			}
		}
		else if (ch == '>'){
			printf("\nO numero que voce pensou e 14? (Digite > se for maior, < se for menor e = se for igual)\n");
	        ch = getche();  //3 tentativa
			printf("\n");
	        system("pause");
			if (ch == '<'){
				printf("\nO numero que voce pensou e 13?\n");  //4 tentativa
				printf("\n");
			}
			else if (ch == '>'){
				printf("\nO numero que voce pensou e 15?\n");  //4 tentativa
				printf("\n");
			}
		}
	}
	printf("\nEsperamos que tenha aproveitado o jogo!\n");
	system("pause");
	
	return 0;
}