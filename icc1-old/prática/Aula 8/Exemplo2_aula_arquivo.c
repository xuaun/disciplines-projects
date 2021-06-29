#include<stdio.h>

int main(){
    FILE *arq;
    char st[100];
    char ss;

    arq = fopen ("teste.txt", "r");  //"r" significa que vc esta lendo um arquivo
    fscanf(arq, "%s", st);  //ele lerá a primeira palavra (string) e, a cada fscanf, ele lerá a próxima palavra
    fscanf(arq, "%c", &ss);  //ele lerá o espaço (pois o espaço é o próximo caracter após a string)
    fscanf(arq, "%c", &ss);  //ele lerá o próximo caracter

    printf("A palavra lida foi: %s\n\n", st);

    printf("O caracter lido foi: %c\n\n", ss);

    fclose(arq);

    return 0;
}
