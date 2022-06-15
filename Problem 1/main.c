// problem
/*

Count the number of times the next measurement is deeper than previous one

Example of input:

199
200
208
210
200
207
240
269
260
263

Example of calculation from given input:

199 (N/A - no previous measurement)
200 (increased)
208 (increased)
210 (increased)
200 (decreased)
207 (increased)
240 (increased)
269 (increased)
260 (decreased)
263 (increased)

Example of output:

The depth has increased 7 times
*/


// includes
#include <stdio.h>
#include "input.h"

// variables

int decreasedTimes; // variable that stores number of times the depth has decreased


// main code
void main() {
	
	for (int i = 0; i < sizeof(input) / sizeof(int); i++) { // cycle through all input values
		if (input[i + 1] > input[i]) { // if next input is bigger add 1 to decrease counter
			decreasedTimes++;
		}
	}
	printf("%d", decreasedTimes); // print number of times the depth has decreased

 }