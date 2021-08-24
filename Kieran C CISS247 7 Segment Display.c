// Assignment3.c - Seven Segment Displays 
// CISS 247, Assignment1 3, Fall, 2020
// Coded by Kieran Bessert 17 Nov 2020 
// Last edited on 17 Nov 2020
#include <stdio.h>
#include <string.h>	// for use of strlen()
#include <ctype.h>	// for use of isalpha()
#include <stdlib.h>	// for use of atoi()

#define MAX	10		// Set max size of input integer
#define ZERO	48
#define ONE	49
#define TWO	50
#define THREE	51
#define FOUR	52
#define FIVE	53
#define SIX	54
#define SEVEN	55
#define EIGHT	56
#define NINE	57

//	GLOBAL	VARIABLE	DECLARATIONS
int negitive = 0;

//	FUNCTION	DECLARATIONS

// Display the top zone characters for one digit.
void displayOneTop(int value){
	if (value == ONE || value == FOUR)	// Uses ASCII Values for numbers
	{
		printf("   ");
	}
	else if (value == ZERO || value == TWO || value == THREE || value == FIVE || value == SIX || value == SEVEN || value == EIGHT || value == NINE)
	{
		printf(" _ ");
	}
}
// Display the top zone characters for all the digits in the number.
void displayAllTop(char *value){
	if (negitive != 0)
	{
		printf("   ");
	}
	for (int i = 0; i < strlen(value); i++)
	{
		displayOneTop(value[i]);
	}
	printf("\n");
}
// Display the middle zone characters for one digit.
void displayOneMid(int value){
	if (value == ZERO)	// Uses ASCII Values for numbers
	{
		printf("| |");
	}
	else if (value == ONE || value == SEVEN)
	{
		printf("  |");
	}
	else if (value == TWO || value == THREE)
	{
		printf(" _|");
	}
	else if (value == FIVE || value == SIX )
	{
		printf("|_ ");
	}
	else if (value == FOUR || value == EIGHT || value == NINE)
	{
		printf("|_|");
	}
}
// Display the middle zone characters for all the digits in the number.
void displayAllMid(char *value){
	if (negitive != 0)
	{
		printf(" _ ");
	}
	for (int i = 0; i < strlen(value); i++)
	{
		displayOneMid(value[i]);
	}
	printf("\n");
}
// Display the bottom zone characters for one digit.
void displayOneBot(int value){
	if (value == ZERO || value == SIX || value == EIGHT)	// Uses ASCII Values for numbers
	{
		printf("|_|");
	}
	else if (value == ONE || value == FOUR || value == SEVEN)
	{
		printf("  |");
	}
	else if ( value == THREE || value == FIVE || value == NINE)
	{
		printf(" _|");
	}
	else if (value == TWO)
	{
		printf("|_ ");
	}
}
// Display the bottom zone characters for all the digits in the number.
void displayAllBot(char *value){
	if (negitive != 0)
	{
		printf("   ");
	}
	for (int i = 0; i < strlen(value); i++)
	{
		displayOneBot(value[i]);
	}
	printf("\n");
}


//	MAIN()	FUNCTION	DECLARATION
// Expects an integer command-line argument: 1023, -85, 9, ect
int main(int count, char *argv[]) {
	// check for the correct number of command-line arguments
	if (count != 2)
	{
		printf("Usage:\n\t ./Assignment3 '#'\n");
		return 1;
	} 
	// check for non-numeric input
	for (int i = 0; i < strlen(argv[1]); i++)
	{
		if (isalpha(argv[1][i]) != 0)
		{
			printf("ERROR:\n\tImproper input value\n");
			return 2;
		}
	}
	// Check for negitive value
	if (atoi(argv[1]) < 0)
	{
		negitive = 1;
		for(int i = 0; i < strlen(argv[1]); i++)
		{
			argv[1][i] = argv[1][(i+1)]; // Shift string to remove negative sign
		}
	}
	displayAllTop(argv[1]);
	displayAllMid(argv[1]);
	displayAllBot(argv[1]);
	return 0;
}
