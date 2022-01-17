#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>
namespace sdds {
	class Reservation {
		std::string m_reservationID;
		std::string m_name;
		std::string m_email;
		size_t m_numOfpeople=0;
		int m_date=0;
		int m_hour=0;

	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		void trim(std::string& src);
		friend std::ostream& operator<<(std::ostream& os, const Reservation res);
	};
	
}

#endif
