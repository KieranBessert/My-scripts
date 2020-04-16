// This program takes its input from a file of numbers of type int and calculates;
// - The total number of values, 
// - The average of all numbers (as a double),
// - The Min and Max number in the file 
// The program then writes these to the screen and as an output file.
// Created by Kieran Bessert 3/3/2020
// Last edited 3/4/2020

#include <iostream>
#include <fstream>  // Included to use files as I/O 
#include <cstdlib>  // Included to use the exit() function
using namespace std;

ifstream in_stream;
ofstream out_stream;

void close_files();
// Precondition: Opened I/O File streams
// Postcondition: Closes the I/O File Streams

int main()
{
    char In_File_Name[16];
    cout << "Enter the input file name (maximum of 15 characters)\n";
    cout << "[The default file is ' input.dat ']\n" << endl;
    cin >> In_File_Name;            // The input file contains nothing but numbers of type int separated by blanks or line breaks.  
                                    // There may be positive, negative, or 0 values in the list.


    in_stream.open(In_File_Name);   // Open input file
    if (in_stream.fail())           // Check to see if open function fails
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    out_stream.open("output.dat");  // Open the output file
                                    // Output to the screen and file are identical
    if (out_stream.fail())          // Checks to see if open function fails
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }


    int next,           // Next number in the file, one by one from top to bottom
        count(0),       // Keeps count of how many numbers are in the file
        min(INT_MAX),         // set variable min to the maximum number possible
        max(INT_MIN);         // Set variable max to the minimum number possible
    double sum(0.0);

    while (in_stream >> next)
    {
        if (next < min)     // If the value being read by the program is lower than min 
        {
            min = next;     // Replace the value of min with the new number
        }
        if (next > max)     // If the Value being read by the program is higher than max
        {
            max = next;     // Replace the value of max with the new number
        }

        sum = sum + next;   // Add the number currently being read to the sum for avreging later
        count++;            // Increment count to track the number of values from the file
    }


    cout.setf(ios::fixed);              // Set the decimal point
    cout.setf(ios::showpoint);          // to 2 spaces
    cout.precision(2);                  // for the AVG value

    cout << endl << "The input file "   // Display the information to the screen
        << In_File_Name << " contains " << count << " values." << endl
        << "The smallest value is " << min << endl
        << "The Largest value is " << max << endl
        << "The average of all the values is " << (sum / count) << endl;

    out_stream << "The input file "     // Place the information displayed on screen to the output file
        << In_File_Name << " contains " << count << " values." << endl
        << "The smallest value is " << min << endl
        << "The Largest value is " << max << endl
        << "The average of all the values is " << (sum / count) << endl;

    close_files();                      // Calls a function to close the I/O stream files.

    return 0;
}

void close_files()
{
    in_stream.close();              // Close input file
    out_stream.close();             // Close output file
}

// input.dat values;
/*
5
34
124
76
-97
223
45
17
22
153
0
-5
943
12
34
*/
