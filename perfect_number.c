#include <stdio.h>
#include <stdlib.h>

int start(){
	
	int num = 0;
	int sum = 0;

	printf("A perfect number is a positive integer that is equal to the sum\n");
	printf("of its proper positive divisors (excluding the number itsself).\n");
	printf("e.g. 6 is a perfect number, because 1+2+3 = 6.\n\n");
	printf("Enter a positive integer to check for perfection:\n> ");
	scanf("%d", &num);

	printf("\n0 ");
	for (int i = 1; i < num; i++){
		if (num % i == 0){
			sum += i;
			printf("+ %d ", i);
		}
	}

	printf("= %d\n", sum);

	if (sum == num)
		printf("\nThis number is indeed quite perfect.");
	else 
		printf("No, this number is quite ordinary.");

	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

