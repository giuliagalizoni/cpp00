#include "Contact.hpp"
#include <iostream>

Contact::Contact() : _index(-1), _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
	// std::cout << "Contact default constructor was called" << std::endl;
}

Contact::Contact(
	int p0,
	std::string p1,
	std::string p2,
	std::string p3,
	std::string p4,
	std::string p5) : _index(p0),
					  _first_name(p1),
					  _last_name(p2),
					  _nickname(p3),
					  _phone_number(p4),
					  _darkest_secret(p5)
{
	std::cout << "Contact created with index " << _index << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact destructor was called for index " << this->_index << std::endl;
}

int Contact::get_index(void) const
{
	return _index;
}

std::string Contact::get_first_name(void) const
{
	return this->_first_name;
}

std::string Contact::get_last_name(void) const
{
	return this->_last_name;
}

std::string Contact::get_nickname(void) const
{
	return this->_nickname;
}

std::string Contact::get_phone(void) const
{
	return this->_phone_number;
}

std::string Contact::get_secret(void) const
{
	return this->_darkest_secret;
}
