#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int	_count;

	Contact	_collectContactData(int index);
	Contact	_getContact(int index) const;
	bool	_validateString(std::string field);
	bool	_validateNumber(std::string field);
	void	_displayContactTable(int contacts_to_show);
	void	_displayContact(Contact contact);
	std::string	_formatString(std::string text);
public:
	PhoneBook();
	~PhoneBook();

	void	startPhonebook();
	void	addContact();
	void	search();


};

#endif
