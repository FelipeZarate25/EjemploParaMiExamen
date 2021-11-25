#include <stdio.h>
#include <windows.h>
#include "c:\include\gotoxy.h"

#define LIMDER 76
#define LIMIZQ  0
#define LIMSUP  0
#define LIMINF 21
#define DERECHA    1
#define IZQUIERDA -1
#define ARRIBA    -1
#define ABAJO      1


int main()
{
    int x, y;
    int compHor, compVert;
    x = 0;
    y = 0;
    compHor = DERECHA;
    compVert = ABAJO;
    
    PonColor(FOREGROUND_RED| BACKGROUND_BLUE);
    while (1)
    {
        //Pintar el cuadro de animacion
        gotoxy(x, y);
        printf("DVD");
        Sleep(100);
        //Borrar el cuadro de animacion
        gotoxy(x, y);
        printf("   ");

        //Mover aster nueva posicion
        x = x + compHor;
        y = y + compVert;

        //Valida limites
        // Limite inferior
        if (y >= LIMINF)
        {
            compVert = ARRIBA;
        }
        //Limite superior
        if (y <= LIMSUP)
        {
            compVert = ABAJO;
        }
        //limite derecho
        if (x > LIMDER)
            compHor = IZQUIERDA;
        //limite izquierdo
        if (x <= LIMIZQ)
            compHor = DERECHA;
    }

}

