// Lab 1 - Review
// This Script takes input data from a file or console, 
// capitalizes portions of that data,
// then outputs the data to either, a file, the console or both.
//
// coded by Kieran Bessert 4/14/2020
// Last edited on 4/23/2020

#include <iostream>
#include <cstdlib>          // Included for use of exit() function
#include <fstream>          // Included to use files as I/O 
#include <string>           // This provides support for C++ string "objects"
using namespace std;

struct PII                  // Declare the struct that will contain the information of each person
{
    string last4ssn,        // SSN declared as a string to include socials with leading 0s
        nameFirst, nameLast, emailAddress;
}person1 = { "1234", "Jane", "Doe", "jdoe@gmail.com" };

ifstream in_stream;         // Declare the input file stream
ofstream out_stream;        // Declare the output file stream

void rdPerson(istream& inStream, PII& p1);
// This function recieves input from input stream
// and passes it to makeUC().
//
//Precon: An empty struct of type PII to be filled
// by either user at console or by opened ifstream.
//Postcon: Changed values for nameFirst and nameLast of 1 struct of type PII.
void makeUC(PII& p1);
// This function recieves a struct of type PII from rdPerson()
// and capitalizes values for nameFirst and nameLast.
//
//Precon: An struct of type PII to be processed
//Postcon: Changed values for nameFirst and nameLast of 1 struct of type PII.
void wtPerson(ofstream& outStream, PII& p1);
// This function recieves a struct of type PII
// and outputs the value to console and optionally to file.
//
//Precon: An struct of type PII to be processed.
//Postcon: Format and print to screen struct, optionally to output file.

int main()
{
    string In_File_Name;
    int choice(1);                      // Variable for processing decision, File or Console

    cout << "WELCOME TO THE NAME CAPITALIZER!!!\n" << endl;
    cout << endl << "Do you wish to enter information MANUALLY or from a FILE?\n"
        << "Press 2 for MANUALLY\n" << "Press 1 for FILE\n" << "Press 0 to EXIT\n" << endl;
    cin >> choice;
    if (choice == 2)
    {
        out_stream.open("output.txt");  // Open the output file, creates if it does not exsist.
        if (out_stream.fail())          // Checks to see if open function fails
        {
            cout << "Output file opening failed.\n";
            exit(1);
        }
        do {                            // Loop Body always runs once
            cout << endl << "Please enter the following information of the person;\n" << endl
                << "last4social\t" << "firstname\t" << "lastname\t" << "emailaddress\n" << endl
                << "[[IMPORTANT: PLEASE SEPERATE EACH ITEM WITH A TAB]]\n" << endl;
            rdPerson(cin, person1);
            wtPerson(out_stream, person1);
            cout << endl << "Do you wish to continue?\n"
                << "Press 1 for YES\n" << "Press 0 to EXIT\n" << endl;
            cin >> choice;
        } while (choice != 0);
    }
    else if (choice == 1)
    {
        cout << "Enter the input file name.\n";
        cout << "[The default file is ' persons.txt ']\n" << endl;
        cin >> In_File_Name;            // The input file that contains peoples information
        in_stream.open(In_File_Name);   // Open input file
        if (in_stream.fail())           // Check to see if open function fails
        {
            cout << "Input file opening failed.\n";
            exit(1);
        }
        out_stream.open("output.txt");  // Open the output file, creates if it does not exsist.
        if (out_stream.fail())          // Checks to see if open function fails
        {
            cout << "Output file opening failed.\n";
            exit(1);
        }
        do {                            // Loop Body always runs once
            rdPerson(in_stream, person1);
            wtPerson(out_stream, person1);
            cout << endl << "Do you wish to continue?\n"
                << "Press 1 for YES\n" << "Press 0 to EXIT\n" << endl;
            cin >> choice;
        } while (choice != 0);
    }
    else
    {
        exit(0);
    }
    in_stream.close();                  // Close input file
    out_stream.close();                 // Close output file
    return 0;
}

void rdPerson(istream& inStream, PII& p1)
{
    string temp;
    char ch;
    ch = getchar();
            // Moves the character forward one for console input formatting
    getline(inStream, temp, '\t');
    p1.last4ssn = temp;
    getline(inStream, temp, '\t');
    p1.nameFirst = temp;
    getline(inStream, temp, '\t');
    p1.nameLast = temp;
    getline(inStream, temp, '\n');
    p1.emailAddress = temp;
    makeUC(p1);
}
void makeUC(PII& p1)
{
    for (int i = 0; i < p1.nameFirst.size(); i++)
        p1.nameFirst[i] = toupper(p1.nameFirst[i]);
            // Letter by letter capitalization for first name.
    for (int i = 0; i < p1.nameLast.size(); i++)
        p1.nameLast[i] = toupper(p1.nameLast[i]);
            // Letter by letter capitalization for last name.
}
void wtPerson(ofstream& outStream, PII& p1)
{
    cout << endl << p1.nameLast << ", " << p1.nameFirst <<
        ":"<< p1.last4ssn << ":" << p1.emailAddress << endl;
            // Outputs to console
    outStream << p1.nameLast << ", " << p1.nameFirst <<
        ":" << p1.last4ssn << ":" << p1.emailAddress << endl;
            // Outputs to the opened output file, comment out to remove functionality.
}

/* EXAMPLE ' persons.txt ' FILE */
/*
5555	luke	skywalker	Red5@RebelAlliance.com
1111	han	solo	DirtyScoundrel@CaptainMelleniumFalcon.com
3333	leia	organa	AlderaanPrincess@Alderaan.com
0202	r2	d2	BeepBoop@BoopBeep.com
3390	c3	p0	GoodnessGraciousMe@mindlessphilosopher.com
0000	lando	calrissian	Administrator@CloudCity.org
*/
