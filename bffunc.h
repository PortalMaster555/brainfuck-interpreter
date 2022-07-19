#define KIB 1024

typedef struct tape
{
	char array[KIB];
	int length;
	int position;

	int brackStack[KIB]; //locations of [
	int bsIndex;

} tape;

FILE *openFile(char *inputFilename);
tape zeroTape();
tape loadBrainfuck(FILE *bfFile);
