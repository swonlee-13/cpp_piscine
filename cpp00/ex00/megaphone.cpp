/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongwol <seongwol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:25:50 by seongwol          #+#    #+#             */
/*   Updated: 2024/02/20 13:41:38 by seongwol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1) {

		for (int i = 1; i < ac; i++) {
			
			std::string a = av[i];
			for(unsigned long long  j = 0; j < a.length(); j++) {

				a[j] = static_cast<char>(std::toupper(a[j]));
			}
			std::cout << a;
		}
	
		std::cout << std::endl;
	}
}
