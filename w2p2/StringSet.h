// Workshop 2 part1
// StringSet.h
// Junwoo Lee
// 124395203
// 9/26/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include <string>

namespace sdds {
	class StringSet {
		std::string* m_stringArray=nullptr;
		size_t m_numOfstring = 0;
	public:
		StringSet();
		StringSet(const char* cstr);
		StringSet(const StringSet& I);
		StringSet(StringSet&& I);
		~StringSet();
		StringSet& operator=(const StringSet& other);
		StringSet& operator=(StringSet&& other);
		size_t size() const;
		std::string operator[](size_t index) const;
	};
}



#endif // !SDDS_STRINGSET_H
