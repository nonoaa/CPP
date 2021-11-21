/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:24:40 by byahn             #+#    #+#             */
/*   Updated: 2021/11/21 20:32:38 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <string>
# include "contact.hpp"

class PhoneBook
{
	private:
		int contact_num;
		Contact contact[8];

	public:
		void AddContact(void);
		void SearchContact(void);
};
