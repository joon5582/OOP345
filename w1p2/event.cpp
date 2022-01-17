// Workshop 1 part2
// event.cpp
// Junwoo Lee
// 124395203
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

unsigned int g_sysClock{ 0 };

using namespace std;
namespace sdds {
	void Event::setempty()
	{
		delete[] m_descOfevent;
		m_descOfevent = nullptr;
		m_eventStartTime = 0;
	}
	Event::Event() :m_descOfevent(nullptr), m_eventStartTime(0) {}

	Event::Event(const Event& I) : m_descOfevent(nullptr), m_eventStartTime(0)
	{
		this->operator=(I);
	}

	Event::~Event()
	{
		delete[] m_descOfevent;
	}


	void Event::display() const
	{
		static int counter{ 0 };
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
		setempty();
		if (cstr && cstr[0] != '\0')
		{
			m_descOfevent = new char[strlen(cstr) + 1];
			strcpy(m_descOfevent, cstr);
			m_eventStartTime = g_sysClock;
		}
	}

	Event& Event::operator=(const Event& other)
	{
		if (this != &other)
		{
			setempty();
			if (other.m_descOfevent && other.m_descOfevent[0] != '\0')
			{
				m_descOfevent = new char[strlen(other.m_descOfevent) + 1];
				strcpy(m_descOfevent, other.m_descOfevent);
				m_eventStartTime = other.m_eventStartTime;
			}
		}
		return *this;
	}



}