#include <stdio.h>
#include <stdlib.h>

int largest(){
	
	int n = 0, largest = 0;

	printf("Enter the number of numbers for the array (0 to exit):\n> ");
	scanf("%d", &n);
	if (n == 0) return 0;

	int array[n];

	printf("\nSet:\n");
	for (int i = 0; i < n; i++){
		array[i] = rand()%100;
		if (array[i] > largest)
			largest = array[i];
		printf("%d ", array[i]);
	}
	
	printf("\n\nLargest: %d", largest);
	printf("\n\n");
	return 1;
}

void desc(){
	printf("-----------------------------------------------------------------\n");
	printf("This program will ask the user for a number, then generate that\n");
	printf("many random numbers. The program will then pick the largest number\n");
	printf("from that set.\n");
	printf("-----------------------------------------------------------------\n");
	printf("\n");
}

int start(){
	int cont = 1;
	do{
		cont = largest();
	}while(cont != 0);
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

