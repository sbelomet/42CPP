/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:53:03 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 14:52:01 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    private:
		std::string ideas[100];
	
	public:
        Brain(void);
        Brain(const Brain& other);
        Brain &operator=(const Brain &other);
        ~Brain();

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
};

#endif
