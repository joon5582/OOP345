// Workshop 3 part2
// SetSummable.h
// Junwoo Lee
// 124395203
// 9/30/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
namespace sdds {

	template<size_t N, class T>
	class SetSummable : public Set<N, T>{
		
	public:
		T accumulate(const std::string& filter) const {
			T result{ filter };
			for (size_t i = 0; i < sdds::Set<N, T>::size(); i++) {
				if (sdds::Set<N, T>::get(i).isCompatibleWith(result))
					result += sdds::Set<N, T>::get(i);
			}
			return result;
		}
	};
}


#endif 
