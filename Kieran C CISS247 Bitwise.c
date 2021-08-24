// bits.c - Bitwise Logical Operations
// CSCI 247, Lab 3, Fall, 2020
// Coded by Kieran Bessert 15 oct 2020 
// Last edited on 17 Oct 2020
#include <stdio.h>
#include <string.h>


//	FUNCTION	DECLARATIONS


// Write a function to compute the bit-wise AND of two integers, using only the ~ and |
// For example, func1(5, 6) equals 4.  (0101 & 0110 = 0100)
int func1(int x, int y){
	/* Because OR can only operate on 1s,
	the compliment is taken of each variable to operate on the 0s.
	The result of the OR collects where 0s exist in either variable.
	A compliment of the result reconverts the 0s,
	only leaving the bits where both variables originally held 1s.*/
	//
	//  x = 00000101
	//  y = 00000111
	//  & = 00000101
	//
	// ~x = 11111010
	// ~y = 11111000
	//
	//  | = 11111010
	// ~| = 00000101
	return ~(~x | ~y);
}

// Write a function to compute the bit-wise exclusive-or of two integers, using only the ~ and & operators.
// For example, func2(4, 5) equals 1.  (0100 ^ 0101 = 0001).
int func2(int x, int y){
 	/*and1 collects the data of where 1s exist in both variables.
 	and2 collects the data of where values match and differ in both variables.
 	&ing the compliments of these new variables result in 
 	and1 turning off the bits in and2 where both variabls contain 1s,
 	leaving only bits that differ.*/
 	//
	// x = 00000100
	// y = 00000101
	// ^ = 00000001
	int and1, and2;
	and1 = x & y;
	// x = 00000100
	// y = 00000101
	// & = 00000100
	and1 = ~and1;
	//~& = 11111011
	and2 = ~x & ~y;
	//~x = 11111011
	//~y = 11111010
	// & = 11111010
	and2 = ~and2;
	//~& = 00000101
	return (and1 & and2);
	//~( &) = 11111011
	//~(~&) = 00000101
	//   &  = 00000001
}

// Write a function to return 1 if any odd-numbered bit in an integer is set to 1, and return 0 otherwise. (The least significant bit is bit number 0).
// For example, func3(0x7) should return 1, func3(0x5) should return 0
int func3(int x){
	/*Only the odd bits of the variable are saved for processing,
	this is done by &ing the variable and the mask.
	The first ! shows the opposite of value present, simplifying the value.
	The second ! corrects the answer back to the truth.*/
	//
	// 0x5 = 00000101 = 0
	// 0x7 = 00000111 = 1
	int mask = 0xAA;
	mask <<= 8;
	mask += 0xAA;
	mask <<= 8;
	mask += 0xAA;
	mask <<= 8;
	mask += 0xAA;
	// mask = 10101010 10101010 10101010 10101010
	return !!(x & mask);
}

// Write a function to return 1 if all the odd-numbered bits in an integer are set to 1, and return 0 otherwise.
//For example, func4(0xFFFFFFFD) should return 0, func4(0xAAAAAAAA) should return 1
int func4(int x){
	/*Only the odd bits of the variable are saved for processing,
	this is done by &ing the variable and the mask.
	Odd bits are checked for differing values against mask with XOR,
	if values differ then not all of the bits contain 1s.
	the ! corrects the answer, if value present then failure.*/
	//
	// FFFFFFFD = 11111111111111111111111111111101 = 0
	// FFFFFFFF = 11111111111111111111111111111111 = 1
	// AAAAAAAA = 10101010101010101010101010101010 = 1
	int temp = 0;
	int mask = 0xAA;
	mask <<= 8;
	mask += 0xAA;
	mask <<= 8;
	mask += 0xAA;
	mask <<= 8;
	mask += 0xAA;
	// mask = 10101010101010101010101010101010
	temp = x & mask;
	// x    = 11111111111111111111111111111101
	// mask = 10101010101010101010101010101010
	//&temp = 10101010101010101010101010101000
	temp ^= mask;
	// mask = 10101010101010101010101010101010
	// temp = 10101010101010101010101010101000
	// XOR  = 00000000000000000000000000000010
	return !temp;
}


//	MAIN()	FUNCTION

int main(int count, char *word[]) {
	printf("Function1 input: 0x5, 0x6\nFunction1 output: %0#x\n\n", func1(5, 6));
	printf("Function1 input: 0x1, 0x3\nFunction1 output: %0#x\n\n", func1(1, 3));
	printf("Function2 input: 0x4, 0x5\nFunction2 output: %0#x\n\n", func2(4, 5));
	printf("Function2 input: 0x1, 0x3\nFunction2 output: %0#x\n\n", func2(1, 3));
	printf("Function3 input: 0x7\nFunction3 output: %0#x\n\n", func3(0x7));
	printf("Function3 input: 0x5\nFunction3 output: %0#x\n\n", func3(0x5));
	printf("Function4 input: 0xFFFFFFFD\nFunction4 output: %0#x\n\n", func4(0xFFFFFFFD));
	printf("Function4 input: 0xAAAAAAAA\nFunction4 output: %0#x\n\n", func4(0xAAAAAAAA));
	return 0;
}
