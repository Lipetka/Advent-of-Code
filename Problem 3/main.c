// includes

#include <stdio.h>
#include <string.h>
#include <math.h>

// inits

checkValues(char str[]);

// variables

int output_array[12]; // variable that stores output array counter
int output_array_epsilon[12]; // variable that stores output array counter
int gamma_dec; // variable for holding gamma rate in decimal form
int epsilon_dec; // variable for holding epsilon rate in decimal form

// main code

int main() {

	printf("\n \n ---------------Problem 3------------------ \n \n");

	char str[15]; // variable that stores the string from input file
	int array_counter = 0; // variable that stores array counter value

	FILE* raw_data; // creating FILE variable
	raw_data = fopen("input.txt", "r"); // open file

	// if file couldn't be opened print error
	if (raw_data == NULL) {
		perror("File couldn't be opened"); // print error
		return(0); // return from main() function
	}

	// while there is some lines to be read
	while (fgets(str, 15, raw_data)) {
		/*
		In this problem I can count every row separately and save their values in global variables
		*/

		checkValues(str); // function which will check the 0/1 value and save it to counters
	}
	fclose(raw_data); // close file to save memory

	printf("The number of ones on each place is: ");

	for (int i = 0; i <= 11; i++) {
		printf("%d ", output_array[i]); // prints raw counter
	}

	printf("\n\n");
	 //  find the binary value of gamma rate
	for (int i = 0; i <= 11; i++) {
		// the problem does not specify what to do if there are equal amount of ones and zeros
		if (output_array[i] == 500) {
			printf("Can't determine");
		}
		else if (output_array[i] > 500) {
			output_array[i] = 1; // if there are more ones than output_array[i] will be 1
		}
		else {
			output_array[i] = 0; // if there are more zeros than output_array[i] will be 0
		}
	}
	// find the binary value of epsilon rate (same as gamma but opposite)
	for (int i = 0; i <= 11; i++) {
		if (output_array[i] == 1) {
			output_array_epsilon[i] = 0; // if there are more ones than output_array[i] will be 1
		}
		else {
			output_array_epsilon[i] = 1; // if there are more zeros than output_array[i] will be 0
		}
	}

	/*
	After this part I end up with array which looks like binary number so all
	I have to do now is to convert this array to binary number
	*/

	printf("Binary interpretation of gamma rate is: ");
	for (int i = 0; i <= 11; i++) {
		printf("%d", output_array[i]);
	}

	printf("\nBinary interpretation of epsilon rate is: ");
	for (int i = 0; i <= 11; i++) {
		printf("%d", output_array_epsilon[i]);
	}

	// conversion from binary to decimal

	//gamma
	for (int i = 0; i <= 11; i++) {
		gamma_dec += output_array[i] * pow(2,(11-i)); 
	}

	//epsilon
	for (int i = 0; i <= 11; i++) {
		epsilon_dec += output_array_epsilon[i] * pow(2, (11 - i));
	}



	printf("\nThe gamma rate in decimal is: %d \n", gamma_dec);
	printf("The epsilon rate in decimal is: %d\n", epsilon_dec);
	printf("The answer to AoC puzzle is: %d", gamma_dec*epsilon_dec);

	printf("\n \n ------------------------------------------- \n \n");
}

checkValues(char str[]) {

	/*
	This function checks if the number is 1, if yes then it will add 
	1 to counter on the corresponding place, after this we end up with 
	an array which looks something like this: {510,156,499,158, etc..}
	So we know how many 1 (ones) are on which place, becouse we know
	the total length of the input we can determine if there are more
	ones or zeros and thus get the first value I am looking for
	*/

	for (int i = 0; i <= 11; i++) {
		if (str[i] == '1') {
			output_array[i] += 1;
		}
	}
}