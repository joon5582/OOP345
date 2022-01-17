// Workshop 3 part2
// Set.h
// Junwoo Lee
// 124395203
// 9/30/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {

	template<size_t N, class T>
	class Set {
		T m_dataArray[N];
		size_t m_numOfelements = 0;
	public:
		size_t size() const {
			return m_numOfelements;
		}
		const T& get(size_t idx) const {
			return m_dataArray[idx];
		}
		void operator+=(const T& item) {
			if (m_numOfelements < N) m_dataArray[m_numOfelements++] = item;
						
		}
	};
}


#endif // !SDDS_SET_H
