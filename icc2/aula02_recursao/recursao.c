#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1




/*
// TODO :(
void write_str() {
	char c;
	//c = fgetc(stdin);
	while ((c=getchar()) != '\n') {
		write_str();	
		c = '\n';
	}
	fputc(c, stdout);
}
*/

void imprime_vetor(int* v) {
	if ( (*v) != -1 ) {
		printf("%d ", *v);
		imprime_vetor(v+1);
	}
}



int main (void) {

	int A[9] = {1, 2, 3, 4, 5, 6, 7, 8, -1};
	imprime_vetor(A);

	return 0;
}
