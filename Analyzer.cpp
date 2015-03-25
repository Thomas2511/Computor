#include "Analyzer.hpp"

bool				Analyzer::analyzer(std::list<Token> * tkns)
{
	func				tab[] = {
		&Analyzer::_isValue,
		&Analyzer::_isOperator,
		&Analyzer::_isEqual,
		&Analyzer::_isDegree
	};
	std::list<Token>::iterator		it;
	for (it = tkns->begin(); it != tkns->end(); ++it)
	{
		for (int i = 0; i < 4; i++)
		{
			if (tab[i](*it))
				break ;
		}
	}
	return 1;
}

bool				Analyzer::_isValue(Token & tkn)
{
	std::string		value = tkn.getValue();
	std::size_t		found = value.find_first_of(".");
	std::size_t		i = 0;

	while (i < (value.size()))
	{
		if (!isdigit(value[i]) && (i != found || found == std::string::npos))
			return 0;
		i++;
	}
	tkn.setType(VALUE);
	return 1;
}

bool				Analyzer::_isOperator(Token & tkn)
{
	std::string		tab[3] = {
		"+",
		"-",
		"*",
	};

	for (int i = 0; i < 3; i++)
	{
		if (tkn.getValue().compare(tab[i]) == 0)
		{
			tkn.setType(OP);
			return 1;
		}
	}
	return 0;
}

bool				Analyzer::_isEqual(Token & tkn)
{
	if (tkn.getValue().compare("=") == 0)
	{
		tkn.setType(EQUAL);
		return 1;
	}
	return 0;
}

bool				Analyzer::_isDegree(Token & tkn)
{
	std::size_t		found = 0;

	found = tkn.getValue().find_first_of("^", found);
	if (found != std::string::npos)
	{
		tkn.setType(DEGREE);
		return 1;
	}
	return 0;
}
