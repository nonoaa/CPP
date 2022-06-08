#include "PhoneBook.hpp"

void PhoneBook::add_contact(void)
{
    int i;
    std::string input;

    std::cout << std::endl;
    std::cout << "1. First name : ";
    std::getline(std::cin, input);
    first_name_ = input;

    std::cout << "2. Last name: ";
    std::getline(std::cin, input);
    last_name_ = input;

    std::cout << "3. Nickname : ";
    std::getline(std::cin, input);
    nickname_ = input;

    std::cout << "4. Phone number : ";
    std::getline(std::cin, input);
    phone_number_ = input;

    std::cout << "5. Darkest secret : ";
    std::getline(std::cin, input);
    darkest_secret_ = input;
}

void PhoneBook::print_all(void)
{
    std::cout << "First name : " << first_name_ << std::endl;
    std::cout << "Last name : " << last_name_ << std::endl;
    std::cout << "Nickname : " << nickname_ << std::endl;
    std::cout << "Phone number : " << phone_number_ << std::endl;
    std::cout << "Darkest secret : " << darkest_secret_ << std::endl;
}

void PhoneBook::print_preview(int index)
{
    print_column(std::to_string(index));
    std::cout << "|";
    print_column(first_name_);
    std::cout << "|";
    print_column(last_name_);
    std::cout << "|";
    print_column(nickname_);
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