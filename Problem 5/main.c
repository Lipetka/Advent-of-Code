#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// inits




// variables

int arrayOfInputs[500][2][2]; // 500 commands ; 2x X1 to Y1 ; 2x Y1 to Y2
int tubeMap[1000][1000] = {0}; // whole tube map


// main code
int main() {

	printf("\n \n ---------------Problem 5------------------ \n \n");

	char str[500], * line, * tmp; // variable that stores the string from input file


	FILE* raw_data; // creating FILE variable
	raw_data = fopen("inputeasy.txt", "r"); // open file

	// if file couldn't be opened print error
	if (raw_data == NULL) {
		perror("File couldn't be opened"); // print error
		return(-1); // return from main() function
	}

	int command = 0;

	while (fgets(str, 15, raw_data)) {
		char commandStr[];
		char* buf;
		int i = 0;
	

		strcpy(commandStr, str);
		buf = strtok(commandStr, "->");
		while (buf != NULL) {

			arrayOfInputs[command][i][j] = atoi(buf);
			buf = strtok(NULL, "->");
			command++;

		}
		printf("%s\n", str);
	}










	// print first 100 map tiles to check if algorithm works

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d", tubeMap[i][j]);
		}
		printf("\n");
	}
}


