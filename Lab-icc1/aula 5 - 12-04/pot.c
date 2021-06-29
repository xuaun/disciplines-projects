/*
Marcelo adora o cálculo e aprendeu que é possível calcular os valores de funções 
exponenciais sem auxílio da calculardora ou das bibliotecas matemáticas da sua 
linguagem de programação favorita. Através da série de potências, é possível 
obter os valores de exponencial apenas realizando a soma do link abaixo:

https://i.imgur.com/C54iPv6.jpg

Para ter certeza que os valores obtidos estão de acordo com os valores reais, 
Marcelo resolveu comparar a sua implementação de uma das séries e verificar seu 
valor com o obtido por uma função de uma biblioteca matemática. Como amigo de 
Marcelo, você resolveu ajudá-lo com essa tarefa. Como entrada, o seu programa
deve receber um valor em ponto flutuante “x” seguido de um inteiro “n” e calcular 
o valor de exp(x) através da série de potência com “n” termos (isto é, o somatório 
irá de 0 até n-1). O resultado final deve ser o valor absoluto do erro obtido 
através da série de potência para a exponencial de “x” e a função exp() da 
biblioteca math.h. Para isso, imprima "O erro obtido eh erro", em que erro está 
em notação científica com 6 casas depois da vírgula. Importante: Não será 
permitida a utilização de vetores, nem o uso da função pow() da biblioteca 
math.h para calcular a potência na sumatória e nem a criação de outras funções 
além da main para a resolução desse exercício. Mais importante: Usem double em 
vez de float!

Entrada
0.5 4

Saída
O erro obtido eh 2.887937e-03
*/

#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[]){
	double x;
	int n, i, a;
	double serie = 1.0;
	double pot;
	double erro;
	
	scanf("%lf %d", &x, &n);
	
	pot = x;
	a = 1;
	
	for (i=1; i<n; i++){
		if (i>1){
			pot = pot*x;
		}
		a = a*i;
		serie = serie + (pot)/a;
	}
	erro = serie - exp(x);
	if (erro < 0){
		erro = erro*(-1);
	}
	
	printf("O erro obtido eh %.6e\n", erro);
	
	return 0;
}
