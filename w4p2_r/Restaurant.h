#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include <utility>
#include "Reservation.h"
namespace sdds {
	class Restaurant {
		Reservation* m_resArray = nullptr;
		size_t m_arraySize=0;

	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& I);
		Restaurant(Restaurant&& I);
		Restaurant& operator=(const Restaurant& other);
		Restaurant& operator=(Restaurant&& other);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
	};
	
}

#endif