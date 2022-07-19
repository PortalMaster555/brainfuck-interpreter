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

	tape tape = zeroTape();
	tape.position = 512; //setting pointer to middle of tape
	
	//UPDATE TAPE AND CODE
	while(code.position <= code.length)
	{
		switch(code.array[code.position])
		{
			case '>':
				tape.position++;
				code.position++;
				break;
			case '<':
				tape.position--;
				code.position++;
				break;
			case '+':
				tape.array[tape.position]++;
				code.position++;
				break;
			case '-':
				tape.array[tape.position]--;
				code.position++;
				break;
			case '.':
				printf("%c", tape.array[tape.position]);
				code.position++;
				break;
			case ',':

				code.position++;
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
				code.position++;
				break;
			case ']':
				
				break;
		}
		code.position++;
	}	
	
	fclose(bfFile);
	return 0;
}
