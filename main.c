#include <stdio.h>

int main(int argc, char **argv)
{

	char *filename = "main.bf";
	
	FILE *bfCode = NULL;
	FILE *outputFile;
	int openAttempts = 5;
	int attempt = 0;

	while(bfCode == NULL)
	{
		bfCode = fopen(filename, "r");
		if(++attempt == openAttempts)
		{
			printf("Failed to open file \"%s\" in %d attempts.\n", filename, openAttempts);
			return 1;
		}
	}

	fclose(bfCode);
	fclose(outputFile);
	return 0;
}
