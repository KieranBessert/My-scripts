// ARM2.C - ARM emulator w/ Stack functionality
// CISS 247, Lab 5, Fall, 2020
// Coded by Kieran Bessert 29 Oct 2020 
// Last edited on 31 Oct 2020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>	// Included for use of access()

#define LINES 200
#define FIELDS 5
#define CHARS 10
#define SP_MIN_VALUE 400

//	GLOBAL	VARIABLE	DECLARATIONS
int registers[32]; // Define Registers x0-x31; SP (X28), LR (X30)
const int XZR = 0;
char memory[LINES][FIELDS][CHARS];
int programCounter = 200;	//Initilize the Program Counter

//	HELPER	FUNCTION	DECLARATIONS
void removeChar(char *string)
{
	for (int i = 0; i < strlen(string); i++)
	{
		string[i] = string[i+1];
	}
}
void pcRoutine()
{
	programCounter += 4;
	printf("\tPC = %d\n\n", programCounter);
}
void stackRoutine()
{
	if(registers[28] != ((LINES*4)+100))
	{
		for(int i = 0; (registers[28] + (i*4)) <= ((LINES*4)+100); i++)
		{
			int temp = ((registers[28] - 100)/4) + (i);
			printf("\tStack: %s = %s\n", memory[temp][0], memory[temp][1]);
		}
		printf("\n");	// For Formatting
	}
}

