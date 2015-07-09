#include <stdio.h>
#include <stdlib.h>

void desc(){
	printf("------------------------------------------------------------------\n");
	printf("Selection Sort: an in-place comparison sort that has O(n^2)\n");
	printf("time complexity. The algorithm divides the input into two parts:\n");
	printf("a subset of items already sorted, and a subset of items remaining\n");
	printf("to be sorted. The algorithm searches the remaining list for the\n");
	printf("next smallest (or largest) item, then exchanges it with the leftmost\n");
	printf("unsorted item. This continues until the set is sorted.\n");
	printf("------------------------------------------------------------------\n");
	printf("\n");
}

int sort(){
	
	int temp_iter = 0;
	int temp_val = 0;
	int min = 100;
	int nums = 0;

	printf("How many random numbers (0<val<100) do you want in the set? (0 will exit)\n> ");
	scanf("%d", &nums);
	if (nums == 0) return 0;

	int array[nums];

	printf("\nUnsorted:\n");
	for (int i = 0; i < nums; i++){
		array[i] = (rand()%99)+1;
		printf("%d ", array[i]);
	}

	printf("\n\nSorted:\n");
	// puts leftmost unsorted into var
	for (int i = 0; i < nums; i++){
		temp_val = array[i];
		min = 100;

		// finds smallest number, puts into var
		for (int o = i; o < nums; o++){
			if (array[o] < min){
				min = array[o];
				temp_iter = o;
			}
		}

		// exchanges smallest and leftmost
		array[i] = min;
		array[temp_iter] = temp_val;
		printf("%d ", array[i]);			
	}
	
	printf("\n\n");

	return 1;
}

int start(){
	int cont = 1;
	do{
		cont = sort();
	}while(cont != 0);
	return 0;
}


int main(){
	printf("\n\n");
	desc();
	start();
	printf("\n\n");
	return 0;
}

