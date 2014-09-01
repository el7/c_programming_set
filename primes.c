#include <stdio.h>
#include <stdlib.h>


int start(int val){

	int p = 1;
	for (int a = 2; a < val; a++){
		if (val % a == 0)
			p = 0;
	}
	if (p == 0)
		printf("Not prime\n");
	else
		printf("Prime\n");

	return 0;
}


int main(int argc, char **argv){
	printf("\n\n");

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

