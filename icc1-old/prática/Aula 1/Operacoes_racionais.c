#include<stdio.h>

int main() {
    float x;
    float y;
    float soma;       //Soma +
    float multi;      //Multiplicação *
    float div;        //Divisão /

    x = 5.0;
    y = 15.0;
    soma = x+y;
    multi = x*y;
    div = y/x;

    printf ("%f \n", soma);                         //Simples
    printf ("O valor da soma eh %f \n", soma);      //Com texto
    printf ("O valor da soma de %f com %f eh %f \n", x, y, soma);      //Texto da soma com as variaveis X e Y aparecendo e a resposta
    printf ("Multiplicacao %f vezes %f eh %f \n", x, y, multi);        //Multiplicação
    printf ("Divisao %f por %f eh %f \n", y, x, div);                  //Divisão

    return 0;
}
