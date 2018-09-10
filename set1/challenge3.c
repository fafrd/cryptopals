#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int main()
{
	unsigned char *input = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

	unsigned char *inputBytes = hexchar2byte_array(input, strlen(input));

	size_t length = strlen(input) / 2;
	unsigned char *keyBytes = calloc(length, sizeof(char));

	for (unsigned char c = 'A'; c <= 'z'; c++)
	{
		if (c == '[')
			c = 'a';

		for (int i = 0; i < length; i++)
			keyBytes[i] = c;

		unsigned char *rawOutput = xor(inputBytes, keyBytes, length);
		unsigned char *hexOutput = byte2hexchar_array(rawOutput, length);

		printf("character %c: value %s\n", c, rawOutput);
		//printf("%s\n", hexOutput);
	}
}
