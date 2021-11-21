/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:17:34 by byahn             #+#    #+#             */
/*   Updated: 2021/11/21 20:23:51 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::SetFirstName(const std::string str)
{
	first_name = str;
}
void Contact::SetLastName(const std::string str)
{
	last_name = str;
}
void Contact::SetNickName(const std::string str)
{
	nickname = str;
}
void Contact::SetPhoneNumber(const std::string str)
{
	phone_number = str;
}
void Contact::SetDarkestSecret(const std::string str)
{
	darkest_secret = str;
}

std::string Contact::GetFirstName(void) const
{
	return (first_name);
}
std::string Contact::GetLastName(void) const
{
	return (last_name);
}
std::string Contact::GetNickName(void) const
{
	return (nickname);
}
std::string Contact::GetPhoneNumber(void) const
{
	return (phone_number);
}
std::string Contact::GetDarkestSecret(void) const
{
	return (darkest_secret);
}
