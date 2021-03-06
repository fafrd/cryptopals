#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printHexString(unsigned char *hex, size_t length)
{
	for (int i = 0; i < length; i+=2)
	{
		printf("%c%c", hex[i], hex[i+1]);
	}
	printf("\n");
}

unsigned char hexchar2byte(unsigned char hex)
{
	unsigned char rv;
	if (hex >= '0' && hex <= '9')
		rv = hex - '0';
	else if (hex >= 'A' && hex <= 'F')
		rv = hex - 'A' + 0xA;
	else if (hex >= 'a' && hex <= 'f')
		rv = hex - 'a' + 0xa;
	else
	{
		printf("encountered unexpected hex character: %c (bytes: 0x%hx)\n", hex);
		exit(1);
	}

	return rv;
}

// expecting hex array length is a multiple of 2
unsigned char* hexchar2byte_array(unsigned char *hex, size_t length)
{
	unsigned char *rv = calloc(length/2, sizeof(char));

	if (length % 2)
		length--;

	int byteCounter = 0;
	for (int i = 0; i < length; i += 2)
	{
		// upper
		unsigned char upper = hexchar2byte(hex[i]);
		upper <<= 4;

		// lower
		unsigned char lower = hexchar2byte(hex[i+1]);

		rv[byteCounter++] = upper | lower;
	}

	return rv;
}

// this only works if byte <= 0xf
unsigned char byte2hexchar(unsigned char byte)
{
	unsigned char rv;
	if (byte < 0xa)
		rv = byte + '0';
	else if (byte <= 0xf)
		rv = byte - 0xa + 'a';
	else
	{
		printf("encountered unexpected byte: %hhx\n", byte);
		exit(1);
	}

	return rv;
}

unsigned char* byte2hexchar_array(unsigned char *bytes, size_t length)
{
	unsigned char *rv = calloc(length*2, sizeof(char));

	int hexCounter = 0;
	for (int i = 0; i < length; i++)
	{
		// upper 4 bits
		unsigned char upper = bytes[i] >> 4;
		rv[hexCounter++] = byte2hexchar(upper);

		// lower 4 bits
		unsigned char lower = bytes[i] & 0x0f;
		rv[hexCounter++] = byte2hexchar(lower);
	}

	return rv;
}

unsigned char byte2base64char(unsigned char byte)
{
	unsigned char rv;

	if (byte <= 25)
		rv = byte + 'A';
	else if (byte <= 51)
		rv = byte + 'a' - 26;
	else if (byte <= 61)
		rv = byte + '0' - 52;
	else if (byte == 62)
		rv = '+';
	else if (byte == 63)
		rv = '/';
	else
	{
		printf("encountered unexpected binary character: %hhx\n", byte);
		exit(1);
	}

	return rv;
}

unsigned char* xor(unsigned char *input, unsigned char *key, size_t length)
{
	unsigned char *rv;

	rv = calloc(length, sizeof(char));

	for (int i = 0; i < length; i++)
	{
		unsigned char targetByte = input[i];
		unsigned char keyByte = key[i];

		rv[i] = targetByte ^ keyByte;
	}

	return rv;
}

float plaintextRating(unsigned char *input, size_t length)
{
	// using a few criteria to rate the likelihood that *input is plaintext...
	// if char outside printable range, return 0
	// vowels should represent ~25% of characters
	// spaces should represent ~20% of characters

	int vowelCount = 0;
	int spaceCount = 0;

	for (int i = 0; i < length; i++)
	{
		// if characters are outside normal range, return 0 immediately
		if (input[i] < ' ' && input[i] != 0x9 && input[i] != 0xa && input[i] != 0xd)
			return 0.0f;
		if (input[i] > '~')
			return 0.0f;

		switch (input[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				vowelCount++;
				break;
			case ' ':
				spaceCount++;
				break;
		}
	}

	// sum the rating of vowels and spaces
	// (let's just say they're equally important)
	float vowelRate = vowelCount / (float)length;
	float spacesRate = spaceCount / (float)length;

	float rating = vowelRate + spacesRate;
	return rating;
}

unsigned char* encryptRepeatingXor(unsigned char *input, unsigned char *key)
{
	size_t inputLength = strlen(input);
	size_t keyLength = strlen(key);
	unsigned char *ciphertext = calloc(inputLength, sizeof(char));

	int keyCounter = 0;
	for (int i = 0; i < inputLength; i++)
	{
		ciphertext[i] = input[i] ^ key[keyCounter];
		//printf("encrypting input char %c with key char %c; result: %hx\n", input[i], key[keyCounter], ciphertext[i]);
	
		if (keyCounter == keyLength - 1)
			keyCounter = 0;
		else
			keyCounter++;
	}

	return ciphertext;
}

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



