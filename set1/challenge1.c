#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
	char *hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	char *expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
	char *b64 = calloc(64, sizeof(char));

	// well... each base64 character represents 6 bits. each hex character is 4 bits.
	// let's make a loop that processes 3 chars (12 bits) at a time. this will output 2 base64 chars

	unsigned int bCounter = 0;
	for (unsigned int i = 0; i < 96; i += 3)
	{
		unsigned char raw0 = hex2bytes(hex[i]);
		unsigned char raw1 = hex2bytes(hex[i+1]);
		unsigned char raw2 = hex2bytes(hex[i+2]);

		char out0 = raw0 << 2; // shove bits over, making room for 2 lower bits
		out0 |= (raw1 >> 2); // OR in the lower 2 bits

		char out1 = raw1 << 4; // shove bits over, making room for 4 lower bits
		out1 &= 0x30; // clear out toppest 2 bits
		out1 |= raw2; // OR in the lower 4 bits

		b64[bCounter++] = bytes2base64(out0);
		b64[bCounter++] = bytes2base64(out1);
	}

	for (unsigned int i = 0; i < bCounter; i++)
		printf("%c", b64[i]);

	printf("\n");
}
