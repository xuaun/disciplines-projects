#include<stdio.h>
                    //Criar um programa que l� os n�meros reais que o usu�rio d� e divide e multiplica
float v1;
float v2;
float multi;
float div;

int main () {
    printf ("Digite um numero:");       //imprime na tela o texto
    scanf ("%f", &v1);                  //recebe o valor do usu�rio

    printf ("Digite outro numero:");
    scanf ("%f", &v2);                  //recebe outro valor do usu�rio

    multi = v1*v2;
    div = v1/v2;

    printf("O valor da multiplicacao eh %f e da divisao eh %f \n", multi, div);

}
