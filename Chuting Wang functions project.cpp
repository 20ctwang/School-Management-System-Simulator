// Chuting Wang functions project.cpp : Defines the entry point for the console application.
//

/*--------------------Chuting Wang functions project----------------------------*/
/*  This program uses funtions. Users can determine if they want to see the 	*/
/*  intro by determining their identity as either teacher, student or visitor.  */
/*  																			*/
/*  Set Up(Home Page) - user sign in/log in 									*/
/*  After selecting user's identity, user would be given a username and initial */
/*  password that can be changed later on. When user finishs signing up, user   */
/*  would be asked to log in by entering their username and password.			*/
/*																				*/
/*  Visitor - Intro to the program												*/
/*  As keep pressing <ENTER>, visitor would know more about this program until  */
/*  the user would be brought back to the set up page again.					*/
/*  																			*/
/*  Teacher/Student - manage class and setting									*/
/*  if user is a teacher, then the user can add class, delete class, manage 	*/
/*  class and change their password in the setting. 							*/
/*  Add Class: A class code would be generated based on teacher's username and 	*/
/*  period number when teacher adds class. For students, they need to enter  	*/
/*  a class code and select the same period as the teacher does in order to add */
/*  a class.																	*/
/*  Delete Class: both student and teacher can feel free to remove the current 	*/
/*  class from their timetable. However, if a teacher removes a class, then 	*/
/*  all students in that class would be automatically removed from that class.  */
/*  Manage Class: Teacher can post announcement which would be viewed by all his*/
/*  student, assign assignments which have been limited to the textbook page #	*/
/*  only and view questions that student ask from the current assignment. for   */
/*  students, they can determine to submitted assignment which can be viewed by	*/
/*  their teacher of that particular class, ask question which is limited to 	*/
/*  question # from the current assignment only. If the teacher has updated the */
/*  the assignment, then the question from previous assignment would disappear. */
/*  Setting: in setting, both student and teacher can change their password, 	*/
/*  reset their password to the initial '1234', or return to the home page,		*/
/*  where they sign up at the beginning. 										*/
/*                                                                              */
/*  *Notice that 'Exit' on the home page is the only choice that can exit the 	*/
/*  program.																	*/
/*  **Only maximum 9 students and 9 teachers can sign up into the classroom		*/
/*  ***Username: 000, the first digit indicates visitor, the second indicates	*/
/*  student, while the third indicates teacher.(eg.001 indicates the first 		*/
/*  teacher signing up into the program.)										*/
/*  ****Class Code: 0000, the first three digits represent teacher username,	*/
/*  and the last digit represents the period number. (eg. 0011 indicates        */
/*  teacher 001 at first period.)												*/
/*                                                                              */
/*                PROGRAM ID:Chuting Wang functions project                     */ 
/*                PROGRAMMER:Chuting Wang            	                        */
/*                RUN DATE:October 2nd, 2018                                    */ 
/*                                                   						    */
/*------------------------------------------------------------------------------*/
/*---------------------------PREPROCESSING DIRECTIVES---------------------------*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

/*--------------------------gotoxy function-------------------------------------*/
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
/*---------------------------------MAINLINE CONTROL--------------------------------*/
int main(void)
{
/*------------------------------------TITLE---------------------------------------*/

	system("TITLE Chuting Wang functions project");
	
/*------------------------------DECLARE FUNCTIONS PROTOTYPES----------------------*/
	//print frame of the program
	void   frame (void);
	//sign in and log in 
	int    setup (int,int[2],int[2],int[10][2],int[10][2],int[5],int[10],int[10]);
	//teacher menu 
	void   teacherMenu (int[5],int[10][4],int[10],char[10][50],int[10][4],int[10][4],int[10][4],int[10],int[10][2],int[10][4],int[10][4],int[10][4],int[10][4]);
	//student menu
	void   studentMenu (int[5],int[10][4],int[2],int[10][4],int[10][4],int[10],int[10][2],int[10],char[10][50],int[10][4],int[10][4],int[10][4],int[10][4],int[10][4]);
	//introduction of the program - visitor menu
	void   visitorMenu (void);
	

/*-------------------------------DECLARE LOCAL VARIABLES--------------------------*/
/*Program*/
	int teacherOrder1[2];         	//record the number of teachers who have signed up
	int studentOrder1[2];			//record the number of teachers who have signed up
	int studentPassword[10][2];		//stduent password,while[0] is 1234 
	int teacherPassword[10][2];		//teacher password
	int teacherChangePassword[10];	//identify if teacher change password
	int studentChangePassword[10];	//identify if student change password
	int loginTempName[5];			//temp name recorded when logging in 
	int teacherClass[10][4];		//identify if teacher has class in that period
	int studentClass[10][4];		//identify if student has class in that period
	int announcementCount[10];		//identify if teacher posted an announcement
	char announcement[10][50];		//announcement 
	int assignment[10][4];			//assignment-page number of exercise
	int assignmentCount[10][4];		//identify if there is an assignment in that period
	int studentThirdClass[10][4];  	//third digit of class code determining if the student select the teacher
	int studentAssignment[10][4];  	//identify if student hands in the assignment
	int question[10][4];           	//question that student asks for the certain assignment 
	int questionCount[10][4];      	//identity if student has question
	
/*Others*/
	int row=0;						//for loop
	int col=0;						//for loop
	int identity=0;					//user identity when logging in
	int flag=0;						//do while 

/*set text color*/
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	WORD wOldColorAttrs;                                                        
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                     
	GetConsoleScreenBufferInfo(h, &csbiInfo);                     
	wOldColorAttrs = csbiInfo.wAttributes;
		
/*set initial value for variables*/
	for(row=0;row<10;row++)
	{
		studentPassword[row][0]=1234; //initial password is 1234
		teacherPassword[row][0]=1234;
		studentPassword[row][1]=0;    //would be changed if user change password
		teacherPassword[row][1]=0;		
		announcementCount[row]=0;	  //initially no announcement
		teacherChangePassword[row]=0;
		studentChangePassword[row]=0;
		for(col=0;col<4;col++)
		{
			teacherClass[row][col]=0;
			studentClass[row][col]=0;
			assignment[row][col]=0;
			assignmentCount[row][col]=0;
			studentAssignment[row][col]=0;
			question[row][col]=0;
			questionCount[row][col]=0;
		}
	}
	teacherOrder1[1]=0; //0 teacher has signed up initially 
	studentOrder1[1]=0; //0 student has signed up initially 
	
/*-------------------------------------FUNCTIONS CALLS-----------------------------------*/
	do
	{
		system("cls"); //clear screen
		frame();       //print frame to screen
		//set up- user sign up and log in
		identity=setup(identity,teacherOrder1,studentOrder1,studentPassword,teacherPassword,loginTempName,teacherChangePassword,studentChangePassword); 
		system("cls"); //clear screen
		frame();	//print frame to screen
		if(identity==1) //if user is a teacher
		{	//teacher page	
			teacherMenu(loginTempName,teacherClass,announcementCount,announcement,studentClass,studentThirdClass,assignment,teacherChangePassword,teacherPassword,assignmentCount,studentAssignment,question,questionCount);
			flag=4; //back to 'set up' 
		}
		if(identity==2) //if user is a student
		{//student page
			studentMenu(loginTempName,studentClass,teacherOrder1,studentThirdClass,teacherClass,studentChangePassword,studentPassword,announcementCount,announcement,studentAssignment,assignmentCount,assignment,question,questionCount);
			flag=4;//back to 'set up' 
		}
		if(identity==3) //if user is a visitor
		{
			visitorMenu(); //visitor page - intro to program
			flag=4; //back to 'set up' 
		}		
		if(identity==4) //when user hits exit of set up function 
		flag=5; //exit the program
	}while(flag<5);	
	return 0; 
}//end main

/*--------------------FUNCTIONS DEFINITION----------------*/
void frame(void) 
{ //print frame to screen
	int row=0;//for loop
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
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
	return;
}//end of frame function 

