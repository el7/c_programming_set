#include <stdio.h>


int reverse(){
	int num = 0;
	int temp = 0;
	int new = 0;

	printf("Enter a number to reverse (0 to exit):\n> ");
	scanf("%d", &num);
	if (num == 0) return 0;


	do{
		temp = num % 10;
		num /= 10;
		new += temp;
		if (num != 0) 
			new *= 10;
	}while(num > 1);
	new += num;

	printf("reversed: %d\n\n", new);

	return 1;
}

void start(){
	int cont = 1;
	do{
		cont = reverse();
	}while(cont != 0);
}

void desc(){
	printf("----------------------------------------------------------------\n");
	printf("This program will accept a number, and the reverse it.\n");
	printf("\nExample: 12345 ---> 54321\n");
	printf("----------------------------------------------------------------\n\n");
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

