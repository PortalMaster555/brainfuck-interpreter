#include <stdio.h>

int main(int argc, char **argv)
{

	char charSet[8] = "><+-.,[]";

	char *bfFilename = "main.bf";
	char *outputFilename = "out.txt";
	
	FILE *bfCode = NULL;
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
	
	printf("%s\n", bfBuffer);
	fclose(bfCode);
	fclose(outputFile);

	return 0;
}
