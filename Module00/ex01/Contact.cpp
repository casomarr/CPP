#include "Contact.hpp"
#include "amazingphonebook.h"

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::~Contact()
{
}

void	Contact::set_first_name(const std::string name)
{
	first_name = name;
}

void	Contact::set_last_name(const std::string name)
{
	last_name = name;
}

void	Contact::set_nickname(const std::string name)
{
	nickname = name;
}

void	Contact::set_phonenumber(const std::string name)
{
	phone_number = name;
}

void	Contact::set_darkest_secret(const std::string name)
{
	darkest_secret = name;
}

const std::string Contact::getFirstName(int length) const
{
	if (length == TRUNCATED)
	{
		if (first_name.size() > 9)
			return first_name.substr(0,9) + ".";
		return first_name;
	}
	return first_name;
}

const std::string Contact::getLastName(int length) const
{
	if (length == TRUNCATED)
	{
		if (last_name.size() > 9)
			return last_name.substr(0,9) + ".";
		return last_name;
	}
		return last_name;
}

const std::string Contact::getNickName(int length) const
{
	if (length == TRUNCATED)
	{
		if (nickname.size() > 9)
			return nickname.substr(0,9) + ".";
		return nickname;
	}
	return nickname;
}

const std::string Contact::getPhoneNumber() const
{
	return phone_number;
}

const std::string Contact::getDarkestSecret() const
{
	return darkest_secret;
}

void Contact::display_chosen_contact()
{
	std::cout << "First Name : ";
	std::cout << this->getFirstName(FULL);
	std::cout << std::endl;
	std::cout << "Last Name : ";
	std::cout << this->getLastName(FULL);
	std::cout << std::endl;
	std::cout << "Nick Name : ";
	std::cout << this->getNickName(FULL);
	std::cout << std::endl;
	std::cout << "Phone Number : ";
	std::cout << this->getPhoneNumber();
	std::cout << std::endl;
	std::cout << "Darkest Secret : ";
	std::cout << this->getDarkestSecret();
	std::cout << std::endl;
}