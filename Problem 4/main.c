#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// inits

void playRound();
void checkWinner();
void checkLastWinner();
int calculatePoints();

// variables

int boardsArray[100][5][5] = {0}; // all arrays
char bingoNumbersString[500]; // bingo numbers as a string
int bingoNumbers[100]; // bingo numbers as a int
bool winner = false; // winner boolean
int round = 0; // number of rounds
int winningBoard; // winning board placeholder
int winningSum; // the sum of board
int lastBoard; // last board won placeholder
bool lastWinner = false; // boolean of last winner
int winningArray[25] = {0}; // array of boards that already won
int winners = 0; // number of winners

// main code
int main() {

	printf("\n \n ---------------Problem 4------------------ \n \n");

	char str[500],*line,*tmp; // variable that stores the string from input file


	FILE* raw_data; // creating FILE variable
	raw_data = fopen("input.txt", "r"); // open file

	// if file couldn't be opened print error
	if (raw_data == NULL) {
		perror("File couldn't be opened"); // print error
		return(-1); // return from main() function
	}

	//  take first line and save it as bingo numbers string

	fgets(str, 500, raw_data);
	strcpy(bingoNumbersString, str);
	
	// split string and save the output as int array

	char *buf; // buffer
	int i = 0; 
	buf = strtok(bingoNumbersString, ","); // split string by comma
	while (buf != NULL) {
		bingoNumbers[i] = atoi(buf); // save split string into array of ints
		buf = strtok(NULL, ","); // clear
		i++;
	}

	// now I save bingotables into separate arrays


	int blockCounter = 0; // block = bingo board

	// put input into array of arrays representing all boards
	
	while (fgets(str, 250, raw_data)) {
		for (int lineCounter = 0; lineCounter < 5; lineCounter++) {
			fgets(str, 250, raw_data); // get line
			line = str;
			for (int colCounter = 0; colCounter < 5; colCounter++) {
				boardsArray[blockCounter][lineCounter][colCounter] = strtol(line, &line, 10); // save bpard as int into array of boards
			}
		}
		blockCounter++;
	}
	
	fclose(raw_data); // close file to save memory



	// now I will code two function which will represent playing one round and the second one will 
	// check if there is a winner

	while (winner == false) {
		playRound(); // plays round
		checkWinner(); // chcecks if there is a winner
		round++; // add round counter
		
		// protection agains no winner situation
		if (round == 100) {
			printf("There is no winnner");
			break;
		}
	}
	
	// calculate points of winning board
	winningSum = calculatePoints(winningBoard);


	// output
	printf("\n\nWinning board is: %d\n", winningBoard);
	printf("Sum is: %d\n", winningSum);
	printf("Game was won on round %d\n", round);
	printf("Winning number is %d\n", bingoNumbers[round-1]);
	printf("The winning score is: %d\n\n", winningSum* bingoNumbers[round - 1]);

	printf("\n \n ---------------Problem 4.2----------------- \n \n");

	// I couldnt get part two to work if I will have time I will come back to this

	while (lastWinner == false) {
		// play rounds as before
		playRound();
		checkWinner();
		round++;
		// protection agains no winner situation
		if (round == 100) {
			printf("There is no winnner");
			break;
		}

		// if there are 24/25 winners stop the loop and calculate points with the last board

		if (winners == 24) {
			break;
		}

	}

	// output

	printf("\n\nTotal number of winners is: %d", winners);
	printf("\nThe last winner is: %d", winningArray[winners - 1]);
	printf("\nThe points of last winner are %d", calculatePoints(winningArray[winners - 1]));
	printf("\nTotal points of last winner are %d\n\n", calculatePoints(winningArray[winners - 1])*bingoNumbers[winners - 1]);


}


void playRound() {


	int drewNumber = bingoNumbers[round]; // take drew number ý

	// bingo boards cycle
	for (int i = 0; i < 25; i++) {
		// line cycle
		for (int j = 0; j < 5; j++) {
			// column cycle
			for (int k = 0; k < 5; k++) {
				if (boardsArray[i][j][k] == drewNumber) {
					boardsArray[i][j][k] = 100; // if theres a drawn number replace it with 100 (or a number that can't be drawn)
				}
			}
		}
	}

	

} 

void checkWinner() {
	// bingo boards cycle
	int i = 0;

	for (i = 0; i < 25; i++) {
		// if the board (i) is already a winning board, skip it (so it doesnt count multiple winners)
		here:
		for (int o = 0; o < 25; o++) {
			if (winningArray[o] == i) {
				i++;
				goto here; // https://ibb.co/vzpq8yw
			}
		}

		for (int j = 0; j < 5; j++) {
			winner = true;
			for (int k = 0; k < 5; k++) {
				if (boardsArray[i][j][k] != 100) {
					// check if there is a continuos 100 flag, if not, set winner as false and continue
					winner = false;
					break;
				}

			}
		}
		if (winner == true) {
			// if there is a winner, save the wining board, add winner count and return
			winningBoard = i;
			winningArray[winners] = winningBoard;
			winners++;
			return;
		}



		for (int j = 0; j < 5; j++) {
			winner = true;
			for (int k = 0; k < 5; k++) {
				if (boardsArray[i][k][j] != 100) {
					// the same as before but with rows
					winner = false;
					break;
				}
			}
		}
		if (winner == true) {
			// the same as before
			winningBoard = i;
			winningArray[winners] = winningBoard;
			winners++;
			return;
		}


	}
}

int calculatePoints(int calcBoard) {
	// calculate the sum of all unmarked numbers
	winningSum = 0;
	// line cycle
	for (int j = 0; j < 5; j++) {
		// column cycle
		for (int k = 0; k < 5; k++) {
			if (boardsArray[calcBoard][j][k] == 100) {
				continue;
			}
			else {
				winningSum += boardsArray[calcBoard][j][k]; // if theres a drawn number replace it with 100 (or a number that can't be drawn)
			}
		}
	}
	return winningSum;
}