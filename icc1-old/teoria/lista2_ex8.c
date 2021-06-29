//Lista 2 ex 8

#include<stdio.h>

int main(){
	float f1 = 0.0;   //faixa etaria 1
	float f2 = 0.0;   //faixa etaria 2
	float f3 = 0.0;   //faixa etaria 3
	float f4 = 0.0;   //faixa etaria 4
	float f5 = 0.0;   //faixa etaria 5
	int temp;     //idade = temporario
	int i;
	float p1 = 0.0;
	float p5 = 0.0;
	
	printf("A seguir, anote as idades dos entrevistados, um por um.\n");
	system("pause");
	
	for (i = 1; i <= 15; i++){
		printf("Digite a idade do entrevistado %d: ", i);
		scanf("%d", &temp);
		if (temp <= 15)
		f1++;
		else if ((temp > 15) && (temp <= 30))
		f2++;
		else if ((temp > 30) && (temp <= 45))
		f3++;
		else if ((temp > 45) && (temp <= 60))
		f4++;
		else if (temp > 61)
		f5++;
	}
	system("pause");
	system("cls");
	
	printf("Veja agora o numero de entrevistados por faixa etaria.\n");
	system("pause");
	
	printf("\nFaixa Etaria 1\t\t%.0f", f1);
	printf("\nFaixa Etaria 2\t\t%.0f", f2);
	printf("\nFaixa Etaria 3\t\t%.0f", f3);
	printf("\nFaixa Etaria 4\t\t%.0f", f4);
	printf("\nFaixa Etaria 5\t\t%.0f\n\n", f5);
	system("pause");
	
	p1 = f1 / 15;
	p5 = f5 / 15;
	
	printf("\nA porcentagem de entrevistados na faixa etaria 1 e %.3f e na faixa etaria 5 e %.3f.", p1, p5);
	
	return 0;
}
