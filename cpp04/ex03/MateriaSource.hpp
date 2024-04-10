/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:39:27 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 14:57:20 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "includes.h"

# define MEMORY_SIZE 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _memory[MEMORY_SIZE];
	
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif

