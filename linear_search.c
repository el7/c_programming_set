#include <stdio.h>
#include <stdlib.h>



int search(){
	
	int num = 0, search_val = 0;
	printf("Enter the number of (random) numbers to fill the array (0 to exit)\n> ");
	scanf("%d", &num);
	if (num == 0) return 0;
	
	int array[num];

	// fill array with rand() vals 1-99
	printf("numbers: \n");
	for(int i = 0; i < num; i++){
		array[i] = (rand()%99)+1;
		printf("%d ", array[i]);
	}
	printf("\n\n");

	while(1){
		printf("Enter a number to search for in the array (0 will go back)\n> ");
		scanf("%d", &search_val);
		if (search_val == 0) return 1;

		// loop array, search for search_val, print positions when shows up
		for (int i = 0; i < num; i++){
			if (array[i] == search_val)
				printf("Your number (%d) was found in position array[%d]\n", search_val, i);
		}
	}

	return 1;
}


void start(){
	int cont = 1;
	do{
		cont = search();
	}while(cont != 0);
}


void desc(){
	printf("----------------------------------------------------------------\n");
	printf("Linear search is slow but easy to implement\n");
	printf("----------------------------------------------------------------\n");
}


int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

