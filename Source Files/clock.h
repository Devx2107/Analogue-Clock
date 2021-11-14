#ifndef CLOCK_H
#define CLOCK_H


#include <graphics.h>
#include <time.h>
#include <math.h>
#include "timeio.h"
#include "structure.h"



Point RotatePoint (Point Rotation, Point Center, double Radian)
{
	Point RotatedPoint;
	
	RotatedPoint.X = (float)(Center.X + ((Rotation.X - Center.X) * cos(Radian) - (Rotation.Y - Center.Y) * sin(Radian)));
	RotatedPoint.Y = (float)(Center.Y + ((Rotation.X - Center.X) * sin(Radian) + (Rotation.Y - Center.Y) * cos(Radian)));
	
	return RotatedPoint;
}


void DrawClock (Point Center, int Call)
{
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	pieslice(Center.X, Center.Y, 0, 360, 155);
	
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	pieslice(Center.X, Center.Y, 0, 360, 150);
	
	Point Rotation;
	
	Rotation.X = Center.X;
	Rotation.Y = (Center.Y - 145);
	
	double angle = 6, Radian;
	Radian = (angle * 0.01745);
	
	for(int i = 1; i <= 60; i++)
	{
		setcolor(WHITE);
		line(Center.X, Center.Y, Rotation.X, Rotation.Y);

		Rotation = RotatePoint(Rotation, Center, Radian);
		
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		pieslice(Center.X, Center.Y, 0, 360, 130);
		
		if(Call == 1)
		{
			delay(50);
		}
	}
	
	angle = 30;
	Radian = (angle * 0.01745);
	
	for(int i = 1; i <= 12; i++)
	{
		setcolor(CYAN);
		setlinestyle(SOLID_LINE, 0, 2);
		line(Center.X, Center.Y, Rotation.X, Rotation.Y);

		Rotation = RotatePoint(Rotation, Center, Radian);
		
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		pieslice(Center.X, Center.Y, 0, 360, 115);
		
		if(Call == 1)
		{
			delay(100);
		}
	}
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	pieslice(Center.X, Center.Y, 0, 360, 2);
	
	return;
}


int Start ()
{
	Time T;
	char Ans;
	
	T = Initiate();
	
	printf("\n\t");
	printf("!..... Analogue Clock..... !");
	
	printf("\n\n");
	
	printf("\tWelcome User !\n");
	printf("\n");
	
	printf("\tDo You Want To Continue With System Time? (Y/N) --> ");
	scanf(" %c", &Ans);
	
	if(toupper(Ans) == 'Y')
	{
		fflush(stdin);
		
		printf("\n\tCurrent Time: %02d:%02d:%02d\n", T.Hour, T.Minute, T.Second);
		printf("\n");
	
		return 1;
	}
	else
	{
		fflush(stdin);
		return 0;
	}
}


