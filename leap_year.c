#include <stdio.h>
#include <stdlib.h>

int start(){

	int year = 0;

	printf("Enter a year to check if it's a leap year.\n> ");
	scanf("%d", &year);

	if (year %4 != 0)
		printf("\nThis is a common year.\n");
	else if (year %100 != 0)
		printf("\nThis is a leap year.\n");
	else if (year %400 != 0)
		printf("\nThis is a common year.\n");
	else
		printf("\nThis is a leap year.\n");


	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

