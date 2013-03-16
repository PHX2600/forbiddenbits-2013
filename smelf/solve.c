#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"

char ciphertext[] = "\x05\x1e\x26\x25\x4b\x00\x74\x65\x41\x00\x1e\x2a\x4b\x00\x1e\x2a\x4b\x4c\x48";

uint32_t offset = 0x12345678;

char mod(char second)
{
	char secondCopy = second;

	//arithmetic shift
	secondCopy = secondCopy >> 7;
	//logical shift
	secondCopy = ((unsigned char)secondCopy) >> 6;	
	//add back in
	second += secondCopy;
	//mask out all but 2 LSBs
	second &= 3;
	second -= secondCopy;
	second = second << 3;

	uint32_t offsetCopy = offset >> second;

	return offset >> second;
}

int main(int argc, char **argv)
{
	int length = sizeof(ciphertext);
	char plaintext[sizeof(ciphertext) + 1];


	memset(plaintext, '\0', sizeof(plaintext));

	for(int i = length-2; i >= 0; i--)
	{
		//actually change the input string itself
		plaintext[i] = ciphertext[i] ^ mod(plaintext[i+1]);
	}
	printf("plaintext=%s\n", plaintext);
	return 0;
}


