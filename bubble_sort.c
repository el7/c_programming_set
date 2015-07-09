#include <stdio.h>
#include <stdlib.h>

int bub(){

	int count = 0;
	int temp = 0;

	printf("Enter the number of random values you want to sort (0 to exit):\n> ");
	scanf("%d", &count);
	if (count == 0) return 0;

	int numbers[count];

	printf("\nUnsorted:\n");  
	for (int i = 0; i < count; i++){ 
		numbers[i] = (rand()%99)+1;  
		printf("%d ", numbers[i]); 
	} 

	for (int a = 0; a < (count-1); a++){
		for (int b = 0; b < (count-a-1); b++){
			if (numbers[b] > numbers[b+1]){
				temp = numbers[b];
				numbers[b] = numbers[b+1];
				numbers[b+1] = temp;
			}
		}
	}

	printf("\n\nSorted:\n");
	for (int c = 0; c < count; c++){
		printf("%d ", numbers[c]);
	}
	printf("\n\n");
	return 1;
}

int start(){
	int cont = 1;
	do{
		cont = bub();
	}while(cont != 0);
	return 0;
}

void desc(){
	printf("---------------------------------------------------------------\n");
	printf("Bubble Sort is a sorting algorithm that repeatedly steps through\n");
	printf("the list to be sorted, compares each pair of adjacent items and \n");
	printf("swaps them if they are in the wrong order. The pass through the\n");
	printf("list is repeated until no swaps are needed, which indicates that\n");
	printf("the list is sorted.\n");
	printf("---------------------------------------------------------------\n");
	printf("\n");
}

int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

