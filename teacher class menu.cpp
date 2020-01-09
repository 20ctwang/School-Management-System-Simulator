// teacher class menu.cpp : Defines the entry point for the console application.
//
//a teacher can has maximum of 4 classes each term, same for student, it indicates period 
//teacher generates class code and determine which period they gonna add on, so student then can only add on that period 
//teacher can determines class name 
//maximum 3 spare for each student 

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

/*gotoxy function*/
void gotoxy(int x, int y)
{
  static HANDLE hStdout = NULL;
  COORD coord;

  coord.X = x;
  coord.Y = y;

  if(!hStdout)
  {
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  }	  
  
  SetConsoleCursorPosition(hStdout,coord);
}


int main(void)
{

	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	WORD wOldColorAttrs;                                                        
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                     
	GetConsoleScreenBufferInfo(h, &csbiInfo);                     
	wOldColorAttrs = csbiInfo.wAttributes;

	int identity=1; //when user is a teacher
	int row=0;//for loop  
	int col=0;
	//set frame 
	for(row=0;row<10;row++)
	{	
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY);	//set foreground color
		gotoxy(3,3+row);
		printf("|");
		gotoxy(76,3+row);
		printf("|");
		gotoxy(3,19+row);
		printf("|");
		gotoxy(76,19+row);
		printf("|");

		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );	//set foreground color		
		gotoxy(7,5+row);
		printf("|");
		gotoxy(72,5+row);
		printf("|");
		gotoxy(7,17+row);
		printf("|");
		gotoxy(72,17+row);
		printf("|");	
	}	
	for(row=0;row<20;row++) //horizontal frame
	{
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY);	//set foreground color
		gotoxy(4+row,2);
		printf("-");
		gotoxy(56+row,2);
		printf("-");
		gotoxy(4+row,29);
		printf("-");
		gotoxy(56+row,29);
		printf("-");
		gotoxy(30+row,3);
		printf("-");
		gotoxy(30+row,28);
		printf("-");

		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );	//set foreground color
		gotoxy(8+row,4);
		printf("-");		
		gotoxy(52+row,4);
		printf("-");
		gotoxy(8+row,27);
		printf("-");		
		gotoxy(52+row,27);
		printf("-");		
	}
	for(row=0;row<3;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY);	//set foreground color
		gotoxy(5,15+row);
		printf("|");
		gotoxy(74,15+row);
		printf("|");
	}
	//end of frame
	
	//print fram if there is not classes added yet
	for(row=0;row<15;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(9,6+row);
		printf("|");
		gotoxy(70,6+row);
		printf("|");
	}
	for(row=0;row<60;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(10+row,5);
		printf("-");
		gotoxy(10+row,21);
		printf("-");
	}
	gotoxy(18,9);
	printf("You don't have any class added yet!");
	gotoxy(23,11);
	printf("Press 'a' to get started!");	
	getch();
	for(row=0;row<15;row++)
	{
		gotoxy(9,6+row);
		printf("  ");
		gotoxy(70,6+row);
		printf("  "); 
		//clear part of the screen
	}
	//print frame of class
	for(row=0;row<3;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );	//set foreground color
		gotoxy(9,6+row);
		printf("|");
		gotoxy(70,10+row);
		printf("|");
		gotoxy(9,14+row);
		printf("|");
		gotoxy(70,18+row);
		printf("|");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(70,6+row);
		printf("|");
		gotoxy(9,10+row);
		printf("|");
		gotoxy(70,14+row);
		printf("|");
		gotoxy(9,18+row);
		printf("|");		
	}
	for(row=0;row<60;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );	//set foreground color		
		gotoxy(10+row,9);
		printf("-");
		gotoxy(10+row,13);
		printf("-");
		gotoxy(10+row,17);
		printf("-");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(10+row,5);
		printf("-");
		gotoxy(10+row,21);
		printf("-");
	}

	//add color for first line 
/*	for(row=0;row<60;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_GREEN);
		gotoxy(10+row,6);
		printf(" ");
		gotoxy(10+row,7);
		printf(" ");
		gotoxy(10+row,8);
		printf(" ");
	}
	*/
getch();
return 0;
}//end main
