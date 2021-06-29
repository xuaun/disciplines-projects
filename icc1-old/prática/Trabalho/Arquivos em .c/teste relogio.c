#include<stdio.h>
#include<time.h>

int main(){
	float tempo, tempo2;

	tempo = clock();

	system("pause");

	printf("\n\n");

	printf("Tempo:  %.2f s.\n",(tempo/CLOCKS_PER_SEC));  //~0s

	printf("\n\n");

	system("pause");

	tempo2 = clock();

	printf("Tempo:  %.2f s.\n",(tempo2/CLOCKS_PER_SEC));  //~xs
	printf("Tempo medio: %.2f s.\n", ((tempo2 - tempo)/ CLOCKS_PER_SEC));

	printf("\n\n");

	system("pause");

	return 0;
}
