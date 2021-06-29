#include<stdio.h>

int main(){
    int salario1 = 5000;  //Meu salario inicial
    int salario2 = 2500;  //Salario do meu colega inicial
    int i = 0;  //Ano inicial (com relação aos salarios)

    while (salario1 > salario2){
        salario1 = salario1 * 1.1;  //Meu salario tem um aumento anual de 10%
        salario2 = salario2 * 1.2;  //O salario do meu amigo tem um aumento anual de 20%
        i++;  //Aumentar 1 ano por laço
    }
    printf("Levara %d anos para que o salario do meu colega seja maior que o meu.\n", i);
    printf("Meu salario final = %d\n", salario1);
    printf("Salario final do meu colega = %d\n", salario2);
    return 0;
}
