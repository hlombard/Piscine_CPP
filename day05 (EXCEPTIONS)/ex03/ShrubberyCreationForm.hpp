#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {

	private:
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);

		virtual void execute(Bureaucrat const & executor) const;

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);

		~ShrubberyCreationForm(void);
};

#endif
