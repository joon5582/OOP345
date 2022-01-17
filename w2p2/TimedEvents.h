// Workshop 2 part1
// TimedEvents.h
// Junwoo Lee
// 124395203
// 9/26/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <chrono>
#include <string>


const unsigned int maxNumofEvents = 10;

namespace sdds { 
	class TimedEvents {
		unsigned int m_numOfRecords;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		struct Event {
			std::string eventName;
			std::string predefUnitTime;
			std::chrono::steady_clock::duration duration;
		}m_events[maxNumofEvents];
		
		
	public:
		TimedEvents();
		TimedEvents& startClock();
		TimedEvents& stopClock();
		TimedEvents& addEvent(const char* cstr);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& te);
	};
	

}



#endif