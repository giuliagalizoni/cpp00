#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

# include <string>
# include <array>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int	count;
	Contact	collectContactData(int index);
public:
	PhoneBook();
	~PhoneBook();

	void	startPhonebook();
	void	addContact();
	void	search();
	Contact	getContact(int index);
};



#endif
