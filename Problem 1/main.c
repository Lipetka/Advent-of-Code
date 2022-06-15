// includes
#include <stdio.h>
#include "input.h"

// inits


// variables

int decreaseTimes = 0;

//int decreasedTimes; // variable that stores number of times the depth has decreased


// main code
void main() {
	
	/*
	
	for (int i = 0; i < sizeof(input) / sizeof(int); i++) { // cycle through all input values
		if (input[i + 1] > input[i]) { // if next input is bigger add 1 to decrease counter
			decreaseTimes++;
		}
	}
	printf("%d", decreaseTimes); // print number of times the depth has decreased

	*/

	for (int i = 0; i < sizeof(input) / sizeof(int); i++) { // cycle through all input values
		int A = input[i+2] + input[i + 1] + input [i]; // calculate value of first group
		int B = input[i +3] + input[i + 2] + input[i + 1]; // calculate value of second group

		if (B > A) { // if second ground is larger, increase number of times the depth has decreased
			decreaseTimes++; 
		}
	}

	printf("%d", decreaseTimes++);

 }

