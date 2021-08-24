// Assignment2.c - Spelling Correction Program
// CISS 247, Assignment1 1, Fall, 2020
// Coded by Kieran Bessert 19 Oct 2020 
// Last edited on 27 Oct 2020
#include <stdio.h>
#include <string.h>
#include <unistd.h>	// Included for use of access()
#include <ctype.h>	// Included for use of tolower()

#define MAX_WORD_LEN 40
#define MAX_WORDS 110000

//	GLOBAL	VARIABLE	DECLARATIONS
char wordList[MAX_WORDS][MAX_WORD_LEN];


//	FUNCTION	DECLARATIONS
// Loads the word-list from the supplied data file.
void getWordList(FILE *file)
{
	for (int i = 0; fgets(wordList[i], MAX_WORD_LEN, file); i++)
	{
	// removes '\n' at the end of each entry
		int length;
		length = strlen(wordList[i]);
		if( wordList[i][length-1] == '\n' )
		{
		    	wordList[i][length-1] = 0;
		}
	}
}

// Determines the Hamming distance between two words. Pass the two words as parameters to the function and have the function return their Hamming distance as an integer.
int getHammingDistance(char stringA[], char stringB[])
{
	if (strlen(stringA) != strlen(stringB))
	{
		return -1;
	}
	int count = 0;
	for (int i = 0; i < strlen(stringA); i++)
	{
		if (stringA[i] != stringB[i]) 
		{
			count++;
		}
	}
	return count;
}


//	MAIN()	FUNCTION	DECLARATION
// Expects command-line argument: "input_file".txt
int main(int count, char *argv[]) {
	// Test for the correct number of arguments
	if (count != 2)
	{
		printf("SYNTAX ERROR\n\nUSAGE: ./Assignment2 wordsEn.txt\n");
		return 1;
	}
	// Test if word list file exists
	if (access(argv[1],F_OK))
	{
		printf("ARGUMENT ERROR\n\nFile does not exist\n");
		return 1;
	}
// Read in and store word list file
	FILE *input = fopen(argv[1], "r");
	getWordList(input);
// Prompt for and store word to be checked
	char word[MAX_WORD_LEN];
	while (strlen(word) >= 1)
	{
		puts("\nPlease enter a word to spellcheck, or press 'Enter' to exit:\n\n\t");
		fgets(word, MAX_WORD_LEN, stdin);
		// Test for exit condition
		if (strlen(word) == 1)
		{
			puts("\tGoodbye!\n");
			return 1;
		}
// Convert string to lowercase
		int length = strlen(word);
		for (int i = 0; word[i]; i++)
		{
			word[i] = tolower(word[i]);
			// remove '\n' at the end of entry
			if( word[length-1] == '\n' )
			{
			    	word[length-1] = 0;
			}
		}
// Parse through the word list for exact matches
		unsigned int match = 1;	// Used for selecting output
		for (int i = 0; i < MAX_WORDS; i++)
		{
		// Compare input word to all word list entries
			if (strcmp(word, wordList[i]) == 0)
			{
				printf("Match Found! %s\n\n", word);
				match = 0;
			}
		}
// Suggests one or more words from the word list as alternatives.
		if (match != 0)
		{
			printf("\nNo match found for %s.\n\n", word);
			for (int j = 1; j < strlen(word); j++)
			{
				int count = 0; // To count number of suggestions given
				for (int i = 0; i < MAX_WORDS; i++)
				{	
					int ham = getHammingDistance(word, wordList[i]);
					if ((ham == j) && (count < 5))
					{
						printf("%s has a hamming distance of %d.\n", wordList[i], ham);
						count++;
					}
				}
			}
		}	
	}
}
