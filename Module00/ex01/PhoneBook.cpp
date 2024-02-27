#include "PhoneBook.hpp"
#include "amazingphonebook.h"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::set(int index, std::string str, void (Contact::*setter)(std::string))
{
	(contact_list[index].*setter)(str);
}

int	PhoneBook::end_of_contact_list(int *oldest_contact)
{
	int	i = 0;

	while (i < 8)
	{
		if (contact_list[i].getDarkestSecret().size() == 0)
			return (i);
		i++;
	}
	if (*oldest_contact < 8)
		*oldest_contact+=1;
	else
		*oldest_contact = 0;
	return (*oldest_contact);
}

void PhoneBook::add_contact(int *oldest_contact)
{
	int index;
	std::string buffer;

	index = this->end_of_contact_list(oldest_contact);

	std::cout << "Enter First Name : ";
	std::getline(std::cin, buffer);
	if (buffer.size() == 0 || isValidString(buffer) == false)
	{
		std::cout << INPUT_ERROR << std::endl;
		return;
	}
	this->set(index, buffer.c_str(), &Contact::set_first_name);

	std::cout << "Enter Last Name : ";
	std::getline(std::cin, buffer);
	if (buffer.size() == 0 || isValidString(buffer) == false)
	{
		std::cout << INPUT_ERROR << std::endl;
		return;
	}
	this->set(index, buffer.c_str(), &Contact::set_last_name);

	std::cout << "Enter NickName : ";
	std::getline(std::cin, buffer);
	if (buffer.size() == 0 || isValidString(buffer) == false)
	{
		std::cout << INPUT_ERROR << std::endl;
		return;
	}
	this->set(index, buffer.c_str(), &Contact::set_nickname);

	std::cout << "Enter Phone Number : ";
	std::getline(std::cin, buffer);
	if (buffer.size() == 0 || isValidString(buffer) == false)
	{
		std::cout << INPUT_ERROR << std::endl;
		return;
	}
	this->set(index, buffer.c_str(), &Contact::set_phonenumber);

	std::cout << "Enter Darkest Secret : ";
	std::getline(std::cin, buffer);
	if (buffer.size() == 0 || isValidString(buffer) == false)
	{
		std::cout << INPUT_ERROR << std::endl;
		return;
	}
	this->set(index, buffer.c_str(), &Contact::set_darkest_secret);

}

void PhoneBook::print_contact()
{
	int			index;
	std::string param;
	int			nb_of_contacts = -1;

	std::cout << "INDEX------FIRST_NAME-LAST_NAME--NICKNAME---" <<std::endl;
	index = 0;
	while (index < 8)
	{
		if (contact_list[index].getDarkestSecret().size() > 0)
		{
			nb_of_contacts++;
			std::cout <<index;
			std::cout <<"         ";
			std::cout << "|";
			param = contact_list[index].getFirstName(TRUNCATED);
			std::cout << std::setfill(' ') << std::setw(10) << param.substr(0,10) << "|";
			param = contact_list[index].getLastName(TRUNCATED);
			std::cout << std::setfill(' ') << std::setw(10) << param.substr(0,10) << "|";
			param = contact_list[index].getNickName(TRUNCATED);
			std::cout << std::setfill(' ') << std::setw(10) << param.substr(0,10) << "|";
			std::cout << std::endl;
		}
		index++;
	}
	if (nb_of_contacts > -1)
	{
		index = ask_index();
		if (index > nb_of_contacts || index < 0)
			std::cout <<"This index does not correspond to a contact"<<std::endl;
		else
			contact_list[index].display_chosen_contact();
	}
}