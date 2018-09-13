#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int main(int argc, const char* argv[])
{
	// encrypt plaintext using repeating-key XOR

	unsigned char *input = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
	unsigned char *key = "ICE";

	//unsigned char *input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus nulla turpis, placerat eu condimentum eget, venenatis eu felis. Nam vitae suscipit urna. Donec cursus libero eget fringilla aliquet. Nullam ultrices nisl vitae malesuada interdum. Pellentesque eu dictum eros, quis tempus quam. Sed interdum sed purus a pretium. Aenean molestie molestie sapien.";
	//unsigned char *key = "ice ice baby";

	unsigned char *out = encryptRepeatingXor(input, key);
	unsigned char *out_hex = byte2hexchar_array(out, strlen(input));

	//printf("%s\n", out_hex); // can't do this - 0x00 hex chars don't get printed
	printHexString(out_hex, strlen(input) * 2);
}

