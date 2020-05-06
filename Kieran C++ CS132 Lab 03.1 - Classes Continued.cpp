// This program is used to manage an inventory of vehicles from a file on the local drive.
// Coded by Kieran Bessert	4/26/2020
// Last edited  5/4/2020

#include <iostream>
#include <fstream>                              // File I/O
#include <string>                               // use of Strings
#include <cstdlib>                              // Included for use of exit() function
using namespace std;

/***********************CLASS***********************/
class Vehicle
{
public:
    bool rdVehicle(istream&);
    void wrtVehicle(ostream&);

    string getVin();                            // Vin Accessor Function
    void updateVin(string);                     // Vin Mutator Function
    double getPrice();                          // Price Accessor Function
    void updatePrice(double);                   // Price Mutator Function
    int getWeeksOnLot();                        // WeeksOnLot Accessor Function
    void updateWeeksOnLot(int);                 // WeeksOnLot Mutator Function

    Vehicle();                                  // Default Constructor
    Vehicle(string newVin);                     // Single Argument Constructor
    Vehicle(string newVin, double newPrice);    // Double Argument Constructor

    friend bool compareModel(Vehicle& car1, Vehicle& car2);// Friend function compare base model
    friend bool operator ==(Vehicle& car1, Vehicle& car2);// Friend function compare base model
    friend Vehicle operator ++(Vehicle& car1);  // Friend function increment WEEKS ON LOT
private:
    void getBaseModel(string&);                 // Internal Private Helper Function
    string baseModel;                           // The first 3 characters of the VIN

    string vin;                                 // The vehicle ID number
    double price;                               // The current asking price for the vehicle
    int weeksOnLot;                             // How many weeks the vehicle has been inventoried
};

/***********************CONSTANT VARIABLES***********************/
const string In_File_Name = "vehicles.txt";     // Constant variable for storing name of the input file
const string Out_File_Name = "output.txt";      // Constant variable for storing name of the output file

/***********************NON-MEMBER FUNCTIONS***********************/
void viewInv1();
// This function reads input data from a file and displays it on screen
// PRECONTDITION: A file of tab seperated values of type STRING, DOUBLE, & INT
// POSTCONDITION: cout statement of the VIN, PRICE, & WEEKS ON LOT data contained in the file
void addToInv2();
// This function appends information to vehicle inventory output file from user input
// PRECONTDITION: New VIN, PRICE, & WEEKS ON LOT data required for inputing by user
// POSTCONDITION: An append output file with the entered data, tab seperated
void updateInv3();
// This function updates the full list of vehicle inventory's PRICE and WEEKS ON LOT, one VIN at a time
// PRECONTDITION: Vehicle Inventory input file and New PRICE & WEEKS ON LOT data for user input
// POSTCONDITION: an output file of the VINs and new values if aged or PRICE lowered
void searchInv4();
// This function searches Vehicle inventory for a VIN value entered by the user
// PRECONTDITION: The first 3 values of VIN data a user wishes to search invetory for
// POSTCONDITION: If match is found, data printed to screen, otherwise the user is informed of failure
void makeUC(string&);          
// This function accepts a call by refrence string and uppercases the string for the length of a string
// PRECONDITION: Any string with lowercase letters
// POSTCONDITION: The string is capitalized

/***********************MAIN***********************/
int main()
{
    ofstream out_stream;                        // Declare the output file
    int menuChoice(0);                          // For user interaction

    cout << "WELCOME TO THE VEHICLE INVENTORY DATA PROGRAM!!!\n";
    do
    {
        cout << "\nMenu:\n 1) View Inventory\n 2) New Entry\n 3) Update Entry\n 4) Search Inventory\n 0) Exit program\n\n\tChoice: ";
        cin >> menuChoice;
        cout << endl << endl;

        switch (menuChoice)
        {
        case 0:
            cout << "THANK YOU FOR USING THE VEHICLE INVENTORY DATA PROGRAM!!!\n\nGOODBYE!\n\n";
            return (0);
        case 1:                                 // View contents of input file
            viewInv1();
            break;
        case 2:                                 // Add entry to input file
            addToInv2();
            break;
        case 3:                                 // Edit Entry of input file
            updateInv3();
            break;
        case 4:                                 // Search input file
            searchInv4();
            break;
        default:
            cout << "Illegal choice.\n";
        }
    } while (true);

    return 0;
}

