#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int start(){
	
	int input = 0;
	int temp = 0;
	int sum = 0;

	printf("(Armstrong property: a number is broken into its\n");
	printf("individual digits, then those digits are cubed, then summed.\n");
	printf("If the sum equals the original number, it's an armstrong number.\n\n");
	printf("Enter a number to check for the armstrong property:\n> ");
	scanf("%d", &input);

	temp = input;
	while(temp > 0){
		sum += pow(temp %10, 3);
		temp /= 10;
	}

	printf("Sum: %d\nInput: %d\n", sum, input);
	if (sum == input)
		printf("Yes, %d is an armstrong number.\n", input);
	
	else
		printf("No, %d is not an armstrong number.\n", input);

	return 0;
}

int mod(){

}

int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

