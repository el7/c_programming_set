#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int start(int fib){

	int fn0 = 0, fn1 = 1, fn2 = fn0+fn1;
	int a = 1;

	// first 3 numbers, starting with F(1)
	if (fib == 0){
		printf("Sorry, F(0) is nothing. Possibly your argument was wrong.\n");
	} else if (fib >= 1){
		printf("%d: %d\t\t\t\t\t\n", a, fn0);
		a++;
	} if (fib >= 2){
		printf("%d: %d\t\t\n", a, fn1);
		a++;
	} if (fib >= 3){
		printf("%d: %d\t\t\n", a, fn2);
		a++;
	} if (fib > 3){
		
		for (; a <= fib; a++){
			fn0 = fn1;
			fn1 = fn2;
			fn2 = fn0+fn1;
			printf("%d: %d\t\t\n", a, fn2);
		}
	}
	return 0;
}


void desc(){

	printf("\n\n");
	printf("----------------------------------------------------------\n");
	printf("Fibonacci Numbers: starting with the number zero as F(1), \n");
	printf("one as F(2) and one as F(3): F(n) = F(n-1) + F(n-2)\n");
	printf("\nexample: F(4) = F(3) + F(2) = 2\n");
	printf("----------------------------------------------------------\n");
}

int user_input(){

	int fib = 0;
	do{
		printf("\n");
		printf("Select an n-th Fibonacci number (n > 0, 0 will exit):\n> ");
		scanf("\n%d", &fib);
		getchar();
		printf("\n");
	} while (fib < 0);
	return fib;
}



int main(int argc, char *argv[]){
	int fib = 0;
	desc();
	if (argc >= 2){
		if (argc > 2)
			printf("Too many arguments. Only argv[1] will be used.\n");
		fib = atoi(argv[1]);
	}

	do{
		if (argc < 2){
			fib = user_input();
		}
	
		argc = 1;
		if (fib == 0){
			return 0;
			printf("\n\n");
		}
		
		start(fib);
	} while (fib != 0);

	printf("\n\n");
	return 0;
}
