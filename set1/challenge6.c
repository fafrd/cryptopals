#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

//char** readfile(FILE *f)
void readfile(FILE *f)
{
	int linecount = 0;
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t linesize = 0;

	// first, count lines...
	while (1)
	{
		linesize = getline(&lineptr, &n, f);
		if (linesize == -1)
			break;
		printf("linesize: %d, linecount: %d\n", linesize, linecount);
		linecount++;
	}

	rewind(f);

	// then, populate a string containing everything except linebreaks
	char *bigone = calloc(linesize * linecount, sizeof(char));
	linecount = 0;
	//while (1)
	for (int i = 0; i < 2; i++)
	{
		linesize = getline(&lineptr, &n, f);
		if (linesize == -1)
			break;
		printf("linesize: %d, linecount: %d\n", linesize, linecount);
		memcpy(bigone + linesize * linecount, lineptr, linesize);
	}

	printf("%s\n", bigone);

	// FIXME- this isn't going to work, because not each line is the same length... the last line is different
}

int main(int argc, const char *argv[])
{
	if (argc < 2)
	{
		printf("expecting file\n");
		exit(1);
	}

	FILE *f = fopen(argv[1], "r");

	unsigned char *first = "this is a test";
	unsigned char *second = "wokka wokka!!!";
	size_t length = strlen(first);

	int hammingDist = calculateHammingDist(first, second, length);
	printf("hamming distance: %d\n", hammingDist);

	readfile(f);

	//for (int i = keysizeStart, i < keysizeEnd; i++)
printf("wut\n");

	return 0;
}

