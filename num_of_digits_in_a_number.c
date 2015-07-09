#include <stdio.h>
#include <stdlib.h>

int digits(){

	int num = 0;
	int digits = 0;
	printf("Enter a number to check how many digits are in it (0 will exit):\n> ");
	scanf("%d", &num);
	if (num == 0) return 0;

	while (num > 0){
		num /= 10;
		digits++;
	}	

	printf("There are %d digits in that number.\n\n", digits);

	return 1;
}

void start(){
	int cont = 1;
	do{
		cont = digits();
	}while(cont != 0);
}

void desc(){
	printf("-----------------------------------------------------------------\n");
	printf("Each number is comprised of digits. Counting them by hand is easy.\n");
	printf("Counting them with a computer program is (very slightly) less easy.\n");
	printf("-----------------------------------------------------------------\n");
	printf("\n");
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

