#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int main(int argc, const char* argv[])
{
	// encrypt plaintext using repeating-key XOR

	char *input = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
	char *key = "ICE";

	char *out = encryptRepeatingXor(input, key);
	char *out_hex = byte2hexchar_array(out, strlen(out));

	printf("%s\n", out_hex);
}

