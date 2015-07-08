#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100 //size of char buffer


char* str_fixer(char *input){

	char *output = input;
	for (int a = 0, b = 0; a < strlen(input); a++, b++){
		if (input[a] != ' ')
			output[b] = input[a];
		else
			b--;
	}
	return output;
}

int palindrome(char *input){

	int size = ((int)strlen(input)) - 1;
	printf("size: %d\n", ((int)strlen(input)));

	for (int a = 0; a < size; a++){
		printf("a: %c b: %c \n", input[a], input[size-a-1]);
		if (input[a] != input[size-a-1])
			return 0;
	}

	return 1;
}


int start(){

	char str_a[SIZE];
	char *str_fix;
	int pal = 0;	

	printf("Enter a string to check for palindromity\n");
	printf("(this program erases whitespace before evaluating)\n> ");
	fgets(str_a, SIZE, stdin);
	int b = SIZE-1;

	// takes away spaces
	str_fix = str_fixer(str_a);

	printf("fixed: %s\n", str_fix);

	// to upper case
	for (int a = 0; a < SIZE; a++){
		str_fix[a] = toupper(str_fix[a]);		
	}
	
	pal = palindrome(str_fix);

	if (pal == 0)
		printf("No, it is not a palindrome.\n");
	else if (pal == 1)
		printf("Yes, it is not a palindrome.\n");


	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

