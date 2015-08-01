#include <stdio.h>


int even_odd(){
	int num = 0;

	// user input
	printf("Enter a number to examine (0 to exit):\n> ");
	scanf("%d", &num);
	if (num == 0) return 0;

	// evaluate
	if (num % 2 != 0) printf("Number is odd\n");
	else printf("Number is even\n");
	printf("\n");

	return 1;
}

void start(){
	int cont = 1;
	do{
		cont = even_odd();
	}while(cont != 0);
}

void desc(){
	printf("----------------------------------------------------------------\n");
	printf("This program will determine if user input is ever or odd.\n");
	printf("\nExample: 12345 ---> odd\n");
	printf("----------------------------------------------------------------\n\n");
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}
