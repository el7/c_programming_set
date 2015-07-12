#include <stdio.h>
#include <stdlib.h>

int sum_func(){

	int sum = 0;
	int num = 0;
	int temp = 0;

	printf("Enter a number to break apart, and then add together (0 to exit)\n> ");
	scanf("%d", &num);
	if (num == 0) return 0;

	do{
		temp = num % 10;
		sum += temp;
		if (num != 0);	
		num /= 10;
	}while(num > 1);
	sum += num;

	printf("sum: %d\n\n", sum);


	return 1;
}

void start(){
	int cont = 1;
	do{
		cont = sum_func();
	}while(cont != 0);
}

void desc(){
	printf("--------------------------------------------------------------\n");
	printf("This program will take a number and sum the digits of that number.\n");
	printf("\nExample: 12345 ----> 1 + 2 + 3 + 4 + 5 = 15\n");
	printf("--------------------------------------------------------------\n");
	printf("\n");
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

