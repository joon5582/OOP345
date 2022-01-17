// Workshop 5 part2
// SpellChecker.h
// Junwoo Lee
// 124395203
// 18/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>
#include <iostream>

#include <string_view>
namespace sdds {

	class SpellChecker {
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t m_replaceCounter[6]{};
		std::size_t replace_all(std::string& inout, std::string what, std::string with);
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}




#endif
