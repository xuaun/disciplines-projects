//#include<stdio.h>
//#include<conio.h>

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


void xplod(){
  Beep(60,20);  // 523 hertz (C5) for 500 milliseconds
  Beep(59,20);
  Beep(58,20);
  Beep(57,20);
  Beep(55,20);
  Beep(50,20);
  Beep(49,20);
  Beep(45,20);
}

void janela(int x, int y){   //Configurar janela e buffer
COORD outbuff;
outbuff.X = x;
outbuff.Y = y;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleScreenBufferSize(hConsole, outbuff);
Sleep(130);
SMALL_RECT windowSize = {0, 0, x-1, y-1};
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

int main(){
    int tecla;
    int x = 0;

    system("pause");

    while(x == 0){
        tecla=getch();
        system("pause");
        printf("\n%d\n", tecla);

        if(tecla == ENTER){
            printf("enter\n\n");
        }
    }

    return 0;
}
