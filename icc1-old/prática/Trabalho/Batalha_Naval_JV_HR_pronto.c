#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ESC 27

int tecla;  //para retornar ao menu principal

int instrucoes(){
    tecla=0;
    while(tecla!=ESC){
        system("cls");

        printf("\n\n\t\t\t\t\t _______________________________________\n");
        printf("\t\t\t\t\t|\t\tInstrucoes\t\t|\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t|O objetivo do jogo de batalha naval e\t|\n");
        printf("\t\t\t\t\t|advinhar onde esta e destruir todas\t|\n");
        printf("\t\t\t\t\t|as embarcacoes do oponente.\t\t|\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t|O jogo pode ser jogado sozinho ou\t|\n");
        printf("\t\t\t\t\t|em duas pessoas,apresentando a\t\t|\n");
        printf("\t\t\t\t\t|possibilidade de se jogar em dois\t|\n");
        printf("\t\t\t\t\t|jogadores.\t\t\t\t|\n");
        printf("\t\t\t\t\t|Encontram-se tres tamanhos de\t\t|\n");
        printf("\t\t\t\t\t|tabuleiro, 5*5, 10*10, 15*15.\t\t|\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t|\tBarcos - tamanho:\t\t|\n");
        printf("\t\t\t\t\t|\tSubmarino - 1\t\t\t|\n");
        printf("\t\t\t\t\t|\tCruzador - 3\t\t\t|\n");
        printf("\t\t\t\t\t|\tPorta-avioes - 5\t\t|\n");
        printf("\t\t\t\t\t|\t\t\t\t\t|\n");
        printf("\t\t\t\t\t|Durante o jogo, pressione ESC no\t|\n");
        printf("\t\t\t\t\t|final de qualquer partida para voltar\t|\n");
        printf("\t\t\t\t\t|ao menu principal.\t\t\t|\n");
        printf("\t\t\t\t\t|_______________________________________|\n");
        printf("\n\n\n");

        printf("\t\t\t\t\t");

        printf("Pressione ESC para voltar ao menu principal...");
        tecla = getch();

        if(tecla==ESC){
            main();
        }
    }
}

