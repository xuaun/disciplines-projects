#include<stdio.h>

int main() {
    int x;
    int y;
    int soma;       //Soma +
    int multi;      //Multiplica��o *
    int div;        //Divis�o /

    x = 5;
    y = 15;
    soma = x+y;
    multi = x*y;
    div = y/x;

    printf ("%d \n", soma);                         //Simples
    printf ("O valor da soma eh %d \n", soma);      //Com texto
    printf ("O valor da soma de %d com %d eh %d \n", x, y, soma);      //Texto da soma com as variaveis X e Y aparecendo e a resposta
    printf ("Multiplicacao %d vezes %d eh %d \n", x, y, multi);        //Multiplica��o
    printf ("Divisao %d por %d eh %d \n", y, x, div);                  //Divis�o

    return 0;
}
