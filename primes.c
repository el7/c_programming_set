#include <stdio.h>
#include <stdlib.h>


int start(int val){

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


void desc(){
	printf("\n\n");
	printf("A prime number is a natural number greater than 1 \n");
	printf("that has no positive divisors other than 1 and itself. ");
	printf("\n\n");
}

int main(int argc, char **argv){
	desc();
	int val = 0;
	if (argc < 2){
		printf("Enter an integer to check for prime value:\n> ");
		scanf("%d", &val);
		start(val);
	} else {
		// convert argv to val
		start(val);
	}
	printf("\n\n");

	return 0;
	
}

