#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

float findMostLikelyPlaintext(unsigned char *input, unsigned char **output)
{
	unsigned char *inputBytes = hexchar2byte_array(input, 60);

	size_t length = 30;
	unsigned char *keyBytes = calloc(length, sizeof(char));
	unsigned char bestKey;
	float bestRating = 0.0;
	unsigned char *bestOutput = calloc(length, sizeof(char));

	for (unsigned char c = 0; c < 255; c++)
	{
		for (int i = 0; i < length; i++)
			keyBytes[i] = c;

		unsigned char *rawOutput = xor(inputBytes, keyBytes, length);
		float currentRating = plaintextRating(rawOutput, length);
		//printf("char: %hx, xor: %s\n", c, rawOutput);
		if (currentRating > bestRating)
		{
			bestKey = c;
			bestRating = currentRating;
			memcpy(bestOutput, rawOutput, length * sizeof(char));
		}
	}

	//printf("character %c: value %s\n", bestKey, bestOutput);
	*output = bestOutput; // honestly i need to learn why this assignment works

	return bestRating;
}

int main(int argc, const char* argv[])
{
	// given a file containing a bunch of equal-length potential ciphertexts, decrypt by single-byte xor
	// and find which of these strings is most likely to be plaintext.
	if (argc < 2)
	{
		printf("expecting file\n");
		exit(1);
	}

	FILE *f = fopen(argv[1], "r");
	char *line;
	size_t len;

	float bestRating = 0.0;
	unsigned char *bestOutput = calloc(30, sizeof(char));
	while (getline(&line, &len, f) != -1)
	{
		//printf("%s", line);
		if (strlen(line) == 61) // ensure that it's 60 characters. one of the lines was 58
		{
			unsigned char *temp;
			float currentRating = findMostLikelyPlaintext(line, &temp);
			//printf("rating: %f; value: %s\n", currentRating, temp);
			if (currentRating > bestRating)
			{
				bestRating = currentRating;
				memcpy(bestOutput, temp, 30 * sizeof(char));
				//printf("new best: %s, %s\n", temp, bestOutput);
			}
		}
	}

	printf("rating: %f; value: %s\n", bestRating, bestOutput);
}

