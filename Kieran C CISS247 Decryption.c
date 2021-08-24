// Assignment1.c - Encryption/Decryption
// CSCI 247, Assignment1 1, Fall, 2020
// Coded by Kieran Bessert 08 oct 2020 
// Last edited on 15 Oct 2020
#include <stdio.h>
#include <string.h>


//	GLOBAL	VARIABLE	DECLARATIONS

unsigned key1 = 0; 
unsigned key2 = 0;


//	FUNCTION	DECLARATIONS

// extracts two 28-bit keys from 4 bytes
void get_keys (char *twokeys, unsigned *key1, unsigned *key2) {
// Breaks the mega key up into 2 keys
	char keyA[4];
	char keyB[4];
	int i = 0;
	int j = 0;
	while (i <= 7)
	{
		if (i < 4)
		{
			keyA[i] = twokeys[i];
			i++;
		}
		else if (i >= 4)
		{
			keyB[j] = twokeys[i];
			i++;
			j++;
		}
	}
	i = j = 0;
// Place the 4 septets into their key
	while (i < 4)
	{	
		*key1 += keyA[i++];
		*key2 += keyB[j++];
		if (i < 4)
		{
			*key1 <<= 7;
			*key2 <<= 7;
		}
	}
}

// shuffle the 7 nibbles according to the pattern
void shuffle_nibbles (unsigned *bits) {
// Place nibbles into array
	unsigned int n[8];
	unsigned int mask = 15;
	for (int i = 0; i < 7; i++)
	{
		n[i] = *bits & mask;
		*bits >>= 4;
	}
// Place nibbles into correct pattern
	*bits = 0;
	*bits += n[0];
	*bits <<= 4;
	*bits += n[1];
	*bits <<= 4;
	*bits += n[2];
	*bits <<= 4;
	*bits += n[6];
	*bits <<= 4;
	*bits += n[4];
	*bits <<= 4;
	*bits += n[5];
	*bits <<= 4;
	*bits += n[3];
}

// returns the integer value of a specified subsequence of 32 bits
// width is the number of bits to be extracted
// index * width is the index of the rightmost bit to extract
unsigned int get_n_bits (unsigned bits, int width, int index) {
// Make a mask that is width bits long
	unsigned int mask = 0;
	for (int i = 0; i < width; ++i)
	{
		mask += 1;
		if (i < (width-1))
		{
			mask <<= 1;
		}
	}
// Move the mask to the index bit by bit
	for (int i = 0; i < (index * width) ; i++)
	{
		mask <<= 1;
	}
// Place the desired bits in temp
	int temp = 0;
	temp = bits & mask;
	for (int i = (index * width); i > 0 ;i--)
	{
		temp >>= 1;
	}
	return temp;
}

// given a sequence of 7 bits, rotate 3 bits to the left
unsigned int rotate_left3(unsigned bits) {
// Copy and store bits 0-3
	unsigned int mask1 = 15;
	unsigned int temp1 = bits & mask1;
	// bits 0001111
// Copy and store bits 4-6
	unsigned int mask2 = 112;
	unsigned int temp2 = bits & mask2;
	// bits 1110000
// Rearrange bits
	temp1 <<= 3;
	temp2 >>= 4;
// Recombine bits
	unsigned int result = 0;
	result += temp1;
	result += temp2;
	return result;
}


//	MAIN()	FUNCTION

// function main()
// expects command-line argument: password
int main(int count, char *word[]) {

	// Check for the right # of arguments
	if (count != 2)
	{
		printf("Usage: ./Assignment1 'password'\n");
		return 0;
	}

// 0. Get keys
	unsigned *keyOne, *keyTwo;
	keyOne = &key1;
	keyTwo = &key2;
	get_keys(word[1], keyOne, keyTwo);
	
// 1. Convert seven digits to an integer
	char line[8];
	unsigned int bits;
	// Get the next 7 characters of input (leaving space for the null at the end)
	while (fgets(line, 8, stdin))
	{
	// Eliminate the extra execution
		if(line[0] =='\n' || line[0] =='\0') 
		{
			printf("\n");
			return 0;
		}
	// convert to a number
		sscanf(line, "%x", &bits);
		
// 2. Exclusive OR with key2
		bits ^= key2;
		
// 3. Shuffle the Nibbles
		shuffle_nibbles(&bits);
		
// 4. Exclusive OR with key1
		bits ^= key1;
		
// 5. Rotate septets
		char output[5];
		for (int i = 0; i < 4; i++)
		{
	// place septets into array
			 output[i] = rotate_left3(get_n_bits(bits, 7, i));
		}
		
// 6. Translate septets to characters
	// output array with printf()
		for (int i = 3; i >= 0; i--)
		{
			printf("%c", output[i]);
		}
	}
	// Added for cleaner output in terminal.
	printf("\n");
	return 0;
}
