#ifndef STRUCTURE_H
#define STRUCTURE_H


typedef struct Point
{
	float X;
	float Y;
}Point;


typedef struct Time
{
	int Second;
	int Minute;
	int Hour;
}Time;


typedef struct Hand
{
	Point HourHand;
	Point MinuteHand;
	Point SecondHand;
}Hand;


typedef struct Date
{
	int Day;
	int Month;
	int Year;
}Date;


#endif

