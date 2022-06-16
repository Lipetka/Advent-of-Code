/*
Since this problem can't be sperated into two parts (it could be but it would be ugly and long) 
I will combine both parts in one code, the flow will be the same but function readNumber will 
have more calculation than are required in part 1
*/

// includes
#include <stdio.h>
#include <stdlib.h>

//inits

void processInput(char str[]);
void readNumber(char type, char str[]);

// variables

int hor_pos; // variable for storing horizontal position
int ver_pos; // variable for storing vertical position
int aim; // variable for storing aim

// main code
int main() {

	printf("\n \n ---------------Problem 2------------------ \n \n");

	char str[15]; // variable that stores the string from input file
	FILE* raw_data; // creating FILE variable
	raw_data = fopen("input.txt", "r"); // open file

	// if file couldn't be opened print error
	if (raw_data == NULL) {
		perror("File couldn't be opened"); // print error
		return(0); // return from main() function
	}

	// while there is some lines to be read
	while (fgets(str, 15, raw_data)) {
		// in this problem I will solve the puzzle while reading so i dont have to save the input in array
		processInput(str); // function that solves the navigation
	}
	fclose(raw_data); // close file to save memory



	// printing outputs

	printf("Final horizontal position is %d \n", hor_pos);
	printf("Final vertical position is %d \n", ver_pos);

	int puzzle_output = hor_pos * ver_pos;

	printf("Puzzle answer is %d * %d = %d", hor_pos, ver_pos, puzzle_output);


	printf("\n \n ------------------------------------------- \n \n");
}


void processInput(char str[]) {
	/*
	since we know the syntax of every command we can simply check for
	some letter (in this case first letter) and determine what it means and
	process them separately
	*/
	switch (str[0]){ // compare first letter
		case 'f': 
			readNumber('f', str); // if command is Forward, add corresponding values to next function
			break;
		case 'u':
			readNumber('u', str);  // if command is Up, add corresponding values to next function
			break;
		case 'd':
			readNumber('d', str);  // if command is Down, add corresponding values to next function
			break;
		default:
			printf("Unknown command"); // exception from unknown command
	}
}


void readNumber(char type, char str[]) {
	/*
	In this function we will extract corresponding numbers from their command
	I used separate function for this so it doesnt get too messy in the switch case tree
	*/
	int i = 0; // counter init and reset

	while (str[i] != '\n') { // while theres no end to analyzed string
		if (isdigit(str[i])) { // check if the char is digit
			int value = str[i] - '0'; // conver char to int
			switch (type) {
				case 'f': 
					hor_pos += value; // if the command was to go forward add value to hor_pos variable
					ver_pos += aim * value;
					break;
				case 'u':
					aim -= value; // adjust aim (part 2)
					// ver_pos -= value; // if the command was to go up substract value to ver_pos variable (part 1)
					break;
				case 'd':
					aim += value; // adjust aim (part 2)
					// ver_pos += value; // if the command was to go down add value to ver_pos variable (part 1)
					break;
				default:
					printf("Error in reading command");
			}
		}
		i++; // increase counter after every char
	}
}