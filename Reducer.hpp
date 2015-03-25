#ifndef REDUCER_HPP
# define REDUCER_HPP

# include <list>
# include "Token.hpp"

class Reducer
{
	public:
		static std::list<Token> *	reducer(std::list<Token> *lst);

	private:
		static int					_extractDegree(Token & tkn);
		static std::list<Token> *	_createReducedForm(double * vec);
		static double				_abs(double d);
};

#endif /* REDUCER_HPP */
