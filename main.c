#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "bffunc.h"

char *inputFilename = "test.bf";

char input;

int main(int argc, char **argv)
{
	//OPEN FILE CONTAINING BRAINFUCK
	FILE *bfFile = openFile(inputFilename);

	//LOAD BRAINFUCK INTO MEMORY, IGNORING COMMENTS
	tape code = loadBrainfuck(bfFile);

	printf("Brainfuck code: %s\n", code.array);



	fclose(bfFile);
	return 0;
}
