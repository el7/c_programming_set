#include <stdio.h>
#include <stdlib.h>

int quicksort(){
	
	int nums = 0;
	printf("Enter the amount of random numbers to sort (0 to exit):\n> ");
	scanf("%d", &nums);
	if (nums == 0) return 0;

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


	return 1;
}

void start(){
	int cont = 1;
	do{
		cont = quicksort();
	}while (cont != 0);
}


void desc(){
	printf("----------------------------------------------------------------\n");
	printf("Quicksort is an efficient sorting algorithm, serving as a \n");
	printf("systematic method for placing the elements of an array in order.\n");
	printf("It is still a commonly used algorithm for sorting. When \n");
	printf("implemented well, it can be about two or three times faster than\n");
	printf("its main competitors, merge sort and heapsort. Quicksort is a\n");
	printf("comparison sort, meaning that it can sort items of any type for\n");
	printf("which a 'less-than' relation is defined. In efficient \n");
	printf("implementations it is not a stable sort, meaning that the relative\n");
	printf("order of equal sort items is not preserved. Mathematical analysis\n");
	printf("of quicksort shows that, on average, the algorithm takes \n");
	printf("O(n log n) comparisons to sort n items.\n");
	printf("----------------------------------------------------------------\n");
	printf("\n");
}


int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

