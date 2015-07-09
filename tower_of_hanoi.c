#include <stdio.h>
#include <stdlib.h>

int hanoi(int num_rings, char peg_1, char peg_2, char peg_3){

	if (num_rings == 1)
		printf("\nmove disk %d from %c to %c", num_rings, peg_1, peg_3);
	else {
		hanoi(num_rings-1,peg_1,peg_3,peg_2);                                     
		printf("\nmove disk %d from %c to %c", num_rings, peg_1, peg_3);          
		hanoi(num_rings-1,peg_2, peg_1, peg_3);                                   
		return 0;
	}

}

int replay(){
	
	int num_rings = 0;
	do{
		printf("\n\nSelect the number of rings to sort (n>2, 0 will exit):\n> ");
		scanf("%d", &num_rings);
		if (num_rings == 0) return 0; 
	}while(num_rings < 3);
	hanoi(num_rings, 'A', 'B', 'C');
	return 1;
}

int start(){
	int cont = 1;
	do{
		cont = replay();
	}while(cont != 0);
	return 0;
}


void desc(){
	printf("---------------------------------------------------------------\n");
	printf("The Tower of Hanoi is a mathematical puzzle. It consists of \n");
	printf("three pegs, and a number of disks of different sizes which can \n");
	printf("be moved onto any peg. The puzzle starts with the disks in a neat\n");
	printf("stack in ascending order of size on one peg, the smallest at the top,\n");
	printf("thus making a conical shape. The objective of the puzzle is to move\n");
	printf("the entire stack to another peg, obeying the following simple rules:\n");
	printf("\n1. Only one disk can be moved at a time.\n");
	printf("2. A disk can only be moved if it is the uppermost disk on a stack.\n");
	printf("3. No disk may be placed on top of a smaller disk.\n\n");
	printf("The minimum number of moves required to solve \n");
	printf("a Tower of Hanoi puzzle is 2^n - 1, where n is the number of disks.\n");
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

