#include <stdio.h>

int main(int argc, char **argv)
{

	char *bfFilename = "main.bf";
	char *outputFilename = "out.txt";
	
	FILE *bfCode = NULL;
	FILE *outputFile;

	bfCode = fopen(bfFilename, "r");
	outputFile = fopen(outputFilename, "w");

	fclose(bfCode);
	fclose(outputFile);

	return 0;
}
