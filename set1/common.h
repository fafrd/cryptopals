#ifndef COMMON_H
#define COMMON_H

unsigned char hexchar2byte(unsigned char);
unsigned char* hexchar2byte_array(unsigned char *, size_t);
unsigned char byte2hexchar(unsigned char);
unsigned char* byte2hexchar_array(unsigned char *, size_t);
unsigned char byte2base64char(unsigned char);
unsigned char* xor(unsigned char *input, unsigned char *key, size_t);

#endif
