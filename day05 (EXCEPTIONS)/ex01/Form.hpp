#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;

	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const & src);

		std::string getName(void) const;
		bool getSign(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		void beSigned(Bureaucrat const & src);

		class GradeTooHighException : public std::exception {
			virtual const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char *what(void) const throw();
		};

		Form & operator=(Form const & src);

		~Form(void);
};

std::ostream & operator<<(std::ostream & out, Form const & src);

#endif
