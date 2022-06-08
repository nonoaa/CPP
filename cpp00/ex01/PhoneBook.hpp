#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook
{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;

	public:
		void add_contact(void);
		void print_all(void);
		void print_preview(int index);
		void print_column(std::string str);
};

#endif