#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{ //i am much too lazy to put functions in, i will pretend to intend to refactor this

	char charSet[8] = "><+-.,[]";

	char *bfFilename = "main.bf";
	char *outputFilename = "out.txt";
	
	FILE *bfCode;
	FILE *outputFile;

	char bfBuffer[1024];

	bfCode = fopen(bfFilename, "r");
	outputFile = fopen(outputFilename, "w");

	char ch;
	int buffSize = 0;
	while((ch = fgetc(bfCode)) != EOF)
	{
		for(int j = 0; j < 8; j++)
		{
			if(ch == charSet[j])
				bfBuffer[buffSize++] = ch;
		}	
	}
	if(feof(bfCode))
		bfBuffer[buffSize++] = '\0';
	
	//
	//

	int currentPos = 512; //intentional laziness because i dont want to implement under or overflow
	char tape[1024] = {0}; //initalize all bytes to 0

	int bracLoc[512];
	int	bLocSize = 0;

	char userInput[2];

	for(int i = 0; i < buffSize; i++)
	{	
		printf("%d \n", i);
		switch(bfBuffer[i])
		{
			case '>': //shift right
				currentPos++;
				break;
			case '<': //shift left
				currentPos--;
				break;
			case '+': //increment
				tape[currentPos]++;
				break;
			case '-': //decrement
				tape[currentPos]--;
				break;
			case '.': //print char
				printf("%c", tape[currentPos]);
				break;
			case ',': //read char from user
				fgets(userInput, 2, stdin);
				tape[currentPos] = userInput[0];
				break;
			case '[': //while not 0 loop
				if(tape[currentPos] != 0)
				{
					bracLoc[bLocSize++] = currentPos;
					break;
				}
				else
				{
					while(bfBuffer[i] != ']')
					{
						printf("%d", i);
						i++;
					}
					break;
				}
			case ']': //jump to 1 after last in [ array if nonzero
				if(tape[currentPos] != 0)
				{
					currentPos = bracLoc[bLocSize - 1] + 1;
					break;
				}
				else
				{
					bLocSize--;
					break;
				}
		}
	}	



	//
	//
	//

	for(int i = 0; i < 1024; i++)
	{
		printf("%d ", tape[i]);
	}

	printf("\n\n%s\n", bfBuffer);
	fclose(bfCode);
	fclose(outputFile);

	return 0;
}
