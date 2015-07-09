#include <stdio.h>
#include <stdlib.h>

int leap(){

	int year = 0;
	printf("Enter a year to check if it's a leap year (0 to exit):\n> ");
	scanf("%d", &year);
	if (year == 0) return 0;

	if (year %4 != 0)
		printf("\nThis is a common year.\n");
	else if (year %100 != 0)
		printf("\nThis is a leap year.\n");
	else if (year %400 != 0)
		printf("\nThis is a common year.\n");
	else
		printf("\nThis is a leap year.\n");

	return 1;
}

int start(){
	int cont = 1;
	do{
		cont = leap();
	}while(cont != 0);
}

void desc(){
	printf("----------------------------------------------------------------\n");
	printf("A leap year is a year in which there is an additional day, exitsing\n");
	printf("in order to keep the calendar year synchronized with the astronomical\n");
	printf("year. Example: 2016 is a leap year.\n");
	printf("----------------------------------------------------------------\n");
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

