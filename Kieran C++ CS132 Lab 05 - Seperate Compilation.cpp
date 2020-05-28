//*****************************************************************************************************************************
//*Vehicle.h file**************************************************************************************************************
//*****************************************************************************************************************************

// This is the Vehicle.h file, the interface definition file for
// the class "Vehicle", which is a container to hold information
// about a specific vehicle in an inventory. This information includes;
// - The 9 character string Vehicle Identification Number (VIN)
// - The 3 character string BASE MODEL (First 3 characters of VIN)
// - The double PRICE of any size
// - The integer NUMBER OF WEEKS the vehicle has been on the lot
// - The integer number of additional OPTIONS the vehicle has
// See "Vehicle.cpp" for the implementation
// Coded by Kieran Bessert 4/26/2020
// Last edited 5/28/2020
#ifndef VEHICLE_H
#define VEHICLE_H
/***********************LIBRARIES***********************/
// A Vehicle Object functions only if standard string objects
// are manipulable, so the <string> file must be included.
#include <string>                                   // use of Strings
using namespace std;
namespace Vehicle_Kieran
{
    /***********************CLASS***********************/
    class Vehicle
    {
    public:
        string getVin();                                // Vin Accessor Function
        // This member function retrieves a string from storage.
        // The retrieved string is sent as the return value of 
        // the function.
        // PRECONDITIONS: This .h file included in the source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" file
        // linked during build. Prior existence of a Vehicle object
        // that can call this function.
        // POSTCONDITION: A 9 character string object is the
        // return value of the function call.
        void updateVin(string);                         // Vin Mutator Function
        // This member function places a string to storage.
        // The string argument is placed as the new value
        // for the VIN variable. After the string is stored 
        // as the VIN private member variable, the private helper
        // function getBaseModel() is automatically called, utilizing 
        // the same string argument.
        // PRECONDITIONS: This .h file included in the source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" file
        // linked during build. Prior existence of a Vehicle object
        // that can call this function.
        // POSTCONDITION: An object with a newly stored string
        // value in the VIN variable.
        double getPrice();                              // Price Accessor Function
        // This member function retrieves a double from storage.
        // the retrieved double is sent as the return value of 
        // the function.
        // PRECONDITIONS: This .h file included in the source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" file
        // linked during build. Prior existence of a Vehicle object
        // that can call this function.
        // POSTCONDITION: A double object is the
        // return value of the function call.
        void updatePrice(double);                       // Price Mutator Function
        // This member function places a double to storage.
        // The double argument is placed as the new value
        // for the PRICE variable
        // PRECONDITIONS: This .h file included in the source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" file
        // linked during build. Prior existence of a Vehicle object
        // that can call this function.
        // POSTCONDITION: An object with a newly stored double
        // value in the PRICE variable.
        int getWeeksOnLot();                            // WeeksOnLot Accessor Function
        // This member function retrieves a integer from storage.
        // the retrieved integer is sent as the return value of 
        // the function.
        // PRECONDITIONS: This .h file included in the source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" file
        // linked during build. Prior existence of a Vehicle object
        // that can call this function.
        // POSTCONDITION: A integer object is the
        // return value of the function call.
        void updateWeeksOnLot(int);                     // WeeksOnLot Mutator Function
        // This member function places an integer to storage.
        // The integer argument is placed as the new value
        // for the WEEKS ON LOT variable
        // PRECONDITIONS: This .h file included in the source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" file
        // linked during build. Prior existence of a Vehicle object
        // that can call this function.
        // POSTCONDITION: An object with a newly stored integer
        // value in the WEEKS ON LOT variable.
        Vehicle();                                      // Default Constructor
        // The default constructor does nothing more than ensure
        // that the private variables are initialized to NULL/zero Values,
        // indicating that the container is empty and available for data.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // POSTCONDITION: An object created, available to recieve data for storage.
        Vehicle(string);                                // Single Argument Constructor
        // The 1-argument constructor accepts a string variable of 9 characters.
        // The string itself is not altered, and the given string will be stored
        // in the private member string variable VIN. After the string is stored
        // as the VIN private member variable, the private helper function getBaseModel()
        // is automatically called, utilizing the same string argument.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // Argument must be an existing variable of the type string.
        // POSTCONDITIONS: An object created, with the argument stored in the VIN variable,
        // available to recieve additional data for storage.
        Vehicle(string, double);                        // Double Argument Constructor
        // The 2-argument constructor accepts a string variable of 9 characters,
        // and a double variable of any size.
        // Neither are altered, and the given string and double will be stored in
        // the private member string variable VIN and double variable PRICE respectively.
        // After the string is stored as the VIN private member variable, the private helper
        // function getBaseModel() is automatically called, utilizing the same string argument.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // Arguments must be an existing variable of the type string and double.
        // POSTCONDITIONS: An object created, with the argument stored in the VIN variable
        // and PRICE variable respectively, available to recieve additional data for storage.
        Vehicle(const Vehicle&);                        // Copy Constructor
        // A Vehicle object may be passed by value to a function and
        // a function may return an object of class Vehicle.
        // Anonymous copies of a Vehicle object will be constructed, used,
        // and destructed automatically at runtime to support
        // such handle of Vehicle objects by the user.
        ~Vehicle();                                     // Destructor
        // The destructor returns dynamic memory to the freestore
        // and sets private variables to indicate an empty container.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // POSTCONDITIONS: If Vehicle object remains in scope, 
        // its private variables indicate an empty container
        void operator =(const Vehicle&);                // Overloaded = operator for dynamic arrays
        // An object of class Vehicle may be assigned as the value of another
        // object of class Vehicle by placing the assignment operator " = "
        // between the two.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // Two objects of class Vehicle in existence, with the object on the right
        // side of the assignment operation containing values that are to be assigned
        // to the left side object.
        // POSTCONDITIONS: Contents of the left side object now indentical to those
        // of the right side object. Right side object remains uncahnged.
        // If the left side object had existing content prior to assignment,
        // that content is lost, and the dynamic storage associated with
        // that content is returned to the freestore.
        friend bool compareModel(Vehicle&, Vehicle&);   // Friend function compare base model
        // The BASE MODEL of an object of class Vehicle may be compared to 
        // the BASE MODEL of another object of class Vehicle by supplying
        // the 2 objects as arguments to this function.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // Two objects of class Vehicle in existence, both with initialized VIN variables.
        // POSTCONDITIONS: A boolian value is returned based on the equality of the
        // BASE MODEL variable of both objects. Both objects remained unchanged.
        friend bool operator ==(Vehicle&, Vehicle&);    // Friend function compare base model
        // The BASE MODEL of an object of class Vehicle may be compared to 
        // the BASE MODEL of another object of class Vehicle by placing one 
        // of each of the objects to the left and right side of the " == " operator.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // Two objects of class Vehicle in existence, both with initialized VIN variables.
        // POSTCONDITIONS: A boolian value is returned based on the equality of the
        // BASE MODEL variable of both objects. Both objects remained unchanged.
        friend void operator ++(Vehicle&);              // Friend function increment WEEKS ON LOT
        // The WEEKS ON LOT variable of an object of class Vehicle may be
        // incremented by 1 by placing the Vehicle object to the right of the 
        // " ++ " operator.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // An object of class Vehicle in existence.
        // POSTCONDITION: The object of class Vehicle that stores a member variable
        // WEEKS ON LOT will be incremented by 1.
        friend istream& operator >> (istream&, Vehicle&);
        // An object of type Vehicle may be used to extract and store information
        // from an instream by placing the existing object to the right of the operator
        // and an existing instream object to the left of the operator.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // An object of class Vehicle in existance and an instream to supply input.
        // POSTCONDITION:  Contents of the left side object stored in those
        // of the right side object of type Vehicle. Left side object remains uncahnged.
        // If the right side Vehicle object had existing content prior to assignment,
        // that content is lost, and the dynamic storage associated with
        // that content is returned to the freestore.
        friend ostream& operator << (ostream&, const Vehicle&);
        // An object of type Vehicle may be used to output and store information
        // from an outstream by placing the existing object to the right of the operator
        // and an existing outstream object to the left of the operator.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // An object of class Vehicle in existance and an outstream to supply input.
        // POSTCONDITION:  Contents of the right side Vehicle object stored in those
        // of the left side object. Right side Vehicle object remains uncahnged.
        // If the left side object is a file and had existing content prior
        // to assignment, that content is lost.
    private:
        // There are 6 private variables used to implement the Vehicle container,
        // and none are accessible or mutable to the user. They are used solely
        // for internal implementation of the functionality of an object.
        string vin;                                     // The vehicle ID number
        string baseModel;                               // The first 3 characters of the VIN
        double price;                                   // The current asking price for the vehicle
        int weeksOnLot;                                 // How many weeks the vehicle has been inventoried
        int options;                                    // How many options each vehicle has
        string* optionsPtr;                             // Points to the dynamic array of list of options
        // There exists 1 private member function used to implement the vehicle container,
        // and it is non-accessible to the user. This function is used solely for extracting
        // the first 3 characters of the VIN variable and placing those values as the BASE MODEL
        void getBaseModel(string&);                     // Internal Private Helper Function
        // This private member function is used to obtain the BASE MODEL variable of 
        // objects of type Vehicle. It is automatically called by the 1 and 2 argument
        // constructors, the VIN mutator, and the instream opterator when a 9 character 
        // string is supplied to fill the VIN variable, and uses the same argument
        // to fill the 3 character BASE MODEL string private member variable.
        // PRECONDITIONS: This .h file included in source file,
        // and the "Kieran Bessert - Lab 5 - Separate Compilation.cpp" linked during build.
        // A 9 character string argument being passed
        // POSTCONDITION: A 3 character string object is stored in
        // the BASE MODEL private member variable.
    };
}
#endif					                            // !VEHICLE_H

