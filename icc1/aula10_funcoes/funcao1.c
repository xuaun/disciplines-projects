#include <stdio.h>

int funcao() {
	int a = 10; // variavel local de funcao
	printf("%p funcao() a : %d\n", &a, a);
}


int main() {
	int a = 5; // variavel local de main
	printf("%p main() a : %d\n", &a, a);
	funcao();	
}
