#include <iostream>
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook(Contact contacts[8])
{
	std::cout << "constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "destructor called" << std::endl;
	return ;
}

