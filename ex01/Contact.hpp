#ifndef CONTACT_CLASS
# define CONTACT_CLASS

# include <string>

class Contact
{
private:
	int	_index;
	std::string const _darkest_secret;
	std::string const _first_name;
	std::string const _last_name;
	std::string const _phone_number;
public:

	Contact( int _index,
		std::string first_name,
		std::string last_name,
		std::string phone_number,
		std::string darkest_secret
	);
	~Contact();

	std::string get_first_name(void) const;
};


#endif
