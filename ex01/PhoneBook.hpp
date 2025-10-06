#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int	count;
	Contact	collectContactData(int index);
	bool	validateString(std::string field);
	bool	validateNumber(std::string field);
public:
	PhoneBook();
	~PhoneBook();

	void	startPhonebook();
	void	addContact();
	void	search();
	Contact	getContact(int index) const;
	void	displayContact(Contact contact);
};

#endif
