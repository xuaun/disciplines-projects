#include<stdio.h>

int main() {
    int x;
    int y;
    int soma;       //Soma +
    int multi;      //Multiplicação *
    int div;        //Divisão /

    x = 5;
    y = 15;
    soma = x+y;
    multi = x*y;
    div = y/x;

    printf ("%d \n", soma);                         //Simples
    printf ("O valor da soma eh %d \n", soma);      //Com texto
    printf ("O valor da soma de %d com %d eh %d \n", x, y, soma);      //Texto da soma com as variaveis X e Y aparecendo e a resposta
    printf ("Multiplicacao %d vezes %d eh %d \n", x, y, multi);        //Multiplicação
    printf ("Divisao %d por %d eh %d \n", y, x, div);                  //Divisão

    return 0;
}
