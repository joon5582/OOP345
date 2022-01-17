#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"
namespace sdds {
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation=nullptr;
	public:
		Workstation(const std::string& str);
		Workstation(const Workstation& I) = delete;
		Workstation(Workstation&& I) = delete;
		Workstation& operator=(const Workstation& other) = delete;
		Workstation& operator=(Workstation& other) = delete;
		~Workstation();
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};


}


#endif
