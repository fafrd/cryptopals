#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *hex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	char *expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
	char *b64 = calloc(64, sizeof(char));

	// well... each base64 character represents 6 bits. each hex character is 4 bits.
	// 



}
