#ifndef TIMEIO_H
#define TIMEIO_H


#include <stdio.h>
#include <ctype.h>


Choice Start ()
{
	Time T;
	Choice Ch;
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
	
		Ch = Y;
	}
	else
	{
		fflush(stdin);
		Ch = N;
	}
	
	return Ch;
}


void GetFormate (int* Formate)
{
	printf("\tTime Formates:\n");
	printf("\n");
	
	printf("\t1. 24 Hour Formate\n");
	printf("\t2. 12 Hour Formate\n");
	
	printf("\n\tSelect time formate:");
	
	printf("\n\t--> ");
	scanf("%d", Formate);
}


void GetPeriod (int* Period, int Formate, Time T)
{
	printf("\t1. AM\t2. PM\n");
	
	printf("\n\t--> ");
	scanf("%d", Period);			
	
	while(1)
	{
	    if(((*Period) == 1) || ((*Period) == 2))
	    {
	        break;
	    }
	
	    system("cls");
	    IfInvalidPeriod (T, Formate, Period);
	}
		
	system("cls");
	IfValidPeriod (T, Formate, *Period);
}


void GetTime (Time* T, int Formate, int Period)
{
	printf("\tInput Time\n");
	printf("\n");
	
	printf("\tHH --> ");
	scanf("%d", &(T->Hour));
	
	printf("\tMM --> ");
	scanf("%d", &(T->Minute));
	
	printf("\tSS --> ");
	scanf("%d", &(T->Second));
	
	printf("\n");
	
	if(Formate == 2)
	{
		GetPeriod (&Period, Formate, *T);
	}
	
	printf("\n");
	printf("\tTime Entered Successfully !\n\t");
	
	system("pause");
}


#endif
