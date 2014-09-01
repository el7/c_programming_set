#include <stdio.h>
#include <stdlib.h>

int start(){
	
	int nums = 0;

	printf("How many numbers do you want in the set?\n> ");
	scanf("%d", &nums);

	int min = 100;
	int array[nums];
	int temp_val = 0;
	int temp_iter = 0;

	printf("\nUnsorted:\n");
	for (int i = 0; i < nums; i++){
		array[i] = rand()%100;
		printf("%d ", array[i]);
	}

	printf("\n\nSorted:\n");
	for (int i = 0; i < nums; i++){
		temp_val = array[i];
		min = 100;

		for (int o = i; o < nums; o++){
			if (array[o] < min){
				min = array[o];
				temp_iter = o;
			}
		}
		array[i] = min;
		array[temp_iter] = temp_val;
		printf("%d ", array[i]);			
	}

	return 0;
}


int main(){
	printf("\n\n");
	start();
	printf("\n\n");
	return 0;
}

