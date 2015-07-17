#include <stdio.h>


int io_example(char input1[], char input2[], char output[]){

	FILE *ifp1, *ifp2, *ofp;
	char *imode = "r"; // open for reading
	char *omode = "w"; // open for writing
	int num = 0;

	// open files
	//
	ifp1 = fopen(input1, imode);
	if (ifp1 == NULL){
		printf("Can't open file '%s': NULL\n", input1);
		return 0;
	}

	ifp2 = fopen(input2, imode);
	if (ifp2 == NULL){
		printf("Can't open file '%s': NULL\n", input2);
		return 0;
	}
		
	ofp = fopen(output, omode);
	if (ofp == NULL){
		printf("Can't open file '%s': NULL\n", output);
		return 0;
	}
	

	while (fscanf(ifp1, "%d", &num) == 2){
		fprintf(ofp, "%d ", num);
	}
	

	return 0;
}




void desc(){
	printf("---------------------------------------------------------------\n");
	printf("This program will take two files, and merge them into a third \n");
	printf("sorted numerically. It will accept three file names as command-line\n");
	printf("arguments, or will seek user input of filenames. The first two \n");
	printf("filenames are input files, and the third is the output file. \n");
	printf("---------------------------------------------------------------\n");
}

int user_input(){

}



int main(int argc, char *argv[]){
	desc();

	int cont = 1;
	int max_args = 4;
	char *input1, *input2, *output;
	
	// collect arguments if 3 or more are given
	if (argc >= 2){
		if (argc > 4)
			printf("Too many arguments. argv[1], argv[2] and argv[3] will be used.\n");
		input1 = argv[1];
		input2 = argv[2];
		output = argv[3];
	}

	// loop the program
	do{
		// [TODO] collect user input if less than 3 arguments are given
		if (argc < 4){
			printf("Not enough arguments. Exiting.\n");
			return 0;
			
		//	printf("Please give an input filename:\n> ");
		//	getline(&input1, 60, stdin);
		//	input1 = user_input();	
		//	printf("Please give an input filename:\n> ");
		//	getline(input2, 60, stdin);
		//	input2 = user_input();	
		//	printf("Please give an output filename:\n> ");
		//	fgets(&output, 60, stdin);
		//	output = user_input();	
		}
	
		argc = 1;
		if (cont == 0){
			return 0;
			printf("\n\n");
		}
		
		cont = io_example(input1, input2, output);
	} while (cont != 0);

	printf("\n\n");
	return 0;
}
