// Workshop 4 part2
// ConfirmationSender.cpp
// Junwoo Lee
// 124395203
// 10/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include "ConfirmationSender.h"
namespace sdds {

	ConfirmationSender::ConfirmationSender() :m_resArray(nullptr)
	{
		m_numOfres = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& I)
	{
		*this = I;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& I) noexcept
	{
		*this = std::move(I);
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other)
	{
		if (this != &other) {
			delete[] m_resArray;
			m_numOfres = other.m_numOfres;
			m_resArray = new const Reservation * [m_numOfres];
			for (size_t i = 0; i < m_numOfres; i++) {
				m_resArray[i] = other.m_resArray[i];
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept
	{
		if (this != &other) {
			delete[] m_resArray;
			m_numOfres = other.m_numOfres;
			m_resArray = other.m_resArray;
			other.m_numOfres = 0;
			other.m_resArray = nullptr;
		}
		return *this;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_resArray;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool isFound = false;
		if (m_numOfres == 0) {
			m_resArray = new const Reservation * [1];
			m_resArray[m_numOfres] = &res;
			m_numOfres++;
		}
		else if (m_numOfres > 0) {
			for (size_t i = 0; i < m_numOfres && !isFound; i++) {
				if (m_resArray[i] == &res) isFound = true;
			}
			if (!isFound) {
				ConfirmationSender temp = *this;
				delete[] m_resArray;
				m_resArray = new const Reservation*[++m_numOfres];
				for (size_t i = 0; i < m_numOfres - 1; i++) {
					m_resArray[i] = temp.m_resArray[i];
				}
				m_resArray[m_numOfres - 1] = &res;
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		int isFound = -1;
		if (m_numOfres > 0) {
			for (int i = 0; i < (int)m_numOfres && isFound<0; i++) {
				if (m_resArray[i] == &res) isFound = i;
			}
			if (isFound>=0) {
				ConfirmationSender temp = *this;
				delete[] m_resArray;
				m_resArray = new const Reservation * [--m_numOfres];
				for (int i = 0; i < isFound; i++) {
					m_resArray[i] = temp.m_resArray[i];
				}
				for (int i = isFound; i < (int)m_numOfres; i++) {
					m_resArray[i] = temp.m_resArray[i + 1];
				}
			}
		}
		return *this;
	}
	
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmationSender)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (confirmationSender.m_numOfres == 0) {
			os << "There are no confirmations to send!" << std::endl;
		}
		else {
			for (size_t i = 0; i < confirmationSender.m_numOfres; i++) {
				os << *(confirmationSender.m_resArray[i]);
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}