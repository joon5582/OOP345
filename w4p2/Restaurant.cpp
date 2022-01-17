// Workshop 4 part2
// Restaurant.cpp
// Junwoo Lee
// 124395203
// 10/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include "Restaurant.h"

namespace sdds {
	sdds::Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_resArray = new Reservation [cnt];
		m_arraySize = cnt;
		for (size_t i = 0; i < m_arraySize; i++) {
			m_resArray[i] = *reservations[i];
		}
	}

	Restaurant::Restaurant(const Restaurant& I)
	{
		*this = I;
	}
	Restaurant::Restaurant(Restaurant&& I) noexcept {
		*this = std::move(I);
	}

	Restaurant& Restaurant::operator=(const Restaurant& other)
	{
		if (this != &other) {
			
			delete[] m_resArray;
			m_arraySize = other.m_arraySize;
			m_resArray = new Reservation [m_arraySize];
			for (size_t i = 0; i < m_arraySize; i++) {
				m_resArray[i] = other.m_resArray[i];
			}
		}
		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
		if (this != &other) {
			delete[] m_resArray;
			m_resArray = other.m_resArray;
			other.m_resArray = nullptr;
			m_arraySize = other.m_arraySize;
			other.m_arraySize = 0;

		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		delete[] m_resArray;
	}

	size_t sdds::Restaurant::size() const
	{
		return m_arraySize;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant)
	{
		static int counter{ 0 };
		counter++;
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << counter << ")" << std::endl;
		os << "--------------------------" << std::endl;
		if (restaurant.size() == 0) {
			os << "This restaurant is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < restaurant.size(); i++) {
				os << restaurant.m_resArray[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}