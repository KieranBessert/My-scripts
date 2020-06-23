//*****************************************************************************************************************************
//*Kieran C++ CS132 Lab 09 - Exception Handling.cpp****************************************************************************
//*****************************************************************************************************************************
// This program is used to demonstrait the usage of Exception Handlers
// Coded by Kieran Bessert 6/17/2020
// Last edited 6/18/2020
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace 
{
	ifstream inF;	// Un-named namespace, variable is global to this file
}
class Errors		// Class for Error Handling
{
public:
	Errors() {}
	Errors(string s, int i) { strError = s; intError = i; }
	string getStrError() { return strError; }
	int getIntError() { return intError; }
private:
	string strError = "Error";
	int intError = -1;
};

struct tNode
{
	char content;
	tNode* leftN;
	tNode* rightN;
};

tNode* buildTree(int depth, tNode* subRoot) throw (Errors)
{
	tNode* localP; // Simple local variable
	if (depth > 0) // Skips functionality once "depth" decrements to 0
	{
		depth--; // Decrement toward "stopping" case
		localP = new tNode; // Create a new node...
		subRoot = localP;

		inF >> localP->content;
		if (!inF)
		{
			throw Errors("Too Few Values in File", depth);
		}
		cout << localP->content << " ";

		localP->leftN = buildTree(depth, NULL);
		localP->rightN = buildTree(depth, NULL);
	}
	return(subRoot); // Return the pointer to the sub-tree.
}

void printMSDigitFirst(int digitsPassedToMe) {

	int digitToPrintInThisInvocation = digitsPassedToMe % 10;  // Store the LEAST-significant of the "digitsPassedToMe"
	int higherOrderDigits = digitsPassedToMe / 10; // Make problem "smaller" for next invocation
	if (higherOrderDigits != 0) // Test for "stopping case".  Any higher-order digits remaining?
	{
		printMSDigitFirst(higherOrderDigits);  // Recursive call with "smaller" task
	}
	cout << digitToPrintInThisInvocation;
}

int main()
{
	int depth(0); // Target depth of tree
	char temp;
	try
	{
		inF.open("..\\treedecode.txt");  // Are you doing ERROR CHECK on file open?
		if (!inF)		// no file found
		{
			throw (string) "File Not Found";
		}
		inF >> depth; // First thing in file is int identifying the depth of the tree
		cout << "Depth = " << depth << endl;
		tNode* root = NULL; // Pointer that will point to ENTIRE tree
		root = buildTree(depth, root);
		if (inF >> temp)
		{
			throw Errors("Too Many Values in File", depth);
		}
		cout << endl;
	}
	catch (Errors e)
	{
		cout << endl << e.getStrError() << " " << e.getIntError() << endl << endl;
	}
	catch (string s)
	{
		cout << endl << s << endl << endl;
	}
	catch (...)
	{
		cout << endl << "Unexpected Error" << endl << endl;
	}
	inF.close();
	return 0;
}