//*****************************************************************************************************************************
//*Kieran C++ CS132 Lab 05 - Seperate Compilation.cpp**************************************************************************
//*****************************************************************************************************************************

// This program is used to manage an inventory of vehicles from a file on the local drive.
// Coded by Kieran Bessert 4/26/2020
// Last edited 5/28/2020
#include <iostream>
#include <fstream>                                          // File I/O
#include <string>                                           // use of Strings
#include <cstdlib>                                          // use of exit() function
#include <iomanip>                                          // use of setprecision()
#include "Kieran Bessert Vehicle.h"                         // use of Vehicle class
using namespace std;
using namespace Vehicle_Kieran;
namespace
{
/***********************CONSTANT VARIABLES***********************/
    const string NAME = "Kieran";
    const string IN_FILE_NAME = "vehicles_db.txt";          // Constant variable for storing name of the input file
    const int MAX_SIZE_INV = 20;                            // The size of array OF objects
    const int MAX_SIZE_VIN = 9;                             // the size of array WITHIN each object
}
/***********************NON-MEMBER FUNCTIONS***********************/
void viewInv1(Vehicle*, int max, ostream& oS);
// This function reads input data from an array and displays it on screen
// PRECONTDITION: An array of objects of type Vehicle
// POSTCONDITION: cout statement of the VIN, PRICE, & WEEKS ON LOT data contained in each object
void addToInv2(Vehicle v[], int& count, ostream& oS);
// This function edits the last empty object in an array to fill its data
// PRECONTDITION: An empty object in the array, and New VIN, PRICE, WEEKS ON LOT data required for inputing by user
// POSTCONDITION: An object in the array containing this information, and the array count incremented
void updateInv3(Vehicle*, int max, ostream& oS);
// This function increments all filled array's WEEKS ON LOT
// PRECONTDITION: An array of objects with VIN data
// POSTCONDITION: All filled arrays with their WEEKS ON LOT incremented by 1
void searchInv4(Vehicle v[], string& searchForVIN, ostream& oS);
// This function searches the filled array for a VIN value entered by the user
// PRECONTDITION: A filled array of VIN data and the first 3 values of VIN data a user wishes to search for
// POSTCONDITION: If match is found in the array, that objects data printed to screen
void makeUC(string&);
// This function accepts a call by refrence string and uppercases the string for the length of a string
// PRECONDITION: Any string with lowercase letters
// POSTCONDITION: The string is capitalized
/***********************MAIN***********************/
int main()
{
    ifstream in_stream;                                     // Declare the input file
    ofstream out_stream;                                    // Declare the output file
    Vehicle vehicles[MAX_SIZE_INV];                         // Declare object array
    Vehicle* vPtr;                                          // Declare pointer of type Vehicle
    string vinSearch;                                       // Variable for storing VIN of desired vehicle
    string exitChoice;                                      // For Exit Program confirmation
    int arrayCount(0);                                      // For keeping track of the used arrays
    int menuChoice(0);                                      // For user interaction
    in_stream.open(IN_FILE_NAME);                           // Open input file
    if (in_stream.fail())                                   // Check to see if open function fails
    {
        cout << "Input file opening failed.\nFile does not exist.\n";
        return(-1);
    }
    for (int ix = 0; ix < MAX_SIZE_INV; ix++)               // Fill the object arrays completely
    {
        in_stream >> vehicles[ix];                          // Use of overloaded >> operator
        if (vehicles[ix].getVin() == "?")                   // Do not count empty arrays
        {
            break;
        }
        arrayCount++;                                       // Count all filled objects in the array
        if (arrayCount == MAX_SIZE_INV)
        {
            cout << "\tMAX INVENTORY SIZE REACHED!\n\tNOT ALL VEHICLES IMPORTED!\n\n";
        }
    }
    cout << "WELCOME TO THE VEHICLE INVENTORY DATA PROGRAM!!!\n";
    vPtr = &vehicles[0];                                    // Set pointer to the first element of the vehicles array
    do {                                                    // Main loop of program
        cout << "\nMenu:\n 1) View Inventory\n 2) New Entry\n"
            << " 3) Update Entries\n 4) Search Inventory\n"
            << " 5) Rearrange Entries\n\n 0) Exit program\n\n\n\tChoice: ";
        cin >> menuChoice;
        cout << endl << endl;
        switch (menuChoice)
        {
        case 1:                                             // View contents of input file
            viewInv1(vPtr, MAX_SIZE_INV, cout);
            break;
        case 2:                                             // Add entry to input file
            addToInv2(vehicles, arrayCount, cout);
            break;
        case 3:                                             // Edit Entry of input file
            updateInv3(vPtr, MAX_SIZE_INV, cout);
            cout << "\nWEEKS ON LOT has been updated for each vehicle in inventory;\n\n";
            break;
        case 4:                                             // Search input file
            cout << "Enter the first 3 characters of the VIN you wish to search for.\n"
                << "[EXAMPLE: ' RGL ']\n\n\tVIN: ";
            cin >> vinSearch;
            cout << endl;
            makeUC(vinSearch);
            searchInv4(vehicles, vinSearch, cout);
            break;
        case 5:
            cout << "\n\nEnter the positions of the 2 vehicles to be swapped.\n"
                << "Positions MUST be:\n  1 or MORE\n  " << arrayCount << " or LESS\n"
                << "\n[EXAMPLE: ' 0  4 ']\n\n\tPosition: ";
            int pos1, pos2;
            cin >> pos1 >> pos2;
            if (pos1 <= arrayCount && pos2 <= arrayCount
                && pos1 != pos2 && pos1 > 0 && pos2 > 0)
            {
                --pos1;
                --pos2;
                Vehicle tempV;
                tempV = vehicles[pos1];
                vehicles[pos1] = vehicles[pos2];
                vehicles[pos2] = tempV;
            }
            else cout << "Positions MUST be:\n  1 or MORE\n  "
                << arrayCount << " or LESS\n" << "\n\nTry Again.\n";
            break;
        case 0:
            cout << "ARE YOU SURE YOU WANT TO EXIT & SAVE CHANGES?\n\n"
                << "\t(Y)ES or (N)O: ";
            cin >> exitChoice;
            makeUC(exitChoice);
            exitChoice = exitChoice.substr(0, 1);
            if (exitChoice != "Y")
            {
                break;
            }
            else
            {
                cout << "\nTHANK YOU FOR USING THE VEHICLE INVENTORY PROGRAM!!!\n\n"
                    << "\tGOODBYE!\n\n";
                in_stream.close();
                out_stream.open(IN_FILE_NAME);              // Open the output file appending
                if (out_stream.fail())                      // Checks to see if open function fails
                {
                    cout << "Output file opening failed.\n";
                    in_stream.close();
                    return(-1);
                }
                for (int ix = 0; ix < MAX_SIZE_INV; ix++)   // Store the object arrays
                {
                    out_stream << vehicles[ix];             // Use of overloaded >> operator
                }
                out_stream.close();
                return (0);
            }
        default:
            cout << "Illegal choice.\n";
        }
    } while (true);
    return(0);
}
/***********************NON-MEMBER FUNCTIONS***********************/
// This Function;
// - Takes an array of objects of type Vehicle and the integer of those objects that are filled in memory
// - Outputs the object's data to the ostream one by one
// - Ignores 'empty' objects
void viewInv1(Vehicle* pointer, int max, ostream& oS)       // The 1) View Inventory menu choice
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    Vehicle* lastVehiclePtr = pointer + (max - 1);
    cout << "VIN\t\tPRICE\t\tWEEKS\tOPTIONS\n";             // Table Formatting
    for (; pointer <= lastVehiclePtr; pointer++)            // Loop until all Objects Accessed
    {
        if ((*pointer).getVin() == "?")
        {
            return;
        }
        oS << (*pointer);                                   // Use of overloaded << operator
    }
}
// This Function;
// - Takes an array of objects of type Vehicle and the integer of those objects that are filled in memory
// - Compares ineger of filled to max allowed, informs the user if inventory is full
// - If space is available, prompts the user for VIN and optionally PRICE data for the new entry
// - Fills the 'blank' object with the new data
// - Outputs the object data to the ostream
// - Increments to the next blank object in the array
void addToInv2(Vehicle v[], int& count, ostream& oS)        // The 2) New Entry menu choice
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    string vin;
    double price;
    int choice(0);
    if (count >= MAX_SIZE_INV)                              // Check to see if array is full.
    {
        cout << "Inventory is full.\n";
        return;
    }
    cout << "9 Digit VIN of the vehicle: ";                 // Prompt for new entry data
    cin >> vin;
    makeUC(vin);                                            // Ensure data entered matches inventpory
    if (vin.length() != MAX_SIZE_VIN)                       // Error checking
    {
        cout << "\n\tInvalid VIN entered.\n";
        return;
    }
    cout << "Do you know the price of the vehicle?\n1) YES\n0) NO\n\n\tChoice: ";
    cin >> choice;
    if (choice == 0)
    {
        v[count].updateVin(vin);
        cout << "VIN\t\tPRICE\t\tWEEKS\tOPTIONS\n";         // Table Formatting
        oS << v[count];                                     // Use of overloaded << operator
        count++;
    }
    else if (choice == 1)
    {
        cout << "\nEnter the PRICE of the vehicle without punctuation: ";
        cin >> price;
        cout << endl;
        v[count].updateVin(vin);
        v[count].updatePrice(price);
        cout << "VIN\t\tPRICE\t\tWEEKS\tOPTIONS\n";         // Table Formatting
        oS << v[count];                                     // Use of overloaded << operator
        count++;
    }
    else
    {
        cout << "Invalid Choice: ";
        return;
    }
}
// This Function;
// - Takes an array of objects of type Vehicle from memory and the max size of the list being used
// - Updates the weeksOnLot for each object in the array by 1
// - Outputs each object to the ostream
// - Ignores 'empty' objects
void updateInv3(Vehicle* pointer, int max, ostream& oS)     // The 3) Update Entry menu choice.
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    Vehicle* lastVehiclePtr = pointer + (max - 1);
    cout << "VIN\t\tPRICE\t\tWEEKS\tOPTIONS\n";             // Table Formatting
    for (; pointer <= lastVehiclePtr; pointer++)            // Loop until all Objects Accessed
    {
        if ((*pointer).getVin() == "?")
        {
            return;
        }
        ++(*pointer);
        oS << (*pointer);                                   // Use of overloaded << operator
    }
}
// This Function;
// - Takes an array of objects of type Vehicle from memory and a 3 character string from the user
// - Compares the first 3 characters in the VIN variable of each object to the string
// - If a match is found, for each it is output to the ostream
// - If no match is found, the user is informed via the ostream
void searchInv4(Vehicle v[], string& searchForVIN, ostream& oS) // The 4) Search Inventory menu choice.
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    Vehicle searchVehicle(searchForVIN);
    int count(0);
    if (searchForVIN.length() != 3)
    {
        cout << searchForVIN << "\tIs not a valid 3 characters.\n\n";
        return;
    }
    cout << "VIN\t\tPRICE\t\tWEEKS\tOPTIONS\n";             // Table Formatting
    for (int ix = 0; ix < MAX_SIZE_INV; ix++)
    {
        if (compareModel(v[ix], searchVehicle))
        {
            oS << v[ix];                                    // Use of overloaded << operator
            count++;
        }
    }
    if (count == 0)
    {
        cout << "\nNo matches found in inventory for VIN\t" << searchForVIN << " .\n\n";
    }
}
// This Function;
// - Takes a string variable & uppercases each letter of the string individually
void makeUC(string& word)                                   // Uppercases the letters of string input
{
    int count = (int)word.length();
    for (; count-- > 0;)
    {
        word[count] = toupper(word[count]);
    }
}