int main(){
    float tempo1, tempo2;
	int tabuleirop[4][5][5];  //tabuleiro 1x2 jogador(es) pequeno (5*5)
    int tabuleirom[4][10][10];  //tabuleiro 1x2 jogador(es) médio (10*10)
    int tabuleirog[4][15][15];  //tabuleiro 1x2 jogador(es) grande (15*15)
	int i, j;  //para organizar a matriz tabuleiro
	int x, y;  //para poder ajudar pra colocar os barcos no tabuleiro de maneira aleatória
	int menu = 0;  //para que o usuario possa ficar no jogo e só sair dele caso queira e fazer isso no menu
    int j1b1, j1b2, j1b3, j1b4, j1b5, j1b6, j1b7;  //varíaveis para representar os barcos do jogador 1 (1=pq, 2, 3, 4=md, 5, 6, 7=gd)
    int j2b1, j2b2, j2b3, j2b4, j2b5, j2b6, j2b7;  //varíaveis para representar os barcos do jogador 2 (1=pq, 2, 3, 4=md, 5, 6, 7=gd)
    int sub1, sub2, cru1, cru2, port1, port2;  //contador barcos destruidos
    int jogo;  //para repetir o jogo até que ele acabe
    int jogador;  //para determinar quantos jogadores
    int tamanho;  //para determinar o tamanho

    srand(time(NULL));  //para gerar posições aleatórias pros barcos

	system("title Batalha Naval");  //nome que o prompt irá receber

   	while(menu==0){

        system("mode con:cols=130 lines=30");  //altera o tamanho do prompt para caber a maior matriz

   	    system("color 02");  //fundo preto, letra verde (para menu)

   	    printf("\n\n\n\n\t\t\t\t\t\t ________________________________\n");
   	    printf("\t\t\t\t\t\t|  Bem-vindo ao batalha naval.\t|\n");
   	    printf("\t\t\t\t\t\t|\t\t\t\t|\n");
   	    printf("\t\t\t\t\t\t|\t1 jogador\t\t|\n");
   	    printf("\t\t\t\t\t\t|\t2 jogadores\t\t|\n");
   	    printf("\t\t\t\t\t\t|\t3 instrucoes\t\t|\n");
   	    printf("\t\t\t\t\t\t|\t4 sair\t\t\t|\n");
   	    printf("\t\t\t\t\t\t|_______________________________|\n");
   	    printf("\t\t\t\t\t\t\t   by: Joao V. e Hingryd\n\n\n");

   	    printf("\t\t\t\t\t\t");

   	    //rever se o menu ficará assim

        scanf("%d", &jogador);  //receber qual opção será selecionada (quantos jogadores ou sair)
        while((jogador<1)||(jogador>4)){  //caso a opção seja inválida
            printf("\n\t\t\t\t\t\tOpcao invalida, digite uma opcao valida: ");
            scanf("%d", &jogador);  //receber novamente a opção do menu
        }

        printf("\t\t\t\t\t\t");

        if(jogador==3){
            instrucoes();
        }else if(jogador==4){
            break;
        }

   	    system("pause");
   	    system("cls");

        printf("\n\n\n\n\t\t\t\t\t\t ________________________________\n");
        printf("\t\t\t\t\t\t|Escolha o tamanho do tabuleiro:|\n");
   	    printf("\t\t\t\t\t\t|\t\t\t\t|\n");
   	    printf("\t\t\t\t\t\t|\t5   5*5 \t\t|\n");
   	    printf("\t\t\t\t\t\t|\t10 10*10\t\t|\n");
   	    printf("\t\t\t\t\t\t|\t15 15*15\t\t|\n");
   	    printf("\t\t\t\t\t\t|\t\t\t\t|\n");
   	    printf("\t\t\t\t\t\t|_______________________________|\n\n\n\n");

   	    printf("\t\t\t\t\t\t");

        scanf("%d", &tamanho);  //receber qual opção será selecionada (tamanho do tabuleiro)
        while(!((tamanho==5)||(tamanho==10)||(tamanho==15))){  //caso a opção selecionada seja inválida
            printf("\n\t\t\t\t\t\tOpcao invalida, digite uma opcao valida: ");
            scanf("%d", &tamanho);  //receber novamente a opção selecionada
        }

        printf("\t\t\t\t\t\t");

        system("pause");
   	    system("cls");

    	for(i=0; i<(tamanho); i++){  //montar tabuleiro jogador 1
    		for(j=0; j<(tamanho); j++){
                if(tamanho==5){  //se tamanho ==5
    			    tabuleirop[1][i][j] = -1;  //Receber valor -1 (tabuleiro falso)
        	    	//printf("%d\t", tabuleirop[1][i][j]);  //teste tabuleiro falso
                    tabuleirop[0][i][j] = -2;  //observar como e qual simbolo colocar para agua
                    //printf("%d\t", tabuleirop[0][i][j]);  //teste tabuleiro verdadeiro
                }else if(tamanho==10){  //se tamanho ==10
                    tabuleirom[1][i][j] = -1;  //Receber valor -1 (tabuleiro falso)
        	    	//printf("%d\t", tabuleirom[1][i][j]);  //teste tabuleiro falso
                    tabuleirom[0][i][j] = -2;  //observar como e qual simbolo colocar para agua
                    //printf("%d\t", tabuleirom[0][i][j]);  //teste tabuleiro verdadeiro
                }else if(tamanho==15){  //se tamanho ==15
                    tabuleirog[1][i][j] = -1;  //Receber valor -1 (tabuleiro falso)
        	    	//printf("%d\t", tabuleirog[1][i][j]);  //teste tabuleiro falso
                    tabuleirog[0][i][j] = -2;  //observar como e qual simbolo colocar para agua
                    //printf("%d\t", tabuleirog[0][i][j]);  //teste tabuleiro verdadeiro
                }
    		}
    	//printf("\n");
    	}

    	if(jogador==2){
            for(i=0; i<(tamanho); i++){  //montar tabuleiro jogador 2
    		    for(j=0; j<(tamanho); j++){
    			    if(tamanho==5){  //se tamanho ==5
        			    tabuleirop[3][i][j] = -1;  //Receber valor -1 (tabuleiro falso)
            	    	//printf("%d\t", tabuleirop[3][i][j]);  //teste tabuleiro falso
                        tabuleirop[2][i][j] = -2;  //observar como e qual simbolo colocar para agua
                        //printf("%d\t", tabuleirop[2][i][j]);  //teste tabuleiro verdadeiro
                    }else if(tamanho==10){  //se tamanho ==10
                        tabuleirom[3][i][j] = -1;  //Receber valor -1 (tabuleiro falso)
            	    	//printf("%d\t", tabuleirom[3][i][j]);  //teste tabuleiro falso
                        tabuleirom[2][i][j] = -2;  //observar como e qual simbolo colocar para agua
                        //printf("%d\t", tabuleirom[2][i][j]);  //teste tabuleiro verdadeiro
                    }else if(tamanho==15){  //se tamanho ==15
                        tabuleirog[3][i][j] = -1;  //Receber valor -1 (tabuleiro falso)
        	    	    //printf("%d\t", tabuleirog[3][i][j]);  //teste tabuleiro falso
                        tabuleirog[2][i][j] = -2;  //observar como e qual simbolo colocar para agua
                        //printf("%d\t", tabuleirog[2][i][j]);  //teste tabuleiro verdadeiro
                    }
    		    }
    	    //printf("\n");
    	    }
    	}

    	//os barcos serão colocados do maior para o menor (evitar possíveis problemas)

    	x = rand() % 2;  //vertical ou horizontal
    	if(x==0){  //horizontal
	    	i = rand() % (tamanho);
        	j = rand() % (tamanho-4);
	    	if(tamanho==5){
                tabuleirop[0][i][j] = 5;
            	tabuleirop[0][i][(j+1)] = 5;
            	tabuleirop[0][i][(j+2)] = 5;
            	tabuleirop[0][i][(j+3)] = 5;
        	    tabuleirop[0][i][(j+4)] = 5;
	    	}else if(tamanho==10){
                tabuleirom[0][i][j] = 5;
                tabuleirom[0][i][(j+1)] = 5;
                tabuleirom[0][i][(j+2)] = 5;
        	    tabuleirom[0][i][(j+3)] = 5;
            	tabuleirom[0][i][(j+4)] = 5;
	    	}else if(tamanho==15){
	    	    tabuleirog[0][i][j] = 5;
            	tabuleirog[0][i][(j+1)] = 5;
            	tabuleirog[0][i][(j+2)] = 5;
            	tabuleirog[0][i][(j+3)] = 5;
        	    tabuleirog[0][i][(j+4)] = 5;
	    	}
    	}else if (x==1){  //vertical
    		i = rand() % (tamanho-4);
    	    j = rand() % (tamanho);
    	    if(tamanho==5){
        	    tabuleirop[0][i][j] = 5;
            	tabuleirop[0][(i+1)][j] = 5;
            	tabuleirop[0][(i+2)][j] = 5;
        	    tabuleirop[0][(i+3)][j] = 5;
            	tabuleirop[0][(i+4)][j] = 5;
    	    }else if(tamanho==10){
    	        tabuleirom[0][i][j] = 5;
            	tabuleirom[0][(i+1)][j] = 5;
            	tabuleirom[0][(i+2)][j] = 5;
            	tabuleirom[0][(i+3)][j] = 5;
        	    tabuleirom[0][(i+4)][j] = 5;
    	    }else if(tamanho==15){
    	        tabuleirog[0][i][j] = 5;
            	tabuleirog[0][(i+1)][j] = 5;
            	tabuleirog[0][(i+2)][j] = 5;
            	tabuleirog[0][(i+3)][j] = 5;
        	    tabuleirog[0][(i+4)][j] = 5;
    	    }
    	}

    	if(jogador==2){  //para jogador 2
            x = rand() % 2;  //vertical ou horizontal  --  barco3
    	    if(x==0){  //horizontal
	    	    i = rand() % (tamanho);
        	    j = rand() % (tamanho-4);
        	    if(tamanho==5){
                    tabuleirop[2][i][j] = 5;
                    tabuleirop[2][i][(j+1)] = 5;
                    tabuleirop[2][i][(j+2)] = 5;
                    tabuleirop[2][i][(j+3)] = 5;
                    tabuleirop[2][i][(j+4)] = 5;
        	    }else if(tamanho==10){
        	        tabuleirom[2][i][j] = 5;
                    tabuleirom[2][i][(j+1)] = 5;
                    tabuleirom[2][i][(j+2)] = 5;
                    tabuleirom[2][i][(j+3)] = 5;
                    tabuleirom[2][i][(j+4)] = 5;
        	    }else if(tamanho==15){
        	        tabuleirog[2][i][j] = 5;
                    tabuleirog[2][i][(j+1)] = 5;
                    tabuleirog[2][i][(j+2)] = 5;
                    tabuleirog[2][i][(j+3)] = 5;
                    tabuleirog[2][i][(j+4)] = 5;
        	    }
        	}else if (x==1){  //vertical
        		i = rand() % (tamanho-4);
    	        j = rand() % (tamanho);
    	        if(tamanho==5){
                    tabuleirop[2][i][j] = 5;
                    tabuleirop[2][(i+1)][j] = 5;
                    tabuleirop[2][(i+2)][j] = 5;
                    tabuleirop[2][(i+3)][j] = 5;
                    tabuleirop[2][(i+4)][j] = 5;
        	    }else if(tamanho==10){
                    tabuleirom[2][i][j] = 5;
                    tabuleirom[2][(i+1)][j] = 5;
                    tabuleirom[2][(i+2)][j] = 5;
                    tabuleirom[2][(i+3)][j] = 5;
                    tabuleirom[2][(i+4)][j] = 5;
        	    }else if(tamanho==15){
                    tabuleirog[2][i][j] = 5;
                    tabuleirog[2][(i+1)][j] = 5;
                    tabuleirog[2][(i+2)][j] = 5;
                    tabuleirog[2][(i+3)][j] = 5;
                    tabuleirog[2][(i+4)][j] = 5;
        	    }
    	    }
    	}

    	if(tamanho>5){
            y = 0;
            while(y==0){
                x = rand() % 2;  //vertical ou horizontal
                if(x==0){  //horizontal
                    i = rand() % (tamanho);
                    j = rand() % (tamanho-4);
                    if(tamanho==10){
                        if((tabuleirom[0][i][j]!=-2)||(tabuleirom[0][i][(j+1)]!=-2)||(tabuleirom[0][i][(j+2)]!=-2)||(tabuleirom[0][i][(j+3)]!=-2)||(tabuleirom[0][i][(j+4)]!=-2)){

                        }else{
                            tabuleirom[0][i][j] = 6;
                            tabuleirom[0][i][(j+1)] = 6;
                            tabuleirom[0][i][(j+2)] = 6;
                            tabuleirom[0][i][(j+3)] = 6;
                            tabuleirom[0][i][(j+4)] = 6;
                            y++;
                        }
                    }else if(tamanho==15){
                        if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][i][(j+1)]!=-2)||(tabuleirog[0][i][(j+2)]!=-2)||(tabuleirog[0][i][(j+3)]!=-2)||(tabuleirog[0][i][(j+4)]!=-2)){

                        }else{
                            tabuleirog[0][i][j] = 6;
                            tabuleirog[0][i][(j+1)] = 6;
                            tabuleirog[0][i][(j+2)] = 6;
                            tabuleirog[0][i][(j+3)] = 6;
                            tabuleirog[0][i][(j+4)] = 6;
                            y++;
                        }
                    }
                }else if (x==1){  //vertical
                    i = rand() % (tamanho-4);
                    j = rand() % (tamanho);
                    if(tamanho==10){
                        if((tabuleirom[0][i][j]!=-2)||(tabuleirom[0][(i+1)][j]!=-2)||(tabuleirom[0][(i+2)][j]!=-2)||(tabuleirom[0][(i+3)][j]!=-2)||(tabuleirom[0][(i+4)][j]!=-2)){

                        }else{
                            tabuleirom[0][i][j] = 6;
                            tabuleirom[0][(i+1)][j] = 6;
                            tabuleirom[0][(i+2)][j] = 6;
                            tabuleirom[0][(i+3)][j] = 6;
                            tabuleirom[0][(i+4)][j] = 6;
                            y++;
                        }
                    }else if(tamanho==15){
                        if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][(i+1)][j]!=-2)||(tabuleirog[0][(i+2)][j]!=-2)||(tabuleirog[0][(i+3)][j]!=-2)||(tabuleirog[0][(i+4)][j]!=-2)){

                        }else{
                            tabuleirog[0][i][j] = 6;
                            tabuleirog[0][(i+1)][j] = 6;
                            tabuleirog[0][(i+2)][j] = 6;
                            tabuleirog[0][(i+3)][j] = 6;
                            tabuleirog[0][(i+4)][j] = 6;
                            y++;
                        }
                    }
                }
            }

            if(jogador==2){
                y = 0;
                while(y==0){
                    x = rand() % 2;  //vertical ou horizontal
                    if(x==0){  //horizontal
                        i = rand() % (tamanho);
                        j = rand() % (tamanho-4);
                        if(tamanho==10){
                            if((tabuleirom[2][i][j]!=-2)||(tabuleirom[2][i][(j+1)]!=-2)||(tabuleirom[2][i][(j+2)]!=-2)||(tabuleirom[2][i][(j+3)]!=-2)||(tabuleirom[2][i][(j+4)]!=-2)){

                            }else{
                                tabuleirom[2][i][j] = 6;
                                tabuleirom[2][i][(j+1)] = 6;
                                tabuleirom[2][i][(j+2)] = 6;
                                tabuleirom[2][i][(j+3)] = 6;
                                tabuleirom[2][i][(j+4)] = 6;
                                y++;
                            }
                        }else if(tamanho==15){
                            if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][i][(j+1)]!=-2)||(tabuleirog[2][i][(j+2)]!=-2)||(tabuleirog[2][i][(j+3)]!=-2)||(tabuleirog[2][i][(j+4)]!=-2)){

                            }else{
                                tabuleirog[2][i][j] = 6;
                                tabuleirog[2][i][(j+1)] = 6;
                                tabuleirog[2][i][(j+2)] = 6;
                                tabuleirog[2][i][(j+3)] = 6;
                                tabuleirog[2][i][(j+4)] = 6;
                                y++;
                            }
                        }
                    }else if (x==1){  //vertical
                        i = rand() % (tamanho-4);
                        j = rand() % (tamanho);
                        if(tamanho==10){
                            if((tabuleirom[2][i][j]!=-2)||(tabuleirom[2][(i+1)][j]!=-2)||(tabuleirom[2][(i+2)][j]!=-2)||(tabuleirom[2][(i+3)][j]!=-2)||(tabuleirom[2][(i+4)][j]!=-2)){

                            }else{
                                tabuleirom[2][i][j] = 6;
                                tabuleirom[2][(i+1)][j] = 6;
                                tabuleirom[2][(i+2)][j] = 6;
                                tabuleirom[2][(i+3)][j] = 6;
                                tabuleirom[2][(i+4)][j] = 6;
                                y++;
                            }
                        }else if(tamanho==15){
                            if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][(i+1)][j]!=-2)||(tabuleirog[2][(i+2)][j]!=-2)||(tabuleirog[2][(i+3)][j]!=-2)||(tabuleirog[2][(i+4)][j]!=-2)){

                            }else{
                                tabuleirog[2][i][j] = 6;
                                tabuleirog[2][(i+1)][j] = 6;
                                tabuleirog[2][(i+2)][j] = 6;
                                tabuleirog[2][(i+3)][j] = 6;
                                tabuleirog[2][(i+4)][j] = 6;
                                y++;
                            }
                        }
                    }
                }
            }

            if(tamanho>10){
                y = 0;
                while(y==0){
                    x = rand() % 2;  //vertical ou horizontal
                    if(x==0){  //horizontal
                        i = rand() % (tamanho);
                        j = rand() % (tamanho-4);
                        if(tamanho==15){
                            if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][i][(j+1)]!=-2)||(tabuleirog[0][i][(j+2)]!=-2)||(tabuleirog[0][i][(j+3)]!=-2)||(tabuleirog[0][i][(j+4)]!=-2)){

                            }else{
                                tabuleirog[0][i][j] = 7;
                                tabuleirog[0][i][(j+1)] = 7;
                                tabuleirog[0][i][(j+2)] = 7;
                                tabuleirog[0][i][(j+3)] = 7;
                                tabuleirog[0][i][(j+4)] = 7;
                                y++;
                            }
                        }
                    }else if (x==1){  //vertical
                        i = rand() % (tamanho-4);
                        j = rand() % (tamanho);
                        if(tamanho==15){
                            if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][(i+1)][j]!=-2)||(tabuleirog[0][(i+2)][j]!=-2)||(tabuleirog[0][(i+3)][j]!=-2)||(tabuleirog[0][(i+4)][j]!=-2)){

                            }else{
                                tabuleirog[0][i][j] = 7;
                                tabuleirog[0][(i+1)][j] = 7;
                                tabuleirog[0][(i+2)][j] = 7;
                                tabuleirog[0][(i+3)][j] = 7;
                                tabuleirog[0][(i+4)][j] = 7;
                                y++;
                            }
                        }
                    }
                }

                if(jogador==2){
                    y = 0;
                    while(y==0){
                        x = rand() % 2;  //vertical ou horizontal
                        if(x==0){  //horizontal
                            i = rand() % (tamanho);
                            j = rand() % (tamanho-4);
                            if(tamanho==15){
                                if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][i][(j+1)]!=-2)||(tabuleirog[2][i][(j+2)]!=-2)||(tabuleirog[2][i][(j+3)]!=-2)||(tabuleirog[2][i][(j+4)]!=-2)){

                                }else{
                                    tabuleirog[2][i][j] = 7;
                                    tabuleirog[2][i][(j+1)] = 7;
                                    tabuleirog[2][i][(j+2)] = 7;
                                    tabuleirog[2][i][(j+3)] = 7;
                                    tabuleirog[2][i][(j+4)] = 7;
                                    y++;
                                }
                            }
                        }else if (x==1){  //vertical
                            i = rand() % (tamanho-4);
                            j = rand() % (tamanho);
                            if(tamanho==15){
                                if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][(i+1)][j]!=-2)||(tabuleirog[2][(i+2)][j]!=-2)||(tabuleirog[2][(i+3)][j]!=-2)||(tabuleirog[2][(i+4)][j]!=-2)){

                                }else{
                                    tabuleirog[2][i][j] = 7;
                                    tabuleirog[2][(i+1)][j] = 7;
                                    tabuleirog[2][(i+2)][j] = 7;
                                    tabuleirog[2][(i+3)][j] = 7;
                                    tabuleirog[2][(i+4)][j] = 7;
                                    y++;
                                }
                            }
                        }
                    }
                }
            }
        }

    	y = 0;
    	while(y==0){

        	x = rand() % 2;  //vertical ou horizontal
        	if(x==0){
                i = rand() % (tamanho);
                j = rand() % (tamanho-2);
                if(tamanho==5){
                    if((tabuleirop[0][i][j]!=-2)||(tabuleirop[0][i][(j+1)]!=-2)||(tabuleirop[0][i][(j+2)]!=-2)){

                    }else{
                        tabuleirop[0][i][j] = 2;
                        tabuleirop[0][i][(j+1)] = 2;
                        tabuleirop[0][i][(j+2)] = 2;
                        y = 1;
                    }
                }else if(tamanho==10){
                    if((tabuleirom[0][i][j]!=-2)||(tabuleirom[0][i][(j+1)]!=-2)||(tabuleirom[0][i][(j+2)]!=-2)){

                    }else{
                        tabuleirom[0][i][j] = 2;
                        tabuleirom[0][i][(j+1)] = 2;
                        tabuleirom[0][i][(j+2)] = 2;
                        y = 1;
                    }
                }else if(tamanho==15){
                    if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][i][(j+1)]!=-2)||(tabuleirog[0][i][(j+2)]!=-2)){

                    }else{
                        tabuleirog[0][i][j] = 2;
                        tabuleirog[0][i][(j+1)] = 2;
                        tabuleirog[0][i][(j+2)] = 2;
                        y = 1;
                    }
                }
        	}else if(x==1){
                i = rand() % (tamanho-2);
                j = rand() % (tamanho);
                if(tamanho==5){
                    if((tabuleirop[0][i][j]!=-2)||(tabuleirop[0][(i+1)][j]!=-2)||(tabuleirop[0][(i+2)][j]!=-2)){

                    }else{
                        tabuleirop[0][i][j] = 2;
                        tabuleirop[0][(i+1)][j] = 2;
                        tabuleirop[0][(i+2)][j] = 2;
                        y = 1;
                    }
                }else if(tamanho==10){
                    if((tabuleirom[0][i][j]!=-2)||(tabuleirom[0][(i+1)][j]!=-2)||(tabuleirom[0][(i+2)][j]!=-2)){

                    }else{
                        tabuleirom[0][i][j] = 2;
                        tabuleirom[0][(i+1)][j] = 2;
                        tabuleirom[0][(i+2)][j] = 2;
                        y = 1;
                    }
                }else if(tamanho==15){
                    if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][(i+1)][j]!=-2)||(tabuleirog[0][(i+2)][j]!=-2)){

                    }else{
                        tabuleirog[0][i][j] = 2;
                        tabuleirog[0][(i+1)][j] = 2;
                        tabuleirog[0][(i+2)][j] = 2;
                        y = 1;
                    }
                }
            }
        }

        if(jogador==2){
            y = 0;
            while(y==0){

                x = rand() % 2;  //vertical ou horizontal
                if(x==0){
                    i = rand() % (tamanho);
                    j = rand() % (tamanho-2);
                    if(tamanho==5){
                        if((tabuleirop[2][i][j]!=-2)||(tabuleirop[2][i][(j+1)]!=-2)||(tabuleirop[2][i][(j+2)]!=-2)){

                        }else{
                            tabuleirop[2][i][j] = 2;
                            tabuleirop[2][i][(j+1)] = 2;
                            tabuleirop[2][i][(j+2)] = 2;
                            y = 1;
                        }
                    }else if(tamanho==10){
                        if((tabuleirom[2][i][j]!=-2)||(tabuleirom[2][i][(j+1)]!=-2)||(tabuleirom[2][i][(j+2)]!=-2)){

                        }else{
                            tabuleirom[2][i][j] = 2;
                            tabuleirom[2][i][(j+1)] = 2;
                            tabuleirom[2][i][(j+2)] = 2;
                            y = 1;
                        }
                    }else if(tamanho==15){
                        if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][i][(j+1)]!=-2)||(tabuleirog[2][i][(j+2)]!=-2)){

                        }else{
                            tabuleirog[2][i][j] = 2;
                            tabuleirog[2][i][(j+1)] = 2;
                            tabuleirog[2][i][(j+2)] = 2;
                            y = 1;
                        }
                    }
                }else if(x==1){
                    i = rand() % (tamanho-2);
                    j = rand() % (tamanho);
                    if(tamanho==5){
                        if((tabuleirop[2][i][j]!=-2)||(tabuleirop[2][(i+1)][j]!=-2)||(tabuleirop[2][(i+2)][j]!=-2)){

                        }else{
                            tabuleirop[2][i][j] = 2;
                            tabuleirop[2][(i+1)][j] = 2;
                            tabuleirop[2][(i+2)][j] = 2;
                            y = 1;
                        }
                    }else if(tamanho==10){
                        if((tabuleirom[2][i][j]!=-2)||(tabuleirom[2][(i+1)][j]!=-2)||(tabuleirom[2][(i+2)][j]!=-2)){

                        }else{
                            tabuleirom[2][i][j] = 2;
                            tabuleirom[2][(i+1)][j] = 2;
                            tabuleirom[2][(i+2)][j] = 2;
                            y = 1;
                        }
                    }else if(tamanho==15){
                        if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][(i+1)][j]!=-2)||(tabuleirog[2][(i+2)][j]!=-2)){

                        }else{
                            tabuleirog[2][i][j] = 2;
                            tabuleirog[2][(i+1)][j] = 2;
                            tabuleirog[2][(i+2)][j] = 2;
                            y = 1;
                        }
                    }
                }
            }
        }

        if(tamanho>5){
            y = 0;
            while(y==0){

                x = rand() % 2;  //vertical ou horizontal
                if(x==0){
                    i = rand() % (tamanho);
                    j = rand() % (tamanho-2);
                    if(tamanho==10){
                        if((tabuleirom[0][i][j]!=-2)||(tabuleirom[0][i][(j+1)]!=-2)||(tabuleirom[0][i][(j+2)]!=-2)){

                        }else{
                            tabuleirom[0][i][j] = 3;
                            tabuleirom[0][i][(j+1)] = 3;
                            tabuleirom[0][i][(j+2)] = 3;
                            y = 1;
                        }
                    }else if(tamanho==15){
                        if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][i][(j+1)]!=-2)||(tabuleirog[0][i][(j+2)]!=-2)){

                        }else{
                            tabuleirog[0][i][j] = 3;
                            tabuleirog[0][i][(j+1)] = 3;
                            tabuleirog[0][i][(j+2)] = 3;
                            y = 1;
                        }
                    }
                }else if(x==1){
                    i = rand() % (tamanho-2);
                    j = rand() % (tamanho);
                    if(tamanho==10){
                        if((tabuleirom[0][i][j]!=-2)||(tabuleirom[0][(i+1)][j]!=-2)||(tabuleirom[0][(i+2)][j]!=-2)){

                        }else{
                            tabuleirom[0][i][j] = 3;
                            tabuleirom[0][(i+1)][j] = 3;
                            tabuleirom[0][(i+2)][j] = 3;
                            y = 1;
                        }
                    }else if(tamanho==15){
                        if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][(i+1)][j]!=-2)||(tabuleirog[0][(i+2)][j]!=-2)){

                        }else{
                            tabuleirog[0][i][j] = 3;
                            tabuleirog[0][(i+1)][j] = 3;
                            tabuleirog[0][(i+2)][j] = 3;
                            y = 1;
                        }
                    }
                }
            }

            if(jogador==2){
                y = 0;
                while(y==0){

                    x = rand() % 2;  //vertical ou horizontal
                    if(x==0){
                        i = rand() % (tamanho);
                        j = rand() % (tamanho-2);
                        if(tamanho==10){
                            if((tabuleirom[2][i][j]!=-2)||(tabuleirom[2][i][(j+1)]!=-2)||(tabuleirom[2][i][(j+2)]!=-2)){

                            }else{
                                tabuleirom[2][i][j] = 3;
                                tabuleirom[2][i][(j+1)] = 3;
                                tabuleirom[2][i][(j+2)] = 3;
                                y = 1;
                            }
                        }else if(tamanho==15){
                            if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][i][(j+1)]!=-2)||(tabuleirog[2][i][(j+2)]!=-2)){

                            }else{
                                tabuleirog[2][i][j] = 3;
                                tabuleirog[2][i][(j+1)] = 3;
                                tabuleirog[2][i][(j+2)] = 3;
                                y = 1;
                            }
                        }
                    }else if(x==1){
                        i = rand() % (tamanho-2);
                        j = rand() % (tamanho);
                        if(tamanho==10){
                            if((tabuleirom[2][i][j]!=-2)||(tabuleirom[2][(i+1)][j]!=-2)||(tabuleirom[2][(i+2)][j]!=-2)){

                            }else{
                                tabuleirom[2][i][j] = 3;
                                tabuleirom[2][(i+1)][j] = 3;
                                tabuleirom[2][(i+2)][j] = 3;
                                y = 1;
                            }
                        }else if(tamanho==15){
                            if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][(i+1)][j]!=-2)||(tabuleirog[2][(i+2)][j]!=-2)){

                            }else{
                                tabuleirog[2][i][j] = 3;
                                tabuleirog[2][(i+1)][j] = 3;
                                tabuleirog[2][(i+2)][j] = 3;
                                y = 1;
                            }
                        }
                    }
                }
            }

            if(tamanho>10){
                y = 0;
                while(y==0){

                    x = rand() % 2;  //vertical ou horizontal
                    if(x==0){
                        i = rand() % (tamanho);
                        j = rand() % (tamanho-2);
                        if(tamanho==15){
                            if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][i][(j+1)]!=-2)||(tabuleirog[0][i][(j+2)]!=-2)){

                            }else{
                                tabuleirog[0][i][j] = 4;
                                tabuleirog[0][i][(j+1)] = 4;
                                tabuleirog[0][i][(j+2)] = 4;
                                y = 1;
                            }
                        }
                    }else if(x==1){
                        i = rand() % (tamanho-2);
                        j = rand() % (tamanho);
                        if(tamanho==15){
                            if((tabuleirog[0][i][j]!=-2)||(tabuleirog[0][(i+1)][j]!=-2)||(tabuleirog[0][(i+2)][j]!=-2)){

                            }else{
                                tabuleirog[0][i][j] = 4;
                                tabuleirog[0][(i+1)][j] = 4;
                                tabuleirog[0][(i+2)][j] = 4;
                                y = 1;
                            }
                        }
                    }
                }

                if(jogador==2){
                y = 0;
                while(y==0){

                    x = rand() % 2;  //vertical ou horizontal
                    if(x==0){
                        i = rand() % (tamanho);
                        j = rand() % (tamanho-2);
                        if(tamanho==15){
                            if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][i][(j+1)]!=-2)||(tabuleirog[2][i][(j+2)]!=-2)){

                            }else{
                                tabuleirog[2][i][j] = 4;
                                tabuleirog[2][i][(j+1)] = 4;
                                tabuleirog[2][i][(j+2)] = 4;
                                y = 1;
                            }
                        }
                    }else if(x==1){
                        i = rand() % (tamanho-2);
                        j = rand() % (tamanho);
                        if(tamanho==15){
                            if((tabuleirog[2][i][j]!=-2)||(tabuleirog[2][(i+1)][j]!=-2)||(tabuleirog[2][(i+2)][j]!=-2)){

                            }else{
                                tabuleirog[2][i][j] = 4;
                                tabuleirog[2][(i+1)][j] = 4;
                                tabuleirog[2][(i+2)][j] = 4;
                                y = 1;
                            }
                        }
                    }
                }
            }
            }
        }

        if(tamanho==5){
            i = rand() % (tamanho);  //posição coluna barco1
            j = rand() % (tamanho);  //posição linha barco1

            while(tabuleirop[0][i][j] != -2){
                i = rand() % (tamanho);  //posição coluna barco1 - novo
                j = rand() % (tamanho);  //posição linha barco1 - novo
            }

            tabuleirop[0][i][j] = 1;  //posição matriz barco1
        }else if(tamanho==10){
            i = rand() % (tamanho);  //posição coluna barco1
            j = rand() % (tamanho);  //posição linha barco1

            while(tabuleirom[0][i][j] != -2){
                i = rand() % (tamanho);  //posição coluna barco1 - novo
                j = rand() % (tamanho);  //posição linha barco1 - novo
            }

            tabuleirom[0][i][j] = 1;  //posição matriz barco1

            i = rand() % (tamanho);  //posição coluna barco1
            j = rand() % (tamanho);  //posição linha barco1

            while(tabuleirom[0][i][j] != -2){
                i = rand() % (tamanho);  //posição coluna barco1 - novo
                j = rand() % (tamanho);  //posição linha barco1 - novo
            }

            tabuleirom[0][i][j] = 1;  //posição matriz barco1
        }else if(tamanho==15){
            i = rand() % (tamanho);  //posição coluna barco1
            j = rand() % (tamanho);  //posição linha barco1

            while(tabuleirog[0][i][j] != -2){
                i = rand() % (tamanho);  //posição coluna barco1 - novo
                j = rand() % (tamanho);  //posição linha barco1 - novo
            }

            tabuleirog[0][i][j] = 1;  //posição matriz barco1

            i = rand() % (tamanho);  //posição coluna barco1
            j = rand() % (tamanho);  //posição linha barco1

            while(tabuleirog[0][i][j] != -2){
                i = rand() % (tamanho);  //posição coluna barco1 - novo
                j = rand() % (tamanho);  //posição linha barco1 - novo
            }

            tabuleirog[0][i][j] = 1;  //posição matriz barco1

            i = rand() % (tamanho);  //posição coluna barco1
            j = rand() % (tamanho);  //posição linha barco1

            while(tabuleirog[0][i][j] != -2){
                i = rand() % (tamanho);  //posição coluna barco1 - novo
                j = rand() % (tamanho);  //posição linha barco1 - novo
            }

            tabuleirog[0][i][j] = 1;  //posição matriz barco1
        }

    	if(jogador==2){
            if(tamanho==5){
                i = rand() % (tamanho);  //posição coluna barco1
                j = rand() % (tamanho);  //posição linha barco1

                while(tabuleirop[2][i][j] != -2){
                    i = rand() % (tamanho);  //posição coluna barco1 - novo
                    j = rand() % (tamanho);  //posição linha barco1 - novo
                }

                tabuleirop[2][i][j] = 1;  //posição matriz barco1
            }else if(tamanho==10){
                i = rand() % (tamanho);  //posição coluna barco1
                j = rand() % (tamanho);  //posição linha barco1

                while(tabuleirog[2][i][j] != -2){
                    i = rand() % (tamanho);  //posição coluna barco1 - novo
                    j = rand() % (tamanho);  //posição linha barco1 - novo
                }

                tabuleirog[2][i][j] = 1;  //posição matriz barco1

                i = rand() % (tamanho);  //posição coluna barco1
                j = rand() % (tamanho);  //posição linha barco1

                while(tabuleirog[2][i][j] != -2){
                    i = rand() % (tamanho);  //posição coluna barco1 - novo
                    j = rand() % (tamanho);  //posição linha barco1 - novo
                }

                tabuleirog[2][i][j] = 1;  //posição matriz barco1
            }else if(tamanho==15){
                i = rand() % (tamanho);  //posição coluna barco1
                j = rand() % (tamanho);  //posição linha barco1

                while(tabuleirog[2][i][j] != -2){
                    i = rand() % (tamanho);  //posição coluna barco1 - novo
                    j = rand() % (tamanho);  //posição linha barco1 - novo
                }

                tabuleirog[2][i][j] = 1;  //posição matriz barco1

                i = rand() % (tamanho);  //posição coluna barco1
                j = rand() % (tamanho);  //posição linha barco1

                while(tabuleirog[2][i][j] != -2){
                    i = rand() % (tamanho);  //posição coluna barco1 - novo
                    j = rand() % (tamanho);  //posição linha barco1 - novo
                }

                tabuleirog[2][i][j] = 1;  //posição matriz barco1

                i = rand() % (tamanho);  //posição coluna barco1
                j = rand() % (tamanho);  //posição linha barco1

                while(tabuleirog[2][i][j] != -2){
                    i = rand() % (tamanho);  //posição coluna barco1 - novo
                    j = rand() % (tamanho);  //posição linha barco1 - novo
                }

                tabuleirog[2][i][j] = 1;  //posição matriz barco1
            }
        }

        j1b1 = 0;  //resetar valor contador sub
        j2b1 = 0;
        j1b2 = 0;  //resetar valor contador ru
        j2b2 = 0;
        j1b3 = 0;
        j2b3 = 0;
        j1b4 = 0;
        j2b4 = 0;
        j1b5 = 0;  //resetar valor contador port
        j2b5 = 0;
        j1b6 = 0;
        j2b6 = 0;
        j1b7 = 0;
        j2b7 = 0;
        sub1 = 0;
        sub2 = 0;
        cru1 = 0;
        cru2 = 0;
        port1 = 0;
        port2 = 0;
        jogo = 0;  //zerar valor para jogo começar

    	/*for(i=0; i<(tamanho); i++){  //teste
    		for(j=0; j<(tamanho); j++){
                if(tamanho==5){  //se tamanho ==5
        	    	printf("%d\t", tabuleirop[1][i][j]);  //teste tabuleiro falso
                    //printf("%d\t", tabuleirop[0][i][j]);  //teste tabuleiro verdadeiro
                }else if(tamanho==10){  //se tamanho ==10
        	    	printf("%d\t", tabuleirom[1][i][j]);  //teste tabuleiro falso
                    //printf("%d\t", tabuleirom[0][i][j]);  //teste tabuleiro verdadeiro
                }else if(tamanho==15){  //se tamanho ==15
        	    	//printf("%d\t", tabuleirog[1][i][j]);  //teste tabuleiro falso
                    printf("%d\t", tabuleirog[0][i][j]);  //teste tabuleiro verdadeiro
                }
    		}
    	printf("\n");
    	}

    	system("pause");  //teste
    	system("cls");*/  //teste

	    tempo1 = clock();

        while(jogo==0){  //começa jogo

    	    system ("color F1");  //fundo branco, letra azul (para jogo - jogador 1)

    	    for(i=0; i<2; i++){
                for(j=0; j<16; j++){
                    printf("- - - -\t");
                }
                printf("\n");
    	    }

    	    printf("\tX=Acerto\tO=Erro\t\tJOGADOR 1\t\tSubmarino:%d/%d\tCruzador:%d/%d\tPorta-Avioes:%d/%d", sub1, (tamanho/5), cru1, (tamanho/5), port1, (tamanho/5));

    	    printf("\n\n");

            for(i=-1; i<(tamanho); i++){
                for(j=0; j<((15-tamanho)/2); j++){
                    printf("\t");
                }
                if(i!=-1){
                    printf("%d\t", (i+1));
                }
                for(j=-1; j<(tamanho); j++){
                    if(i==-1){
                        if(j==-1){
                            printf("\t");
                        }else if(j!=-1){
                            printf("%d\t", (j+1));
                        }
                    }else if(j>=0){
                        if(tamanho==5){
                            //printf("%d\t", tabuleirop[1][i][j]);  //teste
                            if(tabuleirop[1][i][j]==-1){  //se falso ==-1
                                printf("~\t");  //printar "água"
                            }
                            else if(tabuleirop[1][i][j]==0){  //se falso ==0 printar valor referente ao verdadeiro:
                                if(tabuleirop[0][i][j]==-2){  //se verdadeiro ==-2
                                    printf("O\t");  //printar "tiro na água"
                                }else if((tabuleirop[0][i][j]>0)&&(tabuleirop[0][i][j]<8)){  //se verdadeiro >0 e <8
                                    printf("X\t");  //printar acerto
                                //}else if(tabuleirop[0][i][j]==2){
                                    //printf("X\t");
                                //}else if(tabuleirop[0][i][j]==3){
                                    //printf("X\t");
                                }
                            }
                        }else if(tamanho==10){
                            //printf("%d\t", tabuleirom[1][i][j]);  //teste
                            if(tabuleirom[1][i][j]==-1){  //se falso ==-1
                                printf("~\t");  //printar "água"
                            }
                            else if(tabuleirom[1][i][j]==0){  //se falso ==0 printar valor referente ao verdadeiro:
                                if(tabuleirom[0][i][j]==-2){  //se verdadeiro ==-2
                                    printf("O\t");  //printar "tiro na água"
                                }else if((tabuleirom[0][i][j]>0)&&(tabuleirom[0][i][j]<8)){  //se verdadeiro >0 e <8
                                    printf("X\t");  //printar acerto
                                //}else if(tabuleirom[0][i][j]==2){
                                    //printf("X\t");
                                //}else if(tabuleirom[0][i][j]==3){
                                    //printf("X\t");
                                }
                            }
                        }else if(tamanho==15){
                            //printf("%d\t", tabuleirog[1][i][j]);  //teste
                            if(tabuleirog[1][i][j]==-1){  //se falso ==-1
                                printf("~\t");  //printar "água"
                            }
                            else if(tabuleirog[1][i][j]==0){  //se falso ==0 printar valor referente ao verdadeiro:
                                if(tabuleirog[0][i][j]==-2){  //se verdadeiro ==-2
                                    printf("O\t");  //printar "tiro na água"
                                }else if((tabuleirog[0][i][j]>0)&&(tabuleirog[0][i][j]<8)){  //se verdadeiro >0 e <8
                                    printf("X\t");  //printar acerto
                                //}else if(tabuleirog[0][i][j]==2){
                                    //printf("X\t");
                                //}else if(tabuleirog[0][i][j]==3){
                                    //printf("X\t");
                                }
                            }
                        }
                    }
                }
                printf("\n");
            }

            printf("\n\n\n\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
            scanf("%d", &i);  //receber linha do jogador
            i--;
            while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                scanf("%d", &i);  //receber novamente a opção
                i--;
            }

            printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
            scanf("%d", &j);  //receber coluna do jogador
            j--;
            while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma coluna de 1 a %d: ", tamanho);
                scanf("%d", &j);  //receber novamente a opção
                j--;
            }

            if(tamanho==5){
                while(tabuleirop[1][i][j]!=-1){  //caso a opção já tenha sido selecionada, receber novamente os valores
                    printf("\n\t\tPosicoes ja selecionadas anteriormente. Escolha outra combinacao.\n");
                    printf("\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
                    scanf("%d", &i);  //receber linha
                    i--;
                    while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                        scanf("%d", &i);  //receber novamente a opção
                        i--;
                    }
                    printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
                    scanf("%d", &j);  //receber coluna
                    j--;
                    while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\nEscolha uma coluna de 1 a %d: ", tamanho);
                        scanf("%d", &j);  //receber novamente a opção
                        j--;
                    }
                }
            }else if(tamanho==10){
                while(tabuleirom[1][i][j]!=-1){  //caso a opção já tenha sido selecionada, receber novamente os valores
                    printf("\n\t\tPosicoes ja selecionadas anteriormente. Escolha outra combinacao.\n");
                    printf("\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
                    scanf("%d", &i);  //receber linha
                    i--;
                    while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                        scanf("%d", &i);  //receber novamente a opção
                        i--;
                    }
                    printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
                    scanf("%d", &j);  //receber coluna
                    j--;
                    while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\nEscolha uma coluna de 1 a %d: ", tamanho);
                        scanf("%d", &j);  //receber novamente a opção
                        j--;
                    }
                }
            }else if(tamanho==15){
                while(tabuleirog[1][i][j]!=-1){  //caso a opção já tenha sido selecionada, receber novamente os valores
                    printf("\n\t\tPosicoes ja selecionadas anteriormente. Escolha outra combinacao.\n");
                    printf("\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
                    scanf("%d", &i);  //receber linha
                    i--;
                    while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                        scanf("%d", &i);  //receber novamente a opção
                        i--;
                    }
                    printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
                    scanf("%d", &j);  //receber coluna
                    j--;
                    while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\nEscolha uma coluna de 1 a %d: ", tamanho);
                        scanf("%d", &j);  //receber novamente a opção
                        j--;
                    }
                }

            }

            if(tamanho==5){
                tabuleirop[1][i][j] = 0;  //tabuleiro falso recebe 0 na cordenasa selecionada

                if(tabuleirop[0][i][j] != -2){  //se tabuleiro verdadeiro !=-2
                    if(tabuleirop[0][i][j]==1){  //e se tabuleiro verdadeiro ==1
                        j1b1++;
                        sub1++;
                        printf("\n\t\tVoce afundou um submarino.");
                    }else if(tabuleirop[0][i][j]==2){  //e se tabuleiro verdadeiro ==2
                        j1b2++;
                        if(j1b2==3){
                            cru1++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirop[0][i][j]==5){  //e se tabuleiro verdadeiro ==5
                        j1b5++;
                        if(j1b5==5){
                            port1++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }
                }
            }else if(tamanho==10){
                tabuleirom[1][i][j] = 0;  //tabuleiro falso recebe 0 na cordenasa selecionada

                if(tabuleirom[0][i][j] != -2){  //se tabuleiro verdadeiro !=-2
                    if(tabuleirom[0][i][j]==1){  //e se tabuleiro verdadeiro ==1
                        j1b1++;
                        sub1++;
                        printf("\n\t\tVoce afundou um submarino.");
                    }else if(tabuleirom[0][i][j]==2){  //e se tabuleiro verdadeiro ==2
                        j1b2++;
                        if(j1b2==3){
                            cru1++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirom[0][i][j]==3){
                        j1b3++;
                        if(j1b3==3){
                            cru1++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirom[0][i][j]==5){  //e se tabuleiro verdadeiro ==5
                        j1b5++;
                        if(j1b5==5){
                            port1++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }else if(tabuleirom[0][i][j]){
                        j1b6++;
                        if(j1b6==5){
                            port1++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }
                }
            }else if(tamanho==15){
                tabuleirog[1][i][j] = 0;  //tabuleiro falso recebe 0 na cordenasa selecionada

                if(tabuleirog[0][i][j] != -2){  //se tabuleiro verdadeiro !=-2
                    if(tabuleirog[0][i][j]==1){  //e se tabuleiro verdadeiro ==1
                        j1b1++;
                        sub1++;
                        printf("\n\t\tVoce afundou um submarino.");
                    }else if(tabuleirog[0][i][j]==2){  //e se tabuleiro verdadeiro ==2
                        j1b2++;
                        if(j1b2==3){
                            cru1++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirog[0][i][j]==3){
                        j1b3++;
                        if(j1b3==3){
                            cru1++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirog[0][i][j]==4){
                        j1b4++;
                        if(j1b4==3){
                            cru1++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirog[0][i][j]==5){  //e se tabuleiro verdadeiro ==5
                        j1b5++;
                        if(j1b5==5){
                            port1++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }else if(tabuleirog[0][i][j]==6){
                        j1b6++;
                        if(j1b6==5){
                            port1++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }else if(tabuleirog[0][i][j]==7){
                        j1b7++;
                        if(j1b7==5){
                            port1++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }
                }
            }

            if((sub1==(tamanho/5))&&(cru1==(tamanho/5))&&(port1==(tamanho/5))){  //se todos os barcos cairem
                jogo++;  //acabar o jogo
            }

            printf("\n\n\t\t");
            printf("Deseja sair do jogo? Se sim, aperte ESC.\n\n\t\t");
            tecla=getch();
            if(tecla==ESC){
                main();
            }

            system("cls");

            if((jogador==2)&&(jogo==0)){

                system("color 84");  //fundo inza, letra vermelho (para jogo - jogador 2)

                for(i=0; i<2; i++){
                    for(j=0; j<16; j++){
                        printf("- - - -\t");
                    }
                    printf("\n");
    	        }

    	        printf("\tX=Acerto\tO=Erro\t\tJOGADOR 2\t\tSubmarino:%d/%d\tCruzador:%d/%d\tPorta-Avioes:%d/%d", sub2, (tamanho/5), cru2, (tamanho/5, port2, (tamanho/5)));

    	        printf("\n\n");

                for(i=-1; i<(tamanho); i++){
                    for(j=0; j<((15-tamanho)/2); j++){
                        printf("\t");
                    }
                    if(i!=-1){
                        printf("%d\t", (i+1));
                    }
                for(j=-1; j<(tamanho); j++){
                    if(i==-1){
                        if(j==-1){
                            printf("\t");
                        }else if(j!=-1){
                            printf("%d\t", (j+1));
                        }
                    }else if(j>=0){
                        if(tamanho==5){
                            //printf("%d\t", tabuleirop[3][i][j]);  //teste
                            if(tabuleirop[3][i][j]==-1){  //se falso ==-1
                                printf("~\t");  //printar "água"
                            }
                            else if(tabuleirop[3][i][j]==0){  //se falso ==0 printar valor referente ao verdadeiro:
                                if(tabuleirop[2][i][j]==-2){  //se verdadeiro ==-2
                                    printf("O\t");  //printar "tiro na água"
                                }else if((tabuleirop[2][i][j]>0)||(tabuleirop[2][i][j]<8)){  //se verdadeiro >0 e <8
                                    printf("X\t");  //printar acerto
                                //}else if(tabuleirop[2][i][j]==2){
                                    //printf("X\t");
                                //}else if(tabuleirop[2][i][j]==3){
                                    //printf("X\t");
                                }
                            }
                        }else if(tamanho==10){
                            //printf("%d\t", tabuleirom[3][i][j]);  //teste
                            if(tabuleirom[3][i][j]==-1){  //se falso ==-1
                                printf("~\t");  //printar "água"
                            }
                            else if(tabuleirom[3][i][j]==0){  //se falso ==0 printar valor referente ao verdadeiro:
                                if(tabuleirom[2][i][j]==-2){  //se verdadeiro ==-2
                                    printf("O\t");  //printar "tiro na água"
                                }else if((tabuleirom[2][i][j]>0)||(tabuleirom[2][i][j]<8)){  //se verdadeiro >0 e <8
                                    printf("X\t");  //printar acerto
                                //}else if(tabuleirom[2][i][j]==2){
                                    //printf("X\t");
                                //}else if(tabuleirom[2][i][j]==3){
                                    //printf("X\t");
                                }
                            }
                        }else if(tamanho==15){
                            //printf("%d\t", tabuleirog[3][i][j]);  //teste
                            if(tabuleirog[3][i][j]==-1){  //se falso ==-1
                                printf("~\t");  //printar "água"
                            }
                            else if(tabuleirog[3][i][j]==0){  //se falso ==0 printar valor referente ao verdadeiro:
                                if(tabuleirog[2][i][j]==-2){  //se verdadeiro ==-2
                                    printf("O\t");  //printar "tiro na água"
                                }else if((tabuleirog[2][i][j]>0)||(tabuleirog[2][i][j]<8)){  //se verdadeiro >0 e <8
                                    printf("X\t");  //printar acerto
                                //}else if(tabuleirog[2][i][j]==2){
                                    //printf("X\t");
                                //}else if(tabuleirog[2][i][j]==3){
                                    //printf("X\t");
                                }
                            }
                        }
                    }
                }
                printf("\n");
            }

            printf("\n\n\n\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
            scanf("%d", &i);  //receber linha do jogador
            i--;
            while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                scanf("%d", &i);  //receber novamente a opção
                i--;
            }

            printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
            scanf("%d", &j);  //receber coluna do jogador
            j--;
            while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma coluna de 1 a %d: ", tamanho);
                scanf("%d", &j);  //receber novamente a opção
                j--;
            }

            if(tamanho==5){
                while(tabuleirop[3][i][j]!=-1){  //caso a opção já tenha sido selecionada, receber novamente os valores
                    printf("\n\t\tPosicoes ja selecionadas anteriormente. Escolha outra combinacao.\n");
                    printf("\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
                    scanf("%d", &i);  //receber linha
                    i--;
                    while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                        scanf("%d", &i);  //receber novamente a opção
                        i--;
                    }
                    printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
                    scanf("%d", &j);  //receber coluna
                    j--;
                    while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\nEscolha uma coluna de 1 a %d: ", tamanho);
                        scanf("%d", &j);  //receber novamente a opção
                        j--;
                    }
                }
            }else if(tamanho==10){
                while(tabuleirom[3][i][j]!=-1){  //caso a opção já tenha sido selecionada, receber novamente os valores
                    printf("\n\t\tPosicoes ja selecionadas anteriormente. Escolha outra combinacao.\n");
                    printf("\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
                    scanf("%d", &i);  //receber linha
                    i--;
                    while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                        scanf("%d", &i);  //receber novamente a opção
                        i--;
                    }
                    printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
                    scanf("%d", &j);  //receber coluna
                    j--;
                    while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\nEscolha uma coluna de 1 a %d: ", tamanho);
                        scanf("%d", &j);  //receber novamente a opção
                        j--;
                    }
                }
            }else if(tamanho==15){
                while(tabuleirog[3][i][j]!=-1){  //caso a opção já tenha sido selecionada, receber novamente os valores
                    printf("\n\t\tPosicoes ja selecionadas anteriormente. Escolha outra combinacao.\n");
                    printf("\t\tEscolha uma linha (entre 1 e %d): ", tamanho);
                    scanf("%d", &i);  //receber linha
                    i--;
                    while((i<0)||(i>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\n\t\tEscolha uma linha de 1 a %d: ", tamanho);
                        scanf("%d", &i);  //receber novamente a opção
                        i--;
                    }
                    printf("\n\t\tEscolha uma coluna (entre 1 e %d): ", tamanho);
                    scanf("%d", &j);  //receber coluna
                    j--;
                    while((j<0)||(j>(tamanho-1))){  //caso opção seja inválida
                        printf("\n\n\t\tOpcao invalida.\nEscolha uma coluna de 1 a %d: ", tamanho);
                        scanf("%d", &j);  //receber novamente a opção
                        j--;
                    }
                }

            }

            if(tamanho==5){
                tabuleirop[3][i][j] = 0;  //tabuleiro falso recebe 0 na cordenasa selecionada

                if(tabuleirop[2][i][j] != -2){  //se tabuleiro verdadeiro !=-2
                    if(tabuleirop[2][i][j]==1){  //e se tabuleiro verdadeiro ==1
                        j2b1++;
                        sub2++;
                        printf("\n\t\tVoce afundou um submarino.");
                    }else if(tabuleirop[2][i][j]==2){  //e se tabuleiro verdadeiro ==2
                        j2b2++;
                        if(j2b2==3){
                            cru2++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirop[2][i][j]==5){  //e se tabuleiro verdadeiro ==3
                        j2b5++;
                        if(j2b5==5){
                            port2++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }
                }
            }else if(tamanho==10){
                tabuleirom[3][i][j] = 0;  //tabuleiro falso recebe 0 na cordenasa selecionada

                if(tabuleirom[2][i][j] != -2){  //se tabuleiro verdadeiro !=-2
                    if(tabuleirom[2][i][j]==1){  //e se tabuleiro verdadeiro ==1
                        j2b1++;
                        sub2++;
                        printf("\n\t\tVoce afundou um submarino.");
                    }else if(tabuleirom[2][i][j]==2){  //e se tabuleiro verdadeiro ==2
                        j2b2++;
                        if(j2b2==3){
                            cru2++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirom[2][i][j]==3){  //e se tabuleiro verdadeiro ==3
                        j2b3++;
                        if(j2b3==3){
                            cru2++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirom[2][i][j]==5){
                        j2b5++;
                        if(j2b5==5){
                            port2++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }else if(tabuleirom[2][i][j]==6){
                        j2b6++;
                        if(j2b6==5){
                            port2++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }
                }
            }else if(tamanho==15){
                tabuleirog[3][i][j] = 0;  //tabuleiro falso recebe 0 na cordenasa selecionada

                if(tabuleirog[2][i][j] != -2){  //se tabuleiro verdadeiro !=-2
                    if(tabuleirog[2][i][j]==1){  //e se tabuleiro verdadeiro ==1
                        j2b1++;
                        sub2++;
                        printf("\n\t\tVoce afundou um submarino.");
                    }else if(tabuleirog[2][i][j]==2){  //e se tabuleiro verdadeiro ==2
                        j2b2++;
                        if(j2b2==3){
                            cru2++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirog[2][i][j]==3){  //e se tabuleiro verdadeiro ==3
                        j2b3++;
                        if(j2b3==3){
                            cru2++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirog[2][i][j]==4){  //e se tabuleiro verdadeiro ==2
                        j2b4++;
                        if(j2b4==3){
                            cru2++;
                            printf("\n\t\tVoce afundou um cruzador.");
                        }
                    }else if(tabuleirog[2][i][j]==5){  //e se tabuleiro verdadeiro ==3
                        j2b5++;
                        if(j2b5==5){
                            port2++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }else if(tabuleirog[2][i][j]==6){  //e se tabuleiro verdadeiro ==2
                        j2b6++;
                        if(j2b6==5){
                            port2++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }else if(tabuleirog[2][i][j]==7){  //e se tabuleiro verdadeiro ==3
                        j2b7++;
                        if(j2b7==5){
                            port2++;
                            printf("\n\t\tVoce afundou um porta-avioes.");
                        }
                    }
                }
            }

            if((sub2==(tamanho/5))&&(cru2==(tamanho/5))&&(port2==(tamanho/5))){  //se todos os barcos cairem
                jogo++;  //acabar o jogo
            }

            printf("\n\n\t\t");

            printf("Deseja sair do jogo? Se sim, aperte ESC.\n\n\t\t");
            tecla=getch();
            if(tecla==ESC){
                main();
            }

            system("cls");
            }
      	}

      	tempo2 = clock();

      	system("color 76");

        printf("\t\t                                \n");
        printf("\t\t\t\t     ____________________       \n");
        printf("\t\t\t\t   /|                    |\\    \n");
        printf("\t\t\t\t /  |                    | \\   \n");
        printf("\t\t\t\t |  |                    |  |   \n");
        printf("\t\t\t\t  \\ |                    | /   \n");
        printf("\t\t\t\t   \\|                    |/    \n");
        printf("\t\t\t\t    |                    |      \n");
        printf("\t\t\t\t     \\                  /      \n");
        printf("\t\t\t\t      \\                /       \n");
        printf("\t\t\t\t       \\              /        \n");
        printf("\t\t\t\t        |            |          \n");
        printf("\t\t\t\t         |          |           \n");
        printf("\t\t\t\t          |        |            \n");
        printf("\t\t\t\t           |      |             \n");
        printf("\t\t\t\t           |      |             \n");
        printf("\t\t\t\t      _____|      |_____        \n");
        if((sub1==(tamanho/5))&&(cru1==(tamanho/5))&&(port1==(tamanho/5)))printf("\t\t\t\t     |     PLAYER 1     |       \n");
        if((sub2==(tamanho/5))&&(cru2==(tamanho/5))&&(port2==(tamanho/5)))printf("\t\t\t\t     |     PLAYER 2     |       \n");
        printf("\t\t\t\t     |   VOCE VENCEU!!  |       \n");
        printf("\t\t\t\t     | Tempo: %2.2f min. |       \n",((tempo2-tempo1)/CLOCKS_PER_SEC)/60);
        printf("\t\t\t\t      ------------------        \n\n\t\t\t");

        system("pause");
        system("cls");
    }


    system("pause");

    return 0;
}
