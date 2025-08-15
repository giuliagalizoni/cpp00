#include "Contact.hpp"
#include <iostream>

Contact::Contact(
		int p0,
		std::string p1,
		std::string p2,
		std::string p3,
		std::string p4
	) : _index(p0),
		_first_name(p1),
		_last_name(p2),
		_phone_number(p3),
		_darkest_secret(p4) {
	std::cout << "Contact constructor was called" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact destructor was called" << std::endl;
}

std::string Contact::get_first_name(void) const {
	return this->_first_name;
}
