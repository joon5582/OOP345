// Workshop 8 part2
// Utilities.cpp
// Junwoo Lee
// 124395203
// 11/21/2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		Product* rP;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					rP = new Product(desc[i].desc, price[j].price);
					rP->validate();
					priceList += rP;
					delete rP;
				}
			}
		}


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		unique_ptr<Product> sP;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					sP = make_unique<Product>(desc[i].desc, price[j].price);
					sP->validate();
					priceList += move(sP);
				}
			}
		}

		return priceList;
	}
}