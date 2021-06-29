#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define SIM 0
#define NAO 1
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define POSICAO 15
#define ENTER 13

#define W 176
#define I 176

void player1();
//void rank();
//void player2();
int main();

//Globais
char opt;
int linha_atual=0, coluna_atual=0,tiros,jacomecou=NAO, tecla,pontos=0,linha,coluna,
    linha_atual2=0, coluna_atual2=0,tiros2,pontos2=0,perde=0,doisp=NAO,

//Pontuações Player 1
    cont_sub=0, af_sub=0,cont_enc=0, af_enc=0, cont_cruz=0,
    af_cruz=0, cont_hidro=0, af_hidro=0, cont_pa=0, af_pa=0,

//Pontuações Player 2
    cont_sub2=0, af_sub2=0,cont_enc2=0, af_enc2=0, cont_cruz2=0,
    af_cruz2=0, cont_hidro2=0, af_hidro2=0, cont_pa2=0, af_pa2=0;


float tempo;

char mapa[16][26]={              //Mapa que aparecerá pro jogador
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W},
                   {W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W}};

int  mapareveal[16][26]={                  //Mapa Revelado
                   {0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 1, 0, 0, 0, 0, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


void impmapa(){ //Função pra tela fixa
system("cls");
int linha,coluna;
puts("*******************************************************************************");
puts("******************************** BATALHA NAVAL ********************************");
puts("****************************************************************** Ver: 4.0 ***");
//if(doisp==SIM)puts("                                    PLAYER 1");
printf(" Mapa:                                                 ");
if(tiros<15){/*cortexto(140)*/; printf("  Tiros Restantes: %d\n\n",tiros); /*cortexto(129)*/;}
else printf("   Tiros Restantes: %d\n\n",tiros);
              /*cortexto(137);*/
              for (linha=0;linha<16;linha++){
                  printf("\t\t\t   ");//manter no meio do prog
              for(coluna=0;coluna<26;coluna++) {
                  if ((linha == linha_atual)&&(coluna == coluna_atual)&&(tecla!=ENTER)){/*cortexto(156)*/; printf("%c",POSICAO); /*cortexto(137)*/;}
                    else printf("%c",mapa[linha][coluna]);
              }
                  printf("\n");
        } // fim for
/*cortexto(129);*/
//DEBUG
///printf("\nlinha_atual=%d  coluna_atual=%d tecla=%d pontos=%d \n",linha_atual,coluna_atual,tecla,pontos);


         return;
}//fim void

void player1(){

for(;;){
for(;;){

        impmapa(); //Funçao Imprime o Mapa

        printf("\n Movimentos:\n"); // Imprime as direcoes
        printf("     %c          \t\t\t%c Submarino:     %d/1 |\tAfundou: %d/3 \n",30,4,cont_sub,af_sub);
        printf("   %c %c %c        \t\t\t%c Encoura%cado:   %d/2 |\tAfundou: %d/2 \n",17,197,16,16,135,cont_enc,af_enc);
        printf("     %c          \t\t\t%c Cruzador:      %d/3 |\tAfundou: %d/3 \n"  ,31,205,cont_cruz,af_cruz);
        printf("                 \t\t\t%c Hidro Avi%co:   %d/4 |\tAfundou: %d/4 \n",254,198,cont_hidro,af_hidro);
        printf("ENTER=Atirar\t  ESC=Menu   \t\t%c Porta Avi%co:   %d/5 |\tAfundou: %d/2 \n",17,198,cont_pa,af_pa);
        printf ("\n");
        tecla=getch();

system("cls");

              //Definindo As Direcionais
        if (tecla==CIMA) linha_atual--;
            else if (tecla==BAIXO) linha_atual++;
                else if (tecla==DIREITA) coluna_atual++;
                    else if (tecla==ESQUERDA) coluna_atual--;
                        else if (tecla==ENTER) {tiros--; break;}
                            else if (tecla==ESC) main();


//se atingir o limite do mapa (matriz) volta para a anterior
if(linha_atual<0)linha_atual++;
    else if(linha_atual>15)linha_atual--;
if(coluna_atual<0) coluna_atual++;
    else if (coluna_atual>25)coluna_atual--;

}


system("cls");

//Tem jeito (muito) mais simples de montar esse IF, mas pra evitar bugs, preferí assim
//O jeito mais simples é colocar: se(diferente de escondido){ja acertou}
if (mapa[linha_atual][coluna_atual]==4   || mapa[linha_atual][coluna_atual]==16 || mapa[linha_atual][coluna_atual]==205 ||
    mapa[linha_atual][coluna_atual]==254 || mapa[linha_atual][coluna_atual]==17 || mapa[linha_atual][coluna_atual]==126){
                                                 tiros++;
                                                 impmapa();
                                                 printf("J%c acertou essa %crea!",160,160);
                                                 getch();
                                                 }


//Esses Tambem tem como melhorar
                        else if(mapareveal[linha_atual][coluna_atual]==1){
                                                        mapa[linha_atual][coluna_atual]=4;
                                                        cont_sub++;
                                                        impmapa();
                                                        pontos++;
                                                        puts("Acertou um Submarino!");
                                                        /*acerto();*/
                                                        if (cont_sub==1){
                                                            cont_sub=0;
                                                            af_sub++;}
                                                        //chama a funçao colrida
                                                        if (af_sub==3)printf ("\nVoce afundou todos os submarinos!!!");
                                                        getch();//pausa

                                                    }

                        else if (mapareveal[linha_atual][coluna_atual]==2){
                                                        mapa[linha_atual][coluna_atual]=16;
                                                        cont_enc++;
                                                        impmapa();
                                                        pontos++;
                                                        puts("Acertou um Encouracado (2 casas)!");
                                                        /*acerto();*/
                                                        if (cont_enc==2)
                                                        {cont_enc=0;
                                                        af_enc++;}
                                                        if (af_enc==2)printf ("\nVoce afundou todos os Encouracados!!!");
                                                        getch();
                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==3){
                                                        mapa[linha_atual][coluna_atual]=205;
                                                        cont_cruz++;
														impmapa();
														pontos++;
                                                        puts("Acertou um Cruzador (3 casas)!");
                                                        /*acerto();*/
                                                        if (cont_cruz==3){
														cont_cruz=0;
                                                        af_cruz++;}
                                                        if (af_cruz==3) printf ("\nVoce afundou todos os Cruzadores!!!");
                                                        getch();

                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==4){
                                                        mapa[linha_atual][coluna_atual]=254;
                                                        cont_hidro++;
                                                        impmapa();
                                                        pontos++;
                                                        printf("Acertou um Hidro Avi%co (4 casas)!",198);
                                                        /*acerto();*/
                                                        if (cont_hidro==4){
                                                            cont_hidro=0;
                                                            af_hidro++;}
                                                        if (af_hidro==4) printf ("\nVoce afundou todos os Hidro Avioes");
                                                        getch();

                                                        }


                        else if (mapareveal[linha_atual][coluna_atual]==5){
                                                        mapa[linha_atual][coluna_atual]=17;
                                                        cont_pa++;
                                                        impmapa();
                                                        pontos++;
                                                        printf("Acertou um Porta Avi%ces (5 casas)!",228);
                                                        /*acerto();*/
                                                        if (cont_pa==5)
                                                        {cont_pa=0;
                                                        af_pa++;}
                                                        if (af_pa==2) printf ("\nVoce afundou todos os Porta Avioes");
                                                        getch();
                                                        }

                        else if (mapareveal[linha_atual][coluna_atual] == 0){
                                                        mapa[linha_atual][coluna_atual]=126;
                                                        impmapa();
                                                        printf("Acertou na %cgua...",160);
                                                        getch();
                        }

            if(pontos2==44 || tiros2<=0){perde=1; /*ganhou();*/}
            /*player2();*/
}//endfor
}
