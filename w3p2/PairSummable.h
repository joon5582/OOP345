// Workshop 3 part2
// PairSummable.h
// Junwoo Lee
// 124395203
// 9/30/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Pair.h"
namespace sdds {

	template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initialValue;
		static size_t minWidth;
	public:
		PairSummable() {};
		PairSummable(const K& key, const V& value = initialValue) : Pair<V, K>(key, value) {
			if (key.size() > minWidth) minWidth = key.size();
		};
		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			return b.key() == this->key();
		}
		void display(std::ostream& os) const {
			os << std::left << std::setw(minWidth);
			sdds::Pair<V, K>::display(os);
			os << std::right;
		}
		PairSummable<V, K>& operator+=(const PairSummable<V, K>& other) {
			return *this = PairSummable(this->key(), this->value()+other.value());
		}
	};
	
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& other) {
		if (this->value() != "") *this = PairSummable(this->key(), value() + ", " + other.value());
		else *this = PairSummable(this->key(), other.value());
		return *this;
	}

	template<typename V, typename K>
	V PairSummable<V, K>::initialValue{};
	template<typename V, typename K>
	size_t PairSummable<V, K>::minWidth = 0;

}



#endif