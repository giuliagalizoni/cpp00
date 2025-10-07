#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main()
{
	PhoneBook phonebook;
	std::string option;

	while (1)
	{
		std::cout << "What do you wanna do?" << std::endl;
		std::cout << "[   ADD  ]" << std::endl;
		std::cout << "[ SEARCH ]" << std::endl;
		std::cout << "[  EXIT  ]" << std::endl;

		if (!std::getline(std::cin, option))
		{
			std::cout << "\nEOF detected. Exiting phonebook." << std::endl;
			return 1;
		}

		if (option == "ADD")
			phonebook.addContact();
		else if (option == "SEARCH")
			phonebook.search();
		else if (option == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Please enter one of the options below." << std::endl;
	}

	return 0;
}
