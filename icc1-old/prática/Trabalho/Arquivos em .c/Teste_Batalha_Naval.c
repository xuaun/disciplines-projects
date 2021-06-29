#include<stdio.h>
#include<time.h>

//iniciando o jogo system("title Batalha Naval");
//menu = system("color 02");
//jogo = system ("color F1");
//colocar clock() para pegar tempo de partida


int main(){
	int tabuleiro[5][5];
//	int barco1 = 1;
//	int barco2[3] = {2};
//	int barco3[5] = {3};
	int i, j;
	int x, y;
	int menu = 0;
	
    srand(time(NULL));
	
	system("title Batalha Naval");

   	while(menu==0){	
   	    
   	    system("color 02");
   	    
   	    printf("\n\n\t\t\t\t ________________________________\n");
   	    printf("\t\t\t\t|Bem-vindo ao batalha naval.\t|\n");
   	    printf("\t\t\t\t|\t\t\t\t|\n");
   	    printf("\t\t\t\t|\t1 jogador\t\t|\n");
   	    printf("\t\t\t\t|_______________________________|\n\n");
   	    
   	    printf("\t\t\t\t");
   	    
   	    system("pause");
   	    system("cls");
   	    
    	for(i=0; i<5; i++){
    		for(j=0; j<5; j++){
    			tabuleiro[i][j] = -1;  //Receber valor -1 (água)
    		//	printf("%d\t", tabuleiro[i][j]);  //teste tabuleiro
    		}
    	//	printf("\n");
    	} 
    	
    	x = rand() % 2;  //vertical ou horizontal  --  barco3
    	if(x==0){  //horizontal
	    	i = rand() % 5;
        	j = rand() % 1;
	    	tabuleiro[i][j] = 3;
        	tabuleiro[i][(j+1)] = 3;
        	tabuleiro[i][(j+2)] = 3;
        	tabuleiro[i][(j+3)] = 3;
        	tabuleiro[i][(j+4)] = 3;
    	}else if (x==1){  //vertical
    		i = rand() % 1;
    	    j = rand() % 5;
    	    tabuleiro[i][j] = 3;
        	tabuleiro[(i+1)][j] = 3;
        	tabuleiro[(i+2)][j] = 3;
        	tabuleiro[(i+3)][j] = 3;
        	tabuleiro[(i+4)][j] = 3;
    	}
    	y = 0;
	    
    	while(y==0){
	    	
        	x = rand() % 2;  //vertical ou horizontal  --  barco2
	    	while (x==0){  //horizontal
	    	    i = rand() % 5;
            	j = rand() % 3;
        	    if((tabuleiro[i][j]!=-1)||(tabuleiro[i][(j+1)]!=-1)||(tabuleiro[i][(j+2)]!=-1)){
        	    	
	    		}else{
	        	    tabuleiro[i][j] = 2;
    	            tabuleiro[i][(j+1)] = 2;
                	tabuleiro[i][(j+2)] = 2;
                	y = 1;
                	x = 2;
                }
    	    }	    
		    while (x==1){  //vertical
		        i = rand() % 3;
        	    j = rand() % 5;
        	    if((tabuleiro[i][j]!=-1)||(tabuleiro[(i+1)][j]!=-1)||(tabuleiro[(i+2)][j]!=-1)){
    	            
			    }else{
	                tabuleiro[i][j] = 2;
        	        tabuleiro[(i+1)][j] = 2;
                	tabuleiro[(i+2)][j] = 2;
            	    y = 1;
            	    x = 2;
                }
	        }
        }
    	
    	i = rand() % 5;  //posição coluna barco1
    	j = rand() % 5;  //posição linha barco1
    	
    	while(tabuleiro[i][j] != -1){
    		i = rand() % 5;  //posição coluna barco1 - novo
        	j = rand() % 5;  //posição linha barco1 - novo
    	}
    	
    	tabuleiro[i][j] = 1;  //posição matriz barco1
    	
    	system ("color F1");
    	
    	for(i=0; i<5; i++){
    		for(j=0; j<5; j++){
    			if(tabuleiro[i][j]==-1){
    				printf("~\t");
    			}else if(tabuleiro[i][j]==1){
    				printf("X\t");
    			}else if(tabuleiro[i][j]==2){
    				printf("Y\t");
    			}else if(tabuleiro[i][j]==3){
    				printf("Z\t");
    		    }
    			
    			//printf("%d\t", tabuleiro[i][j]);
    		}
    		printf("\n");
	    }
	    
	    system("pause");
	    system("cls");
	
    }

	
	system("pause");
	
	return 0;
}
