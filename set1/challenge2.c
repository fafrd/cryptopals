#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// expecting null-terminated inputs
unsigned char* xor(char *input, char *key)
{
	size_t len = strlen(input);
	if (len != strlen(key))
	{
		printf("Unequal lengths for input and xor key\n");
		return 1;
	}

	//for (int i = 0; i < 

}

int main(int argc, char *argv[])
{
	char *input = "1c0111001f010100061a024b53535009181c";
	char *key = "686974207468652062756c6c277320657965";
	char *expected = "746865206b696420646f6e277420706c6179";

	unsigned char *output = xor(input, key);
}
