/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:43:11 by byahn             #+#    #+#             */
/*   Updated: 2021/11/21 20:19:59 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void SetFirstName(const std::string str);
		void SetLastName(const std::string str);
		void SetNickName(const std::string str);
		void SetPhoneNumber(const std::string str);
		void SetDarkestSecret(const std::string str);

		std::string GetFirstName(void) const;
		std::string GetLastName(void) const;
		std::string GetNickName(void) const;
		std::string GetPhoneNumber(void) const;
		std::string GetDarkestSecret(void) const;
};

#endif
