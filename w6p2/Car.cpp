// Workshop 6 part2
// Car.cpp
// Junwoo Lee
// 124395203
// 11/5/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds {
	Car::Car(std::istream& istr)
	{
		string str, tag, maker, condition;
		
		getline(istr, str);
		if (str.length()!=0) {
  			tag = str.substr(0, str.find(','));
			trim(tag);
			str.erase(0, str.find(',') + 1);
			m_maker = str.substr(0, str.find(','));
			trim(m_maker);

			str.erase(0, str.find(',') + 1);

			m_condition = str.substr(0, str.find(','));
			trim(m_condition);
			if (m_condition == "") m_condition = "n";
			if (m_condition != "n" && m_condition != "u" && m_condition != "b")
				throw "Invalid record!";

			str.erase(0, str.find(',') + 1);
			try {
				m_topspeed = stoi(str);
			}
			catch (const invalid_argument& e) {
				throw e;
			}
		}
	}
	std::string Car::condition() const
	{
		string result;
		if (m_condition == "n")
			result = "new";
		else if (m_condition == "u")
			result = "used";
		else if (m_condition == "b")
			result = "broken";
		return result;
	}

	double Car::topSpeed() const
	{
		return m_topspeed;
	}

	void Car::display(ostream& out) const
	{
		out << "| " << setw(10) << right << m_maker;
		out << " | " << setw(6) << left << condition();
		out << " | " << setw(6) << fixed << setprecision(2) << topSpeed()<< " |";
	}

	void Car::trim(string& src) const
	{
		if (src.length() > 0) {
			int begin = src.find_first_not_of(' ');
			int end = src.find_last_not_of(' ');
			if (begin == -1) src = "";
			else src = src.substr(begin, end - begin + 1);
		}
		
	}
}