#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <iostream>

enum	tokenType {
	UNKNOWN = 0,
	VALUE,
	OP,
	DEGREE,
	EQUAL
};

class Token
{
	public:
		Token( void );
		Token(Token const & src);
		Token(tokenType type);
		~Token( void );
		Token &					operator=(Token const & rhs);

		std::string				getValue( void ) const;
		tokenType				getType( void ) const;
		void					setValue(std::string const val);
		void					setType(tokenType const tkn);

	private:
		std::string				_value;
		tokenType				_type;

};

std::ostream &					operator<<(std::ostream & o, Token const & rhs);

#endif /* TOKEN_HPP */
