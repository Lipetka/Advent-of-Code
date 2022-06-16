#include <stdio.h>
#include <stdlib.h>


void main() {

    char c;
	FILE * raw_data;
	raw_data = fopen("data.txt", "r");
    while (1) {
        c = fgetc(raw_data);
        printf("%c", c);
    }
	return;

}

