#ifndef unitFunc_Included
#define unitFunc_Included

#include <string>
using namespace std;

enum Length_Unit {eLengthUnit_m, eLengthUnit_cm, eLengthUnit_km, eLengthUnit_ft, 
					eLengthUnit_in, eLengthUnit_mi, eLengthUnit_ERROR};

struct length{
	double len;
	Length_Unit uni;
};

Length_Unit SuffixStringToLengthUnit(string suf);

length ReadLength();

string getUnitType(length l);

void printLength(length l);

length convertToMeters(length l);

#endif