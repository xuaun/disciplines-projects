#include<stdio.h>

int main(){
    float nota1, nota2, nota3, media;
    int i;

    for(i = 1; i <= 10; i++){
        printf("\nDigite as notas do aluno %d\n", i);
        scanf("%f", &nota1);
        scanf("%f", &nota2);
        scanf("%f", &nota3);
        media = (nota1 + nota2 + nota3)/3;
        printf("\nA media do aluno %d foi %.1f\n", i, media);
    }

    return 0;
}
