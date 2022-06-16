// includes
#include <stdio.h>
#include <string.h>


// variables

int decreaseTimes = 0; // variable that stores number of times the depth has decreased


// main code

int main() {

	printf("\n \n ---------------Problem 1------------------ \n \n");

	char str[10]; // variable that stores the string from input file
	int input_counter = 0; // counter of input lines for putting input to array
	int input_array[2000]; // array for input
	FILE* raw_data; // creating FILE variable
	raw_data = fopen("input.txt", "r"); // open file
	
	// if file couldn't be opened print error
	if (raw_data == NULL) {
		perror("File couldn't be opened"); // print error
		return(-1); // return from main() function
	}

	// while there is some lines to be read
	while (fgets(str, 10, raw_data)) {
		input_array[input_counter] = atoi(str); // store value converted to int in an array
		input_counter++; // increase array counter
	}
	fclose(raw_data); // close file to save memory
	
	// PART 1
	
	for (int i = 0; i < sizeof(input_array) / sizeof(int); i++) { // cycle through all input values
		if (input_array[i + 1] > input_array[i]) { // if next input is bigger add 1 to decrease counter
			decreaseTimes++;
		}
	}
	printf("Depth will increase %d times \n", decreaseTimes); // print number of times the depth has decreased

	// END OF PART 1

	decreaseTimes = 0; // reset decrase counter
	
	// PART 2

	for (int i = 0; i < sizeof(input_array) / sizeof(int); i++) { // cycle through all input values
		int A = input_array[i + 2] + input_array[i + 1] + input_array[i]; // calculate value of first group
		int B = input_array[i + 3] + input_array[i + 2] + input_array[i + 1]; // calculate value of second group

		if (B > A) { // if second ground is larger, increase number of times the depth has decreased
			decreaseTimes++; 
		}
	}

	printf("After filtering the data, depth will increase %d times", decreaseTimes++);

	printf("\n \n ------------------------------------------- \n \n");
 }

