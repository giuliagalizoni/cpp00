#include <iostream>
#include <string>
#include <algorithm>
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
		std::transform(s.begin(), s.end(), s.begin(), (int (*)(int))std::toupper);
		std::cout << s;
	}
	std::cout << std::endl;

	return 0;
}
