#include<stdio.h>

int main(){
    FILE *arq;
    char st[100];
    char ss;

    arq = fopen ("teste.txt", "r");  //"r" significa que vc esta lendo um arquivo
    fscanf(arq, "%s", st);  //ele ler� a primeira palavra (string) e, a cada fscanf, ele ler� a pr�xima palavra
    fscanf(arq, "%c", &ss);  //ele ler� o espa�o (pois o espa�o � o pr�ximo caracter ap�s a string)
    fscanf(arq, "%c", &ss);  //ele ler� o pr�ximo caracter

    printf("A palavra lida foi: %s\n\n", st);

    printf("O caracter lido foi: %c\n\n", ss);

    fclose(arq);

    return 0;
}