int SwapPeriod (int Period)
{
	if(Period == 1)
	{
		return 2;
	}
	else if(Period == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void DigitalClock (Time T, int Period)
{
    char DigitalHour[5] = {'\0'};
    char DigitalMinute[5] = {'\0'};
    char DigitalSecond[5] = {'\0'};
    
    char DigitalTime[20] = {'\0'};
	
	sprintf(DigitalHour, "%02d", (T.Hour));	
	sprintf(DigitalMinute, "%02d", (T.Minute));
	sprintf(DigitalSecond, "%02d", (T.Second));
	
	strcat(DigitalTime, DigitalHour);
	strcat(DigitalTime, ":");
	strcat(DigitalTime, DigitalMinute);
	strcat(DigitalTime, ":");
	strcat(DigitalTime, DigitalSecond);
	strcat(DigitalTime, " ");

	if(Period == 1)
	{
	    strcat(DigitalTime, "AM");
	}
	else if(Period == 2)
	{
	    strcat(DigitalTime, "PM");
	}
	 	
	setcolor(WHITE);
	rectangle(100, 3, 540, 475);
	
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(10, HORIZ_DIR, 5);
	moveto(320, 375);
	
	outtext(DigitalTime);
}

Hand DrawHands (Point Center, Time T, int Period)
{	
	Hand ClockHands;
	double angle, Radian;
	
	ClockHands.SecondHand.X = Center.X;
	ClockHands.SecondHand.Y = (Center.Y - 120);
	
	angle = (6 * (T.Second % 60));
	Radian = (angle * 0.01745);
	
	ClockHands.SecondHand = RotatePoint (ClockHands.SecondHand, Center, Radian);
	
	ClockHands.MinuteHand.X = Center.X;
	ClockHands.MinuteHand.Y = (Center.Y - 100);
	
	angle = ((6 * (T.Minute % 60)) + (angle / 60));
	Radian = (angle * 0.01745);
	
	ClockHands.MinuteHand = RotatePoint (ClockHands.MinuteHand, Center, Radian);
	
	ClockHands.HourHand.X = Center.X;
	ClockHands.HourHand.Y = (Center.Y - 70);
	
	angle = ((30 * (T.Hour % 12)) + (angle / 12));
	Radian = (angle * 0.01745);
	
	ClockHands.HourHand = RotatePoint (ClockHands.HourHand, Center, Radian);
	
	setcolor(WHITE);	
	setlinestyle(SOLID_LINE, 0, 5);
	line(Center.X, Center.Y, ClockHands.HourHand.X, ClockHands.HourHand.Y);
	
	setcolor(BLUE);	
	setlinestyle(SOLID_LINE, 0, 3);
	line(Center.X, Center.Y, ClockHands.MinuteHand.X, ClockHands.MinuteHand.Y);
	
	setcolor(RED);	
	setlinestyle(SOLID_LINE, 0, 1);
	line(Center.X, Center.Y, ClockHands.SecondHand.X, ClockHands.SecondHand.Y);
	
	DigitalClock(T, Period);
}


void EraseHands (Point Center, Time T)
{
	Hand ClockHands;
	double angle, Radian;
	
	ClockHands.SecondHand.X = Center.X;
	ClockHands.SecondHand.Y = (Center.Y - 120);
	
	angle = (6 * (T.Second % 60));
	Radian = (angle * 0.01745);
	
	ClockHands.SecondHand = RotatePoint (ClockHands.SecondHand, Center, Radian);
	
	ClockHands.MinuteHand.X = Center.X;
	ClockHands.MinuteHand.Y = (Center.Y - 100);
	
	angle = ((6 * (T.Minute % 60)) + (angle / 60));
	Radian = (angle * 0.01745);
	
	ClockHands.MinuteHand = RotatePoint (ClockHands.MinuteHand, Center, Radian);
	
	ClockHands.HourHand.X = Center.X;
	ClockHands.HourHand.Y = (Center.Y - 70);
	
	angle = ((30 * (T.Hour % 12)) + (angle / 12));
	Radian = (angle * 0.01745);
	
	ClockHands.HourHand = RotatePoint (ClockHands.HourHand, Center, Radian);
	
	setcolor(BLACK);	
	setlinestyle(SOLID_LINE, 0, 5);
	line(Center.X, Center.Y, ClockHands.HourHand.X, ClockHands.HourHand.Y);
	
	setcolor(BLACK);	
	setlinestyle(SOLID_LINE, 0, 3);
	line(Center.X, Center.Y, ClockHands.MinuteHand.X, ClockHands.MinuteHand.Y);
	
	setcolor(BLACK);	
	setlinestyle(SOLID_LINE, 0, 1);
	line(Center.X, Center.Y, ClockHands.SecondHand.X, ClockHands.SecondHand.Y);
}


Time UpdateTime (Time T, int Formate, int *Period)
{
	if(Formate == 1)
	{
		T.Second += 1;
		T.Minute += (T.Second / 60);
		T.Hour += (T.Minute / 60);
	
		T.Second %= 60;
		T.Minute %= 60;
		T.Hour %= 24;
	}
	else
	{
		T.Second += 1;
		T.Minute += (T.Second / 60);
		T.Hour += (T.Minute / 60);
	
		T.Second %= 60;
		T.Minute %= 60;
		
		if(T.Hour != 12)
		{
			T.Hour %= 12;
		}
		
		if(!T.Hour)
		{
			T.Hour = 12;
		}
		
		if((T.Hour == 12) && (T.Minute == 0) && (T.Second == 0))
		{
			*Period = SwapPeriod(*Period);
		}
	}
	
	return T;
}


void LiveClock (Point Center, Time T, Hand ClockHands, int Formate, int *Period)
{	
	fflush(stdin);
	
	while(!kbhit())
	{
		EraseHands(Center, T);
		T = UpdateTime (T, Formate, Period);
		DrawHands(Center, T, *Period);
		delay(1000);
	}
}


void MainDriver()
{
    system("pause");
	
	int gm = DETECT, gd;
	
	initgraph(&gm, &gd, (char *)"");
	cleardevice();

	system("cls");
	
	int Formate = 1, Period = 0;
	Time T;
	Point Center;
	char Ans;
	
	Center.X = (getmaxx() / 2);
	Center.Y = (getmaxy() / 2);
	
	Center.Y -= 75;
	
	DrawClock(Center, 1);
	
	if(Start())
	{
		printf("\n");
		printf("\tGreat User ! Press Any Key Any Time To Pause The Clock !\n");
		
		LiveClock(Center, Initiate(), DrawHands (Center, Initiate(), Period), Formate, &Period);
		
		printf("\n");
		printf("\tDo You Want To Continue With Custom Time? (Y/N) --> ");
		scanf(" %c", &Ans);
		
		if(toupper(Ans) != 'Y')
		{
		    fflush(stdin);
			printf("\n");
		    
		    printf("\tGood Bye User ! ");
		    system("pause");
		    
			return;
	    }
	}
	
	closegraph();
	fflush(stdin);
	
	initgraph(&gm, &gd, (char *)"");
	cleardevice();
	
	DrawClock(Center, 2);
	system("cls");
	
	printf("\n\t");
	printf("!..... Analogue Clock..... !");
	
	printf("\n\n");	
	
	GetFormate (&Formate);
	printf("\n");
	
	while(1)
	{
		if(Formate == 1)
		{
			system("cls");
			
			IfValidFormate (Formate);
			GetTime(&T, Formate, &Period);
			
			break;
		}
		
		if(Formate == 2)
		{
			system("cls");
			
			IfValidFormate (Formate);
			GetTime(&T, Formate, &Period);
			
			break;
		}
		
		system("cls");
		IfInvalidFormate (&Formate);
	}
	
	printf("\n");
	printf("\tGreat User ! Press Any Key Any Time To Close The Program !\n");
	
	LiveClock(Center, T, DrawHands (Center, T, Period), Formate, &Period);
	
	getch();
	closegraph();		
}


#endif

