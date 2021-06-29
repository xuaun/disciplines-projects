#include <stdio.h>
#include <stdlib.h>

void inf_rec() {
	inf_rec();
}


int main(int argc, char* argv[]) {

	/*
	// loop infinito
	int x = 1;
	while (1) {
		x = 1;
	}
	*/

	// recursao infinita
	inf_rec();


	return 0;
}
