#include <iostream>
#include <string>
#include <algorithm> // CAN'T USE THIS
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string s = argv[i];
		for (int j = 0; j < (int)s.size(); j++)
			std::cout << (char)std::toupper(s[j]);
		// std::transform(s.begin(), s.end(), s.begin(), (int (*)(int))std::toupper);
		// std::cout << s;
	}
	std::cout << std::endl;

	return 0;
}
