// Workshop 5 part2
// Book.cpp
// Junwoo Lee
// 124395203
// 18/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>
#include "Book.h"

namespace sdds {
	Book::Book() {};
	void Book::setprice(double price)
	{
		m_price = price;
	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_country;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}
	Book::Book(const std::string& strBook)
	{
		std::string temp = strBook;
		std::string author = temp.substr(0, temp.find(','));
		trim(author);

		temp.erase(0, temp.find(',') + 1);

		std::string title = temp.substr(0, temp.find(','));
		trim(title);

		temp.erase(0, temp.find(',') + 1);

		std::string country = temp.substr(0, temp.find(','));
		trim(country);

		temp.erase(0, temp.find(',') + 1);

		double price = std::stod(temp);

		temp.erase(0, temp.find(',') + 1);

		int year = std::stoi(temp);

		

		temp.erase(0, temp.find(',') + 1);

		std::string desc = temp;
		trim(desc);
		m_author = author;
		m_title = title;
		m_country = country;
		m_year = year;
		m_price = price;
		m_desc = desc;
	}

	void Book::trim(std::string& src)
	{
		int begin = src.find_first_not_of(' ');
		int end = src.find_last_not_of(' ');
		src = src.substr(begin, end - begin + 1);
	}
	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << std::setw(20) << std::right << book.m_author << " | ";
		os << std::setw(22) << std::right << book.m_title << " | ";
		os << std::setw(5) << std::right << book.m_country << " | ";
		os << std::setw(4) << std::right << book.m_year << " | ";
		os << std::setw(6) << std::fixed<<std::setprecision(2) << std::right << book.m_price << " | ";
		os << book.m_desc << std::endl;

		return os;
	}
}