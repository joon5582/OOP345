// Workshop 6 part2
// Autoshop.h
// Junwoo Lee
// 124395203
// 11/5/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		Autoshop();
		Autoshop(const Autoshop& I) = delete;
		Autoshop& operator=(const Autoshop& other) = delete;
		void display(std::ostream& out) const;
		~Autoshop();
		
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto& v : m_vehicles) {
				if (test(v)) vehicles.push_back(v);
			}
		}
	};
}

#endif // !SDDS_AUTOSHOP_H

