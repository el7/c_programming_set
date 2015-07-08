#include <stdio.h>
#include <stdlib.h>

int start(int fib){

	int fn0 = 0, fn1 = 1, fn2 = fn0+fn1;
	int a = 1;

	// first 3 numbers, starting with F(1)
	if (fib >= 1){
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
	printf("Fibonacci Numbers: starting with the number zero (0) as F(1), \n");
	printf("F(n) = F(n-1) + F(n-2)");
	printf("\n\n");
}

int main(int argc, char **argv){
	
	desc();
	int fib = 0;
	if (argc < 2){
		do{
			printf("Select an n-th Fibonacci number (n>0) to run F(n):\n> ");
			scanf("%d", &fib);
			printf("\n");
		} while (fib <= 0);
	}
	else{
		
		// convert argv to integer
	}

	start(fib);
	printf("\n\n");
	return 0;
}
