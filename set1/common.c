#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char hex2bytes(char hex)
{
	char rv;
	if (hex >= '0' && hex <= '9')
		rv = hex - '0';
	else if (hex >= 'A' && hex <= 'F')
		rv = hex - 'A' + 0xa;
	else if (hex >= 'a' && hex <= 'f')
		rv = hex - 'a' + 0xa;
	else
	{
		printf("encountered unexpected hex character: %c\n", hex);
		exit(1);
	}

	return rv;
}

char bytes2base64(char byte)
{
	char rv;

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


