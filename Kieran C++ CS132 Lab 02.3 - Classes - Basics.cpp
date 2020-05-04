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
private:
    string vin;                                 // The vehicle ID number
    double price;                               // The current asking price for the vehicle
    int weeksOnLot;                             // How many weeks the vehicle has been inventoried
};

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
// POSTCONDITION: If match is found, data printed to screen, otherwise the user is informed of failure.
void ageInventory(Vehicle&);                    // DEPRECATED FUNCTION
// This function that ages an intire vehicle inventory by 1 week
// PRECONTDITION: A file of tab seperated values of type STRING, DOUBLE, & INT
// POSTCONDITION: an output file of the VIN & PRICE of each vehicle with the WEEKS ON LOT data increased by 1

/***********************MAIN***********************/
int main()
{
    ofstream out_stream;                        // Declare the output file
    int menuChoice(0);                          // For user interaction

    cout << "WELCOME TO THE VEHICLE INVENTORY DATA PROGRAM!!!\n";
    do
    {
        cout << "\nMenu:\n 1) View Inventory\n 2) New Entry\n 3) Update Entry\n 4) Search Inventory\n 0) Exit program\n\nChoice: ";
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
bool Vehicle::rdVehicle(istream& rdS)
{
    if (rdS >> vin)                             // Checks for more entries
	{
		rdS >> price >> weeksOnLot;             // Fills the other 2 values from stream
		return (true);                          // Returns true if reads in another set
	}
	return (false);                             // No other entries exist, Return FALSE
}
void Vehicle::wrtVehicle(ostream& wrtS)
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
    price = -1.00;
    weeksOnLot = 0;
}
Vehicle::Vehicle(string newVin)                 // Single Argument Constructor
{
    vin = newVin;
    price = -1.00;
    weeksOnLot = 0;
}
Vehicle::Vehicle(string newVin, double newPrice)// Double Argument Constructor
{
    vin = newVin;
    price = newPrice;
    weeksOnLot = 0;
}

/***********************NON-MEMBER FUNCTIONS***********************/
void viewInv1()                                 // The 1) View Inventory menu choice
{
    ifstream in_stream;                         // Declare the input file
    string In_File_Name;                        // Variable for storing name of input file
    Vehicle vehicle1;                           // Default constructor

    cout << "Enter the input file name.\n";
    cout << "[The default file is ' vehicles.txt ']\n\n";
    cin >> In_File_Name;                        // The input file that contains Vehicle information
    cout << endl;
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
    string Out_File_Name;                       // Variable for storing name of output file
    string vin;
    double price;
    int choice(0);

    cout << "Enter the output file name.\n";
    cout << "[The default file is ' output.txt ']\n\n";
    cin >> Out_File_Name;                       // The input file that contains Vehicle information
    cout << endl;
    out_stream.open(Out_File_Name, ios::app);   // Open the output file appending
    if (out_stream.fail())                      // Checks to see if open function fails
    {
        cout << "Output file opening failed.\n";
        return;
    }

    cout << "9 Digit VIN of the vehicle: ";
    cin >> vin;
    cout << "Do you know the price of the vehicle?\n1) YES\n0) NO\n\nChoice: ";
    cin >> choice;

    if (choice != 1)
    {
        Vehicle newVehicle(vin);                // Single Argument Constructor
        newVehicle.wrtVehicle(out_stream);
    }
    else {
        cout << "\nEnter the PRICE of the vehicle without punctuation: ";
        cin >> price;
        Vehicle newVehicle(vin,price);          // Double Argument Constructor
        newVehicle.wrtVehicle(out_stream);
    }
    out_stream.close();
}

void updateInv3()                               // The 3) Update Entry menu choice.
{
    ifstream in_stream;                         // Declare the input file
    ofstream out_stream;                        // Declare the output file
    string In_File_Name, Out_File_Name;         // Variables for storing name of the input/output files
    Vehicle vehicle1;                           // Default constructor
    int weeksOnLotTemp;
    double priceTemp;

    cout << "Enter the input file name.\n";
    cout << "[The default file is ' vehicles.txt ']\n\n";
    cin >> In_File_Name;                        // The input file that contains Vehicle information
    cout << endl;
    in_stream.open(In_File_Name);               // Open input file
    if (in_stream.fail())                       // Check to see if open function fails
    {
        cout << "Input file opening failed.\nFile does not exist.\n";
        return;
    }
    cout << "Enter the output file name.\n";
    cout << "[The default file is ' output.txt ']\n\n";
    cin >> Out_File_Name;                       // The input file that contains Vehicle information
    cout << endl;
    out_stream.open(Out_File_Name, ios::app);   // Open the output file appending
    if (out_stream.fail())                      // Checks to see if open function fails
    {
        cout << "Output file opening failed.\n";
        in_stream.close();
        return;
    }

    while (vehicle1.rdVehicle(in_stream) == true)// Loop until all entries read
    {
        cout << "How many Weeks has " << vehicle1.getVin() << " been on the lot? ";
        cin >> weeksOnLotTemp;
        cout << "What is the dollar amount of " << vehicle1.getVin() << " ? ";
        cin >> priceTemp;
        if (weeksOnLotTemp >= vehicle1.getWeeksOnLot())
        {                                       // Checks and updates weeks on lot one VIN at a time
            vehicle1.updateWeeksOnLot(weeksOnLotTemp);
            cout << vehicle1.getVin() << " Weeks on lot Updated\n\n";
        }
        if (priceTemp <= vehicle1.getPrice())
        {                                       // Checks and updates price one VIN at a time
            vehicle1.updatePrice(priceTemp);
            cout << vehicle1.getVin() << " Price Updated\n\n";
        }
        vehicle1.wrtVehicle(out_stream);
    }

    in_stream.close();
    out_stream.close();
}

void searchInv4()                               // The 4) Search Inventory menu choice.
{
    ifstream in_stream;                         // Declare the input file
    string In_File_Name;                        // Variable for storing name of input file
    string vinSearch;                           // Variable for storing VIN of desired vehicle
    string vinSearchTemp;                       // Variable for storing VIN of current vehicle
    Vehicle vehicle1;                           // Default constructor
    int count(0);                                  // Variable for counting VIN matches

    cout << "Enter the input file name.\n";
    cout << "[The default file is ' vehicles.txt ']\n\n";
    cin >> In_File_Name;                        // The input file that contains Vehicle information
    cout << endl;
    in_stream.open(In_File_Name);               // Open input file
    if (in_stream.fail())                       // Check to see if open function fails
    {
        cout << "Input file opening failed.\nFile does not exist.\n";
        return;
    }

    cout << "Enter the first 3 characters of the VIN to search.\n";
    cout << "[EXAMPLE: ' RGL ']\n\n";
    cin >> vinSearch;
    cout << endl;

    while (vehicle1.rdVehicle(in_stream) == true)// Loop until all entries read
    {
        std::string vinSearchTemp = vehicle1.getVin().substr(0,3);
        if (vinSearch == vinSearchTemp)
        {
            vehicle1.wrtVehicle(cout);
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No matches found for " << vinSearch << " in inventory.\n\n";
    }
    in_stream.close();
}

void ageInventory(Vehicle& x)                   // DEPRECATED FUNCTION
{
    int localI = x.getWeeksOnLot();             // Accessor Function
    localI += 1;                                // Age by 1 week on lot
    x.updateWeeksOnLot(localI);                 // Mutator Function
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
