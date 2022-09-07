/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:33:41 by byahn             #+#    #+#             */
/*   Updated: 2021/11/01 17:47:16 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string input = "";
		for (int i = 1; i < argc; i++)
		{
			int j = 0;
			while (argv[i][j])
			{
				input += std::toupper(argv[i][j]);
				j++;
			}
		}
		std::cout << input << std::endl;
	}
	return (0);
}
