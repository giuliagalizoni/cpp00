#ifndef CONTACT_CLASS
# define CONTACT_CLASS

# include <string>

class Contact
{
private:
	int	_index;
	std::string _first_name;
	std::string _last_name;
	std::string _phone_number;
	std::string _darkest_secret;
public:
	Contact(); // Default constructor

	// Parameterized constructor
	Contact( int _index,
		std::string first_name,
		std::string last_name,
		std::string phone_number,
		std::string darkest_secret
	);
	~Contact();

	std::string get_first_name(void) const;
	std::string get_last_name(void) const;
	std::string get_phone(void) const;
	std::string get_secret(void) const;
};


#endif
