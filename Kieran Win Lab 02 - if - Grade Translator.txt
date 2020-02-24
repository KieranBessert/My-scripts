// A C++ program that asks the user for an integer test score in the range of 0 through 100.
// The Program will translate that integer to a letter grade.
// Created by Kieran Bessert 1/22/2020
// Last edited 1/23/2020

#include <iostream>
using namespace std;

int main()
{
    int grade;

    cout << "This program will calculate your grade based on a score you provide.\n";

    cout << "Please enter an integer test score in the range of 0 through 100.\n";
    cin >> grade;

    if (grade > 100 || grade < 0) //error checking to see if the user input a valid integer
    {
        cout << "You have entered a score beyond the range of 0 through 100.\n";
        cout << "Please rerun the program and try again.";
    }

    // below this line simply compares the input integer to grading scale 

    else if (grade >= 93) // A
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is an\n" 
            << "A!!!\n" 
            << "Congratulations!\n";
    }

    else if (grade < 93 && grade >= 90) // A-
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is an\n"
            << "A-!!\n" 
            << "Congratulations!\n";
    }

    else if (grade < 90 && grade >= 87) // B+
    {
        cout << "You have entered a score of\n" 
            << grade << endl 
            << "which is a\n"
            << "B+!\n"
            << "Keep up the hard work!\n";
    }

    else if (grade < 87 && grade >= 83) // B
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is a\n"
            << "B\n" 
            << "Keep up the hard work!\n";
    }

    else if (grade < 83 && grade >= 80) // B-
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is a\n"
            << "B-\n"
            << "Doing Well!\n";
    }

    else if (grade < 80 && grade >= 77) // C+
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is a\n"
            << "C+\n" 
            << "Doing ok!\n";
    }

    else if (grade < 77 && grade >= 73) // C
    {
        cout << "You have entered a score of\n"
            << grade << endl
            << "which is a\n"
            << "C\n"
            << "Doing ok!\n";
    }

    else if (grade < 73 && grade >= 70) // C-
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is a\n"
            << "C-\n"
            << "Try studying.\n";
    }

    else if (grade < 70 && grade >= 67) // D+
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is a\n"
            << "D+\n"
            << "Try studying.\n";
    }

    else if (grade < 67 && grade >= 60) // D
    {
        cout << "You have entered a score of\n"
            << grade << endl
            << "which is a\n"
            << "D\n"
            <<"Try studying.\n";
    }

    else if(grade < 60) // F
    {
        cout << "You have entered a score of\n" 
            << grade << endl
            << "which is an\n"
            << "F\n"
            << "You have failed me for the last time, admiral.\n";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
