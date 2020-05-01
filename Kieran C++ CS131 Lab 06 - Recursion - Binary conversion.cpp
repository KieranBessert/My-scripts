// This program calculates the binary equivalent of a positive integer from 1 to 1000 as many times as desired.
// It will print the binary equivalent to the screen.
// It does so using recursive loops
// Created by Kieran Bessert 2/23/2020
// Last edited 2/23/2020

#include <iostream>
using namespace std;

int convert(int base10);
// Preconditions: Any base 10 integer from 1 to 1000
// Postconditions: The same value in base 2 printed to screen

int main()
{
    int integer(1);

    cout << "Welcome to the Base 10 to Binary converter!!\n" << endl;
    cout << "Please enter an integer from 1 to 1000 for conversion.\n";
    cout << "Please enter a 0 or negative value to quit the program.\n";
    cout << endl;

        while (integer > 0)
    {
        cin >> integer;
        if (integer <= 1000)
        {
            convert(integer);
            cout << endl << endl;
        }

        else
        {
            cout << "Please enter an integer from 1 to 1000 for conversion.\n";
        }
    }

    return 0;
}

int convert(int base10)
{
    int temp;

    if (base10 <= 0) // Base case in recursive function.
    {
        return 0;
    }
    else
    {
        temp = base10 % 2;
        convert(base10 / 2);
        cout << temp;
    }
}

