#ifndef TOKENIZER_HPP
# define TOKENIZER_HPP

# include <list>
# include "Token.hpp"

class Tokenizer
{
	public:
		static std::list<Token>	*		tokenize(std::string const & content);
};

#endif /* TOKENIZER_HPP */
