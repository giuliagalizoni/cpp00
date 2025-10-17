#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{

	int index = _count % 8;
	Contact contact = _collectContactData(index);
	if (contact.get_index() == -1)
		return;
	if (_count >= 8)
	{
		std::cout << "Replacing contact at position " << index << std::endl;
	}

	this->_contacts[index] = contact;
	_count++;
	std::cout << "Contact " << contact.get_first_name() << " was created"
			  << std::endl;
}

void PhoneBook::search()
{
	std::cout << "Searching..." << std::endl;

	if (_count == 0)
	{
		std::cout << "You don't have any contacts yet :(" << std::endl
				  << "how about adding some?" << std::endl
				  << std::endl;
		return;
	}

	int contacts_to_show = (_count > 8) ? 8 : _count;
	_displayContactTable(contacts_to_show);

	std::cout << "Enter the index: " << std::endl;
	std::string input;
	if (!std::getline(std::cin, input))
		return;
	while (!_validateNumber(input))
	{
		if (!std::getline(std::cin, input))
			return;
	}

	int contact_index = std::atoi(input.c_str());
	while (contact_index < 0 || contact_index >= contacts_to_show)
	{
		std::cout << "Invalid index. Please enter a number between 0 and "
				  << (contacts_to_show - 1) << std::endl;
		if (!std::getline(std::cin, input))
			return;
		contact_index = std::atoi(input.c_str());
	}
	_displayContact(_getContact(contact_index));
}

Contact PhoneBook::_collectContactData(int index)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;

	std::cout << "=== ADD NEW CONTACT ===" << std::endl;
	if (!_fillField(first_name, "first name") ||
		!_fillField(last_name, "last name") ||
		!_fillField(nickname, "nickname") ||
		!_fillField(phone, "phone number") ||
		!_fillField(secret, "darkest secret"))
	{
		return Contact();
	}

	Contact contact =
		Contact(index, first_name, last_name, nickname, phone, secret);
	std::cout << "Contact successfully added!" << std::endl << std::endl;

	return contact;
}

bool PhoneBook::_fillField(std::string &field, std::string field_name)
{
	std::cout << "Please enter the " << field_name << " :" << std::endl;
	if (!std::getline(std::cin, field))
		return false;
	if (field_name == "phone number")
	{
		while (!_validateNumber(field))
		{
			if (!std::getline(std::cin, field))
				return false;
		}
	}
	else
	{
		while (!_validateString(field))
		{
			if (!std::getline(std::cin, field))
				return false;
		}
	}
	return true;
}
void PhoneBook::_displayContactTable(int contacts_to_show)
{
	std::cout << "Which contact would you like to see?" << std::endl;
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10)
			  << "First Name" << "|" << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << "__________|__________|__________|__________" << std::endl;

	for (int i = 0; i < contacts_to_show; i++)
	{
		std::cout << std::setw(10) << _contacts[i].get_index() << "|"
				  << std::setw(10)
				  << _formatString(_contacts[i].get_first_name()) << "|"
				  << std::setw(10)
				  << _formatString(_contacts[i].get_last_name()) << "|"
				  << std::setw(10) << _formatString(_contacts[i].get_nickname())
				  << std::endl;
	}
}

void PhoneBook::_displayContact(Contact contact)
{
	std::cout << "=== VIEW CONTACT ===" << std::endl;
	std::cout << "First name: " << contact.get_first_name() << std::endl
			  << "Last name: " << contact.get_last_name() << std::endl
			  << "Nickname: " << contact.get_nickname() << std::endl
			  << "Phone number: " << contact.get_phone() << std::endl
			  << "Darkest Secret: " << contact.get_secret() << std::endl;
	std::cout << "=================" << std::endl << std::endl;
}


bool PhoneBook::_validateString(std::string field)
{
	if (field.empty() ||
		field.find_first_not_of(" \t\n\r") == std::string::npos)
	{
		std::cout << "This field cannot be empty. Please try again"
				  << std::endl;
		return false;
	}
	return true;
}

bool PhoneBook::_validateNumber(std::string field)
{
	if (field.empty() ||
		field.find_first_not_of(" \t\n\r") == std::string::npos)
	{
		std::cout << "This field cannot be empty. Please try again"
				  << std::endl;
		return false;
	}
	if (field.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Please enter a valid number (only digits)" << std::endl;
		return false;
	}
	return true;
}


Contact PhoneBook::_getContact(int index) const
{
	return this->_contacts[index];
}

std::string PhoneBook::_formatString(std::string text)
{
	if (text.length() > 10)
		return text.substr(0, 9).append(".");
	return text;
}
