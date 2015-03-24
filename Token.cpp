#include "Token.hpp"

Token::Token( void ) : _value(""), _type(UNKNOWN)
{
}

Token::Token(Token const & src)
{
	*this = src;
}

Token::Token(tokenType type) : _value(""), _type(type)
{
}

Token::~Token( void )
{
}

Token &						Token::operator=(Token const & rhs)
{
	this->_value = rhs._value;
	this->_type = rhs._type;
	return *this;
}

std::string					Token::getValue( void ) const
{
	return this->_value;
}

tokenType					Token::getType( void ) const
{
	return this->_type;
}

void						Token::setValue(std::string const val)
{
	this->_value = val;
}

void						Token::setType(tokenType const tkn)
{
	this->_type = tkn;
}

std::ostream &				operator<<(std::ostream & o, Token const & rhs)
{
	o << rhs.getValue() << " | ";
	switch (rhs.getType())
	{
		case VALUE:
			o << "Value";
			break ;

		case OP:
			o << "Operator";
			break ;

		case DEGREE:
			o << "Degree";
			break ;

		case EQUAL:
			o << "Equal";
			break ;

		default:
			o << "Unknown";
			break ;
	}
	return o;
}
