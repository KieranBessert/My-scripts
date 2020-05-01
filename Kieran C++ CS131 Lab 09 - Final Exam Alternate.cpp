// This program takes input from a file,
// then outputs information to another file and the screen.
// This Program calculates final grades for a list of students.
// It generates numeric average for each student, then assign a letter grade for each student.
// Created by Kieran Bessert 3/7/2020
// Last edited 3/10/2020

#include <iostream>
#include <fstream>  // Included to use files as I/O 
#include <cstdlib>  // Included to use the exit() function
using namespace std;

struct Student      // Declare the struct that will contain the scores for each student
{
    string nameFirst, nameLast;
    double quiz1 = 0, quiz2 = 0, quiz3 = 0, quiz4 = 0, quiz5 = 0;
    double Lab1 = 0, Lab2 = 0, Lab3 = 0, Lab4 = 0, Midterm = 0, Final = 0;
    double Average = 0;
    char Grade = 65;
}student_data[25];          // No more than 25 Entries per Input File

ifstream in_stream;         // Declare the input file
ofstream out_stream;        // Declare the output file

void fill_data(ifstream& stream);
// This function takes the data from the input stream and fills each struct in the array.
//
// Precondition: An opened ifstream with a file contaning a students first name,
// last name, 5 integer quiz scores, 4 integer lab scores, 
// an integer midterm score, and an integer final score.
//
// Postcondition: Outputs to screen and to ofstream the values entered in a table,
// the average grade for each student, and a letter grade associated with the average.

void close_files();
// Precondition: Opened I/O File streams
// Postcondition: Closes the I/O File Streams

int main()
{
    cout.setf(ios::fixed);      // Set output to screen 
    cout.setf(ios::showpoint);  // at 2 decimal points
    cout.precision(2);          // for the avg value

    char In_File_Name[16];
    cout << "Enter the input file name (maximum of 15 characters)\n";
    cout << "[The default file is ' input.dat ']\n" << endl;
    cin >> In_File_Name;            // The input file that contains Students First name, Last name,
                                    // 5 quiz scores, 4 lab scores, 1 midterm score, and 1 final score.
    cout << endl;

    in_stream.open(In_File_Name);   // Open input file
    if (in_stream.fail())           // Check to see if open function fails
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    out_stream.open("output.dat");  // Open the output file
    if (out_stream.fail())          // Checks to see if open function fails
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    fill_data(in_stream);           // Calls a function to place the data from the ifstream into the array of structs 

    close_files();                  // Calls a function to close the I/O stream files.

    return 0;
}

