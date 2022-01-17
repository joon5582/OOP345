// Workshop 1 part2
// event.h
// Junwoo Lee
// 124395203
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_

extern unsigned int g_sysClock;

namespace sdds {

	class Event {
		char* m_descOfevent;
		unsigned int m_eventStartTime;
		void setempty();
	public:
		Event();
		Event(const Event& I);
		~Event();
		void display()const;
		void set(char* cstr = nullptr);
		Event& operator=(const Event& other);
	};



}

#endif