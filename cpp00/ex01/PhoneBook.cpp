#include "PhoneBook.hpp"

void PhoneBook::add_contact(void)
{
    int i;
    std::string input;

    std::cout << std::endl;
    std::cout << "1. First name : ";
    std::getline(std::cin, input);
    this->first_name = input;

    std::cout << "2. Last name: ";
    std::getline(std::cin, input);
    this->last_name = input;

    std::cout << "3. Nickname : ";
    std::getline(std::cin, input);
    this->nickname = input;

    std::cout << "4. Phone number : ";
    std::getline(std::cin, input);
    this->phone_number = input;

    std::cout << "5. Darkest secret : ";
    std::getline(std::cin, input);
    this->darkest_secret = input;
}

void PhoneBook::print_all(void)
{
    std::cout << "First name : " << this->first_name << std::endl;
    std::cout << "Last name : " << this->last_name << std::endl;
    std::cout << "Nickname : " << this->nickname << std::endl;
    std::cout << "Phone number : " << this->phone_number << std::endl;
    std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
}

void PhoneBook::print_preview(int index)
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

void PhoneBook::print_column(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0 , 9) + ".";
        std::cout << std::right << std::setw(10) << str;
    }
    else
        std::cout << std::right << std::setw(10) << str;
}