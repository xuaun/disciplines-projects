#include<stdio.h>

int main(){
    int temperatura, chuva;

    printf("Qual a temperatura de hoje?: ");
    scanf("%d", &temperatura);

    printf("Esta chovendo? (Digite 0 para nao e 1 para sim): ");
    scanf("%d", &chuva);

    if(temperatura <= 15){
        if(chuva == 1){
            printf("Vou usar uma capa de chuva.");
        }
        else{
            printf("Eu vou pegar uma blusa.");
        }
    }
    else{
        if(chuva == 1){
            printf("Vou pegar um guarda-chuva.");
        }
        else{
            printf("Nao vou pegar nada.");
        }
    }

    return 0;
}

