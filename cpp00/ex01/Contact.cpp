#include "Contact.hpp"

void Contact::add_contact(void)
{
    int i = 0;
    std::string input;

    std::cout << std::endl;
    std::cout << "1. First name : ";
    while (std::getline(std::cin, input))
    {
        if (i == 0)
        {
            if (input == "")
            {
		        std::cout << "Error: input must not be empty." << std::endl;
		        std::cout << "1. First name : ";
                continue;
            }
            this->first_name = input;
            i++;
            std::cout << "2. Last name: ";
        }
        else if (i == 1)
        {
            if (input == "")
            {
		        std::cout << "Error: input must not be empty." << std::endl;
		        std::cout << "2. Last name: ";
                continue;
            }
            this->last_name = input;
            i++;
            std::cout << "3. Nickname : ";
        }
        else if (i == 2)
        {
            if (input == "")
            {
		        std::cout << "Error: input must not be empty." << std::endl;
		        std::cout << "3. Nickname : ";
                continue;
            }
            this->nickname = input;
            i++;
            std::cout << "4. Phone number : ";
        }
        else if (i == 3)
        {
            if (input == "")
            {
		        std::cout << "Error: input must not be empty." << std::endl;
		        std::cout << "4. Phone number : ";
                continue;
            }
            this->phone_number = input;
            i++;
            std::cout << "5. Darkest secret : ";
        }
        else if (i == 4)
        {
            if (input == "")
            {
		        std::cout << "Error: input must not be empty." << std::endl;
		        std::cout << "5. Darkest secret : ";
                continue;
            }
            this->darkest_secret = input;
            i++;
            break;
        }
    }
}

void Contact::print_all(void)
{
    std::cout << "First name : " << this->first_name << std::endl;
    std::cout << "Last name : " << this->last_name << std::endl;
    std::cout << "Nickname : " << this->nickname << std::endl;
    std::cout << "Phone number : " << this->phone_number << std::endl;
    std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
}

void Contact::print_preview(int index)
{
    print_column(std::to_string(index));
    std::cout << "|";
    print_column(this->first_name);
    std::cout << "|";
    print_column(this->last_name);
    std::cout << "|";
    print_column(this->nickname);
    std::cout << std::endl;
}

void Contact::print_column(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0 , 9) + ".";
        std::cout << std::right << std::setw(10) << str;
    }
    else
        std::cout << std::right << std::setw(10) << str;
}