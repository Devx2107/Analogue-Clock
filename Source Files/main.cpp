#include "structure.h"
#include "enum.h"
#include "headers.h"
#include "functions.h"


int main()
{
	printf("\n\t");
	printf("!..... Analogue Clock..... !");
	
	printf("\n\n");	
	
	int Formate, Period = 0;
	Time T;
	
	GetFormate (&Formate);
	printf("\n");
	
	while(1)
	{
		if(Formate == 1)
		{
			system("cls");
			
			IfValidFormate (Formate);
			GetTime(&T, Formate, Period);
			
			break;
		}
		
		if(Formate == 2)
		{
			system("cls");
			
			IfValidFormate (Formate);
			GetTime(&T, Formate, Period);
			
			break;
		}
		
		system("cls");
		IfInvalidFormate (&Formate);
	}
	
	int gm = DETECT, gd;
	
	initgraph(&gm, &gd, (char *)"");
	cleardevice();
	
	Point Center;
	
	Center.X = (getmaxx() / 2);
	Center.Y = (getmaxy() / 2);

	LiveClock(Center, T, DrawClock(Center, T));
	
	getch();
	closegraph();
	
	return 0;
}
