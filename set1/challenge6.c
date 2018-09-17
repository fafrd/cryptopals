#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int calculateHammingDist(unsigned char *first, unsigned char *second, size_t length)
{
	int bits = 0;

	for (int i = 0; i < length; i++)
	{
		if ((first[i] & 0b10000000) ^ (second[i] & 0b10000000))
			bits++;
		if ((first[i] & 0b01000000) ^ (second[i] & 0b01000000))
			bits++;
		if ((first[i] & 0b00100000) ^ (second[i] & 0b00100000))
			bits++;
		if ((first[i] & 0b00010000) ^ (second[i] & 0b00010000))
			bits++;
		if ((first[i] & 0b00001000) ^ (second[i] & 0b00001000))
			bits++;
		if ((first[i] & 0b00000100) ^ (second[i] & 0b00000100))
			bits++;
		if ((first[i] & 0b00000010) ^ (second[i] & 0b00000010))
			bits++;
		if ((first[i] & 0b00000001) ^ (second[i] & 0b00000001))
			bits++;
		//printf("first[i]: %c / %hx, second[i]: %c / %hx\n", first[i], first[i], second[i], second[i]);
		//printf("first[i]&0b: %hx, second[i]&0b: %hx\n", first[i]&0b00010000, second[i]&0b00010000);
		//printf("xor: %d\n", (first[i] & 0b00010000) ^ (second[i] & 0b00010000));
	}

	return bits;
}

int main(int argc, const char *argv[])
{
	unsigned char *first = "this is a test";
	unsigned char *second = "wokka wokka!!!";
	size_t length = strlen(first);

	int hammingDist = calculateHammingDist(first, second, length);
	printf("hamming distance: %d\n", hammingDist);
}

