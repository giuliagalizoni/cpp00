#include <iostream>
#include <iomanip>
#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0) {
	// std::cout << "Phonebook constructor called" << std::endl;
	std::cout << "PhoneBook initialized with " << count << " contacts" << std::endl;
	return ;
}

PhoneBook::~PhoneBook() {
	std::cout << "Phonebook destructor called" << std::endl;
	return ;
}

std::string	formatString(std::string text) {
	if (text.length() > 10)
		return text.substr(0, 9).append(".");
	return text;
}

void	PhoneBook::search() {
	std::cout << "Searching..." << std::endl;

	if (count == 0)
	{
		std::cout << "You don't have any contacts yet :(" << std::endl
				<< "how about adding some?" << std::endl << std::endl;
		return ;
	}
	std::cout << "Which contact would you like to see?" << std::endl;

	for (int i = 0; i < count; i ++)
	{
		std::cout << std::setw(10) << contacts[i].get_index() << "|"
				<< std::setw(10) << formatString(contacts[i].get_first_name()) << "|"
				<< std::setw(10) << formatString(contacts[i].get_last_name()) << "|"
				<< std::setw(10) << formatString(contacts[i].get_nickname())
				<< std::endl;
	}

	std::cout << "Enter the index: " << std::endl;
	int contact_index;
	std::cin >> contact_index; // TODO: error handling here
	std::cin.ignore();
	displayContact(getContact(contact_index));
}

void	PhoneBook::displayContact(Contact contact) {
	std::cout << "First name: " << contact.get_first_name() << std::endl
			 << "Last name: " << contact.get_last_name() << std::endl
			 << "Nickname: " << contact.get_nickname() << std::endl
			 << "Phone number: " << contact.get_phone() << std::endl
			 << "Darkest Secret: " << contact.get_secret() << std::endl;
}

void PhoneBook::addContact()
{
	int index = count % 8;
	Contact contact = collectContactData(index);
	this->contacts[index] = contact;
	count++;
	std::cout << "Contact " << contact.get_first_name() << " was created" << std::endl;
}

bool	PhoneBook::validateString(std::string field) {
	if (field.empty() || field.find_first_not_of(" \t\n\r") == std::string::npos) {
		std::cout << "This field cannot be empty. Please try again" << std::endl;
		return false;
	}
	return true;
}

bool	PhoneBook::validateNumber(std::string field) {
	if (field.empty() || field.find_first_not_of(" \t\n\r") == std::string::npos) {
		std::cout << "This field cannot be empty. Please try again" << std::endl;
		return false;
	}
	if (field.find_first_not_of("0123456789") != std::string::npos) {
		std::cout << "Please enter a valid phone number" << std::endl;
		return false;
	}
	return true;
}

Contact PhoneBook::collectContactData(int index) {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;

	std::cout << "Please enter the first name" << std::endl;
	std::getline(std::cin, first_name);
	while (!validateString(first_name))
		std::getline(std::cin, first_name);
	std::cout << "Please enter the last name" << std::endl;
	std::getline(std::cin, last_name);
	while (!validateString(last_name))
		std::getline(std::cin, last_name);
	std::cout << "Please enter the nickname" << std::endl;
	std::getline(std::cin, nickname);
	while (!validateString(nickname))
		std::getline(std::cin, nickname);
	std::cout << "Please enter the phone number" << std::endl;
	std::getline(std::cin, phone);
	while (!validateNumber(phone))
		std::getline(std::cin, phone);
	std::cout << "Please enter the darkest secret" << std::endl;
	std::getline(std::cin, secret);
	while (!validateString(secret))
		std::getline(std::cin, secret);

	Contact contact(index, first_name, last_name, nickname, phone, secret);
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

		if (option == "ADD" || option == "add")
			addContact();
		else if (option == "SEARCH" || option == "search")
			search();
		else if (option == "EXIT" || option == "exit") {
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Please enter one of the options below." << std::endl;
	}
}
