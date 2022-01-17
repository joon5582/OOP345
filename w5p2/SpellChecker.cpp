// Workshop 5 part2
// SpellChecker.cpp
// Junwoo Lee
// 124395203
// 18/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
namespace sdds {

	size_t SpellChecker::replace_all(std::string& source, std::string what, std::string with)
	{
		size_t count = 0;
		std::string::size_type pos = 0;
		while ((pos = source.find(what, pos)) != std::string::npos) {
			source.replace(pos, what.length(), with);
			pos += with.length();
			count++;
		}
		return count;
	}

	sdds::SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file) throw "Bad file name!";
		else {
			size_t i = 0;
			do {
				file >> m_badWords[i] >> m_goodWords[i];
				i++;
			} while (i < 6 && file);

		}
	}


	void sdds::SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6 && m_badWords[i].length() != 0; i++) {
			m_replaceCounter[i]+=replace_all(text, m_badWords[i], m_goodWords[i]);
		}
	}

	void sdds::SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6 && m_badWords[i].length() != 0; i++) {
			out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replaceCounter[i] << " replacements" << std::endl;
		}
	}

}
