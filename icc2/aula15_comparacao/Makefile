all: busca_e_ordenacao.o
	gcc busca_e_ordenacao.o compara.c -o compara

busca_e_ordenacao.o:
	gcc -c busca_e_ordenacao.c

run:
	./compara

clean:
	rm *.o *.a *~ compara
