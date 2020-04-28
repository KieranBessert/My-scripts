// Practice with Classes
// Coded by Kieran Bessert	4/26/2020
// Laster edited 4/26/2020

#include <iostream>
#include <fstream>				// File I/O
#include <string>				// use of Strings
using namespace std;

class PII
{
public:
	void rdPerson(ifstream&);
	string getLastN();			// Accessor Function
	void putLastN(string);		// Mutator Function
private:
	string last4SSN, firstN, lastN, emailAddress;
};

int main()
{
	PII person1;
	person1.putLastN("Doe");
	cout << "Last name " << person1.getLastN() << endl;

	ifstream rdStream;
	string diskFile = "..\\persons.txt";
	rdStream.open(diskFile);	// Not checking for failure, but YOU better!

	for (int ix = 0; ix < 5; ix++)
	{
		person1.rdPerson(rdStream);
		cout << "Record #" << ix + 1 << ": " << person1.getLastN() << endl;
	}

	rdStream.close();			//.close() file when done
	return 0;
}

void PII::rdPerson(ifstream& rdS)
{
	char c;

	rdS >> last4SSN >> firstN;
	rdS.get(c);					// Pull leading tab character from stream
	getline(rdS, lastN, '\t');	// Grabs multi-word name
	rdS >> emailAddress;		// Grabs rest of line
}
string PII::getLastN()			// Accessor Function
{
	return(lastN);
}
void PII::putLastN(string s)	// Mutator Function
{
	lastN = s;
}

/* EXAMPLE ' persons.txt ' FILE */
/*
5555	luke	skywalker	Red5@RebelAlliance.com
1111	han	solo	DirtyScoundrel@CaptainMelleniumFalcon.com
3333	leia	organa	AlderaanPrincess@Alderaan.com
0202	r2	d2	BeepBoop@BoopBeep.com
3390	c3	p0	GoodnessGraciousMe@mindlessphilosopher.com
0000	lando	calrissian	Administrator@CloudCity.org
*/
