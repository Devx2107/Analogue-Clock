#include "structure.h"
#include "enum.h"
#include "headers.h"
#include "functions.h"


int main()
{
	int gm = DETECT, gd;
	
	initgraph(&gm, &gd, (char *)"");
	cleardevice();
	
	system("pause");
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
		    
			return 0;
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
	
	return 0;
}
