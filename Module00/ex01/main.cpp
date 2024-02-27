#include "amazingphonebook.h"
#include "PhoneBook.hpp"
#include <cstdlib>

static int new_command(std::string& buffer) {
	std::cout << "Enter a command: ";
	if (!std::getline(std::cin, buffer))
	{
		std::cerr << "Getline Error" << std::endl;
		return (1) ;
	}
	return (0);
}

int main()
{
	std::string buffer;
	PhoneBook contact_list;
	int oldest_contact = -1;

	while (true)
	{
		if (new_command(buffer) == 1)
			break;
		if (buffer == "EXIT" || buffer == "exit")
			break;
		else if (buffer == "ADD" || buffer == "add")
			contact_list.add_contact(&oldest_contact);
		else if (buffer == "SEARCH" || buffer == "search")
			contact_list.print_contact();
		else
			print_error();
	}
	return 0;
}
