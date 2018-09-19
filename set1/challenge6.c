#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int main(int argc, const char *argv[])
{
	unsigned char *first = "this is a test";
	unsigned char *second = "wokka wokka!!!";
	size_t length = strlen(first);

	int hammingDist = calculateHammingDist(first, second, length);
	printf("hamming distance: %d\n", hammingDist);
}

