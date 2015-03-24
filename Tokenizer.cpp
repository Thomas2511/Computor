#include <sstream>
#include <string>
#include "Tokenizer.hpp"

std::list<Token> *				Tokenizer::tokenize(std::string const & content)
{
	std::list<Token>			*lst = new std::list<Token>;
	Token						tkn;
	std::stringstream			ss;
	std::string					sub;
	std::size_t					found = 0;

	for (std::size_t i = 0; i < content.size(); i++)
	{
		found = content.find_first_of(" +-*", found);
		sub = content.substr(i, found - i);
		if (sub.compare("") != 0)
		{
			tkn.setValue(sub);
			lst->push_back(tkn);
			if (found == std::string::npos)
				break ;
		}
		if (content[found] == '+' || content[found] == '-' || content[found] == '*')
		{
			ss << content[found];
			tkn.setValue(ss.str());
			lst->push_back(tkn);
			ss.str(std::string());
		}
		i = found++;
	}
	return lst;
}
