#include <stdio.h>
#include <stdlib.h>

int start(int top){

	int fn0 = 0, fn1 = 1, fn2 = fn0+fn1;
	int a = 0;


	// first 3 numbers starting with 0
	printf("%d: %d\t\t\t\t\t\n", a, fn0);
	a++;
	printf("%d: %d\t\t\n", a, fn1);
	a++;
	printf("%d: %d\t\t\n", a, fn2);
	a++;

	for (; fn2 <= top; a++){

		fn0 = fn1;
		fn1 = fn2;
		fn2 = fn0+fn1;
		printf("%d: %d\t\t\n", a, fn2);

	}

	return 0;
}


int main(int argc, char **argv){
	
	printf("\n\n");
	int top = 0;
	if (argc < 2){
		printf("Select a top value for the Fibonacci series:\n> ");
		scanf("%d", &top);
		printf("\n");
	}
	else{
		// convert argv to integer
	}

	start(top);
	printf("\n\n");
	return 0;
	}
