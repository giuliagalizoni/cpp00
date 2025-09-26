#include <iostream>
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0)
{
	// std::cout << "Phonebook constructor called" << std::endl;
	std::cout << "PhoneBook initialized with " << count << " contacts" << std::endl;
	return ;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

void	PhoneBook::search() {
	std::cout << "Searching..." << std::endl;
}

void PhoneBook::addContact()
{
	int index = count % 8;
	Contact contact = collectContactData(index);
	this->contacts[index] = contact;
	count++;
	std::cout << "Contact " << contact.get_first_name() << " was created" << std::endl;
}

Contact PhoneBook::collectContactData(int index) {
	std::string first_name;
	std::string last_name;
	std::string phone;
	std::string secret;

	std::cout << "Please enter the first name" << std::endl;
	std::getline(std::cin, first_name);
	std::cout << "Please enter the last name" << std::endl;
	std::getline(std::cin, last_name);
	std::cout << "Please enter the phone number" << std::endl;
	std::getline(std::cin, phone);
	std::cout << "Please enter the darkest secret" << std::endl;
	std::getline(std::cin, secret);

	Contact contact(index, first_name, last_name, phone, secret);
	return contact;
}

Contact PhoneBook::getContact(int index) {
	return this->contacts[index];
}

void	PhoneBook::startPhonebook() {
	std::string option;

	while(1) {
		std::cout << "What do you wanna do?" << std::endl;
		std::cout << "[   ADD  ]" << std::endl;
		std::cout << "[ SEARCH ]" << std::endl;
		std::cout << "[  EXIT  ]" << std::endl;
		std::getline(std::cin, option);

		if (option == "ADD")
			addContact();
		else if (option == "SEARCH")
			search();
		else if (option == "EXIT")
			break; //TODO: exit gracefully;
		else
			std::cout << "Please enter one of the options below." << std::endl;
	}
}
