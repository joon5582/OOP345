// Workshop 4 part2
// Restaurant.h
// Junwoo Lee
// 124395203
// 10/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <utility>
#include "Reservation.h"
namespace sdds {
	class Restaurant {
		Reservation* m_resArray = nullptr;
		size_t m_arraySize=0;

	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& I);
		Restaurant(Restaurant&& I) noexcept;
		Restaurant& operator=(const Restaurant& other);
		Restaurant& operator=(Restaurant&& other) noexcept;
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
	};
	
}

#endif