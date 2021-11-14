#ifndef TIMEIO_H
#define TIMEIO_H

#include "clock.h"
#include "structure.h"


Time Initiate ()
{
	time_t t;
    struct tm* CurrentTime;

    t = time(NULL);
    CurrentTime = localtime(&t);
    
    Time T;
    
    T.Hour = CurrentTime->tm_hour;
    T.Minute = CurrentTime->tm_min;
    T.Second = CurrentTime->tm_sec;
  
    return T;
}


void IfInvalidFormate (int *Formate)
{
	printf("\n\t");
	printf("!..... Analogue Clock..... !");
	
	printf("\n\n");
	
	printf("\tTime Formates:\n");
	printf("\n");
	
	printf("\t1. 24 Hour Formate\n");
	printf("\t2. 12 Hour Formate\n");
	
	printf("\n\tInvalid Selection ! Select valid time formate:");
	
	printf("\n\t--> ");
	scanf("%d", Formate);
	fflush(stdin);
	
	printf("\n");
}


void IfInvalidPeriod (Time T, int Formate, int *Period)
{
	printf("\n\t");
	printf("!..... Analogue Clock..... !");
	
	printf("\n\n");
	
	printf("\tTime Formates:\n");
	printf("\n");
	
	printf("\t1. 24 Hour Formate\n");
	printf("\t2. 12 Hour Formate\n");
	
	printf("\n\t--> %d\n", Formate);
	
	printf("\n");
	
	printf("\tInput Time\n");
	printf("\n");
	
	printf("\tHH --> %02d\n", T.Hour);
	printf("\tMM --> %02d\n", T.Minute);
	printf("\tSS --> %02d\n", T.Second);
	
	printf("\n");
	
	printf("\t1. AM\t2. PM\n");
	
	printf("\n\tInvalid Selection ! Select Valid Option:");
	printf("\n");

	printf("\t--> ");
	scanf("%d", Period);
	fflush(stdin);
	
	printf("\n");
}


void IfValidFormate (int Formate)
{
	printf("\n\t");
	printf("!..... Analogue Clock..... !");
	
	printf("\n\n");
	
	printf("\tTime Formates:\n");
	printf("\n");
	
	printf("\t1. 24 Hour Formate\n");
	printf("\t2. 12 Hour Formate\n");
	
	printf("\n\t--> %d\n", Formate);
	printf("\n");
}


void IfValidPeriod (Time T, int Formate, int Period)
{
	printf("\n\t");
	printf("!..... Analogue Clock..... !");
	
	printf("\n\n");
	
	printf("\tTime Formates:\n");
	printf("\n");
	
	printf("\t1. 24 Hour Formate\n");
	printf("\t2. 12 Hour Formate\n");
	
	printf("\n\t--> %d\n", Formate);
	printf("\n");
	
	printf("\tInput Time\n");
	printf("\n");
	
	printf("\tHH --> %02d\n", T.Hour);
	printf("\tMM --> %02d\n", T.Minute);
	printf("\tSS --> %02d\n", T.Second);
	
	printf("\n");
	
	if(Formate == 2)
	{
		printf("\t1. AM\t2. PM\n");
		printf("\n");

		printf("\t--> %d\n", Period);
		printf("\n");
	}
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
	
	fflush(stdin);
}


void GetPeriod (int* Period, int Formate, Time T)
{
	if(Formate != 2)
	{
		system("cls");
		IfValidPeriod (T, Formate, *Period);
	
		return;
	}
	
	printf("\t1. AM\t2. PM\n");
	
	printf("\n\t--> ");
	scanf("%d", Period);
	fflush(stdin);			
	
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


void GetTime (Time* T, int Formate, int *Period)
{
	printf("\tInput Time\n");
	printf("\n");
	
	printf("\tHH --> ");
	if((scanf("%d", &(T->Hour)) != 1))
	{
        *T = Initiate();
	}
	
	fflush(stdin);
	
	printf("\tMM --> ");
	if((scanf("%d", &(T->Minute)) != 1))
	{
        *T = Initiate();
	}
	
	fflush(stdin);
	
	printf("\tSS --> ");
	if((scanf("%d", &(T->Second)) != 1))
	{
        *T = Initiate();
	}
	
	fflush(stdin);
	
	printf("\n");
	
	if(Formate == 1)
	{		
		T->Hour %= 24;
		T->Minute %= 60;
		T->Second %= 60;
		
		GetPeriod (Period, Formate, *T);
	}
	else if(Formate == 2)
	{
		T->Hour %= 12;
		T->Minute %= 60;
		T->Second %= 60;
		
		if (!T->Hour)
		{
			T->Hour = 12;
		}
		
		GetPeriod (Period, Formate, *T);
	} 
	
	printf("\n");
	printf("\tTime Entered Successfully !\n\t");
}


#endif
