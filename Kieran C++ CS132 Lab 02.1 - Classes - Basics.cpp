// This program reads information for Vehicles on a lot from a file,
// then updates the amount of time those vehicles have been on the lot.
// Coded by Kieran Bessert	4/26/2020
// Last edited 4/27/2020

#include <iostream>
#include <fstream>		// File I/O
#include <string>		// use of Strings
using namespace std;

class Vehicle           // Basic info pertinent to ALL kinds of vehicles
{
public:
    void rdVehicle(istream&);
    void wrtVehicle(ostream&);
    int getWeeksOnLot();            // Accessor Function
    void updateWeeksOnLot();     // Mutator Function

private:
    string vin;         // The vehicle ID number
    double price = 0;       // The current asking price for the vehicle
    int weeksOnLot = 0;     // How many weeks the vehicle has been in inventory
/*Declare a Vehicle class, with private variable members and public member functions. */
};

void ageInventory(Vehicle&);

ifstream in_stream;     // Declare the input file
ofstream out_stream;    // Declare the output file

int main()
{
    string In_File_Name;
    Vehicle car1;

    cout << "WELCOME TO THE VEHICLE DATA PROGRAM!!!\n" << endl;
    cout << "Enter the input file name.\n";
    cout << "[The default file is ' vehicles.txt ']\n" << endl;
    cin >> In_File_Name;            // The input file that contains Vehicle information
    cout << endl;

    in_stream.open(In_File_Name);   // Open input file
    if (in_stream.fail())           // Check to see if open function fails
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    out_stream.open("output.txt");  // Open the output file
    if (out_stream.fail())          // Checks to see if open function fails
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    for (int ix = 0; ix < 8; ix++)
    {
        car1.rdVehicle(in_stream);
        cout << "Car #" << ix + 1 << ": ";
        ageInventory(car1);
        cout << endl;
    }
/* In main(), make a loop that;
    reads each vehicle in from the file,
    ages the inventory,
    and writes the modified value to an output file.*/

    in_stream.close();              // Close input file
    out_stream.close();             // Close output file
}

void Vehicle::rdVehicle(istream& rdS)
{
    rdS >> vin >> price >> weeksOnLot;
/*Write two public member functions that
    can rdVehicle() from either the console or a file.*/
}
void Vehicle::wrtVehicle(ostream& wrtS)
{
    wrtS << vin << "\t" << price << "\t" << weeksOnLot << "\n";
/*Write two public member functions that
    can wrtVehicle() from either the console or a file.*/
}
int Vehicle::getWeeksOnLot()                // Accessor Function
{
    return(weeksOnLot);
/*Write a public member function to
    see the current value of "weeksOnLot" (an accessor).*/
}
void Vehicle::updateWeeksOnLot()            // Mutator Function
{
    weeksOnLot = weeksOnLot + 1;
    cout << "Weeks on lot has been updated to "<< weeksOnLot << "\n";
/*Write a public member function that
    writes a new value of "weeksOnLot" (a mutator)*/
}

void ageInventory(Vehicle& x)
{
    x.getWeeksOnLot();
    x.wrtVehicle(cout);
    x.updateWeeksOnLot();
/*Develop a normal non-member function called ageInventory() that;
    uses your accessor and mutator to show that 
    a car has been present on the lot for one additional week 
    (i.e., it increments a vehicle’s weeksOnLot value by 1). */
}

/* EXAMPLE ' vehicles.txt ' FILE */
/*
RGLK27844	14800	8
RLVY26499	17450	10
RLTS43992	18456.9	13
RGMA74881	23050	6
TLTD37882	29544.5	11
RLTX26888	0	4
RGMC33389	15000	3
RGLL44488	23999	2
*/
