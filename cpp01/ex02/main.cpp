/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:53:48 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/21 15:31:17 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "String Address: " << &str << "\n";
	std::cout << "Pointer Value: " << stringPTR << "\n";
	std::cout << "Reference Address: " << &stringREF << "\n\n";

	std::cout << "String Value: " << str << "\n";
	std::cout << "Value pointed to by Pointer: " << *stringPTR << "\n";
	std::cout << "Reference Value: " << stringREF << "\n\n";
}
