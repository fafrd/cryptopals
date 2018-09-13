#ifndef COMMON_H
#define COMMON_H

void printHexString(unsigned char *, size_t);
unsigned char hexchar2byte(unsigned char);
unsigned char* hexchar2byte_array(unsigned char *, size_t);
unsigned char byte2hexchar(unsigned char);
unsigned char* byte2hexchar_array(unsigned char *, size_t);
unsigned char byte2base64char(unsigned char);
unsigned char* xor(unsigned char *, unsigned char *, size_t);
float plaintextRating(unsigned char *, size_t);
unsigned char* encryptRepeatingXor(unsigned char *, unsigned char *);

#endif