int setup (int identity,int teacherOrder1[2],int studentOrder1[2],int studentPassword[10][2],int teacherPassword[10][2],int loginTempName[5],int teacherChangePassword[10],int studentChangePassword[10])
{ //set up- user sign up and log in

/*program*/
	int changePassword=0;			//determine uses initial or changed password
	int tempName=0; 				//for visitor temp name
	int tempPassword=0;				//record Password temporarily 
	int signupInputName[5]; 		//for student and teacher temp name 
	int signupTempName[5];			//student and teacher temp name after calculation
	int loginInputName[5];			//student and teacher temp name when login
	int loginTempPassword[5];		//temp password after calculation -48
	int loginInputPassword[5];		//temp password when first enter
	int loginTempPasswordMultiply=0;//temp password after calculation of multiplication
	int teacherIdentity=0;			//identify teacher
	int studentIdentity=0;			//identify student
	int teacherOrder=0;				//determine the order of teacher 
	int studentOrder=0;				//order of student
	
/*Others*/	
	char choice; 					//user's identity
	char choice1; 					//log in or set up
	int  flag=0;					//do while
	int  row=0;  					//for loop
	int goSignUp=0; 				//determine if user goes to log in page
	
	

	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);  
	do
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(9,6);
		printf("WELCOME TO CHUTING'S CLASSROOM!");
		gotoxy(9,8);
		printf("Do not have an account yet?");
		gotoxy(9,10);
		printf("a] Sign up");
		gotoxy(9,11);
		printf("b] Log in");
		gotoxy(9,12);
		printf("c] Exit");
		gotoxy(9,14);
		printf("Choice: ");
		choice1=_getch();
		fflush(stdin);
		printf("%c",choice1); //print choice1
		
		for(row=0;row<10;row++)//clear part of the screen 
		{
			gotoxy(9,8+row);
			printf("\t\t\t\t\t");
		}
		if((teacherOrder1[1]!=0)||(studentOrder1[1]!=0))
		{
			teacherOrder=teacherOrder1[1];
			studentOrder=studentOrder1[1];
		}		
		do
		{
			if((choice1=='a')||(choice1=='A')) //sign up
			{
				do
				{
					for(row=0;row<15;row++)//clear part of the screen 
					{
						gotoxy(9,8+row);
						printf("\t\t\t\t\t\t\t\t");
					}
					//menu of choice
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );
					gotoxy(9,10);
					printf("a) ");
					gotoxy(20,10);
					printf("b) ");
					gotoxy(31,10);
					printf("c) ");		
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(12,10);
					printf("teacher");
					gotoxy(23,10);
					printf("student");
					gotoxy(34,10);
					printf("visitor");
					gotoxy(9,8);
					printf("I'm a: ");
					choice=_getch();
					fflush(stdin);
					printf("%c",choice); //print choice
					Sleep(200);		
					gotoxy(9,10);
					printf("\t\t\t\t\t"); //clear the menu 
					
					switch(choice)
					{
						case 'a':
						case 'A':
							teacherOrder++;
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,8);
							printf("Hello! Our new teacher!");
							gotoxy(9,10);
							printf("Here is your username and initial password.");
							gotoxy(9,12);
							printf("Remember you need them to log in!");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );	
							gotoxy(22,10);
							printf("username");
							gotoxy(43,10);
							printf("password");
							gotoxy(39,9);
							printf("00%d",teacherOrder); //username
							gotoxy(60,11);
							printf("1234"); //password
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
							gotoxy(26,9);
							printf(",---------->");
							gotoxy(47,11);
							printf("'---------->");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,14);
							printf("Press <ENTER> to contninue!");
							getch(); //hold screen
							gotoxy(9,12);
							printf("Now Let's Practice.\t\t\t");
							gotoxy(9,14);
							printf("\t\t\t\t\t"); //print part of the screen
							do
							{					
								gotoxy(9,14);
								printf("USERNAME:");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								for(row=0;row<3;row++)
								{			
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
									signupInputName[row]=_getch();
									fflush(stdin);
									signupTempName[row]=signupInputName[row]-48; //convert to number on keyboard
									printf("%d",signupTempName[row]);
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								}
								getch();
								if((signupTempName[0]==0)&&(signupTempName[1]==0)&&(signupTempName[2]==teacherOrder))
									flag=2;
								else
								{
									gotoxy(9,14);
									printf("\t\t\t\t\t");
									gotoxy(9,14);
									printf("USERNAME:");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
									gotoxy(18,14);
									printf("00%d",teacherOrder);
									gotoxy(9,16);
									printf("INVALID INPUT!");
									gotoxy(9,18);
									printf("THE RIGHT USERNAME IS SHOWN ABOVE!");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,20);
									printf("Press <ENTER> to try again!");
									getch();//hold the screen
									for(row=0;row<10;row++)
									{
										gotoxy(9,14+row);
										printf("\t\t\t\t\t");//clear part of the screen
									}							
									flag=1;
								}//end of else							
							}while(flag<2);						
							do
							{					
								gotoxy(9,16);
								printf("PASSWORD:");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								scanf("%d",&tempPassword); 
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								fflush(stdin);
								if(tempPassword!=1234)
								{
									gotoxy(9,16);
									printf("\t\t\t\t\t");
									gotoxy(9,16);
									printf("PASSWORD:");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
									gotoxy(18,16);
									printf("1234");
									gotoxy(9,18);
									printf("INVALID INPUT!");
									gotoxy(9,20);
									printf("THE RIGHT PASSWORD IS SHOWN ABOVE!");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,22);
									printf("Press <ENTER> to try again!");
									getch();//hold the screen
									for(row=0;row<8;row++)
									{
										gotoxy(9,16+row);
										printf("\t\t\t\t\t");//clear part of the screen
									}							
									flag=1;
								}//end of if
								else
								flag=3;							
							}while(flag<2);	
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );		
							gotoxy(9,18);
							printf("Great! Your teacher account has been set up!");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,20);
							printf("Press <ENTER> and let's get started!");
							getch();					
							identity=1;  //user is identified as a teacher
							choice1='b'; //go to log in page
							break;
							
						case 'b':
						case 'B':
							studentOrder++;
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,8);
							printf("Hello! Our new student!");
							gotoxy(9,10);
							printf("Here is your username and initial password.");
							gotoxy(9,12);
							printf("Remember you need them to log in!");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );	
							gotoxy(22,10);
							printf("username");
							gotoxy(43,10);
							printf("password");
							gotoxy(39,9);
							printf("0%d0",studentOrder); //username
							gotoxy(60,11);
							printf("1234"); //password
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
							gotoxy(26,9);
							printf(",---------->");
							gotoxy(47,11);
							printf("'---------->");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,14);
							printf("Press <ENTER> to contninue!");
							getch(); //hold screen
							gotoxy(9,12);
							printf("Now Let's Practice.\t\t\t");
							gotoxy(9,14);
							printf("\t\t\t\t\t"); //print part of the screen
							do
							{					
								gotoxy(9,14);
								printf("USERNAME:");
								for(row=0;row<3;row++)
								{			
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
									signupInputName[row]=_getch();
									fflush(stdin);
									signupTempName[row]=signupInputName[row]-48; //convert to number on keyboard
									printf("%d",signupTempName[row]);
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								}
								getch();
								if((signupTempName[0]==0)&&(signupTempName[1]==studentOrder)&&(signupTempName[2]==0))
									flag=2;
								else
								{
									gotoxy(9,14);
									printf("\t\t\t\t\t");
									gotoxy(9,14);
									printf("USERNAME:");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
									gotoxy(18,14);
									printf("0%d0",studentOrder);
									gotoxy(9,16);
									printf("INVALID INPUT!");
									gotoxy(9,18);
									printf("THE RIGHT USERNAME IS SHOWN ABOVE!");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,20);
									printf("Press <ENTER> to try again!");
									getch();//hold the screen
									for(row=0;row<10;row++)
									{
										gotoxy(9,14+row);
										printf("\t\t\t\t\t");//clear part of the screen
									}							
									flag=1;
								}//end of else							
							}while(flag<2);
							
							do
							{					
								gotoxy(9,16);
								printf("PASSWORD:");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								scanf("%d",&tempPassword); 
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								fflush(stdin);
								if(tempPassword!=1234)
								{
									gotoxy(9,16);
									printf("\t\t\t\t\t");
									gotoxy(9,16);
									printf("PASSWORD:");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
									gotoxy(18,16);
									printf("1234");
									gotoxy(9,18);
									printf("INVALID INPUT!");
									gotoxy(9,20);
									printf("THE RIGHT PASSWORD IS SHOWN ABOVE!");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,22);
									printf("Press <ENTER> to try again!");
									getch();//hold the screen
									for(row=0;row<8;row++)
									{
										gotoxy(9,16+row);
										printf("\t\t\t\t\t");//clear part of the screen
									}							
									flag=1;
								}//end of if
								else
								flag=3;
							}while(flag<2);	
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );		
							gotoxy(9,18);
							printf("Great! Your student account has been set up!");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,20);
							printf("Press <ENTER> and let's get started!");
							getch();					
							identity=2;  //user is identified as a student
							choice1='b'; //go to log in page
							break;
	
						case 'c':
						case 'C':
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,8);
							printf("Hello! Our new visitor!");
							gotoxy(9,10);
							printf("Here is your username and initial password.");
							gotoxy(9,12);
							printf("Remember you need them to log in!");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );	
							gotoxy(22,10);
							printf("username");
							gotoxy(43,10);
							printf("password");
							gotoxy(39,9);
							printf("100"); //username
							gotoxy(60,11);
							printf("1234"); //password
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
							gotoxy(26,9);
							printf(",---------->");
							gotoxy(47,11);
							printf("'---------->");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,14);
							printf("Press <ENTER> to contninue!");
							getch(); //hold screen
							gotoxy(9,12);
							printf("Now Let's Practice.\t\t\t");
							gotoxy(9,14);
							printf("\t\t\t\t\t"); //print part of the screen
							do
							{					
								gotoxy(9,14);
								printf("USERNAME:");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								scanf("%d",&tempName); 
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								fflush(stdin);
								if(tempName!=100)
								{
									gotoxy(9,14);
									printf("\t\t\t\t\t");
									gotoxy(9,14);
									printf("USERNAME:");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
									gotoxy(18,14);
									printf("100");
									gotoxy(9,16);
									printf("INVALID INPUT!");
									gotoxy(9,18);
									printf("THE RIGHT USERNAME IS SHOWN ABOVE!");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,20);
									printf("Press <ENTER> to try again!");
									getch();//hold the screen
									for(row=0;row<10;row++)
									{
										gotoxy(9,14+row);
										printf("\t\t\t\t\t");//clear part of the screen
									}							
									flag=1;
								}//end of if
								else
								flag=2;
							}while(flag<2);
							
							do
							{					
								gotoxy(9,16);
								printf("PASSWORD:");
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
								scanf("%d",&tempPassword); 
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								fflush(stdin);
								if(tempPassword!=1234)
								{
									gotoxy(9,16);
									printf("\t\t\t\t\t");
									gotoxy(9,16);
									printf("PASSWORD:");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );	
									gotoxy(18,16);
									printf("1234");
									gotoxy(9,18);
									printf("INVALID INPUT!");
									gotoxy(9,20);
									printf("THE RIGHT USERNAME IS SHOWN ABOVE!");
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,22);
									printf("Press <ENTER> to try again!");
									getch();//hold the screen
									for(row=0;row<8;row++)
									{
										gotoxy(9,16+row);
										printf("\t\t\t\t\t");//clear part of the screen
									}							
									flag=1;
								}//end of if
								else
								flag=3;
							}while(flag<2);	
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );		
							gotoxy(9,18);
							printf("Great! Your visitor account has been set up!");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,20);
							printf("Please notice that this is a temporary account!");
							gotoxy(9,22);
							printf("Press <ENTER> and let's get started!");
							getch();					
							choice1='b'; //go to log in page
							identity=3; //user is identified as a visitor				
							break;
	
						default:
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
							gotoxy(9,10);
							printf("INVALID INPUT!");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,12);
							printf("Press <ENTER> to try again!");
							getch();//hold screen
							//clear part of the screen
							gotoxy(9,8);
							printf("\t\t\t\t\t");
							gotoxy(9,10);
							printf("\t\t\t\t\t");
							gotoxy(9,12);
							printf("\t\t\t\t\t");
							flag=2;
							break;
					}//end of switch for choice
				}while(flag<3);
			}//end of if 
			if((choice1=='b')||(choice1=='B')) //log in
			{			
				//clear part of the screen
				for(row=0;row<15;row++)
				{
					gotoxy(9,8+row);
					printf("\t\t\t\t\t\t\t\t");
				}	
				gotoxy(9,8);
				printf("Enter your username and password to log in!");
				do //username
				{
					gotoxy(9,10);
					printf("USERNAME: ");
					gotoxy(9,12);
					printf("PASSWORD: ");
					gotoxy(19,10);
					for(row=0;row<3;row++)
					{			
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
						loginInputName[row]=_getch();
						fflush(stdin);
						loginTempName[row]=loginInputName[row]-48; //convert to number on keyboard
						printf("%d",loginTempName[row]);
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					}
					getch();
					if((loginTempName[0]==0)&&(loginTempName[1]==0)&&(loginTempName[2]<=teacherOrder)&&(loginTempName[2]>0))
					{
						teacherIdentity=loginTempName[2]; //identified which teacher logs in
						identity=1; //if user is a teacher
						flag=3;
						goSignUp=2;
					}
					else if((loginTempName[0]==0)&&(loginTempName[1]<=studentOrder)&&(loginTempName[1]>0)&&(loginTempName[2]==0)) 
					{
						studentIdentity=loginTempName[2]; //identified which student logs in
						identity=2; //if user is a student
						flag=3;
						goSignUp=2;
					}
					else if((loginTempName[0]==1)&&(loginTempName[1]==0)&&(loginTempName[2]==0))
					{					
						identity=3; //if user is a visitor
						flag=3;
						goSignUp=2;
					}
					else
					{
						identity=0;
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(9,14);
						printf("INVALID USERNAME!");
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(9,16);
						printf("Do not have an account yet?");
						do
						{
							gotoxy(9,18);
							printf("Press 'a' to create a new account, or 'b' to try again!");
							choice=_getch();
							fflush(stdin);
							switch(choice)
							{
							case 'a':
							case 'A':
								choice1='a';
								flag=3; 
								goSignUp=1; //go to sign up page
								break;
							case 'b':
							case 'B':
								flag=2; //enter username again
								for(row=0;row<15;row++)
								{
									gotoxy(9,10+row);
									printf("\t\t\t\t\t\t\t\t"); //clean part of the screen
								}
								break;
							default:
								flag=1;
								break;							
							}//end of switch
						}while(flag<2);
					}//end of else
				}while(flag<3);	//enter username
	
				while(goSignUp!=1) 
				{
					do //password
					{
						gotoxy(9,12);
						printf("PASSWORD: ");
						gotoxy(19,12);
						for(row=0;row<4;row++)
						{			
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
							loginInputPassword[row]=_getch();
							fflush(stdin);
							loginTempPassword[row]=loginInputPassword[row]-48; //convert to number on keyboard
							printf("*");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						}
						gotoxy(9,14);
						printf("Press <ENTER> to continue!");
						getch();
						gotoxy(9,14);
						printf("\t\t\t\t\t");//clear part of the screen
						
						loginTempPasswordMultiply=(loginTempPassword[0]*1000)+loginTempPassword[1]*100+loginTempPassword[2]*10+loginTempPassword[3];
						if(identity==1)
						changePassword=teacherChangePassword[teacherIdentity];
						if(identity==2)
						changePassword=studentChangePassword[studentIdentity];
						if((identity==1)&&(loginTempPasswordMultiply==teacherPassword[teacherIdentity][changePassword]))
						{							
							flag=5; 
							goSignUp=1;
						}
						else if((identity==2)&&(loginTempPasswordMultiply==studentPassword[studentIdentity][changePassword]))		
						{							
							flag=5;
							goSignUp=1;
						}			
						else if((identity==3)&&(loginTempPasswordMultiply==1234))
						{							
							flag=5;
							goSignUp=1;
						}
						else 
						{
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
							gotoxy(9,14);
							printf("INVALID PASSWORD!");
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(9,16);
							printf("Do not have an account yet?");
							do
							{
								gotoxy(9,18);
								printf("Press 'a' to create a new account, or 'b' to try again!");
								choice=_getch();
								fflush(stdin);
								switch(choice)
								{
								case 'a':
								case 'A':
									choice1='a';
									flag=3; //go to sign up page
									break;
								case 'b':
								case 'B':
									flag=2; //enter password again
									for(row=0;row<15;row++)
									{
										gotoxy(9,12+row);
										printf("\t\t\t\t\t\t\t\t"); //clean part of the screen
									}
									break;
								default:
									flag=1;
									break;							
								}//end of switch
							}while(flag<2);//determine to create a new account or enter password again
						}//end of else
					}while(flag<3); //enter password 
				}//end of while for entering password
			}//end of if for log in 
			if ((choice1=='c')||(choice1=='C')) //exit
			{
				flag=5;
				identity=4;
			}
			if((choice1!='a')&&(choice1!='A')&&(choice1!='b')&&(choice1!='B')&&(choice1!='c')&&(choice1!='C'))
			flag=4;	
		}while(flag<4);	//sign up
	}while(flag<5); //home page	
	teacherOrder1[1]=teacherOrder;	
	studentOrder1[1]=studentOrder;
	return(identity); //return identity to main 
}//end of intro function 

