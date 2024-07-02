/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:42:11 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/02 09:48:46 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();

		virtual void execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form);

#endif
