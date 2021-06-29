#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FREE -1
#define DEL -2

int hash_division(int key, int m, int k);
int hash_multi(int key, double A, int m, int k); 
int insert(int* t, int key, int m);
int search(int* t, int key, int m);
int delete(int* t, int key, int m);
int* create_hash_table(int m);

 
/* insere elemento na tabela Hash
   Parametros:
	int* t - tabela hash
	int key - chave a ser inserida
	int m   - tamanho da tabela
*/
int insert(int* t, int key, int m) {

	if (key < 0) return -1;

	double A = (sqrt(5)-1)/2.0;
	int pos, k = -1;

	do {
		k++;
		//pos = hash_division(key, m, k);
		pos = hash_multi(key, A, m, k);
		if (t[pos] != FREE && t[pos] != DEL) printf("Colisao (%d)\n", t[pos]);

	} while (t[pos] != FREE && t[pos] != DEL);

	t[pos] = key;

}

int delete(int *t, int key, int m) {
	int pos = search(t, key, m);
	if (pos < 0) return pos;
	t[pos] = DEL;
}

int search(int *t, int key, int m) {

	if (key < 0) return -1;

	double A = (sqrt(5)-1)/2.0;
	int pos, k = -1;

	do {
		k++;
		//pos = hash_division(key, m, k);
		pos = hash_multi(key, A, m, k);
		if (k >= m || t[pos] == FREE) break;
		if (t[pos] != key) printf("Colisao (%d) \n", t[pos]);

	} while (t[pos] != key);

	if (t[pos] == key) return pos;
	else return FREE;

}

int hash_division(int key, int m, int k) {
	return (int)( (key+(k*k)) % m);
}

int hash_multi(int key, double A, int m, int k) { 
	double val = (key+(k*k))*A;
	val = val - ((int)val);
	return (int)(val*m);
}

// int hash_uni()

/* cria tabela hash 
	posicoes sao inicializadas com FREE
	indicando espacos livres
   Parametros:
	int m - tamanho da tabela
*/
int* create_hash_table(int m) {
	int* t = malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		t[i] = FREE;
	}
	return t;
}

int main(int argc, char* argv[]) {

	if (argc < 2) return 1;

	int m = atoi(argv[1]);
	int key;

	int* t = create_hash_table(m);	

	do {
		scanf("%d", &key);
		insert(t, key, m);

	} while (key >= 0);

	for (int i = 0; i < m; i++) {
		printf("%d ", t[i]);
	}
	printf("\n\n");

	do {
		scanf("%d", &key);
		delete(t, key, m);

	} while (key >= 0);

	for (int i = 0; i < m; i++) {
		printf("%d ", t[i]);
	}
	printf("\n\n");


	do {
		scanf("%d", &key);
		search(t, key, m);

	} while (key >= 0);


	free(t);

	return 0;
}
