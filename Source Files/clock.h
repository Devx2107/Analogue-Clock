#ifndef CLOCK_H
#define CLOCK_H


#include <graphics.h>


Point RotatePoint (Point Rotation, Point Center, double Radian)
{
	Point RotatedPoint;
	
	RotatedPoint.X = (float)(Center.X + ((Rotation.X - Center.X) * cos(Radian) - (Rotation.Y - Center.Y) * sin(Radian)));
	RotatedPoint.Y = (float)(Center.Y + ((Rotation.X - Center.X) * sin(Radian) + (Rotation.Y - Center.Y) * cos(Radian)));
	
	return RotatedPoint;
}


void DigitalClock (Time T)
{
    char DigitalHour[5] = {'\0'};
    char DigitalMinute[5] = {'\0'};
    char DigitalSecond[5] = {'\0'};
    
    char DigitalTime[20] = {'\0'};
	
	if(!T.Hour)
	{
		sprintf(DigitalHour, "%02d", 12);
	}
	else
	{
		sprintf(DigitalHour, "%02d", (T.Hour));
	}
	
	sprintf(DigitalMinute, "%02d", (T.Minute));
	sprintf(DigitalSecond, "%02d", (T.Second));
	
	strcat(DigitalTime, DigitalHour);
	strcat(DigitalTime, ":");
	strcat(DigitalTime, DigitalMinute);
	strcat(DigitalTime, ":");
	strcat(DigitalTime, DigitalSecond);
	
	setcolor(WHITE);
	rectangle(100, 3, 540, 475);
	
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(10, HORIZ_DIR, 5);
	moveto(320, 375);
	
	outtext(DigitalTime);
}


Hand DrawHands (Point Center, Time T)
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
	
	DigitalClock(T);
}


Hand DrawClock (Point Center, Time T)
{	
	Center.Y -= 75;
	
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
		
		delay(50);
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
		
		delay(100);
	}
	
	Hand ClockHands = DrawHands (Center, T);
	
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	pieslice(Center.X, Center.Y, 0, 360, 2);
	
	delay(1000);
	
	return ClockHands;
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


Time UpdateTime (Time T)
{
	T.Second += 1;
	T.Minute += (T.Second / 60);
	T.Hour += (T.Minute / 60);
	
	T.Second %= 60;
	T.Minute %= 60;
	T.Hour %= 12;
	
	return T;
}


void LiveClock (Point Center, Time T, Hand ClockHands)
{
	Center.Y -= 75;
	
	while(!kbhit())
	{
		EraseHands(Center, T);
		T = UpdateTime (T);
		DrawHands(Center, T);
		delay(1000);
	}
}


#endif

