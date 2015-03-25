/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 13:35:21 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/03/25 19:59:02 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Analyzer.hpp"
#include "Reducer.hpp"

int						main(int ac, char **av)
{
	std::list<Token>	*lst;
	std::list<Token>	*reduced;

	if (ac >= 2)
	{
		lst = Tokenizer::tokenize(av[1]);
		Analyzer::analyzer(lst);
		for (std::list<Token>::iterator it = lst->begin(); it != lst->end(); ++it)
		{
			std::cout << (*it) << std::endl;
		}
		reduced = Reducer::reducer(lst);
		std::cout << "--- v REDUCED VERSION v ---" << std::endl;
		for (std::list<Token>::iterator it = reduced->begin(); it != reduced->end(); ++it)
		{
			std::cout << (*it) << std::endl;
		}
	}
	return 0;
}
