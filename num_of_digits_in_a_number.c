#include <stdio.h>
#include <stdlib.h>

int start(){

	int num = 0;
	int digits = 0;
	printf("Enter a number to check how many digits are in it.\n> ");
	scanf("%d", &num);

	while (num > 0){
		num /= 10;
		digits++;
	}	

	printf("There are %d digits in that number.", digits);

	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

