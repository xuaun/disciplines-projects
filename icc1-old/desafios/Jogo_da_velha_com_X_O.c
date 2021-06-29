/*Crie uma matriz para armazenar o
tabuleiro do jogo da velha (3x3). Faça um
programa que permita interagir com 2
jogadores, lendo suas jogadas e
apresentando na tela a situação atual do
tabuleiro. A partida será realizada entre 2
jogadores. E o sistema deve informar
qual foi o jogador que venceu a partida*/

#include<stdio.h>

int main () {
	char v[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};  //inicia todas as posições com '-'
	int i, j;
	int x = 0;

	printf("Jogo da velha com dois jogadores (lembre-se que comeca do 0 e vai ate o 2 o numero de colunas e linhas)\n");
	system("pause");
	system("cls");

	while(x==0){
    	for(i=0; i<3; i++){
    		for(j=0; j<3; j++){
    			printf("%c\t", v[i][j]);
    		}
    		printf("\n");
    	}

        printf("Jogador 1: escolha uma linha para jogar (entre 0 e 2). ");
        scanf("%d", &i);

        while ((i<0) || (i>2)){
        	printf("Opcao errada. Jogador 1: escolha uma linha para jogar(entre 0 e 2). ");
            scanf("%d", &i);
		}

        printf("Jogador 1: escolha uma coluna para jogar (entre 0 e 2). ");
        scanf("%d", &j);

        while ((j<0) || (j>2)){
        	printf("Opcao errada. Jogador 1: escolha uma coluna para jogar(entre 0 e 2). ");
            scanf("%d", &j);
		}

        while((v[i][j]=='X')||(v[i][j]=='O')){
        	printf("Posicoes ja selecionadas anteriormente, digite uma nova combinacao de linha e coluna.\n");
        	printf("Jogador 1: escolha uma linha para jogar. ");
            scanf("%d", &i);

            while ((i<0) || (i>2)){
        	    printf("Opcao errada. Jogador 1: escolha uma linha para jogar(entre 0 e 2). ");
                scanf("%d", &i);
		    }

            printf("Jogador 1: escolha uma coluna para jogar. ");
            scanf("%d", &j);

            while ((j<0) || (j>2)){
        	    printf("Opcao errada. Jogador 1: escolha uma coluna para jogar(entre 0 e 2). ");
                scanf("%d", &j);
		    }
		}

		v[i][j] = 'X';

		system("pause");
	    system("cls");

        if((v[0][0]==v[1][1])&&(v[0][0]==v[2][2])&&(v[0][0]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
		}
		else if((v[2][0]==v[1][1])&&(v[2][0]==v[0][2])&&(v[2][0]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
		}
		else if((v[0][0]==v[0][1])&&(v[0][0]==v[0][2])&&(v[0][0]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
		}
		else if((v[1][0]==v[1][1])&&(v[1][0]==v[1][2])&&(v[1][0]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
		}
		else if((v[2][0]==v[2][1])&&(v[2][0]==v[2][2])&&(v[2][0]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
    	}
    	else if((v[0][0]==v[1][0])&&(v[0][0]==v[2][0])&&(v[0][0]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
    	}
    	else if((v[0][1]==v[1][1])&&(v[0][1]==v[2][1])&&(v[0][1]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
    	}
    	else if((v[0][2]==v[1][2])&&(v[0][2]==v[2][2])&&(v[0][2]=='X')){
        	printf("Jogador 1 venceu!\n");
        	x++;
    	}

        for(i=0; i<3; i++){
    		for(j=0; j<3; j++){
    			printf("%c\t", v[i][j]);
    		}
    		printf("\n");
    	}
        if(x==0){

			printf("Jogador 2: escolha uma linha para jogar. ");
            scanf("%d", &i);

            while ((i<0) || (i>2)){
        	    printf("Opcao errada. Jogador 2: escolha uma linha para jogar(entre 0 e 2). ");
                scanf("%d", &i);
		    }

            printf("Jogador 2: escolha uma coluna para jogar. ");
            scanf("%d", &j);

            while ((j<0) || (j>2)){
        	    printf("Opcao errada. Jogador 2: escolha uma coluna para jogar(entre 0 e 2). ");
                scanf("%d", &j);
		    }

            while((v[i][j]=='X')||(v[i][j]=='O')){
            	printf("Posicoes ja selecionadas antigamente, digite uma nova combinacao de linha e coluna.\n");
            	printf("Jogador 2: escolha uma linha para jogar. ");
                scanf("%d", &i);

                while ((i<0) || (i>2)){
        	        printf("Opcao errada. Jogador 2: escolha uma linha para jogar(entre 0 e 2). ");
                    scanf("%d", &i);
		        }

               printf("Jogador 2: escolha uma coluna para jogar. ");
               scanf("%d", &j);

               while ((j<0) || (j>2)){
                   printf("Opcao errada. Jogador 2: escolha uma coluna para jogar(entre 0 e 2). ");
                   scanf("%d", &j);
		       }
		   }

		   v[i][j] = 'O';

		   	system("pause");
        	system("cls");
	    }

        if((v[0][0]==v[1][1])&&(v[0][0]==v[2][2])&&(v[0][0]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
		}
		else if((v[2][0]==v[1][1])&&(v[2][0]==v[0][2])&&(v[2][0]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
		}
		else if((v[0][0]==v[0][1])&&(v[0][0]==v[0][2])&&(v[0][0]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
		}
		else if((v[1][0]==v[1][1])&&(v[1][0]==v[1][2])&&(v[1][0]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
		}
		else if((v[2][0]==v[2][1])&&(v[2][0]==v[2][2])&&(v[2][0]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
    	}
    	else if((v[0][0]==v[1][0])&&(v[0][0]==v[2][0])&&(v[0][0]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
    	}
    	else if((v[0][1]==v[1][1])&&(v[0][1]==v[2][1])&&(v[0][1]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
    	}
    	else if((v[0][2]==v[1][2])&&(v[0][2]==v[2][2])&&(v[0][2]=='O')){
        	printf("Jogador 2 venceu!\n");
        	x++;
    	}
    }

    printf("\n\n");

    system("pause");
    return 0;
}
