#include <iostream>
#include <iomanip>
#include "./PhoneBook.hpp"
#include <cstdlib>
#include <algorithm>

PhoneBook::PhoneBook() : count(0) {
	std::cout << "PhoneBook constructor called" << std::endl;
	std::cout << "PhoneBook initialized with " << count << " contacts" << std::endl;
	return ;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destructor called" << std::endl;
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
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;
	std::cout << "__________|__________|__________|__________" << std::endl;

	int contacts_to_show = (count > 8) ? 8 : count;

	for (int i = 0; i < contacts_to_show; i ++)
	{
		std::cout << std::setw(10) << contacts[i].get_index() << "|"
				<< std::setw(10) << formatString(contacts[i].get_first_name()) << "|"
				<< std::setw(10) << formatString(contacts[i].get_last_name()) << "|"
				<< std::setw(10) << formatString(contacts[i].get_nickname())
				<< std::endl;
	}

	std::cout << "Enter the index: " << std::endl;
	std::string input;
	std::getline(std::cin, input);
	while (!validateNumber(input))
		std::getline(std::cin, input);
	int contact_index = std::atoi(input.c_str());
	while (contact_index < 0 || contact_index >= contacts_to_show) {
		std::cout << "Invalid index. Please enter a number between 0 and " << (contacts_to_show - 1) << std::endl;
		std::getline(std::cin, input);
		contact_index = std::atoi(input.c_str());
	}
	displayContact(getContact(contact_index));
}

void	PhoneBook::displayContact(Contact contact) {
	std::cout << "=== VIEW CONTACT ===" << std::endl;
	std::cout << "First name: " << contact.get_first_name() << std::endl
			 << "Last name: " << contact.get_last_name() << std::endl
			 << "Nickname: " << contact.get_nickname() << std::endl
			 << "Phone number: " << contact.get_phone() << std::endl
			 << "Darkest Secret: " << contact.get_secret() << std::endl;
			 std::cout << "=================" << std::endl << std::endl;
}

void PhoneBook::addContact()
{
	int index = count % 8;
	Contact contact = collectContactData(index);

	if (count >= 8) {
		std::cout << "Replacing contact at position " << index << std::endl;
	}

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
		std::cout << "Please enter a valid number (only digits)" << std::endl;
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

	std::cout << "=== ADD NEW CONTACT ===" << std::endl;
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
	std::cout << "Contact successfully added!" << std::endl << std::endl;
	return contact;
}

Contact PhoneBook::getContact(int index) const {
	return this->contacts[index];
}

void	PhoneBook::startPhonebook() {
	std::string option;

	while(1) {
		std::cout << "What do you wanna do?" << std::endl;
		std::cout << "[   ADD  ]" << std::endl;
		std::cout << "[ SEARCH ]" << std::endl;
		std::cout << "[  EXIT  ]" << std::endl;

		if (!std::getline(std::cin, option)) {
			std::cout << "\nEOF detected. Exiting phonebook." << std::endl;
			return;
		}

		std::transform(option.begin(), option.end(), option.begin(), ::toupper);
		if (option == "ADD")
			addContact();
		else if (option == "SEARCH")
			search();
		else if (option == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Please enter one of the options below." << std::endl;
	}
}
