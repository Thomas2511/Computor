/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 13:35:21 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/03/26 18:55:42 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Analyzer.hpp"
#include "Reducer.hpp"
#include "Solver.hpp"

int						main(int ac, char **av)
{
	std::list<Token>	*lst;
	std::vector<double>	reduced;

	if (ac >= 2)
	{
		lst = Tokenizer::tokenize(av[1]);
		Analyzer::analyzer(lst);
		reduced = Reducer::reducer(lst);
		try
		{
			Solver::solver(reduced);
		}
		catch (const Solver::DegreeTooHighException & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
