#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int	_count;

	bool	_collectContactData(int index, Contact& contact);
	Contact	_getContact(int index) const;
	bool	_fillField(std::string field, std::string field_name);
	bool	_validateString(std::string field);
	bool	_validateNumber(std::string field);
	void	_displayContactTable(int contacts_to_show);
	void	_displayContact(Contact contact);
	void	_handleEOF();
	std::string	_formatString(std::string text);
public:
	PhoneBook();
	~PhoneBook();

	void	startPhonebook();
	void	addContact();
	void	search();


};

#endif
