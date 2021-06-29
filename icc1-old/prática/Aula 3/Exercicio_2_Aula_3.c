#include<stdio.h>

int main(){
    int i, n, x, z;

    printf("Quantos testes voce deseja fazer?\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("\nDigite um numero natural: ");
        scanf("%d", &x);
        for(z = x - 1; z >= -1; z = z - 1){
            printf("%d ", x);
            x = x - 1;
        }
    }

    return 0;
}
