// Workshop 1 part1
// event.cpp
// Junwoo Lee
// 124395203
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"
unsigned int g_sysClock = 0;
using namespace std;
namespace sdds {
	void Event::setempty()
	{
		strcpy(m_descOfevent, "");
		m_eventStartTime = 0;
	}
	Event::Event()
	{
		setempty();
	}

	void Event::display() const
	{
		static int counter = 0;
		counter++;
		int hour = m_eventStartTime / 3600;
		int min = (m_eventStartTime % 3600) / 60;
		int sec = (m_eventStartTime % 3600) % 60;
		cout << setw(2) << setfill(' ') << counter << ". ";
		if (m_descOfevent && m_descOfevent[0] != '\0')
		{
			cout << setw(2) << setfill('0') << hour;
			cout << ":" << setw(2) << setfill('0') << min;
			cout << ":" << setw(2) << setfill('0') << sec;
			cout << " => " << m_descOfevent << endl;
		}
		else {
			cout << "| No Event |" << endl;
		}
	}

	void Event::set(char* cstr)
	{
		if (cstr && cstr[0] != '\0')
		{
			strcpy(m_descOfevent, cstr);
			m_eventStartTime = g_sysClock;
		}
		else
		{
			setempty();
		}
	}

}