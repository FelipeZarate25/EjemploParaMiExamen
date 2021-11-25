#include <windows.h> //Encabezados para handles
#include <wincon.h>	//Encabezados para las funciones de consola

#ifndef GLOBAL_H
#define GLOBAL_H
	#define TECLA_A	97
	#define TECLA_D 100
	#define	BARRA_SPC 32
	#define IZQUIERDA -1
	#define DERECHA		1
	#define ARRIBA	-1
	#define ABAJO	1
	#define KEY_UP 72
	#define KEY_LEFT 75
	#define KEY_RIGHT 77
	#define KEY_DOWN 80
	#define KEY_ESC 27
#define TECLA_IZQ 'a'
#define TECLE_DER 'd'

	void gotoxy(int iColumna,int iRenglon);
	int LeeTecla(void);
	int LeeFlecha(void);
	int PonColor(WORD Color);
#endif