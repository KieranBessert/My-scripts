// floatbits.c - Floating Point
// CISS 247, Lab 6, Fall, 2020
// Coded by Kieran Bessert 4 Nov 2020 
// Last edited on 7 Nov 2020
#include <stdio.h>

typedef unsigned float_bits;

int float_class(float_bits *f)
{
	int mask = 255;
	unsigned int exponent = (*f >> 23);
	exponent = exponent & mask;
	exponent += 1;
	exponent = exponent & ~1;
	exponent = exponent << 23;
	return exponent;
}
float_bits float_negate(float_bits *f)
{
	int mask = 1;
	mask = mask << 31;
	*f = *f ^ mask;
	return *f;
}
float_bits float_absval(float_bits *f)
{
	int mask = 1;
	mask = mask << 31;
	mask = ~mask;
	*f = *f & mask;
	return *f;
}

float_bits float_twice(float_bits *f)
{
	int mask = 1;
	mask = mask << 23;
	*f += mask;
	return *f;
}

float_bits float_half(float_bits *f)
{
	int mask = 1;
	mask = ~mask;
	mask = mask << 22;
	*f += mask;
	return *f;
}


int main(int argc, char *argv[]) {
	float_bits fbits;
	sscanf(argv[1], "%f", (float *)&fbits);
	float *f = (float*)&fbits;
	printf("Input Value Test:\n");
	printf("\t- Negative int, floating-point number is “special” (±∞, or NaN).\n");
	printf("\t- Zero, floating-point number is denormalized.\n");
	printf("\t- Positive int, floating-point number is normalized\n");
	printf("  %d\n\n", float_class(&fbits));
	printf("Pre-Negate: %e\n", *f);
	fbits = float_negate(&fbits);
	f = (float*)&fbits;
	printf("Post-Negate: %e\n\n", *f);
	printf("Pre-Absolute: %e\n", *f);
	fbits = float_absval(&fbits);
	f = (float*)&fbits;
	printf("Post-Absolute: %e\n\n", *f);
	printf("Pre-Double: %e\n", *f);
	fbits = float_twice(&fbits);
	f = (float*)&fbits;
	printf("Post-Double: %e\n\n", *f);
	printf("Pre-Half: %e\n", *f);
	fbits = float_half(&fbits);
	f = (float*)&fbits;
	printf("Post-Half: %e\n\n", *f);
}
