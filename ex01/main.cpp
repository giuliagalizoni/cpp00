#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phonebook;
	phonebook.startPhonebook();
	Contact contact = phonebook.getContact(0);
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "Last name: " << contact.get_last_name() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;

	return 0;
}
