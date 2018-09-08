#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		printf("encountered unexpected hex character: %c\n", hex);
		exit(1);
	}

	return rv;
}

// expecting hex array length is a multiple of 2
unsigned char* hexchar2byte_array(unsigned char *hex, size_t length)
{
	unsigned char *rv = calloc(length/2, sizeof(char));

	if (length % 2)
	{
		printf("expected hex array to be a multiple of 2\n");
		exit(1);
	}

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

