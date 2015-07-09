#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void desc(){
	printf("----------------------------------------------------\n");
	printf("(Armstrong property: a number is broken into its\n");
	printf("individual digits, then those digits are cubed, then summed.\n");
	printf("If the sum equals the original number, it's an armstrong number.\n");
	printf("\nexample: 153 = (1^3) + (5^3) + (3^3)\n");
	printf("----------------------------------------------------\n");
	printf("\n");
}


int arm(){
	
	int input = 0;
	int temp = 0;
	int sum = 0;

	printf("Enter a number to check for the armstrong property (0 exits):\n> ");
	scanf("%d", &input);
	if (input == 0) return 0;
	temp = input;

	// raise each digit to 3rd power, then sum
	while(temp > 0){
		sum += pow(temp %10, 3);
		temp /= 10;
	}

	printf("\nInput: %d\nSum: %d\n\n", input, sum);
	if (sum == input) printf("Yes, %d is an armstrong number.\n\n", input);
	else printf("No, %d is not an armstrong number.\n\n", input);

	return 1;
}

int start(){
	// recylces until user stops
	int cont = 1;
	do{
		cont = arm();
	} while (cont != 0);
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

