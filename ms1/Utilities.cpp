// Name: Junwoo Lee
// Seneca Student ID: 124395203
// Seneca email: jlee648@myseneca.ca
// Date of completion: 11/18/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"
using namespace std;
namespace sdds {
	char Utilities::m_delimiter{};
	void trim(string& src)
	{
		if (src.length() > 0) {
			int begin = src.find_first_not_of(' ');
			int end = src.find_last_not_of(' ');
			if (begin == -1) src = "";
			else src = src.substr(begin, end - begin + 1);
		}
	}

	void sdds::Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t sdds::Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string sdds::Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		int next_del;
		string result;
		if (str[next_pos] == m_delimiter)
		{
			more = false;
			throw - 1;
		}
			
		else {
			string temp = str.substr(next_pos);
			if ((next_del = temp.find_first_of(m_delimiter)) != -1) {
				result = temp.substr(0, next_del);
				trim(result);
				next_pos += next_del+1;
				more = true;
			}
			else {
				result = temp;
				trim(result);
				more = false;
			}
		}
		if (m_widthField < result.length())
			m_widthField = result.length();

		return result;
	}

	void sdds::Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char sdds::Utilities::getDelimiter()
	{
		return m_delimiter;
	}

}
