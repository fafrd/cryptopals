#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int main()
{
	unsigned char *input = "1c0111001f010100061a024b53535009181c";
	unsigned char *key = "686974207468652062756c6c277320657965";
	unsigned char *expected = "746865206b696420646f6e277420706c6179";

	unsigned char *inputBytes = hexchar2byte_array(input, strlen(input));
	unsigned char *keyBytes = hexchar2byte_array(key, strlen(key));

	size_t length = strlen(input) / 2;
	unsigned char *rawOutput = xor(inputBytes, keyBytes, length);
	unsigned char *hexOutput = byte2hexchar_array(rawOutput, length);

	printf("%s\n", hexOutput);
}
