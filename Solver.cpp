#include "Solver.hpp"
#include "Reducer.hpp"

const char *		Solver::DegreeTooHighException::what() const throw()
{
	return "The polynomial degree is strictly greater than 2, I can't resolve this.";
}

void				Solver::solver(std::vector<double> vec)
{
	int				deg;
	int				i;
	double			x;

	deg = Solver::_checkDegree(vec);
	if (deg > 2)
		throw DegreeTooHighException();
	for (i = 0; i < 1024; i++)
		if (vec[i] != 0)
			break ;
	if (i == 1024)
	{
		std::cout << "All the real numbers are solutions for this polynomial." << std::endl;
		return ;
	}
	if (deg == 2)
		_resolveDegreeTwo(vec);
	else
	{
		x = -vec[0] / vec[1];
		std::cout << "The solution is:" << std::endl;
		std::cout << x << std::endl;
	}
}

int					Solver::_checkDegree(std::vector<double> vec)
{
	int				i = 1024;

	while (--i > 0)
		if (vec[i] != 0)
			break ;
	std::cout << "Polynomial degree : " << i << std::endl;
	return i;
}

void				Solver::_resolveDegreeTwo(std::vector<double> vec)
{
	double			a = vec[2];
	double			b = vec[1];
	double			c = vec[0];
	double			disc;
	double			x1;
	double			x2;

	disc = (b * b) - (4 * a * c);
	if (disc > 0)
	{
		x1 = (-b - _squareRoot(disc)) / (2 * a);
		x2 = (-b + _squareRoot(disc)) / (2 * a);
		std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
		std::cout << x1 << std::endl;
		std::cout << x2 << std::endl;
	}
	if (disc == 0)
	{
		x1 = x2 = -b / (2 * a);
		std::cout << "The solution is:" << std::endl;
		std::cout << x1 << std::endl;
	}
	if (disc < 0)
	{
		std::cout << "Discriminant is strictly negative, the polynomial has two complex solutions:" << std::endl;
		x1 = (-b / (2 * a));
		x2 = (_squareRoot(disc) / (2 * a));
		std::cout << x1 << " + i * " << x2 << std::endl;
		std::cout << x1 << " - i * " << x2 << std::endl;
	}
}

double				Solver::_squareRoot(double x)
{
	double			error = 0.000001;
	double			s;
	char			i = 0;

	if (x < 0)
	{
		i = 1;
		x *= -1;
	}
	s = x;
	while ((s - x / s) > error)
		s = (s + x / s) / 2;
	return s;
}
