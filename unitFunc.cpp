#include <iostream>
#include <sstream>
#include <string>
#include "unitFunc.h"
using namespace std;

Length_Unit SuffixStringToLengthUnit(string suf) {
	
	#define DEFINE_UNIT(name, unit, suffix, system, plural)  if(suf == #suffix) return eLengthUnit_##suffix;
	#include "units.h"
	#undef DEFINE_UNIT
	return eLengthUnit_ERROR;
}

length ReadLength() {
	length store;
	while (true) {
		cout << "Please enter a real length: " << endl;
		stringstream s;
		string z;
		getline(cin, z);
		s << z;
		double x;
		if (s >> x) {
			char check;
			if (s >> check) {
				cout << "You entered more than required!" << endl;
				break;
			}
			store.len = x;
			break;
		}
		else {
			cout << "INVALID INPUT" << endl;
		}
	}
	while (true) {
		cout << "Please enter a unit suffix: " << endl;
		stringstream w;
		string y;
		getline(cin, y);
		w << y;
		string un;
		if (w >> un) {
			char check;
			if (w >> check) {
				cout << "You entered more than required!" << endl;
				break;
			}
			store.uni = SuffixStringToLengthUnit(un);
			break;
		}
		else {
			cout << "INVALID INPUT" << endl;
		}
	}
	return store;
}

string getUnitType(length l) {
	Length_Unit w = l.uni;
	switch (w) {
		#define DEFINE_UNIT(name, unit, suffix, system, plural) case eLengthUnit_##suffix : return #suffix;
		#include "units.h"
		#undef DEFINE_UNIT
		case eLengthUnit_ERROR : return "ERROR";
	}
}

void printLength(length l) {
	if (l.len != 1) {
		#define DEFINE_UNIT(name, unit, suffix, system, plural)  if(getUnitType(l) == #suffix) cout << l.len << #suffix << " " << "(" << l.len << " " << #plural << ")" << endl;
		#include "units.h"
		#undef DEFINE_UNIT
	}
	else {
		#define DEFINE_UNIT(name, unit, suffix, system, plural)  if(getUnitType(l) == #suffix) cout << l.len << #suffix << " " << "(" << l.len << " " << #name << ")" << endl;
		#include "units.h"
		#undef DEFINE_UNIT
	}
	if (l.uni == eLengthUnit_ERROR) {
		cout << l.len << " " << getUnitType(l) << endl;
	}
}

length convertToMeters(length l) {
	#define DEFINE_UNIT(name, unit, suffix, system, plural)  if (getUnitType(l) == #suffix) l.len = (l.len * unit);
	#include "units.h"
	#undef DEFINE_UNIT
	l.uni = eLengthUnit_m;
	return l;	
}