// Workshop 1 part1
// event.h
// Junwoo Lee
// 124395203
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_


namespace sdds {

	class Event {
		char m_descOfevent[129];
		unsigned int m_eventStartTime;
		void setempty();
	public:
		Event();
		void display()const;
		void set(char* cstr = nullptr);
	};

}

#endif