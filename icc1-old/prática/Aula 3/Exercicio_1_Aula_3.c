#include<stdio.h>

int main(){
    int i, x, num;       //i para chegarmos a 10 números, x como condição para vermos se o número lido é primo, num é o número para ser lido

    for(i = 0; i < 10; i++){
        int div = 0;         //div para ver se num é divisivel apenas por num e 1
        printf("Digite um numero inteiro e positivo: ");
        scanf("%d", &num);

        for(x = 1; x <= num; x++){
            if(num % x == 0){
                div++;
            }
        }
        if (div == 2)     //se div == 2 significa que ele é divisivel por 1 e por ele mesmo
            printf("O numero %d eh primo!\n", num);
        else
            printf("O numero %d nao eh primo!\n", num);
    }

    return 0;
}
