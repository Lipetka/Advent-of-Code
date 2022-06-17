#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// inits

void playRound();
void checkWinner();
void checkLastWinner();
void calculatePoints();

// variables

int boardsArray[100][5][5] = {0};
char bingoNumbersString[500];
int bingoNumbers[100];
bool winner = false; // winner boolean
int round = 0;
int winningBoard;
int winningSum;
int lastBoard;

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

	char *buf;
	int i = 0;
	buf = strtok(bingoNumbersString, ",");
	while (buf != NULL) {
		bingoNumbers[i] = atoi(buf);
		buf = strtok(NULL, ",");
		i++;
	}

	// now I save bingotables into separate arrays


	int blockCounter = 0;

	// put input into array of arrays representing all boards
	
	while (fgets(str, 250, raw_data)) {
		for (int lineCounter = 0; lineCounter < 5; lineCounter++) {
			fgets(str, 250, raw_data);
			line = str;
			for (int colCounter = 0; colCounter < 5; colCounter++) {
				boardsArray[blockCounter][lineCounter][colCounter] = strtol(line, &line, 10);
			}
		}
		blockCounter++;
	}
	
	fclose(raw_data); // close file to save memory



	// now I will code two function which will represent playing one round and the second one will 
	// check if there is a winner

	while (winner == false) {
		playRound();
		checkWinner();
		round++;
		// protection agains no winner situation

		if (round == 100) {
			printf("There is no winnner");
			break;
		}
	}
	
	printf("All boards:\n");

	for (int br = 0; br < 25; br++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				printf("%d ", boardsArray[br][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	// calculate points of winning board
	calculatePoints();

	printf("\n\nWinning board is: %d\n", winningBoard);
	printf("Sum is: %d\n", winningSum);
	printf("Game was won on round %d\n", round);
	printf("Winning number is %d\n", bingoNumbers[round-1]);
	printf("The winning score is: %d\n\n", winningSum* bingoNumbers[round - 1]);

	printf("\n \n ---------------Problem 4.2----------------- \n \n");

	while (winner == false) {
		playRound();
		checkLastWinner();
		round++;
		// protection agains no winner situation

		if (round == 100) {
			printf("There is no winnner");
			break;
		}
	}



}


void playRound() {


	int drewNumber = bingoNumbers[round]; // take drew number 

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


		for (int j = 0; j < 5; j++) {
			winner = true;
			for (int k = 0; k < 5; k++) {
				if (boardsArray[i][j][k] != 100) {
					winner = false;
					break;
				}

			}
		}
		if (winner == true) {
			printf("Winning board: %d\n", i);
			winningBoard = i;
			return;
		}



		for (int j = 0; j < 5; j++) {
			winner = true;
			for (int k = 0; k < 5; k++) {
				if (boardsArray[i][k][j] != 100) {
					winner = false;
					break;
				}
			}
		}
		if (winner == true) {
			printf("Winning board: %d\n", i);
			winningBoard = i;
			return;
		}


	}
}

void calculatePoints() {
	// calculate the sum of all unmarked numbers

	// line cycle
	for (int j = 0; j < 5; j++) {
		// column cycle
		for (int k = 0; k < 5; k++) {
			if (boardsArray[winningBoard][j][k] == 100) {
				continue;
			}
			else {
				winningSum += boardsArray[winningBoard][j][k]; // if theres a drawn number replace it with 100 (or a number that can't be drawn)
			}
		}
	}
	
}

void checkLastWinner() {
	// bingo boards cycle
	int i = 0;

	for (i = 0; i < 25; i++) {


		for (int j = 0; j < 5; j++) {
			winner = true;
			for (int k = 0; k < 5; k++) {
				if (boardsArray[i][j][k] != 100) {
					winner = false;
					break;
				}

			}
		}
		if (winner == true) {
			printf("Winning board: %d\n", i);
			lastBoard = i;
			return;
		}



		for (int j = 0; j < 5; j++) {
			winner = true;
			for (int k = 0; k < 5; k++) {
				if (boardsArray[i][k][j] != 100) {
					winner = false;
					break;
				}
			}
		}
		if (winner == true) {
			printf("Winning board: %d\n", i);
			lastBoard = i;
			return;
		}
	}
}