// Workshop 4 part2
// Reservation.h
// Junwoo Lee
// 124395203
// 10/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



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
