// Workshop 3 part2
// Pair.h
// Junwoo Lee
// 124395203
// 9/30/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
namespace sdds {

	template<typename V, typename K>
	class Pair {
		K m_key{};
		V m_value{};
		
	public:
		Pair() {};
		Pair(const K& key, const V& value) : m_key(key), m_value(value){}
		const V& value() const {
			return m_value;
		}
		const K& key() const {
			return m_key;
		}
		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		}
	};
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}

}

#endif