#include <iostream>
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0)
{
	std::cout << "Phonebook constructor called" << std::endl;
	std::cout << "PhoneBook initialized with " << count << " contacts" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}
void PhoneBook::addContact(int index)
{
	Contact contact = collectContactData(index++);
	this->contacts[0] = contact;
	std::cout << "Contact " << contact.get_first_name() << " was created" << std::endl;
}

Contact PhoneBook::collectContactData(int index) {
	std::string first_name;
	std::string last_name;
	std::string phone;
	std::string secret;

	std::cout << "Please enter the first name" << std::endl;
	std::cin >> first_name;
	std::cout << "Please enter the last name" << std::endl;
	std::cin >> last_name;
	std::cout << "Please enter the phone number" << std::endl;
	std::cin >> phone;
	std::cout << "Please enter the darkest secret" << std::endl;
	std::cin >> secret;

	Contact contact(index, first_name, last_name, phone, secret);
	return contact;
}
