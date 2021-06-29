#include<stdio.h>

float v1;
float v2;
float soma;
float multi;
float div;

int main () {
    printf ("Digite um numero:");
    scanf ("%f", &v1);

    printf ("Digite outro numero:");
    scanf ("%f", &v2);

    soma = v1+v2;
    multi = v1*v2;
    div = v1/v2;

    printf("O valor da soma eh %f, da multiplicacao eh %f e da divisao eh %f \n", soma, multi, div);

}
