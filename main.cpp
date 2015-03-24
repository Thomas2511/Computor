/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 13:35:21 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/03/24 16:26:50 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Analyzer.hpp"

int						main(int ac, char **av)
{
	std::list<Token>	*lst;

	if (ac >= 2)
	{
		lst = Tokenizer::tokenize(av[1]);
		Analyzer::analyzer(lst);
		for (std::list<Token>::iterator it = lst->begin(); it != lst->end(); ++it)
		{
			std::cout << (*it) << std::endl;
		}
	}
	return 0;
}
