#include <stdio.h>
#include <stdlib.h>


int primes(int val){


	int p = 1;
	for (int a = 2; a < val; a++){
		if (val % a == 0)
			p = 0;
	}
	if (p == 0)
		printf("%d is NOT prime\n", val);
	else
		printf("%d IS prime\n", val);

	return 0;
}

int user_input(){

	int fib = 0;
	do{
		printf("\n");
		printf("Enter a number to check for prime-ness (n > 0, 0 will exit):\n> ");
		scanf("\n%d", &fib);
		getchar();
		printf("\n");
	} while (fib < 0);
	return fib;
}


void desc(){
	printf("-----------------------------------------------------------------\n");
	printf("A prime number is a natural number greater than 1 that has no \n");
	printf("positive divisors other than 1 and itself. \n\n");
	printf("Example: 3 is prime because its only divisors are 1 and 3 (itself).\n");
	printf("-----------------------------------------------------------------\n\n");
}

int main(int argc, char **argv){
	
	int fib = 0;
	printf("\n\n");
	desc();

	if (argc >= 2){
		if (argc > 2)
			printf("Too many arguments. Only argv[1] will be used.\n");
		fib = atoi(argv[1]);
	}
	do{
		if (argc < 2)
			fib = user_input();
		
		argc = 1;
		if (fib == 0){
			return 0;
			printf("\n\n");
		}
		
		primes(fib);
	} while (fib != 0);

	printf("\n\n");
	return 0;
}

