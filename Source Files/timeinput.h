#ifndef TIMEINPUT_H
#define TIMEINPUT_H


#include <stdio.h>


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