//	INSTRUCTION	FUNCTION	DECLARATIONS
void ADD(char *dest, char *src1, char *src2)
{
	if (dest[0] == 'X' || dest[0] == 'x')
		removeChar(dest);
	if (src1[0] == 'X' || src1[0] == 'x')
		removeChar(src1);
	if (src2[0] == 'X' || src2[0] == 'x')
		removeChar(src2);
	registers[atoi(dest)] = registers[atoi(src1)] + registers[atoi(src2)];
	printf("\tRegisters: X%d = %d, X%d = %d, X%d = %d\n", atoi(dest), registers[atoi(dest)], atoi(src1), registers[atoi(src1)], atoi(src2), registers[atoi(src2)]);
}
void SUB(char *dest, char *src1, char *src2)
{
	if (dest[0] == 'X' || dest[0] == 'x')
		removeChar(dest);
	if (src1[0] == 'X' || src1[0] == 'x')
		removeChar(src1);
	if (src2[0] == 'X' || src2[0] == 'x')
		removeChar(src2);
	registers[atoi(dest)] = registers[atoi(src1)] - registers[atoi(src2)];
	printf("\tRegisters: X%d = %d, X%d = %d, X%d = %d\n", atoi(dest), registers[atoi(dest)], atoi(src1), registers[atoi(src1)], atoi(src2), registers[atoi(src2)]);
}
void ADDI(char *dest, char *src, char *imdt)
{
	if (dest[0] == 'X' || dest[0] == 'x')
		removeChar(dest);
	if (src[0] == 'X' || src[0] == 'x')
		removeChar(src);
	if (imdt[0] == '#')
		removeChar(imdt);
	registers[atoi(dest)] = registers[atoi(src)] + atoi(imdt);
	printf("\tRegisters: X%d = %d, X%d = %d\n", atoi(dest), registers[atoi(dest)], atoi(src), registers[atoi(src)]);
}
void SUBI(char *dest, char *src, char *imdt)
{
	if (dest[0] == 'X' || dest[0] == 'x')
		removeChar(dest);
	if (src[0] == 'X' || src[0] == 'x')
		removeChar(src);
	if (imdt[0] == '#')
		removeChar(imdt);
	registers[atoi(dest)] = registers[atoi(src)] - atoi(imdt);
	printf("\tRegisters: X%d = %d, X%d = %d\n", atoi(dest), registers[atoi(dest)], atoi(src), registers[atoi(src)]);
}
void LDUR(char *dest, char *src, char *offset)
{
	if (dest[0] == 'X' || dest[0] == 'x')
		removeChar(dest);
	if (src[0] == '[')
		removeChar(src);
	if (src[0] == 'X' || src[0] == 'x')
		removeChar(src);
	if (offset[0] == '#')
	removeChar(offset);
	for (int i = 0; i <= LINES; i++)
	{
		if(atoi(memory[i][0]) == (registers[atoi(src)] + atoi(offset)))
		{
			registers[atoi(dest)] = atoi(memory[i][1]);
		}
	}
	printf("\tRegisters: X%d = %d, X%d = %d\n", atoi(dest), registers[atoi(dest)], atoi(src), registers[atoi(src)]);
}
void STUR(char *src, char *dest, char *offset)
{
	if (src[0] == 'X' || src[0] == 'x')
		removeChar(src);
	if (dest[0] == '[')
		removeChar(dest);
	if (dest[0] == 'X' || dest[0] == 'x')
		removeChar(dest);
	if (offset[0] == '#')
		removeChar(offset);
	for (int i = 0; i <= LINES; i++)
	{
		if(atoi(memory[i][0]) == (registers[atoi(dest)] + atoi(offset)))
		{
			sprintf(memory[i][1], "%d", registers[atoi(src)]);
		}
	}
	printf("\tRegisters: X%d = %d, X%d = %d\n", atoi(src), registers[atoi(src)], atoi(dest), registers[atoi(dest)]);
}
void B(char *branch) // BRANCH
{	
	if (branch[0] == '#')
		removeChar(branch);
	programCounter += (atoi(branch) * 4); // Translates words to bytes
}
void BL(char *branch) // BRANCH with Link
{
	if (branch[0] == '#')
		removeChar(branch);
	registers[30] = programCounter + 4; // Stores ProgramCounter in LinkRegister[30]
	programCounter += (atoi(branch) * 4); // Translates words to bytes
	printf("\tLink Register X30 = %d\n\n", registers[30]);
}
void BR(char *branch) // BRANCH to Register
{
	if (branch[0] == 'X' || branch[0] == 'x')
		removeChar(branch);
	programCounter = registers[atoi(branch)]; // Retrieves Address from register
	printf("\tRegisters: X%d = %d\n\n", atoi(branch), registers[atoi(branch)]);
}
void CBZ(char *compare, char *branch)
{
	if (compare[0] == 'X' || compare[0] == 'x')
		removeChar(compare);
	if (branch[0] == '#')
		removeChar(branch);
	if ((registers[atoi(compare)] == 0))
	{
		programCounter += (atoi(branch) * 4); // Translates words to bytes
	}
	else
	{
		pcRoutine();
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
	for (int i = 0; i <= LINES; i++)
	{
		fgets(buffer, 50, code);
		sscanf(buffer, "%s %s %s %s %s\n", memory[i][0], memory[i][1], memory[i][2], memory[i][3], memory[i][4]);
	}
//	EXCECUTION	PORTION	EXCECUTION	PORTION	EXCECUTION	PORTION
	for(int i = 0; i < 32; i++)
	{
		registers[i] = 0; // Initilize the registers
	}
	registers[28] = atoi(memory[LINES][0]);	// Initilize the Stack Pointer
	while (XZR == 0)
	{
		int lineCount = ((programCounter - 100) / 4);	// For tracking progress through instructions
		if(registers[28] <= SP_MIN_VALUE)	// Check for Stack overflow
		{
			printf("\tERROR: Stack Overflow\n");
			return -1;
		}
		
/*ADD*/	if ((strcmp(memory[lineCount][1], "ADD" ) == 0))
		{
			printf("Instruction: %s %s %s %s\n", memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			ADD(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			pcRoutine();
			stackRoutine();
		}
/*SUB*/	else if ((strcmp(memory[lineCount][1], "SUB") == 0))
		{
			printf("Instruction: %s %s %s %s\n", memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			SUB(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			pcRoutine();
			stackRoutine();
		}
/*ADDI*/	else if ((strcmp(memory[lineCount][1], "ADDI") == 0))
		{
			printf("Instruction: %s %s %s %s\n", memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			ADDI(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			pcRoutine();
			stackRoutine();
		}
/*SUBI*/	else if ((strcmp(memory[lineCount][1], "SUBI") == 0))
		{
			printf("Instruction: %s %s %s %s\n", memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			SUBI(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			pcRoutine();
			stackRoutine();
		}
/*LDUR*/	else if ((strcmp(memory[lineCount][1], "LDUR") == 0))
		{
			printf("Instruction: %s %s %s %s\n", memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			LDUR(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			pcRoutine();
			stackRoutine();
		}
/*STUR*/	else if ((strcmp(memory[lineCount][1], "STUR") == 0))
		{
			printf("Instruction: %s %s %s %s\n", memory[lineCount][1], memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			STUR(memory[lineCount][2], memory[lineCount][3], memory[lineCount][4]);
			pcRoutine();
			stackRoutine();
		}
/*B*/		else if ((strcmp(memory[lineCount][1], "B") == 0))
		{
			printf("Instruction: %s %s\n\n", memory[lineCount][1], memory[lineCount][2]);
			B(memory[lineCount][2]);
		}
/*BL*/		else if ((strcmp(memory[lineCount][1], "BL") == 0))
		{
			printf("Instruction: %s %s\n", memory[lineCount][1], memory[lineCount][2]);
			BL(memory[lineCount][2]);
		}
/*BR*/		else if ((strcmp(memory[lineCount][1], "BR") == 0))
		{
			printf("Instruction: %s %s\n", memory[lineCount][1], memory[lineCount][2]);
			if (strcmp(memory[lineCount][2], "XZR") == 0)
			{
				puts("\tTerminating Program Successfully");
				return 0;
			}
			BR(memory[lineCount][2]);
		}
/*CBZ*/	else if ((strcmp(memory[lineCount][1], "CBZ") == 0))
		{
			printf("Instruction: %s %s %s\n", memory[lineCount][1], memory[lineCount][2], memory[lineCount][3]);
			CBZ(memory[lineCount][2], memory[lineCount][3]);
		}
/*OTHER*/	else
		{
			//printf("\tBONK") //	FOR	TESTING	USE	ONLY
		}
	}
	return 0;
}
