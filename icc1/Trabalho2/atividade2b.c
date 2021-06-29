/* Programa realizado como trabalho para a disciplina 
"SCC0221 - Introdução à Ciência da Computação I - 2018".

Programa que realiza um recomendador simples que utiliza notas 
dos usuarios com gostos mais parecidos como base para prever 
as notas de um determinado usuario em relacao a um determinado 
item desta lista, e utilizar notas previstas para criar uma 
lista de recomendacoes ordenada por essas notas previstas.

	Entradas:
	int n = numero de usuarios;
	int i = itens da lista;
	float t = limiar de similaridade
	int notas = notas n*i
	
	Saida:
	-saida1: notas preditas com precisão de duas casas decimais;
	-saida2: DI (para uma nota que nao estimada).

	João Víctor de Araujo Lima / LCE-USP 2018
*/

#include <stdio.h>
#include <math.h>

//Essa funcao calcula o valor de similaridade entre dois
//usuarios com base em suas notas nos itens "votados"

float similaridade(int* n1, int* n2, int i){
	//n1 = dados do usuario 1, n2 = dados do usuario 2,	
	//i = n de elementos da lista
	int l1;					//variavel local para usar no for
	float raiz1, raiz2, s;	//variaveis para calcular similaridade
	raiz1 = 0.0;
	raiz2 = 0.0;
	s=0.0;

	//Formula para calcular sim: s=cos(u,v)=u.v/||u|.|v||

	for (l1=0; l1<i; l1++){
		s+=(*(n1+l1)) * (*(n2+l1));
		raiz1+=(*(n1+l1))*(*(n1+l1));
		raiz2+=(*(n2+l1))*(*(n2+l1));

		//Teste dos valores de s, raiz1 e raiz2
		//printf("%.2f\t%.2f\t%.2f\n", s, raiz1, raiz2);
	}	
	
	s=s/(sqrt(raiz1)*sqrt(raiz2));
	//printf("\n%.2f\n", s);

	return s;	//Retorna o valor da similaridade calculada
}

int main(int argc, char* argv[]){
	int n, i;				//n: usuarios, i: itens
	int laco1, laco2, laco3;//variaveis que usarei no for
	float t;				//valor base para similaridade

	scanf("%d %d %f", &n, &i, &t);
	
	int notas[n][i];
	
	//Para pegar notas inseridas pelo usuario:
	for (laco1=0; laco1<n; laco1++){
		for (laco2=0; laco2<i; laco2++){
			scanf(" %d", &notas[laco1][laco2]);
		}
	}
	
	//Testar valores com suas posicoes na matriz:
	//for(laco1=0; laco1<n; laco1++){
	//	for(laco2=0; laco2<i; laco2++){
	//		printf("[%d][%d] %d", laco1, laco2, notas[laco1][laco2]);
	//	}
	//	printf("\n");
	//}
	
	//Mais para frente sera usada a media das notas dos
	//usuarios para calcular a nota estimada ponderada 
	//do usuario, para isso criou-se um vetor para ja 
	//guardar os valores dessas medias dos itens votados:
	
	float media[n];
	int temp;
	
	for (laco1=0; laco1<n; laco1++){
		media[laco1]=0.0;
		temp = 0;
		for (laco2=0;laco2<i;laco2++){
			if (notas[laco1][laco2]!=0){
				media[laco1]+= notas[laco1][laco2];
				temp++;
			}
		}
		media[laco1] = media[laco1]/(float)temp;
		//printf("%.2f\n", media[laco1]);
	}

	//similaridade entre usuários (formula)
	//similaridade = cos = u.v/||u|.|v|| = n1a+n1j+n2a+.../raiz(n1a²+n2a²...)xraiz(n1j²+n2j²...)
	
	//Variavel para guardar a relacao similaridade entre
	//os usuarios:

	float similar[n][n];
	for(laco1=0; laco1<n; laco1++){
		for(laco2=n-1; laco2>=laco1; laco2--){
			if(laco1==laco2){
				similar[laco1][laco2] = 0;
			}else{
				//passa, como parametros, o vetor onde se encontra
				//as notas dos usuarios comparados e o numero de
				//elementos votados para se calcular a 
				//similaridade entre ambos:
				similar[laco1][laco2] = similaridade(notas[laco1], notas[laco2], i);
			}
			//printf("%.2f  ", similar[laco1][laco2]);
		}
		//printf("\n");
	}
	
	//Com todos os dados obtidos ate entao, observa-se quais pontos
	//na lista possuem nota 0 (sem nota) para se calulcar a
	//nota estimada ponderada com base nas similaridades dos 
	//usuarios acima de t:
	
	float dividendo, divisor, nota_pond;
	int paragrafo=0;
	
	for(laco1=0; laco1<n; laco1++){
		for(laco2=0; laco2<i; laco2++){
			if(notas[laco1][laco2]==0){
				//caso encontre algum 0 na lista:			
				dividendo=0.0;
				//printf("media: %.2f\n", media[laco1]);
				divisor=0.0;
				for(laco3=0; laco3<n; laco3++){
					//procura-se valores de similaridade 
					//acima de t:				
					//printf("teste1\n");
					if((similar[laco3][laco1]>=t)&&(laco3<laco1)){
						//printf("teste2\n");
						//printf("sim: %.2f\n", similar[laco3][laco1]);
						if(notas[laco3][laco2]!=0){
							dividendo+=similar[laco3][laco1]*(notas[laco3][laco2]-media[laco3]);
							divisor+=similar[laco3][laco1];
						}
					}else if((similar[laco1][laco3]>=t)&&(laco3>laco1)){
						if(notas[laco3][laco2]!=0){
							dividendo+=similar[laco1][laco3]*(notas[laco3][laco2]-media[laco3]);
							divisor+=similar[laco1][laco3];
						}
						//printf("nota: %d dividendo: %.2f, divisor: %.2f\n", notas[laco3][laco2], dividendo, divisor);
					}
				}
				//caso tenha encontrado, termina a conta, se nao
				//aponta "Dados Insuficientes":
				if(divisor !=0.0){
					nota_pond = media[laco1] + (dividendo/divisor);
					printf("%.2f ", nota_pond);
					paragrafo=1;
				}else{
					printf("DI ");
					paragrafo=1;
				}
			}
		}
		if(paragrafo==1){
			printf("\n");
			paragrafo=0;
		}
	}

	return 0;
}
