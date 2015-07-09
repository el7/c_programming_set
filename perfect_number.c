#include <stdio.h>
#include <stdlib.h>

int perfect(){
	
	int num = 0;
	int sum = 0;
	printf("Enter a positive integer to check for perfection (0 to exit):\n> ");
	scanf("%d", &num);
	if (num == 0) return 0;
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

	printf("\n\n");
	return 1;
}

void desc(){
	printf("-----------------------------------------------------------------\n");	
	printf("A perfect number is a positive integer that is equal to the sum\n");
	printf("of its proper positive divisors (excluding the number itsself).\n");
	printf("example: 6 is a perfect number, because 1+2+3 = 6.\n");
	printf("-----------------------------------------------------------------\n");	
	printf("\n");
}

int start(){
	int cont = 1;
	do{
		cont = perfect();
	}while(cont != 0);
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

