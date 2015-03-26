#include <string>
#include <sstream>
#include <vector>
#include "Reducer.hpp"

std::vector<double>							Reducer::reducer(std::list<Token> *lst)
{
	int										deg;
	int										sign = 1;
	double									val;
	std::vector<double>						vec;
	std::list<Token>::iterator				it;

	for (int i = 0; i < 1024; i++)
		vec.push_back(0);
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
	_displayReducedForm(vec);
	delete lst;
	return (vec);
}

double										Reducer::abs(double d)
{
	if (d < 0)
		d *= -1;
	return d;
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

void										Reducer::_displayReducedForm(std::vector<double> vec)
{
	std::stringstream						ss;
	bool									fst = 0;

	for (int i = 0; i < 1024; i++)
	{
		if (vec[i] > 0 && fst == 1)
			ss << " + ";
		if (vec[i] < 0)
			ss << " - ";
		if (vec[i] != 0)
		{
			ss << abs(vec[i]);
			if (i > 0)
				ss << " * ";
			if (i > 1)
				ss << "X^" << i;
			if (i == 1)
				ss << "X";
			fst = 1;
		}
	}
	if (!fst)
		return ;
	std::cout << "Reduced form: " << ss.str() << " = 0" << std::endl;
}
