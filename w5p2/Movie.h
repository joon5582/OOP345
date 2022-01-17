// Workshop 5 part2
// Movie.h
// Junwoo Lee
// 124395203
// 18/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
namespace sdds {

	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};
		void trim(std::string& src);
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

	};

}


#endif
