#include<stdio.h>

int main() {
    float x;
    float y;
    float soma;       //Soma +
    float multi;      //Multiplica��o *
    float div;        //Divis�o /

    x = 5.0;
    y = 15.0;
    soma = x+y;
    multi = x*y;
    div = y/x;

    printf ("%f \n", soma);                         //Simples
    printf ("O valor da soma eh %f \n", soma);      //Com texto
    printf ("O valor da soma de %f com %f eh %f \n", x, y, soma);      //Texto da soma com as variaveis X e Y aparecendo e a resposta
    printf ("Multiplicacao %f vezes %f eh %f \n", x, y, multi);        //Multiplica��o
    printf ("Divisao %f por %f eh %f \n", y, x, div);                  //Divis�o

    return 0;
}
