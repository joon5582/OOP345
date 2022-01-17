// Workshop 5 part2
// Movie.cpp
// Junwoo Lee
// 124395203
// 18/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iomanip>
#include "Movie.h"
namespace sdds {
	void Movie::trim(std::string& src)
	{
		int begin = src.find_first_not_of(' ');
		int end = src.find_last_not_of(' ');
		src = src.substr(begin, end - begin + 1);
	}
	Movie::Movie(){}

	const std::string& Movie::title() const
	{
		return m_title;
	}

	Movie::Movie(const std::string& strMovie)
	{
		std::string temp = strMovie;

		std::string title = temp.substr(0, temp.find(','));
		trim(title);

		temp.erase(0, temp.find(',') + 1);
		int year = std::stoi(temp);

		temp.erase(0, temp.find(',') + 1);
		std::string desc = temp;
		trim(desc);
	
		m_title = title;
		m_year = year;
		m_desc = desc;
	}


	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << std::setw(40) << std::right << movie.m_title << " | ";
		os << std::setw(4) << std::right << movie.m_year << " | ";
		os << movie.m_desc << std::endl;

		return os;
	}



}

