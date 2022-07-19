#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "bffunc.h"

FILE *openFile(char *inputFilename)
{
	FILE *bfFile = fopen(inputFilename, "r");
	if(bfFile == NULL)
	{
		fprintf(stderr, "Failed to open file \"%s\": %s\n", inputFilename, strerror(errno));
		exit(1);
	}
	return bfFile;
}

tape zeroTape()
{
	tape tape;
	memset(tape.array, 0, KIB * sizeof(char)); //yes i know sizeof(char) isnt needed
	tape.length = 0;
	tape.position = 0;
	return tape;
}

tape loadBrainfuck(FILE *bfFile)
{
	char validChars[8] = "><+-.,[]";
	char bfRead;
	tape code = zeroTape();
	while((bfRead = fgetc(bfFile)) != EOF)
	{
		for(int i = 0; i < 8; i++)
		{
			if(bfRead == validChars[i])
			{
				code.array[code.length++] = bfRead;
			}
		}
	}
	code.array[code.length] = '\0';
	return code;
}
