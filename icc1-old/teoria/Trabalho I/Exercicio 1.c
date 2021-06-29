#include<stdio.h>

int main () {
    float numaulas;  //Variavel criada para termos um controle depois do numero de aulas para obter 70% de frequencia
    float minaulas;  //numero minimo de aulas para se obter 70% de frequencia
    int matricula[100];  //vetor para receber os numeros de matriculas dos alunos
    float nota1[100];  //vetor para receber as primeiras notas dos alunos
    float nota2[100];  //vetor para receber as segundas notas dos alunos
    float nota3[100];  //vetor para receber as terceiras notas dos alunos
    float frequencia[100];  //vetor para receber os numeros de aulas frequentadas pelos alunos
    float notafinal[100];  //vetor para armazenar as notas finais dos alunos
    int RN = 0;  //variavel para saber quantos alunos reprovaram por nota
    int RF = 0;  //variavel para saber quantos alunos reprovaram por falta
    int RA = 0;  //variavel para saber quantos alunos reprovaram por nota e falta
    int i;
    int recado[100] = {0};  //vetor para printar, no final, se o aluno reprovou ou nao (0=nao,1=sim)
    float maiornota = 0.0;  //variavel criada para obter maior nota da turma
    float menornota = 10.0;  //variavel criada para obter a menor nota da turma
    float somanota = 0.0;  //variavel criada para armazenar as notas dos alunos da turma e calcular a media da turma posteriormente
    int totalreprovados = 0;  //variavel criada para armazenar quantos alunos reprovaram da turma
    float freq[100];  //vetor para calcular porcentagem de frequencia do aluno

    printf("Programa de ajuda ao professor com a disciplina. \nDigite aqui qual o total de aulas dadas durante o periodo do curso: ");
    scanf("%f", &numaulas);
    while (numaulas < 0){
        printf("Numero de aulas dadas invalido.\nDigite novamente o total de aulas dadas durante o periodo do curso: ");
        scanf("%d", &numaulas);
    }

    printf("\n");
    system("pause");
    system("cls");

    minaulas = (numaulas * 0.7);

    for (i = 0; i < 100; i++){
        printf("Digite o numero de matricula do %d aluno: ", i+1);
        scanf("%d", &matricula[i]);

        printf("Digite a 1 nota do aluno %d: ", matricula[i]);
        scanf("%f", &nota1[i]);
        while((nota1[i]<0)||(nota1[i]>10)){
            printf("Nota invalida. Digite novamente a 1 nota do aluno %d: ", matricula[i]);
            scanf("%f", &nota1[i]);
        }

        printf("Digite a 2 nota do aluno %d: ", matricula[i]);
        scanf("%f", &nota2[i]);
        while((nota2[i]<0)||(nota2[i]>10)){
            printf("Nota invalida. Digite novamente a 2 nota do aluno %d: ", matricula[i]);
            scanf("%f", &nota2[i]);
        }

        printf("Digite a 3 nota do aluno %d: ", matricula[i]);
        scanf("%f", &nota3[i]);
        while((nota3[i]<0)||(nota3[i]>10)){
            printf("Nota invalida. Digite novamente a 3 nota do aluno %d: ", matricula[i]);
            scanf("%f", &nota3[i]);
        }

        printf("Coloque a quantidade de aulas frequentadas pelo aluno %d: ", matricula[i]);
        scanf("%f", &frequencia[i]);
        while((frequencia[i]<0)||(frequencia[i]>numaulas)){
            printf("Quantidade de aulas frequentadas invalida. Digite novamente a quantidade de aulas frequentadas pelo aluno %d: ", matricula[i]);
            scanf("%f", &frequencia[i]);
        }

        freq[i] = (frequencia[i] * 100.0) / numaulas;

        notafinal[i] = (nota1[i] + nota2[i] + nota3[i]) / 3.0;

        if (notafinal[i] < 6.0){
            RN++;
            recado[i] = 1;
        }

        if (frequencia[i] < minaulas){
            RF++;
            recado[i] = 1;
        }

        if ((notafinal[i] < 6.0) && (frequencia[i] < minaulas)){
            RA++;
            recado[i] = 1;
        }

        if (notafinal[i] > maiornota){
            maiornota = notafinal[i];
        }

        if (notafinal[i] < menornota){
            menornota = notafinal[i];
        }

        if (recado[i] == 1){
            totalreprovados++;
        }
        somanota = somanota + notafinal[i];

        printf("\n");
        system("pause");
        system("cls");
    }

    printf("Matricula\tAulas assistidas\tfrequencia\tNota\tResultado\n");
    for (i = 0; i < 100; i++){
        if (recado[i] == 0){
            printf("%d\t\t%.0f\t\t\t%.0f\t\t%.2f\tAprovado\n", matricula[i], frequencia[i], freq[i], notafinal[i]);
        }
        else{
            printf("%d\t\t%.0f\t\t\t%.0f\t\t%.2f\tReprovado\n", matricula[i], frequencia[i], freq[i], notafinal[i]);
        }
    }

    printf("\nA media da turma foi %.2f.\nA maior nota foi %.2f e a menor foi %.2f.\nReprovaram %d alunos, %d  por nota, %d  por falta e %d  por nota e falta.\n", (somanota/100.0), maiornota, menornota, totalreprovados, RN, RF, RA);

    system("pause");

    return 0;
}
