#include<stdio.h>

int main(){
    FILE *arq;

    arq = fopen ("dados.txt", "wt");  //"wt" significa que vc esta ("w") criando um arquivo para escrever nele e que ("t") será no formato texto
    fprintf(arq, "OLAAAAAAAAAAAR !!!!");
    fclose(arq);

    return 0;
}
//aparecerá um arquivo .txt no local em que o .exe estiver criado (caso eu quisesse criar em outro local, na linha 6, seria ("local:\\NomeArquivo.txt")
