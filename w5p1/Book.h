#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>

namespace sdds {

	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_desc;
		void trim(std::string& src);
	public:
		Book();
		void setprice(double price);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};


}


#endif