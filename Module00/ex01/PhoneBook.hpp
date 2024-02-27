#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class	PhoneBook
{
	public :
		PhoneBook();
		~PhoneBook();
		void	add_contact(int *oldest_contact);
		void	print_contact();;
		void	set(int index, std::string str, void (Contact::*setter)(std::string));
		int	end_of_contact_list(int *oldest_contact);
	private:
		Contact	contact_list[8];
};

#endif
