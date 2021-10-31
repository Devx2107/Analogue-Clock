#ifndef VALIDATION_H
#define VALIDATION_H


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
	
	printf("\t1. AM\t2. PM\n");
	printf("\n");

	printf("\t--> %d\n", Period);
	printf("\n");
}


#endif
