
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact
{
	public :
		Contact();
		~Contact();
		void set_first_name(const std::string name);
		void set_last_name(const std::string name);
		void set_nickname(const std::string name);
		void set_phonenumber(const std::string name);
		void set_darkest_secret(const std::string name);
		const std::string	getFirstName(int lenght) const;
		const std::string	getLastName(int lenght) const;
		const std::string	getNickName(int lenght) const;
		const std::string	getPhoneNumber() const;
		const std::string	getDarkestSecret() const;
		void display_chosen_contact();

	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif