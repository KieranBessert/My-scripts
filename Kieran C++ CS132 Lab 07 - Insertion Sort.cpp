//*****************************************************************************************************************************
//*Kieran C++ CS132 Lab 07 - Insertion Sort.cpp********************************************************************************
//*****************************************************************************************************************************
// This program is used to sort a file containing any number of integers, 
// from lowest to highest, using linked list nodes
// Coded by Kieran Bessert 6/8/2020
// Last edited 6/8/2020
#include <iostream>
#include <fstream>                                          // File I/O
#include <string>                                           // use of Strings
#include <cstdlib>                                          // use of exit() function
using namespace std;
namespace
{
	/***********************CONSTANT VARIABLES***********************/
	const string IN_FILE_NAME = "..\\unsorted127.txt";      // Constant variable for storing name of the input file
	const string OUT_FILE_NAME = "unsorted127_sorted.txt";  // Constant variable for storing name of the output file
	const int MAX_SIZE_INT = 127;							// The maximum number of integers from the file
}
class Unsorted
{
public:
	int value;
	class Unsorted* nextNumber;								// Self-referential structure
};
int main()
{
	ifstream in_stream;                                     // Declare the input file
	ofstream out_stream;                                    // Declare the output file
	class Unsorted* headPtr = NULL;
	class Unsorted* movingPtr;
	class Unsorted* newNode;
	int intCount = 0;
	int choice = 1;
	char exitChoice = 'n';
	in_stream.open(IN_FILE_NAME);                           // Open input file
	if (in_stream.fail())                                   // Check to see if open function fails
	{
		cout << "Input file opening failed.\nFile does not exist.\n";
		return(-1);
	}

	for (int ix = 0; ix <= MAX_SIZE_INT; ix++)              // Import the values from the input file and sort
	{
		newNode = new Unsorted;								// Dynamically create new node
		intCount++;											// Keep track of how many values imported
		in_stream >> newNode->value;						// Store the value from the file in a node
		if (headPtr == NULL)								// Check if no list exists
		{
			headPtr = newNode;								// New node becomes head of list
			headPtr->nextNumber = NULL;
		}
		else if (newNode->value < headPtr->value)			// Add a value to the FRONT of the list
		{
			newNode->nextNumber = headPtr;					// Must not lose this reference
			headPtr = newNode;								// Revise headPtr to reference newNode
		}
		else if (newNode->value > headPtr->value)			// Add a value to the END of the list
		{
			movingPtr = headPtr;							// Find end of list
			do
			{
				if (movingPtr->nextNumber == NULL)			// Add a value to the END of the list
				{ 
					movingPtr->nextNumber = newNode;		// Place newNode to END of list
					newNode->nextNumber = NULL;				// Mark as last node
					break;
				}
				else if ((movingPtr->nextNumber)->value		// Add a value to the MIDDLE of the list
										> newNode->value)
				{ 
					newNode->nextNumber = movingPtr->nextNumber;// Must not lose this reference
					movingPtr->nextNumber = newNode;		// Revise to reference newNode
					break;
				}
				else
				{
					movingPtr = movingPtr->nextNumber;
				}
			} while (true);
		}
	}
	in_stream.close();
	out_stream.open(OUT_FILE_NAME);							// Open the output file
	if (out_stream.fail())									// Checks to see if open function fails
	{
		cout << "Output file opening failed.\n";
		in_stream.close();
		return(-1);
	}
	for (int ix = intCount; ix >= 0; ix--)					// Print Nodes out and release to freestore
	{
		if (headPtr == NULL)								// Check if no list exists
		{
			cout << "\n\t*** END OF LIST ***\n";
		}
		else if ((headPtr->nextNumber) != NULL)
		{
			movingPtr = headPtr;								// Start at head of list
			headPtr = headPtr->nextNumber;						// Move headPtr to next item in list as new head
			cout << headPtr->value << endl;						// Output to screen
			out_stream << headPtr->value << endl;				// Output to file
			delete movingPtr;									// Return memory to freestore
		}
		else if ((headPtr->nextNumber) == NULL)
		{
			movingPtr = headPtr;								// Start at head of list
			headPtr = NULL;										// Set headPtr to null
		}
	}
	out_stream.close();
	return 0;
}

//*****************************************************************************************************************************
//*EXAMPLE ' unsorted127.txt ' FILE********************************************************************************************
//*****************************************************************************************************************************
/*
16
17
18
19
20
116
117
1
119
120
2
200
*/
