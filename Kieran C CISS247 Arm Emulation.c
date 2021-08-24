// ARM.C - ARM emulator
// CISS 247, Lab 4, Fall, 2020
// Coded by Kieran Bessert 22 Oct 2020 
// Last edited on 25 Oct 2020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>	// Included for use of access()

#define LINES 50
#define FIELDS 5
#define CHARS 10


//	GLOBAL	VARIABLE	DECLARATIONS
int programCounter = 200;
int registers[11]; // Define Registers x0-x10
char memory[LINES][FIELDS][CHARS];

//	HELPER	FUNCTION	DECLARATIONS
void removeChar(char *string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		string[i] = string[i+1];
	}
}

//	INSTRUCTION	FUNCTION	DECLARATIONS
void ADD(char *dest, char *src1, char *src2)
{
	removeChar(dest);
	removeChar(src1);
	removeChar(src2);
	registers[atoi(dest)] = registers[atoi(src1)] + registers[atoi(src2)];
	printf("\tRegisters: X%d = %d, X%d = %d, X%d = %d\n\n", atoi(dest), registers[atoi(dest)], atoi(src1), registers[atoi(src1)], atoi(src2), registers[atoi(src2)]);
}
void ADDI(char *dest, char *src, char *imdt)
{
	removeChar(dest);
	removeChar(src);
	removeChar(imdt);
	registers[atoi(dest)] = registers[atoi(src)] + atoi(imdt);
	printf("\tRegisters: X%d = %d, X%d = %d\n\n", atoi(dest), registers[atoi(dest)], atoi(src), registers[atoi(src)]);
}
void LDUR(char *dest, char *src, char *offset)
{
	removeChar(dest);
	removeChar(src);
	removeChar(src);
	removeChar(offset);
	for (int i = 0; i < LINES; i++)
	{
		if(atoi(memory[i][0]) == (registers[atoi(src)] + atoi(offset)))
		{
			registers[atoi(dest)] = atoi(memory[i][1]);
		}
	}
	printf("\tRegisters: X%d = %d, X%d = %d\n\n", atoi(dest), registers[atoi(dest)], atoi(src), registers[atoi(src)]);
}
void STUR(char *src, char *dest, char *offset)
{
	removeChar(src);
	removeChar(dest);
	removeChar(dest);
	removeChar(offset);
	for (int i = 0; i < LINES; i++)
	{
		if(atoi(memory[i][0]) == (registers[atoi(dest)] + atoi(offset)))
		{
			sprintf(memory[i][1], "%d", registers[atoi(src)]);
		// https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm
		}
	}
	printf("\tRegisters: X%d = %d, X%d = %d\n\n", atoi(src), registers[atoi(src)], atoi(dest), registers[atoi(dest)]);
}
void B(char *branch)
{	
	removeChar(branch);
	programCounter += (atoi(branch) * 4); // Translates words to bytes
}
void SUB(char *dest, char *src1, char *src2)
{
	removeChar(dest);
	removeChar(src1);
	removeChar(src2);
	registers[atoi(dest)] = registers[atoi(src1)] - registers[atoi(src2)];
	printf("\tRegisters: X%d = %d, X%d = %d, X%d = %d\n\n", atoi(dest), registers[atoi(dest)], atoi(src1), registers[atoi(src1)], atoi(src2), registers[atoi(src2)]);
}
void CBZ(char *compare, char *branch)
{
	removeChar(compare);
	removeChar(branch);
	if (registers[atoi(compare)] == 0)
	{
		programCounter += (atoi(branch) * 4); // Translates words to bytes
	}
	printf("\tRegisters: X%s = %d\n\n", compare, registers[atoi(compare)]);
}


//	MAIN()	FUNCTION
// Expects a single argument: "code".txt
int main(int count, char *argv[]) {
	// Test for the correct number of arguments
	if (count != 2)
	{
		printf("SYNTAX ERROR\n\nUSAGE: ./Assignment2 code.txt\n");
		return -1;
	}
	// Test if word list file exists
	if (access(argv[1],F_OK))
	{
		printf("ARGUMENT ERROR\n\nFile does not exist\n");
		return -1;
	}
//	PARSING	(LOADING)	PORTION	PARSING	(LOADING)	PORTION
	FILE *code = fopen(argv[1], "r");
	char buffer[50];
	for (int i = 0; i < LINES; i++)
	{
		fgets(buffer, 50, code);
		sscanf(buffer, "%s %s %s %s %s\n", memory[i][0], memory[i][1], memory[i][2], memory[i][3], memory[i][4]);
	}
//	EXCECUTION	PORTION	EXCECUTION	PORTION	EXCECUTION	PORTION
	int lineCount = 0;	// For tracking progress in the 
	while (lineCount <= LINES)
	{
/*ADD*/	if ((strcmp(memory[lineCount][1], "ADD" ) == 0) && (programCounter == atoi(memory[lineCount][0])))
		{
			printf("PC = %d, Instruction: %s %s %s %s\n", programCounter, memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			ADD(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			programCounter += 4;
			lineCount++;
		}
/*ADDI*/	else if ((strcmp(memory[lineCount][1], "ADDI") == 0) && (programCounter == atoi(memory[lineCount][0])))
		{
			printf("PC = %d, Instruction: %s %s %s %s\n", programCounter, memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			ADDI(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			programCounter += 4;
			lineCount++;
		}
/*LDUR*/	else if ((strcmp(memory[lineCount][1], "LDUR") == 0) && (programCounter == atoi(memory[lineCount][0])))
		{
			printf("PC = %d, Instruction: %s %s %s %s\n", programCounter, memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			LDUR(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			programCounter += 4;
			lineCount++;
		}
/*STUR*/	else if ((strcmp(memory[lineCount][1], "STUR") == 0) && (programCounter == atoi(memory[lineCount][0])))
		{
			printf("PC = %d, Instruction: %s %s %s %s\n", programCounter, memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			STUR(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			programCounter += 4;
			lineCount++;
		}
/*B*/		else if ((strcmp(memory[lineCount][1], "B") == 0) && (programCounter == atoi(memory[lineCount][0])))
		{
			printf("PC = %d, Instruction: %s %s\n\n", programCounter, memory[lineCount][1], memory[lineCount][2]);
			B(memory[lineCount][2]);
			lineCount++;
		}
/*SUB*/	else if ((strcmp(memory[lineCount][1], "SUB") == 0)  && (programCounter == atoi(memory[lineCount][0])))
		{
			printf("PC = %d, Instruction: %s %s %s %s\n", programCounter, memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			SUB(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			programCounter += 4;
			lineCount++;
		}
/*CBZ*/	else if ((strcmp(memory[lineCount][1], "CBZ") == 0) && (programCounter == atoi(memory[lineCount][0])))
		{
			printf("PC = %d, Instruction: %s %s %s\n", programCounter, memory[lineCount][1], memory[lineCount][2], memory[lineCount][3]);
			CBZ(memory[lineCount][2], memory[lineCount][3]);
			lineCount++;
		}
/*OTHER*/	else
		{
			lineCount++;
		}
		
	}
	return 0;
}
