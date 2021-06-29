#include <stdio.h>

int main(int agrc, char *argv[]){
	int a,b;
	
	scanf("%d %d", &a, &b);
	double conta = (a+b)/(double) (a-b);
	printf("%lf\n", conta);
	
	return 0;
}
