/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:34:42 by byahn             #+#    #+#             */
/*   Updated: 2021/11/21 19:48:48 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.hpp"

void show_preview(PhoneBook* pb, int total_num)
{
    std::cout << std::right << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "First Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Last Name";
    std::cout << "|";
    std::cout << std::right << std::setw(10) << "Nickname";
	std::cout << std::endl;

	for (int i = 0; i < total_num; i++)
	{
		pb[i].print_preview(i);
	}
	std::cout << std::endl;
}

void select_index(PhoneBook* pb, int total_num)
{
	int index;
	std::string input;
	std::stringstream ss;

	std::cout << "Select index : ";
	std::getline(std::cin, input);
	ss << input;
	ss >> index;

	if (index < 0 || index >= total_num || ss.fail() == true)
	{
		std::cout << "Wrong index!" << std::endl;
	}
	else
	{
		pb[index].print_all();
	}
}

int	main()
{
	int total_num = 0;
	int idx = 0;
	std::string input;
	PhoneBook pb[8];

	while (1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			pb[idx++].add_contact();
			idx %= 8;
			if (total_num < 8)
				total_num++;
		}
		else if (input == "SEARCH")
		{
			show_preview(pb, total_num);
			select_index(pb, total_num);
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Wrong Input.\n";
	}

	return (0);
}