/***********************MEMBER FUNCTIONS***********************/
bool Vehicle::rdVehicle(istream& rdS)           // Reads data from the stream
{
    if (rdS >> vin)                             // Checks for more entries
    {
        getBaseModel(vin);
        rdS >> price >> weeksOnLot;             // Fills the other 2 values from stream
        return (true);                          // Returns true if reads in another set
    }
    return (false);                             // No other entries exist, Return FALSE
}
void Vehicle::wrtVehicle(ostream& wrtS)         // Writes data to a stream
{
    wrtS << vin << "\t" << price << "\t" << weeksOnLot << "\n";
}
string Vehicle::getVin()                        // Accessor Function
{
    return(vin);
}
void Vehicle::updateVin(string newVin)          // Mutator Function
{
    vin = newVin;
    getBaseModel(newVin);
}
double Vehicle::getPrice()                      // Accessor Function
{
    return(price);
}
void Vehicle::updatePrice(double newPrice)      // Mutator Function
{
    price = newPrice;
}
int Vehicle::getWeeksOnLot()                    // Accessor Function
{
    return(weeksOnLot);
}
void Vehicle::updateWeeksOnLot(int newWeeks)    // Mutator Function
{
    weeksOnLot = newWeeks;
}
/***********************CONSTRUCTORS***********************/
Vehicle::Vehicle()                              // Default Constructor
{
    vin = "?";
    baseModel = "?";
    price = -1.00;
    weeksOnLot = 0;
}
Vehicle::Vehicle(string newVin)                 // Single Argument Constructor
{
    vin = newVin;
    getBaseModel(newVin);
    price = -1.00;
    weeksOnLot = 0;
}
Vehicle::Vehicle(string newVin, double newPrice)// Double Argument Constructor
{
    vin = newVin;
    getBaseModel(newVin);
    price = newPrice;
    weeksOnLot = 0;
}
/***********************FRIEND FUNCTIONS***********************/
bool compareModel(Vehicle& car1, Vehicle& car2) // Friend function compare base model
{
    return(car1.baseModel == car2.baseModel);
}
bool operator ==(Vehicle& car1, Vehicle& car2)  // Friend function compare base model
{
    return(car1.baseModel == car2.baseModel);
}
Vehicle operator ++(Vehicle& car1)              // Friend function increment WEEKS ON LOT
{
    Vehicle temp;
    car1.weeksOnLot += 1;
    return(temp);
}

/***********************PRIVATE HELPER FUNCTIONS***********************/
void Vehicle::getBaseModel(string& vin)
{
    baseModel = vin.substr(0, 3);
}

/***********************NON-MEMBER FUNCTIONS***********************/
void viewInv1()                                 // The 1) View Inventory menu choice
{
    ifstream in_stream;                         // Declare the input file
    Vehicle vehicle1;                           // Default constructor

    in_stream.open(In_File_Name);               // Open input file
    if (in_stream.fail())                       // Check to see if open function fails
    {
        cout << "Input file opening failed.\nFile does not exist.\n";
        return;
    }
    while (vehicle1.rdVehicle(in_stream) == true)// Loop until all entries read
    {
        vehicle1.wrtVehicle(cout);
    }
    in_stream.close();
}

void addToInv2()                                // The 2) New Entry menu choice
{
    ofstream out_stream;                        // Declare the output file
    string vin;
    double price;
    int choice(0);

    out_stream.open(Out_File_Name, ios::app);   // Open the output file appending
    if (out_stream.fail())                      // Checks to see if open function fails
    {
        cout << "Output file opening failed.\n";
        return;
    }

    cout << "9 Digit VIN of the vehicle: ";
    cin >> vin;
    cout << "Do you know the price of the vehicle?\n1) YES\n0) NO\n\n\tChoice: ";
    cin >> choice;

    if (choice != 1)
    {
        Vehicle newVehicle(vin);                // Single Argument Constructor
        newVehicle.wrtVehicle(out_stream);
    }
    else {
        cout << "\nEnter the PRICE of the vehicle without punctuation: ";
        cin >> price;
        Vehicle newVehicle(vin, price);          // Double Argument Constructor
        newVehicle.wrtVehicle(out_stream);
    }
    out_stream.close();
}

void updateInv3()                               // The 3) Update Entry menu choice.
{
    ifstream in_stream;                         // Declare the input file
    ofstream out_stream;                        // Declare the output file
    Vehicle vehicle1;                           // Default constructor
    string vinTemp;

    in_stream.open(In_File_Name);               // Open input file
    if (in_stream.fail())                       // Check to see if open function fails
    {
        cout << "Input file opening failed.\nFile does not exist.\n";
        return;
    }
    out_stream.open(Out_File_Name, ios::app);   // Open the output file appending
    if (out_stream.fail())                      // Checks to see if open function fails
    {
        cout << "Output file opening failed.\n";
        in_stream.close();
        return;
    }

    cout << "WEEKS ON LOT has been updated for ever vehicle in inventory;\n\n";
    while (vehicle1.rdVehicle(in_stream) == true)
    {
        ++vehicle1;
        vehicle1.wrtVehicle(cout);
        vehicle1.wrtVehicle(out_stream);
    }
    in_stream.close();
    out_stream.close();
}

void searchInv4()                               // The 4) Search Inventory menu choice.
{
    ifstream in_stream;                         // Declare the input file
    Vehicle vehicle2;                           // Default Constructor
    string vinSearch;                           // Variable for storing VIN of desired vehicle
    int count(0);                               // Variable for counting VIN matches

    in_stream.open(In_File_Name);               // Open input file
    if (in_stream.fail())                       // Check to see if open function fails
    {
        cout << "Input file opening failed.\nFile does not exist.\n";
        return;
    }

    cout << "Enter the first 3 characters of the VIN you wish to search for.\n";
    cout << "[EXAMPLE: ' RGL ']\n\n\tVIN: ";
    cin >> vinSearch;
    makeUC(vinSearch);
    Vehicle vehicle1(vinSearch);                 // Single Argument Constructor
    cout << endl;
    while (vehicle2.rdVehicle(in_stream) == true)// Loop until all entries read
    {
        /*
        if (compareModel(vehicle1,vehicle2))
        {
            vehicle2.wrtVehicle(cout);
            count++;
        }
        */
        if (vehicle1==vehicle2)
        {
            vehicle2.wrtVehicle(cout);
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No matches found for " << vinSearch << " in inventory.\n\n";
    }
    in_stream.close();
}

void makeUC(string& vin)                        //  Uppercases the first 3 letters of string input
{
    int count = (int)vin.length();

    for (; count-- > 0;)
    {
        vin[count] = toupper(vin[count]);
    }
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
