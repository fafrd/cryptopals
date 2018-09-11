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
	unsigned char bestKey;
	float bestRating = 0.0;
	unsigned char *bestOutput = calloc(length, sizeof(char));

	for (unsigned char c = 'A'; c <= 'z'; c++)
	{
		if (c == '[')
			c = 'a';

		for (int i = 0; i < length; i++)
			keyBytes[i] = c;

		unsigned char *rawOutput = xor(inputBytes, keyBytes, length);
		float currentRating = plaintextRating(rawOutput, length);
		//printf("for character %c, rating is %f, bestRating is %f\n", c, currentRating, bestRating);
		//printf("string: %s\n", rawOutput);
		if (currentRating > bestRating)
		{
			bestKey = c;
			bestRating = currentRating;
			memcpy(bestOutput, rawOutput, length * sizeof(char));
		}
	}

	printf("character %c: value %s\n", bestKey, bestOutput);
	printf("rating: %f\n", bestRating);
}

