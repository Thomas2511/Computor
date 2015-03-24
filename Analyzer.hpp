#ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <list>
# include <sstream>
# include <iostream>
# include "Token.hpp"

class Analyzer
{
	public:
		static bool				analyzer(std::list<Token> * tkns);

	private:
		static bool				_isValue(Token & tkn);
		static bool				_isOperator(Token & tkn);
		static bool				_isDegree(Token & tkn);
		static bool				_isEqual(Token & tkn);
};

typedef bool					(*func)(Token & tkn);

#endif /* ANALYZER_HPP */
