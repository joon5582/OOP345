// Workshop 6 part2
// Utilities.cpp
// Junwoo Lee
// 124395203
// 11/5/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <string>
#include <sstream>
#include "Car.h"
#include "Racecar.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* result = nullptr;

		char vType = '\0';

		string str;
		stringstream sstr;
		getline(in, str);
		if (in.eof()) in.setstate(std::ios_base::failbit);
		sstr.str(str);
		streampos pos = sstr.tellg();
		sstr >> vType;
		sstr.seekg(pos);


		if (vType == 'c' || vType == 'C')
		{
			result = new Car(sstr);
		}
		else if (vType == 'r' || vType == 'R') {
			result = new Racecar(sstr);
		}
		else {
			throw vType;
		}


		return result;
	}
}
