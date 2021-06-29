#include<stdio.h>

int main(){
    int salario1 = 5000;
    int salario2 = 2500;
    int i;

    for (i = 1; i < 6; i++){
        salario1 = salario1 * 1.1;
        salario2 = salario2 * 1.1;
        printf("\nano = %d\n", i);
        printf("Meu salario = %d\n", salario1);
        printf("Salario do meu colega = %d\n", salario2);
    }
    return 0;
}
