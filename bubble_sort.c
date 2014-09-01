#include <stdio.h>
#include <stdlib.h>

int start(){

	int count = 0;

	printf("How many numbers would you like to sort?\n> ");
	scanf("%d", &count);

	int numbers[count];
	printf("Enter those numbers now: \n");

	for (int a = 0; a < count; a++){
		printf("%d: ", a+1);
		scanf("%d", &numbers[a]);
	}
	
	printf("\nSorted:\n\n");
	int temp = 0;

	for (int a = 0; a < count-1; a++){
		for (int b = a+1; b < count; b++){

			if (numbers[b-1] > numbers[b]){
				temp = numbers[b-1];
				numbers[b-1] = numbers[b];
				numbers[b] = temp;
			}
		}
	}

	for (int c = 0; c < count; c++){
		printf("%d: %d\n", c+1, numbers[c]);
	}

	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

