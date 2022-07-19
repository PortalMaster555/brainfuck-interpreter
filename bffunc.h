#define KIB 1024

typedef struct tape
{
	char array[KIB];
	int length;
	int position;
} tape;

FILE *openFile(char *inputFilename);
tape loadBrainfuck(FILE *bfFile);

