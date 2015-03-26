#ifndef SOLVER_HPP
# define SOLVER_HPP

# include <exception>
# include <vector>
# include "Token.hpp"

class Solver
{
	public:
		class DegreeTooHighException : public std::exception
		{
			public:
				virtual const char *		what() const throw();
		};
		static void						solver(std::vector<double> vec);

	private:
		static int						_checkDegree(std::vector<double> vec);
		static void						_resolveDegreeTwo(std::vector<double> vec);
		static double					_squareRoot(double const x);
};

#endif /* SOLVER_HPP */