void teacherMenu(int loginTempName[5],int teacherClass[10][4],int announcementCount[10],char announcement[10][50],int studentClass[10][4],int studentThirdClass[10][4],int assignment[10][4],int teacherChangePassword[10],int teacherPassword[10][2],int assignmentCount[10][4],int studentAssignment[10][4],int question[10][4],int questionCount[10][4])
{ //teacher page
/*Program*/
	int teacherIdentity=0;			//identify teacher
	int enterPeriod=0;				//period entered
	int currentPasswordEnter=0;		//temp password recorded           
	int tempPassword[4];			//temp password when setting new after calculation
	int inputPassword[4];			//temp password when setting new ---- entering
	int newPassword[10];			//new password after multiplication
	
/*Others*/
	int row=0;						//for loop
	int flag=0;						//do while
	int flag1=0;					//do while
	int line=0;						//gotoxy position of student #
	int condition=0;				//identify the number of classes added
	char choice;					//choice on teacher home page
	char teacherChoice;				//choice in manage class
	char settingChoice;				//choice in setting
	char passwordChoice;			//choice in password - change or reset
	char yesNo;						//yes or no

	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	
	teacherIdentity=loginTempName[2];
	do
	{	
		if((teacherClass[teacherIdentity][0]==0)&&(teacherClass[teacherIdentity][1]==0)&&(teacherClass[teacherIdentity][2]==0)&&(teacherClass[teacherIdentity][3]==0))
		{//when having no class added
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
		}//end of if when teacher has no class added
		
		if((teacherClass[teacherIdentity][0]==1)||(teacherClass[teacherIdentity][1]==2)||(teacherClass[teacherIdentity][2]==3)||(teacherClass[teacherIdentity][3]==4))
		{//when teacher has 1-3 classes added
			condition=3; 
			for(row=0;row<4;row++)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(15,7+4*row);
				printf("period %d:",row+1);
				if(teacherClass[teacherIdentity][row]==0)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED |FOREGROUND_INTENSITY );	//set foreground color
					gotoxy(24,7+4*row);
					printf(" EMPTY");
				}
				if(teacherClass[teacherIdentity][row]!=0)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(24,7+4*row);
					printf(" 00%d%d      ",teacherIdentity,row+1);
				}
			}							
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
		}//end of if
		//menu
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );		
		gotoxy(9,22);
		printf("a] add class b] delete class c] manage class d] setting");
		if((teacherClass[teacherIdentity][0]==0)&&(teacherClass[teacherIdentity][1]==0)&&(teacherClass[teacherIdentity][2]==0)&&(teacherClass[teacherIdentity][3]==0))
		{//if there is not class added yet, then user cannot select or delete class
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);
			gotoxy(22,22);
			printf("b] delete class c] manage class");
			condition=1;
		}
		if((teacherClass[teacherIdentity][0]==1)&&(teacherClass[teacherIdentity][1]==2)&&(teacherClass[teacherIdentity][2]==3)&&(teacherClass[teacherIdentity][3]==4))
		{//if all periods have class, then user cannot add class anymore
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);
			gotoxy(9,22);
			printf("a] add class");
			condition=2;
		}
		do
		{//select in menu
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(30,23);
			printf("choice: "); //prompt user to select
			choice=_getch();
			fflush(stdin);
			gotoxy(30,23);
			printf("choice: %c",choice); //print choice to screen
			switch(choice)
			{
				case 'a'://add class
				case 'A':
					if(condition==2) 
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(9,24);
						printf("INVALID INPUT!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(9,25);
						printf("Press <ENTER> to try again!");
						getch(); //hold screen
						flag=2;
						for(row=0;row<4;row++)
						{
							gotoxy(9,23+row);
							printf("\t\t\t\t\t");//clean part of the screen
						}
					}	
					else
					{
						if(condition==1)
						{						
							for(row=0;row<15;row++) //clear part of the screen
							{
								gotoxy(9,6+row);
								printf("  ");
								gotoxy(70,6+row);
								printf("  "); 
								gotoxy(9,9);
								printf("\t\t\t\t\t\t");
								gotoxy(9,11);
								printf("\t\t\t\t\t\t\t");
								//clear part of the screen
							}			
						}//end of if
						//clear part of the screen
						gotoxy(9,22);
						printf("\t\t\t\t\t\t\t");
						gotoxy(9,23);
						printf("\t\t\t\t\t\t\t");
						for(row=0;row<4;row++)
						{
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(15,7+4*row);
							printf("period %d",row+1);
						}
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
						do
						{						
							gotoxy(9,22);
							printf("Enter period # to add class: ");
							scanf("%d",&enterPeriod);
							fflush(stdin);
							if((enterPeriod>0)&&(enterPeriod<=4))
							{
								if(teacherClass[teacherIdentity][enterPeriod-1]!=0) //if there is a class on that period already
								{
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
									gotoxy(9,23);
									printf("INVALID INPUT!");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("00%d%d is currently on Period %d",teacherIdentity,enterPeriod,enterPeriod);
									gotoxy(9,25);
									printf("Press <ENTER> to continue!");
									getch();
									for(row=0;row<4;row++)
									{
										gotoxy(9,23+row);
										printf("\t\t\t\t\t\t"); //clear part of screen
									}
									flag=3; //select again
								} 
								else
								{
									teacherClass[teacherIdentity][enterPeriod-1]=enterPeriod;										
									gotoxy(9,23);
									printf("Class code: ");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
									gotoxy(21,23);
									printf("00%d%d",teacherIdentity,teacherClass[teacherIdentity][enterPeriod-1]);
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("Press <ENTER> to add class 00%d%d into period %d!",teacherIdentity,teacherClass[teacherIdentity][enterPeriod-1],enterPeriod);
									flag=3;
									getch();
									for(row=0;row<5;row++)
									{
										gotoxy(9,22+row);
										printf("\t\t\t\t\t\t"); //clear part of screen
									}
								}
							}
							else
							{
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(9,24);
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(9,26);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								for(row=0;row<5;row++)
								{
									gotoxy(9,22+row);
									printf("\t\t\t\t\t");//clean part of the screen
								}
							}
						}while(flag<2);							
					}//end of else of add class	
					break;
					
				case 'b': //delete class
				case 'B':	
					if(condition==1)
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(9,24);
						printf("INVALID INPUT!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(9,25);
						printf("Press <ENTER> to try again!");
						getch(); //hold screen
						flag=2;
						for(row=0;row<4;row++)
						{
							gotoxy(9,23+row);
							printf("\t\t\t\t\t");//clean part of the screen
						}
					}	
					else
					{
						gotoxy(9,22);
						printf("\t\t\t\t\t\t\t");
						gotoxy(9,23);
						printf("\t\t\t\t\t\t\t");
						do
						{						
							gotoxy(9,22);
							printf("Enter period # to delete class: ");
							scanf("%d",&enterPeriod);
							fflush(stdin);
							if((enterPeriod>0)&&(enterPeriod<=4))
							{
								if(teacherClass[teacherIdentity][enterPeriod-1]==0)
								{
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
									gotoxy(9,23);
									printf("INVALID INPUT!");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("There is no class currently on Period %d",enterPeriod);
									gotoxy(9,25);
									printf("Press <ENTER> to continue!");
									getch();
									for(row=0;row<5;row++)
									{
										gotoxy(9,22+row);
										printf("\t\t\t\t\t\t"); //clear part of screen
									}
									flag=3; //select again
								} 
								else
								{
									teacherClass[teacherIdentity][enterPeriod-1]=0;										
									gotoxy(9,23);
									printf("Class code: ");
									SetConsoleTextAttribute ( h, FOREGROUND_RED |FOREGROUND_INTENSITY );
									gotoxy(21,23);
									printf("00%d%d",teacherIdentity,teacherClass[teacherIdentity][enterPeriod-1]);
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("Press <ENTER> to remove class 00%d%d from period %d!",teacherIdentity,teacherClass[teacherIdentity][enterPeriod-1],enterPeriod);
									flag=3;
									getch();
									for(row=0;row<20;row++)
									{
										gotoxy(9,5+row);
										printf("\t\t\t\t\t\t\t\t"); //clear part of screen
									}									
								}
							}
							else
							{
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(9,24);
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(9,26);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								for(row=0;row<5;row++)
								{
									gotoxy(9,22+row);
									printf("\t\t\t\t\t");//clean part of the screen
								}
							}
						}while(flag<2);	
					}				
					break;
					
				case 'c': //manage class
				case 'C':
					if(condition==1)
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(9,24);
						printf("INVALID INPUT!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(9,25);
						printf("Press <ENTER> to try again!");
						getch(); //hold screen
						flag=2;
						for(row=0;row<4;row++)
						{
							gotoxy(9,23+row);
							printf("\t\t\t\t\t");//clean part of the screen
						}
					}	
					else
					{
						gotoxy(9,22);
						printf("\t\t\t\t\t\t\t");
						gotoxy(9,23);
						printf("\t\t\t\t\t\t\t");
						do
						{						
							gotoxy(9,22);
							printf("Enter period # to manage your class: ");
							scanf("%d",&enterPeriod);
							fflush(stdin);
							if((enterPeriod>0)&&(enterPeriod<=4))
							{
								if(teacherClass[teacherIdentity][enterPeriod-1]==0)
								{
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
									gotoxy(9,23);
									printf("INVALID INPUT!");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("There is no class currently on Period %d",enterPeriod);
									gotoxy(9,25);
									printf("Press <ENTER> to continue!");
									getch();
									for(row=0;row<5;row++)
									{
										gotoxy(9,22+row);
										printf("\t\t\t\t\t\t"); //clear part of screen
									}
									flag=3; //select again
								} 
								else
								{																			
									gotoxy(9,23);
									printf("Class code: ");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
									gotoxy(21,23);
									printf("00%d%d",teacherIdentity,teacherClass[teacherIdentity][enterPeriod-1]);
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("Press <ENTER> to continue!");
									flag=3;
									getch();
									for(row=0;row<20;row++)
									{
										gotoxy(9,5+row);
										printf("\t\t\t\t\t\t\t\t"); //clear part of screen
									}
									do
									{
										//print frame of one period
										SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(9,6);
										printf("|");
										gotoxy(70,6);
										printf("|");
										for(row=0;row<60;row++)
										{
											gotoxy(10+row,5);
											printf("-");
											gotoxy(10+row,7);
											printf("-");
										}
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(10,6);
										printf("Announcement: ");
										gotoxy(10,8);
										printf("Period: %d  Class Code:00%d%d  teacher: 00%d",enterPeriod,teacherIdentity,teacherClass[teacherIdentity][enterPeriod-1],teacherIdentity);
									
										if(announcementCount[teacherIdentity]==0)
										{
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);
											gotoxy(24,6);
											printf("Nothing is posted!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										}
										if(announcementCount[teacherIdentity]==1)
										{
											gotoxy(24,6);
											printf("\t\t\t\t\t");//clean part of the screen 
											gotoxy(24,6);
											printf("%s",announcement[teacherIdentity]);
										}
										//print frame of student list and menu																		
										SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										for(row=0;row<20;row++)
										{
											gotoxy(11+row,10);
											printf("-");
											gotoxy(11+row,22);
											printf("-");
											gotoxy(49+row,10);
											printf("-");
											gotoxy(49+row,22);
											printf("-");
										}
										for(row=0;row<11;row++)
										{
											gotoxy(10,11+row);
											printf("|");
											gotoxy(31,11+row);
											printf("|");
											gotoxy(48,11+row);
											printf("|");
											gotoxy(69,11+row);
											printf("|");
										}									
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(15,11);
										printf("STUDENT LIST");
										gotoxy(53,11);
										printf("MENU");
										gotoxy(49,13);
										printf("a] Announcement");
										gotoxy(49,15);
										printf("b] Assignment");
										gotoxy(49,17);
										printf("c] Question");
										gotoxy(49,19);
										printf("d] Return");										
										//end of frame of student list and menu
										line=0;
										for(row=0;row<10;row++)
										{											
											if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
											{
												gotoxy(12,12+line);
												printf("0%d0\t\t",row);//print student # who selects this course	
												line++;	//= \n										
											} 																						
										}
																			
										gotoxy(49,21);
										printf("Choice: ");
										teacherChoice=_getch();
										fflush(stdin);
										gotoxy(49,21);
										printf("Choice: %c",teacherChoice);
										switch(teacherChoice)
										{
											case 'a': //announcement
											case 'A':
												if(announcementCount[teacherIdentity]==0) //when posting announcement first time
												{
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													gotoxy(33,10);
													printf("Enter the announcement and press");
													gotoxy(33,11);
													printf("<ENTER>: ");
													gotoxy(33,12);
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
													scanf("%[^\n]",announcement[teacherIdentity]);
													fflush(stdin);
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
													gotoxy(33,14);
													printf("Press <ENTER> to continue!");
													getch();
													announcementCount[teacherIdentity]=1;
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
												}
												else
												{
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													gotoxy(33,10);
													printf("Current Announcement: %s",announcement[teacherIdentity]);
													do
													{
													
														gotoxy(33,12);
														printf("Are you sure you want to add an announcement");
														gotoxy(33,13);
														printf("to replace the current one? Y/N: ");
														yesNo=_getch();
														fflush(stdin);																														
														switch(yesNo)
														{
															case 'y':
															case 'Y':
																gotoxy(33,14);
																printf("Enter the announcement and press <ENTER>: ");
																gotoxy(33,15);
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
																scanf("%[^\n]",announcement[teacherIdentity]);
																fflush(stdin);
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
																gotoxy(33,17);
																printf("Press <ENTER> to continue!");
																getch();
																announcementCount[teacherIdentity]=1;
																for(row=0;row<15;row++)
																{
																	gotoxy(33,10+row);
																	printf("\t\t\t\t\t");//clean part of the screen
																}																	
																flag1=2;
																break;
																
															case 'n':
															case 'N':
																for(row=0;row<15;row++)
																{
																	gotoxy(33,10+row);
																	printf("\t\t\t\t\t");//clean part of the screen
																}		
																flag=0; //return to menu
																flag1=2;
																break;
															
															default:
																SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
																gotoxy(33,15);
																printf("INVALID INPUT!");
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
																gotoxy(33,17);
																printf("Press <ENTER> to try again!");
																getch(); //hold screen																	
																for(row=0;row<5;row++)
																{
																	gotoxy(33,13+row);
																	printf("\t\t\t\t");//clean part of the screen
																}
																flag1=1;
																break;
														}//end of switch
													}while(flag1<2);
												}
												flag=0;							
												break;
												
											case 'b': //assignment
											case 'B':
												if(assignmentCount[teacherIdentity][enterPeriod-1]==0) //when posting assignment first time
												{
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													gotoxy(33,10);
													printf("Enter the page number of work and press");
													gotoxy(33,11);
													printf("<ENTER>: ");
													gotoxy(33,12);
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
													scanf("%d",&assignment[teacherIdentity][enterPeriod-1]);
													fflush(stdin);
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
													gotoxy(33,14);
													printf("Press <ENTER> to continue!");
													getch();
													for(row=0;row<10;row++)
													{											
														if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
														{
															studentAssignment[row][enterPeriod-1]=0; //new assignment added 
														} 																						
													}
													assignmentCount[teacherIdentity][enterPeriod-1]=1;
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
												}
												else
												{													
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}													
													gotoxy(33,10);
													printf("Current Assignment: %d",assignment[teacherIdentity][enterPeriod-1]);
													do
													{
														line=0;
														for(row=0;row<10;row++)
														{											
															if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
															{
																gotoxy(12,12+line);	
																if(studentAssignment[row][enterPeriod-1]==0)	//if student has not handed in assignment														
																	printf("0%d0",row);//print student # who selects this course
																if(studentAssignment[row][enterPeriod-1]==1) //if student hands in assignment
																{
																	SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
																	printf("0%d0 submitted",row);//print student # who selects this course	
																	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
																}
																line++;	//= \n										
															} 																						
														}
														gotoxy(33,12);
														printf("Add a new assignment");
														gotoxy(33,13);
														printf("to replace the current one? Y/N: ");
														yesNo=_getch();
														fflush(stdin);																														
														switch(yesNo)
														{
															case 'y':
															case 'Y':
																gotoxy(33,14);
																printf("Enter the page number of work: ");
																gotoxy(33,15);
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
																scanf("%d",&assignment[teacherIdentity][enterPeriod-1]);
																fflush(stdin);
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
																gotoxy(33,17);
																printf("Press <ENTER> to continue!");
																getch();
																assignmentCount[teacherIdentity][enterPeriod-1]=1;
																for(row=0;row<15;row++)
																{
																	gotoxy(33,10+row);
																	printf("\t\t\t\t\t");//clean part of the screen
																}																	
																flag1=2;
																for(row=0;row<10;row++)
																{											
																	if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
																	{
																		questionCount[row][enterPeriod-1]=0; //all question cleared
																		question[row][enterPeriod-1]=0;
																		studentAssignment[row][enterPeriod-1]=0; //new assignment added 
																	} 																						
																}
																break;
																
															case 'n':
															case 'N':
																for(row=0;row<15;row++)
																{
																	gotoxy(33,10+row);
																	printf("\t\t\t\t\t");//clean part of the screen
																}
																flag=0; //return to menu
																flag1=2;
																break;
															
															default:
																SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
																gotoxy(33,15);
																printf("INVALID INPUT!");
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
																gotoxy(33,17);
																printf("Press <ENTER> to try again!");
																getch(); //hold screen																	
																for(row=0;row<5;row++)
																{
																	gotoxy(33,13+row);
																	printf("\t\t\t\t");//clean part of the screen
																}
																flag1=1;
																break;
														}//end of switch
													}while(flag1<2);
												}
												flag=0;								
												break;
												
											case 'c': //view question from students about current assignment 
											case 'C':
												if(assignmentCount[teacherIdentity][enterPeriod-1]==0) //if there is not assignment posted
												{
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													gotoxy(33,10);
													printf("There is not assignment posted yet!");
													gotoxy(33,12);
													printf("No question is asked from students!");
													gotoxy(33,14);
													printf("Press <ENTER> to continue!");
													getch();
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
												}
												else //if there is assignment posted
												{													
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													line=0;
													for(row=0;row<10;row++)
													{											
														if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
														{
															gotoxy(12,12+line);	
															if(questionCount[row][enterPeriod-1]==0)	//if student has not question														
																printf("0%d0",row);//print student # who selects this course
															if(questionCount[row][enterPeriod-1]==1) //if student has question
															{
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
																printf("0%d0 %d",row,question[row][enterPeriod-1]);//print student # who selects this course	
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															}
															line++;	//= \n										
														} 																						
													}
													gotoxy(33,10);
													printf("Current Assignment: %d",assignment[teacherIdentity][enterPeriod-1]);
													gotoxy(33,12);
													printf("Press <ENTER> to continue!");
													getch();									
												}//end of else if there is assignment posted
												for(row=0;row<15;row++)
												{
													gotoxy(33,10+row);
													printf("\t\t\t\t\t");//clean part of the screen
												}
												flag=0;
												break;
												
											case 'd':
											case 'D':
												for(row=0;row<20;row++)
												{
													gotoxy(9,5+row);
													printf("\t\t\t\t\t\t\t\t");//clean part of the screen
												}		
												flag=3;											
												break;
												
											default:
												flag=0;
												gotoxy(49,21);
												printf("\t\t\t");//clean part of the screen
												break;													
										}//end of switch
									}while(flag<1);
								}//end of else if user select the right period
							}
							else
							{
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(9,24);
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(9,26);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								for(row=0;row<4;row++)
								{
									gotoxy(9,23+row);
									printf("\t\t\t\t\t");//clean part of the screen
								}
							}
						}while(flag<2);	
						
					}	//end of else														
					break;
				
				case 'd': //setting - change password or exit to home page
				case 'D':
					do
					{					
						for(row=0;row<21;row++)
						{
							gotoxy(9,5+row);
							printf("\t\t\t\t\t\t\t\t"); //clear screen
						}
						for(row=0;row<7;row++)
						{
							gotoxy(9,7+row);
							printf("|");
						}
						gotoxy(10,6);
						printf("Teacher: 00%d",teacherIdentity);
						gotoxy(10,8);
						printf("a] Password");
						gotoxy(10,10);
						printf("b] Exit");
						gotoxy(10,12);
						printf("c] Return");
						gotoxy(10,14);
						printf("Choice:");
						settingChoice=_getch();
						fflush(stdin);
						switch(settingChoice)
						{
							case 'a':
							case 'A':
								do
								{							
									for(row=0;row<15;row++)
									{
										gotoxy(10,7+row);
										printf("\t\t\t\t\t\t\t\t"); //clear screen
									}
									gotoxy(10,8);
									printf("a] Password Change");
									gotoxy(10,10);
									printf("b] Password Reset");
									gotoxy(10,12);
									printf("Choice");
									passwordChoice=_getch();
									fflush(stdin);
									switch(passwordChoice)
									{							
										case 'a': //password change
										case 'A':
											do
											{									
												for(row=0;row<15;row++)
												{
													gotoxy(10,7+row);
													printf("\t\t\t\t\t\t\t\t"); //clear screen
												}
												gotoxy(10,8);
												printf("Current Password:");
												scanf("%d",&currentPasswordEnter);
												fflush(stdin);
												if((teacherChangePassword[teacherIdentity]==0)&&(currentPasswordEnter==1234))//if current password is 1234
												{
													do
													{											
														gotoxy(10,10);
														printf("New Password:");
														for(row=0;row<4;row++)
														{	
															inputPassword[row]=_getch();
															fflush(stdin);
															tempPassword[row]=inputPassword[row]-48; //convert to number on keyboard
															printf("%d",tempPassword[row]);
														}
														newPassword[teacherIdentity]=tempPassword[0]*1000+tempPassword[1]*100+tempPassword[2]*10+tempPassword[3];
														if(newPassword[teacherIdentity]==1234)
														{
															SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("INVALID INPUT!");
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("New password cannot be the same as the current one!");
															gotoxy(10,14);
															printf("Press <ENTER> to try again!");												
															getch(); //hold screen
															for(row=0;row<7;row++)
															{
																gotoxy(10,10+row);
																printf("\t\t\t\t\t\t\t\t"); //clear screen
															}
															flag1=0;													
														}
														else
														{
															teacherPassword[teacherIdentity][1]=newPassword[teacherIdentity];
															teacherChangePassword[teacherIdentity]=1;													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("Great! New password has been set up!");													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,14);
															printf("You will be returned to home page");
															gotoxy(10,15);
															printf("as we have noticed you have set a new password");
															gotoxy(10,17);
															printf("Press <ENTER> to continue!");
															getch();
															for(row=0;row<21;row++)
															{
																gotoxy(9,5+row);
																printf("\t\t\t\t\t\t\t\t");
															}
															flag=4;
															flag1=2;	
														}												
													}while(flag1<1);							
												}
												else if((teacherChangePassword[teacherIdentity]==1)&&(currentPasswordEnter==teacherPassword[teacherIdentity][1])) //if user has changed password before
												{
													//set new password
													do
													{											
														gotoxy(10,10);
														printf("New Password:");
														for(row=0;row<4;row++)
														{	
															inputPassword[row]=_getch();
															fflush(stdin);
															tempPassword[row]=inputPassword[row]-48; //convert to number on keyboard
															printf("%d",tempPassword[row]);
														}
														newPassword[teacherIdentity]=tempPassword[0]*1000+tempPassword[1]*100+tempPassword[2]*10+tempPassword[3];
														if(newPassword[teacherIdentity]==currentPasswordEnter)
														{
															SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("INVALID INPUT!");
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("New password cannot be the same as the current one!");
															gotoxy(10,14);
															printf("Press <ENTER> to try again!");												
															getch(); //hold screen
															for(row=0;row<7;row++)
															{
																gotoxy(10,10+row);
																printf("\t\t\t\t\t\t\t\t"); //clear screen
															}
															flag1=0;													
														}
														else
														{
															teacherPassword[teacherIdentity][1]=newPassword[teacherIdentity];
															teacherChangePassword[teacherIdentity]=1;													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("Great! New password has been set up!");													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,14);
															printf("You will be returned to home page");
															gotoxy(10,15);
															printf("as we have noticed you have set a new password");
															gotoxy(10,17);
															printf("Press <ENTER> to continue!");
															getch();
															for(row=0;row<21;row++)
															{
																gotoxy(9,5+row);
																printf("\t\t\t\t\t\t\t\t");
															}
															flag=4;
															flag1=2;	
														}												
													}while(flag1<1);
												}
												else 
												{
													SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
													gotoxy(10,10);
													printf("INVALID INPUT!");
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
													gotoxy(10,12);
													printf("Press <ENTER> to try again!");
													getch(); //hold screen
													flag1=1;										
												}
											}while(flag1<2);
											break;
											
										case 'b':
										case 'B': //password reset
											teacherChangePassword[teacherIdentity]=0;
											teacherPassword[teacherIdentity][1]=0;
											for(row=0;row<15;row++)
											{
												gotoxy(10,7+row);
												printf("\t\t\t\t\t\t\t\t"); //clear screen
											}
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
											gotoxy(10,8);
											printf("Great! Your password has been set up to '1234'!");	
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(10,10);			
											printf("You will be returned to home page");
											gotoxy(10,11);
											printf("as we have noticed you have set a new password");
											gotoxy(10,13);
											printf("Press <ENTER> to continue!");
											getch();
											for(row=0;row<21;row++)
											{
												gotoxy(9,5+row);
												printf("\t\t\t\t\t\t\t\t");
											}
											flag=4;									
											break;
											
										default:
											SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
											gotoxy(10,14); 
											printf("INVALID INPUT!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(10,16);
											printf("Press <ENTER> to try again!");
											getch(); //hold screen
											flag=0;
											break;
									}//end of switch
								}while(flag<1);
								break;
								
							case 'b': //exit
							case 'B':
								flag=4;
								break;	
							
							case 'c': //return to teacher homepage
							case 'C':
								for(row=0;row<20;row++)
								{
									gotoxy(9,5+row);
									printf("\t\t\t\t\t\t\t\t");//clean part of the screen
								}
								flag=3;
								break;
								
							default:
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(10,14); 
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(10,16);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								break;	
						}//end of switch
					}while(flag<2);
					break;
				
				default: //select again
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
					gotoxy(9,24);
					printf("INVALID INPUT!");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(9,25);
					printf("Press <ENTER> to try again!");
					getch(); //hold screen
					flag=2;
					for(row=0;row<4;row++)
					{
						gotoxy(9,23+row);
						printf("\t\t\t\t\t");//clean part of the screen
					}
					break;			
			}//end of switch
		}while(flag<3); //back to user select choice
	}while(flag<4); //restart this function 	
	return;
}

