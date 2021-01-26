#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {

	private:
		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);

		virtual void execute(Bureaucrat const & executor) const;

		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);

		~RobotomyRequestForm(void);
};

#endif
