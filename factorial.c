#include <stdio.h>

int fact(){
	
	int numb = 0;
	int final = 1;
	printf("Enter the number you'd like to evaluate the factorial of (0 to exit):\n> ");
	scanf("%d", &numb);
	if (numb == 0) return 0;

	for (int i = numb; i > 0; i--)
		final *= i;

	printf("Evaluation: %d\n\n", final);

	return 1;
}

int start(){
	int cont = 1;
	do{
		cont = fact();
	}while(cont != 0);
}


void desc(){
	printf("----------------------------------------------------------------\n");
	printf("The factorial of a non-negative number n, denoted by n!, is the\n");
	printf("product of all positive integers less than or equal to n.\n\n");
	printf("Example: 3! = 3 * 2 * 1 = 6\n");
	printf("----------------------------------------------------------------\n");
	printf("\n");
}


int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");

	return 0;
}

