#include <stdio.h>

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
	char tape[1024];
		

	



	//
	//
	//

	printf("%s\n", bfBuffer);
	fclose(bfCode);
	fclose(outputFile);

	return 0;
}
