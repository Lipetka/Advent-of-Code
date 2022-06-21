#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// inits

void addTube(int i);
int countOverlaps();

// variables

int arrayOfInputs[510][2][2]; // [# of command][(step) 0, 1][ X:0 Y:1]
int tubeMap[1000][1000] = {0}; // whole tube map


// main code
int main() {

	printf("\n \n ---------------Problem 5------------------ \n \n");



	FILE* raw_data; // creating FILE variable
	raw_data = fopen("inputeasy.txt", "r"); // open file

	// if file couldn't be opened print error
	if (raw_data == NULL) {
		perror("File couldn't be opened"); // print error
		return(-1); // return from main() function
	}

	char str[500]; // variable that stores the string from input file
	char str2[500]; 
	char* commandStr;	// command saved as string
	int command = 0; // command counter
	char* buf; // buffer for line

	// get one line
	while (fgets(str, 25, raw_data)) {


		strcpy(str2, str); // copy the input to second string

		buf = strtok(str, " -> "); // divide the command

		commandStr = strtok(buf, ",");
		arrayOfInputs[command][0][0] = atoi(commandStr); // X1


		buf = strtok(NULL, " -> "); // divide the command

		arrayOfInputs[command][0][1] = atoi(buf); // Y1

		// second part so i dont have to do it in loop

		buf = strtok(str2, " -> "); // divide the command
		buf = strtok(NULL, " -> "); // get the second token

		commandStr = strtok(buf, ",");
		arrayOfInputs[command][1][0] = atoi(commandStr); // X2

		buf = strtok(NULL, ""); // divide the command
		arrayOfInputs[command][1][1] = atoi(buf); // Y2

		command++;

		// I tried doing it in loops but i figured it will be easier to do it as above

		/*
		while (buf != NULL) {

			printf("\n%s\n", buf);
			i = 0;

			strcpy(inputStr, buf);

			buf = strtok(NULL, "->");
			commbuf = strtok(inputStr, ","); // get first number (X1)
			arrayOfInputs[command][i][0] = atoi(commbuf); // save first number 
			while (commbuf != NULL) {
				arrayOfInputs[command][i][1] = atoi(commbuf); // save second number
				commbuf = strtok(NULL, ","); // get the second number (Y1)
			}

			i++;
			strcpy(inputStr, buf);
		}
		*/
	}


	printf("\n\n--OUT--\n\n");

	//printf input array
	/*
	printf("All commands: \n");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				printf("%d", arrayOfInputs[i][j][k]);
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	*/
	for (int i = 0; i < 10; i++) {
		addTube(i); // coounts horizontal and vertical tubes and adds them to map
	}


	// print first 100 map tiles to check if algorithm works
	
	printf("\n");

	for(int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%d", tubeMap[i][j]);
			}
		printf("\n");
	}
	

	int overlaps = countOverlaps(); // counts how many points overlap at least two times
	printf("\n\nOverlaps: %d\n\n", overlaps);


	printf("-.-.-.-.-.-.testy-.-.-.-.\n\n\n");

	int test[5][5];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d", tubeMap[i][j]);
		}
		printf("\n");
	}
}

void addTube(int i) {
	int X1 = arrayOfInputs[i][0][0];
	int X2 = arrayOfInputs[i][1][0];
	int Y1 = arrayOfInputs[i][0][1];
	int Y2 = arrayOfInputs[i][1][1];
	int size;

	if (X1 == X2) {
		if (Y1 > Y2) {
			size = Y1 - Y2;
			for (int j = 0; j <= size; j++) {
				tubeMap[Y2+j][X1]++;
			}
			return;
		}
		else {
			size = Y2 - Y1;
			for (int j = 0; j <= size; j++) {
				tubeMap[Y1 + j][X1]++;
			}
			return;
		}
	}else if(Y1 == Y2) {
		if (X1 > X2) {
			size = X1 - X2;
			for (int j = 0; j <= size; j++) {
				tubeMap[Y1][X2 + j]++;
			}
			return;
		}
		else {
			size = X2 - X1;
			for (int j = 0; j <= size; j++) {
				tubeMap[Y1][X1 + j]++;
			}
			return;
		}
	}else if((X1 != X2)&&(Y1 != Y2)) {
		if (X1 > X2) {
			size = X1 - X2;

			if (Y1 > Y2) {
				for (int j = 0; j <= size;j++) {
					tubeMap[Y2 + j][X2 + j]++;
				}
				return;
			}
			else {
				for (int j = 0; j <= size; j++) {
					tubeMap[Y1 + j][X2 + j]++;
				}
				return;
			}
		}
		else if (X1 < X2) {
			size = X2 - X1;

			if (Y1 > Y2) {
				for (int j = 0; j <= size; j++) {
					tubeMap[Y2 + j][X1 + j]++;
				}
				return;
			}
			else {
				for (int j = 0; j <= size; j++) {
					tubeMap[Y1 + j][X1 + j]++;
				}
				return;
			}

		}
	}
	else {
		printf("\nerror\n");
		return;
	}

}

int countOverlaps() {
	int overlaps = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (tubeMap[i][j] > 1) {
				overlaps++;
				tubeMap[i][j] = 0;
			}
		}
	}
	return overlaps;
}

