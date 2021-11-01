/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:34:42 by byahn             #+#    #+#             */
/*   Updated: 2021/11/01 19:41:04 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			;
		else if (input == "SEARCH")
			;
		else if (input == "EXIT")
			break;
	}


	return (0);
}
