#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdint.h"

char ciphertext[] = "\x4c\x10\x49\x00\x24\x09\x49\x36\x09\x05\x1e\x26\x25\x4b\x00\x74\x65\x41\x00\x1e\x2a\x4b\x00\x1e\x2a\x4b\x4c\x48\x00\x00\x00\x00\x78\x56\x34\x12";

uint32_t offset = 0x12345678;

int main(int argc, char **argv)
{
	char *input = argv[1];

	int length = strlen(input);
	if(length > 30)
	{
		printf("Too long\n");
		return 30;
	}

	for(int i = 0; i < length; i++)
	{
		char first = input[i];
		char second = input[i+1];
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

		//actually change the input string itself
		input[i] = input[i] ^ offsetCopy;

		if(input[i] != ciphertext[i])
		{
			printf("ERROR!\n");
			printf("i=%d\n", i);
			printf("ciphertext[i]=%d\n", ciphertext[i]);
			printf("input=%d\n", input[i]);
			return i;
		}
	}
	printf("SUCCESS!\n");
	return 0;
}


