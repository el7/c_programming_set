#include <stdio.h>
#include <stdlib.h>

int start(){
	
	int n = 0, largest = 0;

	printf("Enter the number of digits for the array.\n> ");
	scanf("%d", &n);

	int array[n];

	printf("\nSet:\n");
	for (int i = 0; i < n; i++){
		array[i] = rand()%100;
		if (array[i] > largest)
			largest = array[i];
		printf("%d ", array[i]);
	}
	
	printf("\n\nLargest: %d", largest);

	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

