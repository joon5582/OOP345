// Workshop 2 part1
// StringSet.cpp
// Junwoo Lee
// 124395203
// 9/26/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <fstream>
#include "StringSet.h"
#include "utility"
using namespace sdds;

StringSet::StringSet() {}

StringSet::StringSet(const char* cstr)
{
	std::ifstream fin(cstr);
	std::string word;
	size_t count = 0;
	while (std::getline(fin, word, ' '))count++;
	m_numOfstring = count;
	m_stringArray = new std::string[m_numOfstring];
	fin.clear();
	fin.seekg(0);
	size_t i = 0;
	while (std::getline(fin, m_stringArray[i++], ' '));
}

StringSet::StringSet(const StringSet& I)
{
	*this = I;
}

sdds::StringSet::StringSet(StringSet&& I)
{
	*this = std::move(I);
}

StringSet::~StringSet()
{
	delete[] m_stringArray;
}

StringSet& StringSet::operator=(const StringSet& other)
{
	if (this != &other)
	{
		delete[] m_stringArray;
		m_numOfstring = other.m_numOfstring;
		m_stringArray = new std::string[m_numOfstring];
		for (size_t i = 0; i < m_numOfstring; i++)
		{
			m_stringArray[i] = other.m_stringArray[i];
		}
	}
	return *this;
}

StringSet& StringSet::operator=(StringSet&& other)
{
	if (this != &other)
	{
		delete[] m_stringArray;
		m_numOfstring = other.m_numOfstring;
		m_stringArray = other.m_stringArray;		
		other.m_stringArray = nullptr;
		other.m_numOfstring = 0;
	}
	return *this;
}

size_t StringSet::size() const
{
	return m_numOfstring;
}

std::string StringSet::operator[](size_t index) const
{
	return (index >= 0 && index < m_numOfstring) ? m_stringArray[index] : "";
}
	
