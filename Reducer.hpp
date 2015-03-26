#ifndef REDUCER_HPP
# define REDUCER_HPP

# include <list>
# include <vector>
# include "Token.hpp"

class Reducer
{
	public:
		static std::vector<double>	reducer(std::list<Token> *lst);
		static double				abs(double d);

	private:
		static int					_extractDegree(Token & tkn);
		static void					_displayReducedForm(std::vector<double> vec);
};

#endif /* REDUCER_HPP */