void fill_data(ifstream& stream)
{
    int count1(0);                                                      // Count variable for limiting the loop
    double temp_quiz(0), temp_Lab(0), temp_Midterm(0), temp_Final(0);   // Temp variables for calculating average grade

    cout << "First" << "\t" << "Last" << "\t" << endl;                  // Formating for the print to screen table
    cout << "Name" << "\t" << "Name" << "\t"
        << "Average" << "\t" << "Grade" << "\t" << endl;

    out_stream << "First" << "\t" << "Last" << "\t" << endl;            // Formatting for the output table
    out_stream << "Name" << "\t" << "Name" << "\t"
        << "Quiz 1" << "\t" << "Quiz 2" << "\t" << "Quiz 3" << "\t" << "Quiz 4" << "\t" << "Quiz 5" << "\t"
        << "Lab 1" << "\t" << "Lab 2" << "\t" << "Lab 3" << "\t" << "Lab 4" << "\t"
        << "Midterm" << "\t" << "Final" << "\t" << "Average" << "\t" << "Grade" << "\t" << endl;

    while (in_stream >> student_data[count1].nameFirst >> student_data[count1].nameLast
        >> student_data[count1].quiz1 >> student_data[count1].quiz2 >> student_data[count1].quiz3
        >> student_data[count1].quiz4 >> student_data[count1].quiz5
        >> student_data[count1].Lab1 >> student_data[count1].Lab2
        >> student_data[count1].Lab3 >> student_data[count1].Lab4
        >> student_data[count1].Midterm >> student_data[count1].Final && count1 < 25)   // Places the data per line of the input file
                                                                                        // into each struct of the array.
    {
        cout << student_data[count1].nameFirst << "\t" << student_data[count1].nameLast << "\t";        // Outputs to screen the first and last names per student

        out_stream << student_data[count1].nameFirst << "\t" << student_data[count1].nameLast << "\t"   // Outputs to file the first names, last names,
            << student_data[count1].quiz1 << "\t" << student_data[count1].quiz2 << "\t"                 // all quiz scores,
            << student_data[count1].quiz3 << "\t" << student_data[count1].quiz4 << "\t"                 // 
            << student_data[count1].quiz5 << "\t"                                                       // 
            << student_data[count1].Lab1 << "\t" << student_data[count1].Lab2 << "\t"                   // all lab scores,
            << student_data[count1].Lab3 << "\t" << student_data[count1].Lab4 << "\t"                   //
            << student_data[count1].Midterm << "\t" << student_data[count1].Final << "\t";              // midterm and final scores of each student.

        temp_quiz = student_data[count1].quiz1 + student_data[count1].quiz2 + student_data[count1].quiz3 + student_data[count1].quiz4 + student_data[count1].quiz5;
        temp_quiz = (temp_quiz / 5) * 0.25;                 // Calculates the average of the quiz scores and the
                                                            // weight of the that average toward total grade

        temp_Lab = student_data[count1].Lab1 + student_data[count1].Lab2 + student_data[count1].Lab3 + student_data[count1].Lab4;
        temp_Lab = (temp_Lab / 4) * 0.35;                   // Calculates the average of the lab scores and the
                                                            // weight of the that average toward total grade

        temp_Midterm = student_data[count1].Midterm * 0.2;  // Calculates the weight of the midterm toward total grade
        temp_Final = student_data[count1].Final * 0.2;      // Calculates the weight of the final toward total grade

        student_data[count1].Average = temp_quiz + temp_Lab + temp_Midterm + temp_Final;    // Adds together the weighted averages for total grade
        cout << student_data[count1].Average << "\t";                                       // Outputs to screen the average grade per student

        out_stream.setf(ios::fixed);
        out_stream.precision(2);
        out_stream << student_data[count1].Average << "\t";                                 // Outputs to file the average grade per student
        out_stream.precision(0);

        if (student_data[count1].Average >= 90)                 // Compares the average grade per student to the value of an A
        {
            student_data[count1].Grade = 65;                    // If met, sets letter grade to A
            out_stream << student_data[count1].Grade << endl;   // Outputs to file the letter grade per student
            cout << student_data[count1].Grade << endl;         // Outputs to screen the letter grade per student
        }
        else if (student_data[count1].Average < 90
            && student_data[count1].Average >= 80)  // Compares the average grade per student to the value of an B
        {
            student_data[count1].Grade = 66;                    // If met, sets letter grade to B
            out_stream << student_data[count1].Grade << endl;   // Outputs to file the letter grade per student
            cout << student_data[count1].Grade << endl;         // Outputs to screen the letter grade per student
        }
        else if (student_data[count1].Average < 80
            && student_data[count1].Average >= 70)  // Compares the average grade per student to the value of an C
        {
            student_data[count1].Grade = 67;                    // If met, sets letter grade to C
            out_stream << student_data[count1].Grade << endl;   // Outputs to file the letter grade per student
            cout << student_data[count1].Grade << endl;         // Outputs to screen the letter grade per student
        }
        else if (student_data[count1].Average < 70
            && student_data[count1].Average >= 60)  // Compares the average grade per student to the value of an D
        {
            student_data[count1].Grade = 68;                    // If met, sets letter grade to D
            out_stream << student_data[count1].Grade << endl;   // Outputs to file the letter grade per student
            cout << student_data[count1].Grade << endl;         // Outputs to screen the letter grade per student
        }
        else if (student_data[count1].Average < 60) // Compares the average grade per student to the value of an F
        {
            student_data[count1].Grade = 70;                    // If met, sets letter grade to F
            out_stream << student_data[count1].Grade << endl;   // Outputs to file the letter grade per student
            cout << student_data[count1].Grade << endl;         // Outputs to screen the letter grade per student
        }
        ++count1;                                   // increases count to limit number of entries in while loop
    }
}


void close_files()
{
    in_stream.close();              // Close input file
    out_stream.close();             // Close output file
}

/* Example input.dat file
Bob Smith 100 90 95 70 63 100 100 90 85 65 85
Sue Jones 70 85 73 0 52 90 80 76 83 70 56
Kathy Berna 90 90 90 90 90 80 70 40 60 90 55
Josh Doe 100 100 100 100 100 100 100 100 100 100 100
Zach Hero 90 85 79 0 46 55 98 98 98 100 12
Bad Student 10 0 0 0 0 0 0 0 0 0 0
*/
