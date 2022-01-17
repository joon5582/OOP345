// Workshop 4 part2
// ConfirmationSender.h
// Junwoo Lee
// 124395203
// 10/10/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
#include "Restaurant.h"
namespace sdds {
	class ConfirmationSender {
		const Reservation** m_resArray=nullptr;
		size_t m_numOfres = 0;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& I);
		ConfirmationSender(ConfirmationSender&& I) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender& other);
		ConfirmationSender& operator=(ConfirmationSender&& other) noexcept;
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmationSender);
	};

}

#endif