// Win Lab01 Change Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Created by Kieran Bessert 1/14/2020
//Program that prompts the user to enter a number of quarters, dimes, and nickels and then outputs the monetary value of the coins in cents.
//For example, if the user enters 2 for the number of quarters, 3 for the number of dimes and 1 for the number of nickels, then the program should output that the coins are worth 85 cents.

#include <iostream>
using namespace std;

int main()
{
    double quarters, dimes, nickles, total;

    cout << "This program will calculate the monetary value of a number of quarters, dimes, and nickels.\n";

    cout << "Please enter the number of quarters.\n";
    cin >> quarters;
    cout << "You entered " <<
        quarters <<
        " quarters.\n";
        quarters = quarters * 0.25;

    cout << "Please enter the number of dimes.\n";
    cin >> dimes;
    cout << "You entered " <<
        dimes <<
        " dimes.\n";
    dimes = dimes * .10;
    
    cout << "Please enter the number of nickles.\n";
    cin >> nickles;
    cout << "You entered " <<
        nickles <<
        " nickles.\n";
    nickles = nickles * .05;

    total = quarters + dimes + nickles;

    cout << "The monetary value of your coins is " <<
        total <<
        " dollars.\n";

        return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
