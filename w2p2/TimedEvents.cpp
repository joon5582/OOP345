// Workshop 2 part1
// TimedEvents.cpp
// Junwoo Lee
// 124395203
// 9/26/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#include <iostream>
#include <iomanip>
#include <cstring>
#include "TimedEvents.h"


namespace sdds {
	TimedEvents::TimedEvents() : m_numOfRecords(0) {}
	TimedEvents& TimedEvents::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
		return *this;
	}
	TimedEvents& TimedEvents::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
		return *this;
	
	}
	TimedEvents& TimedEvents::addEvent(const char* cstr)
	{
		m_events[m_numOfRecords].eventName = cstr;
		m_events[m_numOfRecords].predefUnitTime = "nanoseconds";
		m_events[m_numOfRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_numOfRecords++;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const TimedEvents& te)
	{
		std::cout << "--------------------------" << std::endl;
		std::cout << "Execution Times:" << std::endl;
		std::cout << "--------------------------" << std::endl;
		for (int i = 0; i<(int)te.m_numOfRecords; i++) {
			std::cout << std::setw(21) << std::left << te.m_events[i].eventName;
			std::cout << std::setw(13) << std::right << te.m_events[i].duration.count() << ' ';
			std::cout << te.m_events[i].predefUnitTime << std::endl;
		}
		std::cout << "--------------------------" << std::endl;
		return os;
	}
}