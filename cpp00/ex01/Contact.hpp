/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:38:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/20 11:43:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	darkest_secret;

		void operator=(const Contact& C)
		{
			first_name = C.first_name;
			last_name = C.last_name;
			nickname = C.last_name;
			phone_num = C.phone_num;
			darkest_secret = C.darkest_secret;
		}

		void clear_contact(void);
};

#endif
