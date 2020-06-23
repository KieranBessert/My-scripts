//*****************************************************************************************************************************
//*Kieran C++ CS132 Lab 10 - Templates.cpp*************************************************************************************
//*****************************************************************************************************************************
// This program is used to sort a file containing any number of integers, 
// from lowest to highest, using linked list nodes
// Coded by Kieran Bessert 6/22/2020
// Last edited 6/22/2020
#include <iostream>
#include <fstream>                                          // File I/O
#include <string>                                           // use of Strings
#include <cstdlib>                                          // use of exit() function
using namespace std;
namespace
{
	/***********************CONSTANT VARIABLES***********************/
	//const string IN_FILE_NAME = "..\\unsorted127.txt";      // Constant variable for storing name of the input file
	const string IN_FILE_NAME = "..\\unsortedalphas.txt";      // Constant variable for storing name of the input file
	const int MAX_SIZE_INT = 127;							// The maximum number of integers from the file
}
class Unsorted
{
public:
  //int value;
	char value;
	class Unsorted* nextNumber;								// Self-referential structure
};

template<class myPlaceHolder>
Unsorted* insertNode(myPlaceHolder* headPtr, myPlaceHolder* newNodePtr)
{
	myPlaceHolder* movingPtr;
	if (headPtr == NULL)								// Check if no list exists
	{
		headPtr = newNodePtr;							// New node becomes head of list
		headPtr->nextNumber = NULL;
	}
	else if (newNodePtr->value < headPtr->value)		// Add a value to the FRONT of the list
	{
		newNodePtr->nextNumber = headPtr;				// Must not lose this reference
		headPtr = newNodePtr;							// Revise headPtr to reference newNode
	}
	else if (newNodePtr->value > headPtr->value)		// Add a value to the END of the list
	{
		movingPtr = headPtr;							// Find end of list
		do
		{
			if (movingPtr->nextNumber == NULL)			// Add a value to the END of the list
			{
				movingPtr->nextNumber = newNodePtr;		// Place newNode to END of list
				newNodePtr->nextNumber = NULL;			// Mark as last node
				break;
			}
			else if ((movingPtr->nextNumber)->value		// Add a value to the MIDDLE of the list
										> newNodePtr->value)
			{
				newNodePtr->nextNumber = movingPtr->nextNumber;// Must not lose this reference
				movingPtr->nextNumber = newNodePtr;		// Revise to reference newNode
				break;
			}
			else
			{
				movingPtr = movingPtr->nextNumber;
			}
		} while (true);
	}
	return headPtr;
}

int main()
{
//	declare necessary variables
	ifstream in_stream;									// Declare the input file
	Unsorted* listHead = NULL;
	Unsorted* newNode;
	newNode = new Unsorted;								// Dynamically create new node
	Unsorted* movingPtr;
	int intCount = 0;

//	open file "unsorted127.txt"							// Changeable to "unsortedalphas.txt"
	in_stream.open(IN_FILE_NAME);                       // Open input file
	if (in_stream.fail())                               // Check to see if open function fails
	{
		cout << "Input file opening failed.\nFile does not exist.\n";
		return(-1);
	}

//	set listHead to NULL (Done Above)
//	loop
	for (;; intCount++)     // Import the values from the input file and sort
	{
//		create newNode
		newNode = new Unsorted;							// Dynamically create new node
//		if (read successfully from file into newNode)
		if (in_stream >> newNode->value)
		{
			cout << newNode->value << endl;
//			listHead = insertNode(listHead, newNode)
			listHead = insertNode(listHead, newNode);
//			loop up
		}
//		else
		else
		{
//			delete the unused node
			delete newNode;								// Return memory to freestore
//			close the file
			in_stream.close();
//			break out of loop
			break;
		}
//	end of loop
	}

//	display the list contents to cout
	movingPtr = listHead;
	for (int ix = intCount; ix >= 0; ix--)				// Print Nodes out and release to freestore
	{
		if (listHead == NULL)							// Check if no list exists
		{
			cout << "\n\t*** END OF LIST ***\n";
		}
		else if ((listHead->nextNumber) != NULL)
		{
			movingPtr = listHead;						// Start at head of list
			cout << listHead->value << endl;			// Output to screen
			listHead = listHead->nextNumber;			// Move headPtr to next item in list as new head
			delete movingPtr;							// Return memory to freestore
		}
		else if ((listHead->nextNumber) == NULL)
		{
			movingPtr = listHead;						// Start at head of list
			listHead = NULL;							// Set headPtr to null
		}
	}
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


//*****************************************************************************************************************************
//*EXAMPLE ' unsortedalphas.txt ' FILE*****************************************************************************************
//*****************************************************************************************************************************
/*
*/
