// Name: Junwoo Lee
// Seneca Student ID: 124395203
// Seneca email: jlee648@myseneca.ca
// Date of completion: 11/18/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"


using namespace std;
using namespace sdds;

namespace sdds {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;
	Station::Station(const std::string& str)
	{
		size_t pos = 0;
		bool more = true;
		Utilities util;
		m_stationId = ++id_generator;
		try {
			m_itemName = util.extractToken(str, pos, more);
			m_nextSerialNum = stoi(util.extractToken(str, pos, more));
			m_numOfItems = stoi(util.extractToken(str, pos, more));
			Station::m_widthField = Station::m_widthField > util.getFieldWidth() ? Station::m_widthField : util.getFieldWidth();
			m_desc = util.extractToken(str, pos, more);
		}
		catch (std::invalid_argument& e) {
			throw e;
		}


	}
	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_nextSerialNum++;
	}
	size_t Station::getQuantity() const
	{
		return m_numOfItems;
	}
	void Station::updateQuantity()
	{
		if (m_numOfItems >= 1)
			m_numOfItems--;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		os << '[' << setw(3) << setfill('0') << right << m_stationId
			<< "] Item: " << setw(m_widthField) << setfill(' ') << left << m_itemName
			<< " [" << setw(6) << right << setfill('0') << m_nextSerialNum << ']';
		if (full) {
			os << " Quantity: " << setw(m_widthField) << setfill(' ') << left << m_numOfItems
				<< " Description: " << m_desc;
		}
		os << endl;
	}
}