#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"
#include "Restaurant.h"
namespace sdds {
	class ConfirmationSender {
		const Reservation** m_resArray=nullptr;
		size_t m_numOfres = 0;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& I);
		ConfirmationSender(ConfirmationSender&& I);
		ConfirmationSender& operator=(const ConfirmationSender& other);
		ConfirmationSender& operator=(ConfirmationSender&& other);
		~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmationSender);
	};

}

#endif