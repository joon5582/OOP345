// Workshop 5 part2
// book.h
// Junwoo Lee
// 124395203
// 18/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>

namespace sdds {

	class Book {
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{};
		double m_price{};
		std::string m_desc{};
		void trim(std::string& src);
	public:
		Book();
		void setprice(double price);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		}
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}

#endif