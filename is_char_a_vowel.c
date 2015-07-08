#include <stdio.h>
#include <stdlib.h>

int start(){
	
	char i = NULL;
	printf("Enter a character to see if it's a vowel.\n");
	printf("(enter 1 to exit. I'll give you a hint, it's not a vowel.)\n");

	while(i != '1'){
		printf("> ");
		scanf("%c", &i);
		while ( getchar() != '\n' );
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
			printf("Yes, %c is a vowel.", i);
		else if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
			printf("Yes, %c is a vowel.", i);
		else if (i == 'y' || i == 'Y')
			printf("%c is sometimes a vowel.", i);
		else
			printf("Sorry Jack, %c is not a vowel.", i);
		printf("\n");
	}
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");

	return 0;
}

