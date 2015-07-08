#include <stdio.h>
#include <stdlib.h>

int start(){
	
	int nums = 0;
	printf("Quicksort.\nHow many numbers to sort?\n> ");
	int array[nums];

	printf("Unsorted:\n");
	for (int i = 0; i < nums; i++){
		array[i] = rand()%100;
		printf("%d ", array[i]);
	}

	printf("\n\nSorted:\n");

	for (int i = 0; i < nums; i++){
		for (int j = nums-1; j >= 0; j--){

		}
	}


	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