//*****************************************************************************************************************************
//*Vehicle.cpp file************************************************************************************************************
//*****************************************************************************************************************************

// This is the Vehicle.cpp file, the implementation file for the class "Vehicle".
// See "Vehicle.h" file for the interface definition.
// Coded by Kieran Bessert 4/26/2020
// Last edited 5/28/2020
#include <iostream>
#include <fstream>                                      // File I/O
#include <string>                                       // use of Strings
#include <cstdlib>                                      // use of exit() function
#include <iomanip>                                      // use of setprecision()
#include "Kieran Bessert Vehicle.h"                     // use of Vehicle class
using namespace std;
namespace Vehicle_Kieran
{
    /***********************MEMBER FUNCTIONS***********************/
    string Vehicle::getVin()                                // Accessor Function
    {
        return(vin);
    }
    void Vehicle::updateVin(string newVin)                  // Mutator Function
    {
        vin = newVin;
        getBaseModel(newVin);
    }
    double Vehicle::getPrice()                              // Accessor Function
    {
        return(price);
    }
    void Vehicle::updatePrice(double newPrice)              // Mutator Function
    {
        price = newPrice;
    }
    int Vehicle::getWeeksOnLot()                            // Accessor Function
    {
        return(weeksOnLot);
    }
    void Vehicle::updateWeeksOnLot(int newWeeks)            // Mutator Function
    {
        weeksOnLot = newWeeks;
    }
    /***********************CONSTRUCTORS/DESTRUCTOR***********************/
    Vehicle::Vehicle()                                      // Default Constructor
    {
        vin = "?";
        baseModel = "?";
        price = -1.00;
        weeksOnLot = 0;
        options = 0;
        optionsPtr = NULL;
    }
    Vehicle::Vehicle(string newVin)                         // Single Argument Constructor
    {
        vin = newVin;
        getBaseModel(newVin);
        price = -1.00;
        weeksOnLot = 0;
        options = 0;
        optionsPtr = NULL;
    }
    Vehicle::Vehicle(string newVin, double newPrice)        // Double Argument Constructor
    {
        vin = newVin;
        getBaseModel(newVin);
        price = newPrice;
        weeksOnLot = 0;
        options = 0;
        optionsPtr = NULL;
    }
    Vehicle::Vehicle(const Vehicle& original)               // Copy Constructor
    {
        vin = original.vin;
        baseModel = original.baseModel;
        price = original.price;
        weeksOnLot = original.weeksOnLot;
        options = original.options;
        if (options != 0)                                   // If Dynamic Stoarge in use on right side...
        {
            optionsPtr = new string[options];               // ...make an independent copy
            for (int ix = 0; ix < options; ix++)
            {
                *(optionsPtr + ix) = *(original.optionsPtr + ix);
            }
        }
        else optionsPtr = NULL;
    }
    Vehicle::~Vehicle()                                     // Destructor
    {
        if (optionsPtr != NULL)
        {
            delete[] optionsPtr;
        }
    }
    void Vehicle::operator =(const Vehicle& rightSide)      // Overloaded = operator for dynamic arrays
    {
        if (optionsPtr != NULL)                             // If Dynamic Storage in use on left side...
        {
            delete[] optionsPtr;                            // ...delete it
        }
        vin = rightSide.vin;
        baseModel = rightSide.baseModel;
        price = rightSide.price;
        weeksOnLot = rightSide.weeksOnLot;
        options = rightSide.options;
        if (options != 0)                                   // If Dynamic Stoarge in use on right side...
        {
            optionsPtr = new string[options];               // ...make an independent copy
            for (int ix = 0; ix < options; ix++)
            {
                *(optionsPtr + ix) = *(rightSide.optionsPtr + ix);
            }
        }
        else optionsPtr = NULL;
    }
    /***********************FRIEND FUNCTIONS***********************/
    bool compareModel(Vehicle& car1, Vehicle& car2)         // Friend function compare base model 1
    {
        return(car1.baseModel == car2.baseModel);
    }
    bool operator ==(Vehicle& car1, Vehicle& car2)          // Friend function compare base model 2
    {
        return(car1.baseModel == car2.baseModel);
    }
    void operator ++(Vehicle& car1)                         // Friend function increment WEEKS ON LOT
    {
        car1.weeksOnLot += 1;
    }
    istream& operator >> (istream& rdS, Vehicle& v)         // Overloaded >> operator
    {
        rdS >> v.vin >> v.price
            >> v.weeksOnLot >> v.options;                   // Fills the other 3 values from stream
        v.getBaseModel(v.vin);
        rdS.get();                                          // 'Eat' the \n character
        if (v.options > 0)
        {
            v.optionsPtr = new string[v.options];           // Create a dynamic array of options for the vehicle
            string* sPtr = v.optionsPtr;                    // Preserve value of optionsPtr for later deletion
            for (int ix = 0; ix < v.options; ix++)
            {
                getline(rdS, *sPtr);
                sPtr++;
            }
        }
        return (rdS);
    }
    ostream& operator << (ostream& wrtS, const Vehicle& v)  // Overloaded << operator
    {
        wrtS << v.vin << "\t" << v.price << "\t"
            << v.weeksOnLot << "\t" << v.options << "\n";
        if (v.options > 0)                                  // If options exist...
        {
            string* sPtr = v.optionsPtr;
            for (int ix = 0; ix < v.options; ix++)          // ...for each...
            {
                wrtS << *sPtr << endl;                      // ...send it to stream...
                sPtr++;                                     // ...and advance to next row of options
            }
        }
        return(wrtS);
    }
    /***********************PRIVATE HELPER FUNCTIONS***********************/
    void Vehicle::getBaseModel(string& vin)
    {
        baseModel = vin.substr(0, 3);
    }
}

//*****************************************************************************************************************************
//*EXAMPLE ' vehicles_db.txt ' FILE********************************************************************************************
//*****************************************************************************************************************************
/*
RGLK27844	14800	8	0
RLVY26499	17450	10	2
Moonroof
Leather upholstery
RLTS43992	18456.9	13	3
5 spd manual transmission
4WD, heavy duty suspension
Trailer hitch
RGMA74881	23050	6	0
TLTD37882	29544.5	11	1
ST Package
RLTX26888	0	4	0
RGMC33389	15000	3	0
RGLL44488	23999	2	0
*/
