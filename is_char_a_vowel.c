#include <stdio.h>
#include <stdlib.h>

int vowel(){
	
	char i = NULL;
	printf("Enter a character to see if it's a vowel.\n");
	printf("(enter 0 to exit. I'll give you a hint, it's not a vowel.)\n");

	while(i != '0'){
		printf("> ");
		scanf("%c", &i);
		if (i == '0') return 0;
		while ( getchar() != '\n' );
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
			printf("Yes, %c is a vowel.", i);
		else if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
			printf("Yes, %c is a vowel.", i);
		else if (i == 'y' || i == 'Y' || i == 'w' || i == 'W')
			printf("%c is sometimes a vowel.", i);
		else
			printf("Sorry Jack, %c is not a vowel.", i);
		printf("\n");
	}
}

void start(){
	vowel();
}

void desc(){
	printf("-----------------------------------------------------------------\n");
	printf("A vowel is a sound in the spoken language, pronounced with an open\n");
	printf("vocal tract so that there is no build-up of air pressure at any point\n");
	printf("above the glottis. This contrasts with consonants, which have a\n");
	printf("constriction or closure at some point along the vocal tract.\n\n");
	printf("example: 'ah!' vs 'sh!'\n");
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

