#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prod(int matrix_a_x, int matrix_a_y, int matrix_b_x, int matrix_b_y){
	
	int matrix_a[matrix_a_x][matrix_a_y];
	int matrix_b[matrix_b_x][matrix_b_y];
	int matrix_c[matrix_a_x][matrix_b_y];

	printf("Filling with random numbers ...\n");
	printf("Matrix A:\n\n");
	for (int a = 0; a < matrix_a_x; a++){
		for (int b = 0; b < matrix_a_y; b++){
			matrix_a[a][b] = rand()%100;
			printf("%d ", matrix_a[a][b]);
		}
		printf("\n");
	}

	printf("\nMatrix B:\n\n");
	for (int a = 0; a < matrix_b_x; a++){
		for (int b = 0; b < matrix_b_y; b++){
			matrix_b[a][b] = rand()%100;
			printf("%d ", matrix_a[a][b]);
		}
		printf("\n");
	}

	printf("Multiplying ...\n\n");
	printf("\nMatrix C:\n\n");
	for (int a = 0; a < matrix_b_x; a++){
		for (int b = 0; b < matrix_b_y; b++){
			matrix_c[a][b] = 1;
			printf("%d ", matrix_c[a][b]);
		}
		printf("\n");
	}


	return 0;
}


int scalar(int matrix_a_x, int matrix_a_y, int matrix_b_x, int matrix_b_y){

	

	return 0;
}


int start(){

	int choice = 0;
	int matrix_a_x = 0, matrix_b_x = 0;
	int matrix_a_y = 0, matrix_b_y = 0;
//	printf("Are you looking for \n(1)scalar multiplication or \n(2)matrix product?\n> ");
//	scanf("%d", &choice);

	printf("We will work with only 2 matricies. How big will each matrix be?\n");
	printf("Matrix A (x):\n> ");
	scanf("%d", &matrix_a_x);
	printf("Matrix A (y):\n> ");
	scanf("%d", &matrix_a_y);
	printf("Matrix B (x):\n> ");
	scanf("%d", &matrix_b_x);
	printf("Matrix B (y):\n> ");
	scanf("%d", &matrix_b_y);
	
	if (choice == 1)
		scalar(matrix_a_x, matrix_a_y, matrix_b_x, matrix_b_y);
	else if (choice == 2)
		prod(matrix_a_x, matrix_a_y, matrix_b_x, matrix_b_y);

	return 0;
}


int main(){
	printf("\n\n");
	srand(time(NULL));
	start();

	printf("\n\n");
	return 0;
}

