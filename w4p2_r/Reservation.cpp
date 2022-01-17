#include <iomanip>
#include "Reservation.h"

namespace sdds {
	sdds::Reservation::Reservation()
	{
	}

	void sdds::Reservation::update(int day, int time)
	{
		m_date = day;
		m_hour = time;
	}

	sdds::Reservation::Reservation(const std::string& res)
	{
		std::string temp = res;
		std::string id = temp.substr(0, temp.find(':'));
		trim(id);

		temp.erase(0, temp.find(':')+1);

		std::string name = temp.substr(0, temp.find(','));
		trim(name);

		temp.erase(0, temp.find(',')+1);

		std::string email = temp.substr(0, temp.find(','));
		trim(email);

		temp.erase(0, temp.find(',')+1);

		int numOfpeople = std::stoi(temp);

		temp.erase(0, temp.find(',')+1);

		int day = std::stoi(temp);

		temp.erase(0, temp.find(',')+1);

		int hour = std::stoi(temp);
		m_reservationID = id;
		m_name = name;
		m_email = email;
		m_numOfpeople = numOfpeople;
		m_date = day;
		m_hour = hour;
	}

	void Reservation::trim(std::string& src)
	{
		int begin = src.find_first_not_of(' ');
		int end = src.find_last_not_of(' ');
		src = src.substr(begin, end-begin+1);
	}

	


	std::ostream& operator<<(std::ostream& os, const Reservation res)
	{
		os << "Reservation " << std::setw(10) << std::right << res.m_reservationID << ": " << std::setw(20) << std::right << res.m_name << "  " << std::setw(20) << std::left << "<" + res.m_email + ">" << "    ";
		int hour = res.m_hour;
		if (hour >= 6 && hour <= 9)
			os << "Breakfast on day "<<res.m_date<<" @ " << hour << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople==1? " person.":" people." )<< std::endl;
		else if (hour >= 11 && hour <= 15)
			os << "Lunch on day " << res.m_date << " @ " << hour << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople == 1 ? " person." : " people.") << std::endl;
		else if (hour >= 17 && hour <= 21)
			os << "Dinner on day " << res.m_date << " @ " << hour << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople == 1 ? " person." : " people.") << std::endl;
		else
			os << "Drinks on day " << res.m_date << " @ " << hour << ":00 for " << res.m_numOfpeople << (res.m_numOfpeople == 1 ? " person." : " people.") << std::endl;
		return os;
	}

}