void studentMenu(int loginTempName[5],int studentClass[10][4],int teacherOrder1[1],int studentThirdClass[10][4],int teacherClass[10][4],int studentChangePassword[10],int studentPassword[10][2],int announcementCount[10],char announcement[10][50],int studentAssignment[10][4],int assignmentCount[10][4],int assignment[10][4],int question[10][4],int questionCount[10][4])
{ //student page
/*Program*/
	int studentIdentity=0;			//student identity
	int enterPeriod=0;				//period entered
	int enterClassCode[5];			//class code entered
	int tempClassCode[5];			//temp class code after calculation -48
	int teacherIdentity=0;			//teacher identity
	int currentPasswordEnter=0;		//enter current password
	int tempPassword[5];			//temp password after calculation-48
	int inputPassword[5];			//password inputted
	int newPassword[10];			//new password after multiplication

/*Others*/	
	char choice;					//choice in student home page
	char yesNo;						//yes or no
	char settingChoice;				//choice in setting
	char passwordChoice;			//choice in password - change or reset
	char studentChoice;				//choice in manage class
	int flag=0;						//do while
	int condition=0;				//identify number of classes added
	int row=0;						//for loop
	int line=0;						//gotoxy position of student on student lists
	int flag1=0;					//do while

	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	studentIdentity=loginTempName[1];
	do
	{
		for(row=0;row<22;row++)
		{
			gotoxy(9,5+row);
			printf("\t\t\t\t\t\t\t");
		}
		if((studentClass[studentIdentity][0]==0)&&(studentClass[studentIdentity][1]==0)&&(studentClass[studentIdentity][2]==0)&&(studentClass[studentIdentity][3]==0))
		{//when having no class added
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
		}//end of if when teacher has no class added
		
		if((studentClass[studentIdentity][0]==1)||(studentClass[studentIdentity][1]==2)||(studentClass[studentIdentity][2]==3)||(studentClass[studentIdentity][3]==4))
		{//when student has 1-3 classes added
			condition=3; 
			for(row=0;row<4;row++)
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(15,7+4*row);
				printf("period %d:",row+1);
				if(studentClass[studentIdentity][row]==0)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED |FOREGROUND_INTENSITY );	//set foreground color
					gotoxy(24,7+4*row);
					printf(" SPARE");
				}
				if(studentClass[studentIdentity][row]!=0)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(24,7+4*row);
					printf(" 00%d%d      ",studentThirdClass[studentIdentity][row],row+1);
				}
			}							
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
		}//end of if
		//menu
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );		
		gotoxy(9,22);
		printf("a] add class b] delete class c] manage class d] setting");
		if((studentClass[studentIdentity][0]==0)&&(studentClass[studentIdentity][1]==0)&&(studentClass[studentIdentity][2]==0)&&(studentClass[studentIdentity][3]==0))
		{//if there is not class added yet, then user cannot select or delete class
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);
			gotoxy(22,22);
			printf("b] delete class c] manage class");
			condition=1;
		}
		if((studentClass[studentIdentity][0]==1)&&(studentClass[studentIdentity][1]==2)&&(studentClass[studentIdentity][2]==3)&&(studentClass[studentIdentity][3]==4))
		{//if all periods have class, then user cannot add class anymore
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE);
			gotoxy(9,22);
			printf("a] add class");
			condition=2;
		}
		do
		{//select in menu
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(30,23);
			printf("choice: "); //prompt user to select
			choice=_getch();
			fflush(stdin);
			gotoxy(30,23);
			printf("choice: %c",choice); //print choice to screen
			switch(choice)
			{
				case 'a'://add class
				case 'A':
					if(condition==2) 
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(9,24);
						printf("INVALID INPUT!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(9,25);
						printf("Press <ENTER> to try again!");
						getch(); //hold screen
						flag=2;
						for(row=0;row<4;row++)
						{
							gotoxy(9,23+row);
							printf("\t\t\t\t\t");//clean part of the screen
						}
					}	
					else
					{
						if(condition==1)
						{						
							for(row=0;row<15;row++) //clear part of the screen
							{
								gotoxy(9,6+row);
								printf("  ");
								gotoxy(70,6+row);
								printf("  "); 
								gotoxy(9,9);
								printf("\t\t\t\t\t\t");
								gotoxy(9,11);
								printf("\t\t\t\t\t\t\t");
								//clear part of the screen
							}			
						}//end of if
						//clear part of the screen
						gotoxy(9,22);
						printf("\t\t\t\t\t\t\t");
						gotoxy(9,23);
						printf("\t\t\t\t\t\t\t");
						for(row=0;row<4;row++)
						{
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(15,7+4*row);
							printf("period %d",row+1);
						}
						//print frame
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
						//end of printing frame
						do
						{						
							gotoxy(9,22);
							printf("Enter period # to add class: ");
							scanf("%d",&enterPeriod);
							fflush(stdin);
							if((enterPeriod>0)&&(enterPeriod<=4))
							{
								if(studentClass[studentIdentity][enterPeriod-1]!=0) //if there is a class on the period 
								{
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
									gotoxy(9,23);
									printf("INVALID INPUT!");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("00%d%d is currently on Period %d",studentThirdClass[studentIdentity][enterPeriod-1],studentClass[studentIdentity][enterPeriod-1],enterPeriod);
									gotoxy(9,25);
									printf("Press <ENTER> to continue!");
									getch();
									for(row=0;row<4;row++)
									{
										gotoxy(9,23+row);
										printf("\t\t\t\t\t\t"); //clear part of screen
									}
									flag=3; //select again
								} 
								else
								{
									gotoxy(9,23);
									printf("Enter a four-digit Class Code: ");
									for(row=0;row<4;row++)
									{			
										SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY );
										enterClassCode[row]=_getch();
										fflush(stdin);
										tempClassCode[row]=enterClassCode[row]-48; //convert to number on keyboard
										printf("%d",tempClassCode[row]);
										SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									}
									if((tempClassCode[0]==0)&&(tempClassCode[1]==0)&&(tempClassCode[2]>=0)&&(tempClassCode[2]<=teacherOrder1[1])&&(tempClassCode[3]==enterPeriod))
									{
										teacherIdentity=tempClassCode[2];
										if(teacherClass[teacherIdentity][enterPeriod-1]==0)
										{ //if class code does not exist
											SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
											gotoxy(9,24);
											printf("INVALID INPUT!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(9,25);
											printf("This Class Code does not exist!");
											gotoxy(9,26);
											printf("Press <ENTER> to continue!");
											getch();
											flag=3; //select again
										}
										else
										{
											studentThirdClass[studentIdentity][enterPeriod-1]=teacherIdentity;
											studentClass[studentIdentity][enterPeriod-1]=enterPeriod;
											gotoxy(9,25);
											printf("Press <ENTER> to add class 00%d%d into period %d!",studentThirdClass[studentIdentity][enterPeriod-1],studentClass[studentIdentity][enterPeriod-1],enterPeriod);
											flag=3;
											getch();
											for(row=0;row<5;row++)
											{
												gotoxy(9,22+row);
												printf("\t\t\t\t\t\t"); //clear part of screen
											}
										}
									}
									else
									{
										//class code does not exist
										SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
										gotoxy(9,24);
										printf("INVALID INPUT!");
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(9,25);
										printf("This Class Code does not exist!");
										gotoxy(9,26);
										printf("Press <ENTER> to continue!");
										getch();
										flag=3; //select again
									}								
								}//end of else
							}//end of if
							else
							{
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(9,24);
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(9,26);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								for(row=0;row<5;row++)
								{
									gotoxy(9,22+row);
									printf("\t\t\t\t\t");//clean part of the screen
								}
							}
						}while(flag<2);							
					}//end of else of add class	
					break;
					
				case 'b': //delete class
				case 'B':	
					if(condition==1)
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(9,24);
						printf("INVALID INPUT!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(9,25);
						printf("Press <ENTER> to try again!");
						getch(); //hold screen
						flag=2;
						for(row=0;row<4;row++)
						{
							gotoxy(9,23+row);
							printf("\t\t\t\t\t");//clean part of the screen
						}
					}	
					else
					{
						gotoxy(9,22);
						printf("\t\t\t\t\t\t\t");
						gotoxy(9,23);
						printf("\t\t\t\t\t\t\t");
						do
						{						
							gotoxy(9,22);
							printf("Enter period # to delete class: ");
							scanf("%d",&enterPeriod);
							fflush(stdin);
							if((enterPeriod>0)&&(enterPeriod<=4))
							{
								if(studentClass[studentIdentity][enterPeriod-1]==0)
								{
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
									gotoxy(9,23);
									printf("INVALID INPUT!");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("There is no class currently on Period %d",enterPeriod);
									gotoxy(9,25);
									printf("Press <ENTER> to continue!");
									getch();
									for(row=0;row<5;row++)
									{
										gotoxy(9,22+row);
										printf("\t\t\t\t\t\t"); //clear part of screen
									}
									flag=3; //select again
								} 
								else
								{																		
									gotoxy(9,23);
									printf("Class code: ");
									SetConsoleTextAttribute ( h, FOREGROUND_RED |FOREGROUND_INTENSITY );
									gotoxy(21,23);
									printf("00%d%d",studentThirdClass[studentIdentity][enterPeriod-1],studentClass[studentIdentity][enterPeriod-1]);
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("Press <ENTER> to remove class 00%d%d from period %d!",studentThirdClass[studentIdentity][enterPeriod-1],studentClass[studentIdentity][enterPeriod-1],enterPeriod);
									flag=3;
									getch();
									for(row=0;row<20;row++)
									{
										gotoxy(9,5+row);
										printf("\t\t\t\t\t\t\t"); //clear part of screen
									}
									studentClass[studentIdentity][enterPeriod-1]=0;	
									studentThirdClass[studentIdentity][enterPeriod-1]=0;									
								}
							}
							else
							{
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(9,24);
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(9,26);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								for(row=0;row<5;row++)
								{
									gotoxy(9,22+row);
									printf("\t\t\t\t\t");//clean part of the screen
								}
							}
						}while(flag<2);	
					}				
					break;
					
				case 'c': //manage class
				case 'C':
					if(condition==1)
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
						gotoxy(9,24);
						printf("INVALID INPUT!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(9,25);
						printf("Press <ENTER> to try again!");
						getch(); //hold screen
						flag=2;
						for(row=0;row<4;row++)
						{
							gotoxy(9,23+row);
							printf("\t\t\t\t\t");//clean part of the screen
						}
					}	
					else
					{
						gotoxy(9,22);
						printf("\t\t\t\t\t\t\t");
						gotoxy(9,23);
						printf("\t\t\t\t\t\t\t");
						do
						{						
							gotoxy(9,22);
							printf("Enter period # to manage your class: ");
							scanf("%d",&enterPeriod);
							fflush(stdin);
							if((enterPeriod>0)&&(enterPeriod<=4))
							{
								if(studentClass[studentIdentity][enterPeriod-1]==0)
								{
									SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
									gotoxy(9,23);
									printf("INVALID INPUT!");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("There is no class currently on Period %d",enterPeriod);
									gotoxy(9,25);
									printf("Press <ENTER> to continue!");
									getch();
									for(row=0;row<5;row++)
									{
										gotoxy(9,22+row);
										printf("\t\t\t\t\t\t"); //clear part of screen
									}
									flag=3; //select again
								} 
								else
								{																			
									gotoxy(9,23);
									printf("Class code: ");
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
									gotoxy(21,23);
									printf("00%d%d",studentThirdClass[studentIdentity][enterPeriod-1],studentClass[studentIdentity][enterPeriod-1]);
									SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
									gotoxy(9,24);
									printf("Press <ENTER> to continue!");
									flag=3;
									getch();
									teacherIdentity=studentThirdClass[studentIdentity][enterPeriod-1];
									for(row=0;row<20;row++)
									{
										gotoxy(9,5+row);
										printf("\t\t\t\t\t\t\t\t"); //clear part of screen
									}
									do
									{
										//print frame of one period
										SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(9,6);
										printf("|");
										gotoxy(70,6);
										printf("|");
										for(row=0;row<60;row++)
										{
											gotoxy(10+row,5);
											printf("-");
											gotoxy(10+row,7);
											printf("-");
										}
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(10,6);
										printf("Announcement: ");
										gotoxy(10,8);
										printf("Period: %d  Class Code:00%d%d  teacher: 00%d",enterPeriod,studentThirdClass[studentIdentity][enterPeriod-1],studentClass[studentIdentity][enterPeriod-1],teacherIdentity);
									
										if(announcementCount[teacherIdentity]==0)
										{
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);
											gotoxy(24,6);
											printf("Nothing is posted!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										}
										if(announcementCount[teacherIdentity]==1)
										{
											gotoxy(24,6);
											printf("\t\t\t\t\t");//clean part of the screen 
											gotoxy(24,6);
											printf("%s",announcement[teacherIdentity]);
										}
										//print frame of student list and menu										
										
										SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										for(row=0;row<20;row++)
										{
											gotoxy(11+row,10);
											printf("-");
											gotoxy(11+row,22);
											printf("-");
											gotoxy(49+row,10);
											printf("-");
											gotoxy(49+row,22);
											printf("-");
										}
										for(row=0;row<11;row++)
										{
											gotoxy(10,11+row);
											printf("|");
											gotoxy(31,11+row);
											printf("|");
											gotoxy(48,11+row);
											printf("|");
											gotoxy(69,11+row);
											printf("|");
										}									
										SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
										gotoxy(15,11);
										printf("STUDENT LIST");
										gotoxy(53,11);
										printf("MENU");
										gotoxy(49,13);
										printf("a] Assignment");
										gotoxy(49,15);
										printf("b] Question");
										gotoxy(49,17);
										printf("c] Return");										
										//end of frame of student list and menu
										line=0;
										for(row=0;row<10;row++)
										{											
											if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
											{
												gotoxy(12,12+line);
												printf("0%d0            ",row);//print student # who selects this course	
												line++;	//= \n
											}									
										}																
										gotoxy(49,19);
										printf("Choice: ");
										studentChoice=_getch();
										fflush(stdin);
										gotoxy(49,19);
										printf("Choice: %c",studentChoice);
										switch(studentChoice)
										{									
												
											case 'a': //assignment
											case 'A':
												if(assignmentCount[teacherIdentity][enterPeriod-1]==0) //if there is not assignment posted
												{
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													gotoxy(33,10);
													printf("There is not assignment posted yet!");
													gotoxy(33,12);
													printf("Press <ENTER> to continue!");
													getch();
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
												}
												else //if there is assignment posted
												{													
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													line=0;
													for(row=0;row<10;row++)
													{											
														if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
														{
															gotoxy(12,12+line);	
															if(studentAssignment[row][enterPeriod-1]==0)	//if student has not handed in assignment														
																printf("0%d0",row);//print student # who selects this course
															if(studentAssignment[row][enterPeriod-1]==1) //if student hands in assignment
															{
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
																printf("0%d0 submitted",row);//print student # who selects this course	
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															}
															line++;	//= \n										
														} 																						
													}
													gotoxy(33,10);
													printf("Current Assignment: %d",assignment[teacherIdentity][enterPeriod-1]);
													do
													{
														if(studentAssignment[studentIdentity][enterPeriod-1]==0)
														{
															gotoxy(33,12);
															printf("You have not submitted your assignment!");
															gotoxy(33,14);
															printf("Hand in now? Y/N: ");
															yesNo=_getch();
															fflush(stdin);																														
															switch(yesNo)
															{
																case 'y':
																case 'Y':																	
																	gotoxy(33,16);
																	SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
																	printf("Great! Your assignment has been sent!");
																	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
																	gotoxy(33,18);
																	printf("Press <ENTER> to continue!");
																	getch();
																	studentAssignment[studentIdentity][enterPeriod-1]=1;
																	for(row=0;row<15;row++)
																	{
																		gotoxy(33,10+row);
																		printf("\t\t\t\t\t");//clean part of the screen
																	}																	
																	flag1=2;
																	break;
																	
																case 'n':
																case 'N':
																	studentAssignment[studentIdentity][enterPeriod-1]=0;
																	for(row=0;row<15;row++)
																	{
																		gotoxy(33,10+row);
																		printf("\t\t\t\t\t");//clean part of the screen
																	}
																	flag=0; //return to menu
																	flag1=2;
																	break;
																
																default:
																	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
																	gotoxy(33,16);
																	printf("INVALID INPUT!");
																	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
																	gotoxy(33,18);
																	printf("Press <ENTER> to try again!");
																	getch(); //hold screen																	
																	for(row=0;row<5;row++)
																	{
																		gotoxy(33,13+row);
																		printf("\t\t\t\t\t");//clean part of the screen
																	}
																	flag1=1;
																	break;
															}//end of switch
														}//end of if student has not handed in assignment yet
														if(studentAssignment[studentIdentity][enterPeriod-1]==1) //if student has handed in their assignment
														{
															gotoxy(33,12);
															printf("You have handed in the assignment!");
															gotoxy(33,14);
															printf("New assignment is not posted yet!");
															gotoxy(33,16);
															printf("Press <ENTER> to continue!");
															getch(); //hold screen
															for(row=0;row<15;row++)
															{
																gotoxy(33,10+row);
																printf("\t\t\t\t\t");//clean part of the screen
															}																	
															flag1=2;
														}														
													}while(flag1<2);
												}
												flag=0; 
												break;
												
											case 'b': //question for assignment posted
											case 'B':
												if(assignmentCount[teacherIdentity][enterPeriod-1]==0) //if there is not assignment posted
												{
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													gotoxy(33,10);
													printf("There is not assignment posted yet!");
													gotoxy(33,12);
													printf("Press <ENTER> to continue!");
													getch();
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
												}
												else //if there is assignment posted
												{													
													for(row=0;row<15;row++)
													{
														gotoxy(33,10+row);
														printf("\t\t\t\t\t");//clean part of the screen
													}
													line=0;
													for(row=0;row<10;row++)
													{											
														if((studentThirdClass[row][enterPeriod-1]==teacherIdentity)&&(studentClass[row][enterPeriod-1]==enterPeriod)) //only if student selects this teacher and the same period
														{
															gotoxy(12,12+line);	
															if(questionCount[row][enterPeriod-1]==0)	//if student has not question														
																printf("0%d0",row);//print student # who selects this course
															if(questionCount[row][enterPeriod-1]==1) //if student has question
															{
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
																printf("0%d0 %d",row,question[row][enterPeriod-1]);//print student # who selects this course	
																SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															}
															line++;	//= \n										
														} 																						
													}
													gotoxy(33,10);
													printf("Current Assignment: %d",assignment[teacherIdentity][enterPeriod-1]);
													if(questionCount[studentIdentity][enterPeriod]==0) //if studnet does not ask question on the current assignment before
													{
														gotoxy(33,11);
														printf("Current question: N/A");
													}
													else //if student does have question before
													{
														gotoxy(33,11);
														printf("Current question: %d",question[studentIdentity][enterPeriod-1]);
													}													
													gotoxy(33,13);
													printf("Enter Question # on");
													gotoxy(33,14);
													printf("the assignment:");
													scanf("%d",&question[studentIdentity][enterPeriod-1]);
													fflush(stdin);	
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );												
													gotoxy(33,16);
													printf("Questions have sent to teacher!");
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
													gotoxy(33,18);
													printf("Press <ENTER> to continue!");
													getch();				
													questionCount[studentIdentity][enterPeriod-1]=1;									
												}//end of else if there is assignment posted
												for(row=0;row<15;row++)
												{
													gotoxy(33,10+row);
													printf("\t\t\t\t\t");//clean part of the screen
												}
												flag=0;
												break;
												
											case 'c': //return
											case 'C':
												for(row=0;row<20;row++)
												{
													gotoxy(9,5+row);
													printf("\t\t\t\t\t\t\t\t");//clean part of the screen
												}		
												flag=3;											
												break;
												
											default:
												flag=0;
												gotoxy(49,21);
												printf("\t\t\t");//clean part of the screen
												break;													
										}//end of switch
									}while(flag<1);
								}//end of else if user select the right period
							}
							else
							{
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(9,24);
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(9,26);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								for(row=0;row<4;row++)
								{
									gotoxy(9,23+row);
									printf("\t\t\t\t\t");//clean part of the screen
								}
							}
						}while(flag<2);	
												
					}	//end of else														
					break;				
				
				case 'd': //setting - change password or exit to home page
				case 'D':
					do
					{					
						for(row=0;row<21;row++)
						{
							gotoxy(9,5+row);
							printf("\t\t\t\t\t\t\t\t"); //clear screen
						}
						for(row=0;row<7;row++)
						{
							gotoxy(9,7+row);
							printf("|");
						}
						gotoxy(10,6);
						printf("Student: 00%d",studentIdentity);
						gotoxy(10,8);
						printf("a] Password");
						gotoxy(10,10);
						printf("b] Exit");
						gotoxy(10,12);
						printf("c] Return");
						gotoxy(10,14);
						printf("Choice:");
						settingChoice=_getch();
						fflush(stdin);
						switch(settingChoice)
						{
							case 'a':
							case 'A':
								do
								{							
									for(row=0;row<15;row++)
									{
										gotoxy(10,7+row);
										printf("\t\t\t\t\t\t\t\t"); //clear screen
									}
									gotoxy(10,8);
									printf("a] Password Change");
									gotoxy(10,10);
									printf("b] Password Reset");
									gotoxy(10,12);
									printf("Choice");
									passwordChoice=_getch();
									fflush(stdin);
									switch(passwordChoice)
									{							
										case 'a': //password change
										case 'A':
											do
											{									
												for(row=0;row<15;row++)
												{
													gotoxy(10,7+row);
													printf("\t\t\t\t\t\t\t\t"); //clear screen
												}
												gotoxy(10,8);
												printf("Current Password:");
												scanf("%d",&currentPasswordEnter);
												fflush(stdin);
												if((studentChangePassword[studentIdentity]==0)&&(currentPasswordEnter==1234))//if current password is 1234
												{
													do
													{											
														gotoxy(10,10);
														printf("New Password:");
														for(row=0;row<4;row++)
														{	
															inputPassword[row]=_getch();
															fflush(stdin);
															tempPassword[row]=inputPassword[row]-48; //convert to number on keyboard
															printf("%d",tempPassword[row]);
														}
														newPassword[studentIdentity]=tempPassword[0]*1000+tempPassword[1]*100+tempPassword[2]*10+tempPassword[3];
														if(newPassword[studentIdentity]==1234) //if password entered same as the current password
														{
															SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("INVALID INPUT!");
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("New password cannot be the same as the current one!");
															gotoxy(10,14);
															printf("Press <ENTER> to try again!");												
															getch(); //hold screen
															for(row=0;row<7;row++)
															{
																gotoxy(10,10+row);
																printf("\t\t\t\t\t\t\t\t"); //clear screen
															}
															flag1=0;													
														}
														else
														{
															studentPassword[studentIdentity][1]=newPassword[studentIdentity];
															studentChangePassword[studentIdentity]=1;													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("Great! New password has been set up!");													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,14);
															printf("You will be returned to home page");
															gotoxy(10,15);
															printf("as we have noticed you have set a new password");
															gotoxy(10,17);
															printf("Press <ENTER> to continue!");
															getch();
															for(row=0;row<21;row++)
															{
																gotoxy(9,5+row);
																printf("\t\t\t\t\t\t\t\t");
															}
															flag=4;
															flag1=2;	
														}												
													}while(flag1<1);							
												}
												else if((studentChangePassword[studentIdentity]==1)&&(currentPasswordEnter==studentPassword[studentIdentity][1])) //if user has changed password before
												{
													//set new password
													do
													{											
														gotoxy(10,10);
														printf("New Password:");
														for(row=0;row<4;row++)
														{	
															inputPassword[row]=_getch();
															fflush(stdin);
															tempPassword[row]=inputPassword[row]-48; //convert to number on keyboard
															printf("%d",tempPassword[row]);
														}
														newPassword[studentIdentity]=tempPassword[0]*1000+tempPassword[1]*100+tempPassword[2]*10+tempPassword[3];
														if(newPassword[studentIdentity]==currentPasswordEnter)
														{
															SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("INVALID INPUT!");
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("New password cannot be the same as the current one!");
															gotoxy(10,14);
															printf("Press <ENTER> to try again!");												
															getch(); //hold screen
															for(row=0;row<7;row++)
															{
																gotoxy(10,10+row);
																printf("\t\t\t\t\t\t\t\t"); //clear screen
															}
															flag1=0;													
														}
														else
														{
															studentPassword[studentIdentity][1]=newPassword[studentIdentity];
															studentChangePassword[studentIdentity]=1;													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY );
															gotoxy(10,12);
															printf("Great! New password has been set up!");													
															SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
															gotoxy(10,14);
															printf("You will be returned to home page");
															gotoxy(10,15);
															printf("as we have noticed you have set a new password");
															gotoxy(10,17);
															printf("Press <ENTER> to continue!");
															getch();
															for(row=0;row<21;row++)
															{
																gotoxy(9,5+row);
																printf("\t\t\t\t\t\t\t\t");
															}
															flag=4;
															flag1=2;	
														}												
													}while(flag1<1);
												}
												else 
												{
													SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
													gotoxy(10,10);
													printf("INVALID INPUT!");
													SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
													gotoxy(10,12);
													printf("Press <ENTER> to try again!");
													getch(); //hold screen
													flag1=1;										
												}
											}while(flag1<2);
											break;
											
										case 'b':
										case 'B': //password reset
											studentChangePassword[studentIdentity]=0;
											studentPassword[studentIdentity][1]=0;
											for(row=0;row<15;row++)
											{
												gotoxy(10,7+row);
												printf("\t\t\t\t\t\t\t\t"); //clear screen
											}
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
											gotoxy(10,8);
											printf("Great! Your password has been set up to '1234'!");	
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(10,10);			
											printf("You will be returned to home page");
											gotoxy(10,11);
											printf("as we have noticed you have set a new password");
											gotoxy(10,13);
											printf("Press <ENTER> to continue!");
											getch();
											for(row=0;row<21;row++)
											{
												gotoxy(9,5+row);
												printf("\t\t\t\t\t\t\t\t");
											}
											flag=4;									
											break;
											
										default:
											SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
											gotoxy(10,14); 
											printf("INVALID INPUT!");
											SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
											gotoxy(10,16);
											printf("Press <ENTER> to try again!");
											getch(); //hold screen
											flag=0;
											break;
									}//end of switch
								}while(flag<1);
								break;
								
							case 'b': //exit
							case 'B':
								flag=4;
								break;	
							
							case 'c': //return to student home page
							case 'C':
								for(row=0;row<20;row++)
								{
									gotoxy(9,5+row);
									printf("\t\t\t\t\t\t\t\t");//clean part of the screen
								}
								flag=3;
								break;
								
							default:
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
								gotoxy(10,14); 
								printf("INVALID INPUT!");
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
								gotoxy(10,16);
								printf("Press <ENTER> to try again!");
								getch(); //hold screen
								flag=1;
								break;	
						}//end of switch
					}while(flag<2);
					break;

				default: //select again
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY );
					gotoxy(9,24);
					printf("INVALID INPUT!");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(9,25);
					printf("Press <ENTER> to try again!");
					getch(); //hold screen
					flag=2;
					for(row=0;row<4;row++)
					{
						gotoxy(9,23+row);
						printf("\t\t\t\t\t");//clean part of the screen
					}
					break;			
			}//end of switch
		}while(flag<3); //back to user select choice
	}while(flag<4); //restart this function 	
	return;
}

