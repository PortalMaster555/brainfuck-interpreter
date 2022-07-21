#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "bffunc.h"

char *inputFilename = "main.bf";
char *outputFilename = "out.txt";

char input;

int main(int argc, char **argv)
{
	//OPEN FILE CONTAINING BRAINFUCK
	FILE *bfFile = openFile(inputFilename);
	FILE *outFile = openFile(outputFilename);

	//LOAD BRAINFUCK INTO MEMORY, IGNORING COMMENTS
	tape code = loadBrainfuck(bfFile);

	printf("Brainfuck code: %s\n", code.array);

	tape tape = zeroTape();
	tape.position = 512; //setting pointer to middle of tape

	char userInput[2];

	printf("Output: ");
	//UPDATE TAPE AND CODE
	while(code.position <= code.length)
	{
		switch(code.array[code.position])
		{
			case '>':
				tape.position++;
				break;
			case '<':
				tape.position--;
				break;
			case '+':
				tape.array[tape.position]++;
				break;
			case '-':
				tape.array[tape.position]--;
				break;
			case '.':
				printf("%c", tape.array[tape.position]);
				fputc(tape.array[tape.position], outFile);
				break;
			case ',':
				fgets(userInput, 2, stdin);
				tape.array[tape.position] = userInput[0];
				break;
			case '[':
				if(tape.array[tape.position] == 0)
				{
					while(code.array[code.position] != ']')
					{
						code.position++;
						if(code.position > code.length)
						{
							printf("\nNo right bracket found\n");
							return 0;
						}
					}
				}
				else
				{
					code.brackStack[code.bsIndex++] = code.position;
				//	printf(" Bracket Loc: %d  ", code.brackStack[code.bsIndex]);
				}
				break;
			case ']':
				if(tape.array[tape.position] != 0)
				{
				//	printf("Jump bracket: %d ", code.brackStack[code.bsIndex - 1]);
					code.position = code.brackStack[code.bsIndex - 1];
				}
				else
				{
					code.brackStack[code.bsIndex--] = -1;
				}
				break;
		}
		code.position++;
	}	
	fclose(bfFile);
	return 0;
}
