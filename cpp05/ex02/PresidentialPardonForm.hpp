/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:42:21 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/02 09:47:44 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();

		virtual void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form);

#endif