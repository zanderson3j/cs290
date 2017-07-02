#include <iostream>
#include "unitFunc.h"
using namespace std;

int main() {

	while (true) {
		length test = ReadLength();
		printLength(test);
		test = convertToMeters(test);
		printLength(test);
		cout << "Enter 0 to continue or any other number to quit: ";
		int cnt;
		cin >> cnt;
		if (cnt != 0) break;
		else  cin.get();
	}

}