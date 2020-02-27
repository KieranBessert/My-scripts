// example and workplace for data type structure
// coded by Kieran Bessert 2/27/2020
// Last edited on 2/27/2020

#include <iostream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

void get_info(date& the_date);
date DueDate;

int main()
{
    get_info(DueDate);

    cout << "You entered " 
        << DueDate.day 
        << " of "
        << DueDate.month 
        << ", "
        << DueDate.year 
        << " as your Due Date." 
        << endl;

    date LateDate;
    LateDate.day = DueDate.day + 1;
    LateDate.month = DueDate.month + 1;
    LateDate.year = DueDate.year + 1;

    cout << "You will be a DAY late on "
        << LateDate.day
        << " of "
        << DueDate.month
        << ", "
        << DueDate.year
        << "."
        << endl
        << "You will be a MONTH late on "
        << LateDate.day
        << " of "
        << LateDate.month
        << ", "
        << DueDate.year
        << "."
        << endl
        << "You will be a YEAR late on "
        << LateDate.day
        << " of "
        << LateDate.month
        << ", "
        << LateDate.year
        << "."
        << endl;
}

void get_info(date& the_date)
{
    cout << "Please enter the integer DAY of your Due Date.\n";
    cin >> DueDate.day;
    cout << "Please enter the integer MONTH of your Due Date.\n";
    cin >> DueDate.month;
    cout << "Please enter the integer YEAR of your Due Date.\n";
    cin >> DueDate.year;
}
