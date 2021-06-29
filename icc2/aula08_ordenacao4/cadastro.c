#include "busca_e_ordenacao.h"
#include <string.h>

typedef struct {
	int id;
	char desc[30];
	double price;
} Product;

#define MAX_VALUE 3000

int compare_id(Product* a, Product* b) {
	//return (( a->id - b->id ) > 0 ? 1 : 0);
	//return ( b->id - a->id ) > 0;
	return b->id - a->id;
}

int compare_price(Product* a, Product* b) {
	return (b->price - a->price);
}

int compare_desc(Product* a, Product* b) {
	return strcmp(b->desc, a->desc);
}

void product_sort(Product* v, int n, int (*compare)(Product*, Product*)) {
	int i = 1; 
	while (i < n) {
		Product chave = v[i]; 
		int j = i-1; // inspeciona elemento anterior

		// Quero comparar dos produtos 
		while (j >= 0 && compare(&v[j], &chave) < 0 ) {
			v[j+1] = v[j]; // movimenta elemento
			j--;
		}
		v[j+1] = chave; // copia chave para a posicao correta

		i++; // vai para a proxima chave
	}
}

void print_products(Product*v, int n) {
	printf("Lista de Produtos\n");
	printf("=================\n");
	for (int i = 0; i < n; i++ ) {
		printf("%d\t%s\t%.2f\n", v[i].id, v[i].desc, v[i].price);
	} 
	printf("=================\n");
}


int main (int argc, char* argv[]) {


	int N = 6;
	Product list[6];

	for (int k = 0; k < N; k++) {
		list[k].id = (rand()%1000)+1;
		list[k].price = (rand()/(double)RAND_MAX)*MAX_VALUE;
	}
	strcpy(list[0].desc, "Desktop PC");
	strcpy(list[1].desc, "TV 50'");
	strcpy(list[2].desc, "Mouse Gamer");
	strcpy(list[3].desc, "Notebook Orange");
	strcpy(list[4].desc, "SteamBox");
	strcpy(list[5].desc, "Mouse Gamer");

	print_products(list, N);

	product_sort(list, N, compare_id);

	print_products(list, N);

	product_sort(list, N, compare_desc);

	print_products(list, N);


	return 0;
}
