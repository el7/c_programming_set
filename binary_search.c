#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int start(){

	int size = 0;
	printf("How big of an array would you like to search?\n> ");
	scanf("%d", &size);
	int array[size];
	int temp = 0;

	printf("\nFilling with random values ...\n");
	// fill
	for (int a = 0; a < size; a++){
		array[a] = rand()%100;
	}


	// sort
    for (int a = 0; a < size-1; a++){                                            
        for (int b = a+1; b < size; b++){
            if (array[b-1] > array[b]){                                       
                temp = array[b-1];                                              
                array[b-1] = array[b];                                        
                array[b] = temp;                                                
			}                                                                     
        }                                                                         
		printf("%d ", array[a]);
    } 
	printf("%d ", array[size-1]);

	int search = 0;
	temp = 0;
	// binary search
	while (search != -1){
		printf("\n\nSelect a number to search for\n(-1 will exit):\n> ");
		scanf("%d", &search);
		

		while (temp != search){
			temp = search/2;
			if (temp == search)
				printf("The number found was %d\n", temp);
			else if (temp < search)
				temp = (size + temp)/2;
			else if (temp > search)
				temp = (size - temp)/2;
		}
	}

	return 0;
}


int main(){
	printf("\n\n");
	srand(time(NULL));
	start();
	printf("\n\n");
	return 0;
}




