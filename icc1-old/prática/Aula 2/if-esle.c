#include<stdio.h>

int main(){
    int temperatura, chuva;

    printf("Qual a temperatura de hoje?: ");
    scanf("%d", &temperatura);

    printf("Esta chovendo? (Digite 0 para nao e 1 para sim): ");
    scanf("%d", &chuva);

    if(temperatura < 15){         //se a temperatura for menos do que 15
        printf("Eu vou usar blusa e ");
    }
    else{                         //se não...
         printf("Nao vou usar blusa e ");
    }
    if(chuva == 1){
        printf("vou pegar o guarda-chuva.");
    }
    else{
        printf("nao vou pegar meu guarda-chuva.");
    }

    return 0;
}

