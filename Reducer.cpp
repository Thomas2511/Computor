#include <string>
#include <sstream>
#include <vector>
#include "Reducer.hpp"
#include "X.hpp"

std::list<Token> *							Reducer::reducer(std::list<Token> *lst)
{
	int										deg;
	int										sign = 1;
	double									val;
	double									vec[1024];
	std::string								prev;
	std::list<Token>::iterator				it;

	for (int i = 0; i < 1024; i++)
		vec[i] = 0;
	for (it = lst->begin(); (*it).getType() != EQUAL; it++)
	{
		if ((*it).getType() == VALUE)
			val = std::atof((*it).getValue().c_str()) * sign;
		if ((*it).getValue().compare("-") == 0)
			sign = -1;
		if ((*it).getType() == DEGREE)
		{
			deg = _extractDegree(*it);
			vec[deg] += val;
		}
	}
	sign = 1;
	while (it != lst->end())
	{
		if ((*it).getType() == VALUE)
			val = std::atof((*it).getValue().c_str()) * sign;
		if ((*it).getValue().compare("-") == 0)
			sign = -1;
		if ((*it).getType() == DEGREE)
		{
			deg = _extractDegree(*it);
			vec[deg] -= val;
		}
		it++;
	}
	delete lst;
	return (_createReducedForm(vec));
}

int											Reducer::_extractDegree(Token & tkn)
{
	std::string								s = tkn.getValue();
	std::size_t								found = 0;
	int										ret = 0;

	found = s.find_first_of("^", found);
	ret = std::atoi(s.substr(found + 1, s.size() - (found + 1)).c_str());
	return ret;
}

std::list<Token> *							Reducer::_createReducedForm(double * vec)
{
	std::list<Token>						*lst = new std::list<Token>;
	std::stringstream						ss;
	bool									fst = 0;

	for (int i = 0; i < 1024; i++)
	{
		if (vec[i] > 0 && fst == 1)
			lst->push_back(Token("+", OP));
		if (vec[i] < 0)
			lst->push_back(Token("-", OP));
		if (vec[i] != 0)
		{
			ss << _abs(vec[i]);
			lst->push_back(Token(ss.str(), VALUE));
			ss.str(std::string());
			lst->push_back(Token("*", OP));
			ss << "X^" << i;
			lst->push_back(Token(ss.str(), DEGREE));
			ss.str(std::string());
			fst = 1;
		}
	}
	lst->push_back(Token("=", EQUAL));
	lst->push_back(Token("0", VALUE));
	return lst;
}

double										Reducer::_abs(double d)
{
	if (d < 0)
		d *= -1;
	return d;
}
