/***

	Ernesto Peñaloza Romero D.R. 2016
	Ultima actualizacion 24 de febrero del 2016

	
*/

#pragma message ("FESA::Compilando gotoxy.h")
//#include "stdafx.h"
#include <windows.h> //Encabezados para handles
#include <wincon.h>	//Encabezados para las funciones de consola
#include <conio.h>


//#define DEPURAR

void gotoxy(int iColumna,int iRenglon)
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


	//Obtener el gestor del buffer
	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	//Obtener informacion de la consola
	GetConsoleScreenBufferInfo(hStdOut, &csbiInfo);
	//Informacion sobre donde poner el cursor
	csbiInfo.dwCursorPosition.X=iColumna;
	csbiInfo.dwCursorPosition.Y=iRenglon;

	//poner el cursor
	if (! SetConsoleCursorPosition(hStdOut, csbiInfo.dwCursorPosition)) 
	{
		//Gestion de error?("fnMueveCursor"); 
	}

}
int LeeTecla(void)
{
	int cTecla;
	int lTecla;

	
		cTecla=(int)' ';
		cTecla=_kbhit();
		if (cTecla == 1)
			lTecla=_getch();
		else
			lTecla=0;

	return lTecla;
}
//224- 72- 80
int LeeFlecha(void)
{
	int cTecla;


	cTecla=(int)' ';
	cTecla=_kbhit();
	if (cTecla == 1)
	{
		cTecla=_getch();

		#ifdef DEPURAR 
		printf("Flecha detectada.%i \n",cTecla);
		#endif
		if (cTecla == 224)
			cTecla=_getch();
		else 
			cTecla=0;
	}
	else
		cTecla=0;
	switch(cTecla)
	{
	case 72:
		cTecla = VK_UP;
		break;
	case 80:
		cTecla = VK_DOWN;
		break;
	case 75:
		cTecla = VK_LEFT;
		break;
	case 77:
		cTecla = VK_LEFT;
		break;
	}
	#ifdef DEPURAR 		
	if(cTecla)
		printf("el valor de la tecla es %i\n",cTecla);
	#endif
	return cTecla;
}
/*
FOREGROUND_BLUE Text color contains blue. 
FOREGROUND_GREEN Text color contains green. 
FOREGROUND_RED Text color contains red. 
FOREGROUND_INTENSITY Text color is intensified. 
BACKGROUND_BLUE Background color contains blue. 
BACKGROUND_GREEN Background color contains green. 
BACKGROUND_RED Background color contains red. 
BACKGROUND_INTENSITY Background color is intensified. 
COMMON_LVB_LEADING_BYTE Leading byte. 
COMMON_LVB_TRAILING_BYTE Trailing byte. 
COMMON_LVB_GRID_HORIZONTAL Top horizontal. 
COMMON_LVB_GRID_LVERTICAL Left vertical. 
COMMON_LVB_GRID_RVERTICAL Right vertical. 
COMMON_LVB_REVERSE_VIDEO Reverse foreground and background attributes. 
COMMON_LVB_UNDERSCORE Underscore. 

*/
int PonColor(WORD Color)
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	int iCodError;


	//Obtener el gestor del buffer
	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	//Obtener informacion de la consola
	GetConsoleScreenBufferInfo(hStdOut, &csbiInfo);
	
	//Se establece el color
	if (! SetConsoleTextAttribute(hStdOut, Color))    
		iCodError=1;
	else
		iCodError=0;
	return iCodError;
}