void visitorMenu (void)
{ //visitor page- intro to program

	int row=0; //for loop
	
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(0,0);
	printf("TEACHER/STUDENT HOME PAGE"); 
	for(row=0;row<4;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(15,7+4*row);
		printf("period %d:",row+1);
		SetConsoleTextAttribute ( h, FOREGROUND_RED |FOREGROUND_INTENSITY );
		gotoxy(24,7+4*row);
		printf("EMPTY");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(24,7);
		printf("0011  ");		
	}
	SetConsoleTextAttribute ( h,FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(22,8);
	printf("'--------> period #");
	gotoxy(27,6);
	printf(",------------> class code of the course");
	gotoxy(28,7);
	printf("                 in period 1");	
	gotoxy(30,11);
	printf("-----> there is not class on period 2");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );						
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
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_INTENSITY );		
	gotoxy(9,22);
	printf("a] add class b] delete class c] manage class d] setting");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(9,24);
	printf("Press <ENTER> to continue!");
	getch();
	gotoxy(0,0);
	printf("\t\t\t\t\t\t\t\t");
	for(row=0;row<21;row++)
	{
		gotoxy(9,5+row);
		printf("\t\t\t\t\t\t\t\t");
	}
	gotoxy(0,0);
	printf("TEACHER/STUDENT CLASS MANAGEMENT");
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(9,6);
	printf("|");
	gotoxy(70,6);
	printf("|");
	for(row=0;row<60;row++)
	{
		gotoxy(10+row,5);
		printf("-");
		gotoxy(10+row,7);
		printf("-");
	}
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(10,6);
	printf("Announcement: ");
	gotoxy(10,8);
	printf("Period: 1  Class Code:0011 teacher: 001");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE);
	gotoxy(24,6);
	printf("Nothing is posted!");
	//print frame of student list and menu																		
	SetConsoleTextAttribute ( h,  FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	for(row=0;row<20;row++)
	{
		gotoxy(11+row,10);
		printf("-");
		gotoxy(11+row,22);
		printf("-");
		gotoxy(49+row,10);
		printf("-");
		gotoxy(49+row,22);
		printf("-");
	}
	for(row=0;row<11;row++)
	{
		gotoxy(10,11+row);
		printf("|");
		gotoxy(31,11+row);
		printf("|");
		gotoxy(48,11+row);
		printf("|");
		gotoxy(69,11+row);
		printf("|");
	}					
	gotoxy(16,13);
	printf("'--> student in");
	gotoxy(16,14);
	printf("   this class");				
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(14,12);
	printf("010");
	gotoxy(15,11);
	printf("STUDENT LIST");
	gotoxy(53,11);
	printf("MENU");
	gotoxy(49,13);
	printf("a] Announcement");
	gotoxy(49,15);
	printf("b] Assignment");
	gotoxy(49,17);
	printf("c] Question");
	gotoxy(49,19);
	printf("d] Return");										
	//end of frame of student list and menu
	gotoxy(9,24);
	printf("Press <ENTER> to continue!");
	getch();
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(14,13);
	printf("'--> student has ");
	gotoxy(16,14);
	printf("   submitted ");
	gotoxy(16,15);
	printf("  assignment");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
	gotoxy(14,12);
	printf("010 sumbitted");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(9,24);
	printf("Press <ENTER> to continue!");
	getch();
	SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(14,13);
	printf("'--> student asks");
	gotoxy(16,14);
	printf("  question #1");
	gotoxy(16,15);
	printf("    from    ");
	gotoxy(16,16);
	printf("  assignment");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_INTENSITY );
	gotoxy(14,12);
	printf("010 1        ");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(9,24);
	printf("This is the end of tour!              ");
	gotoxy(9,26);
	printf("Press <ENTER> to start the Classroom!");
	getch();
	return;
}
