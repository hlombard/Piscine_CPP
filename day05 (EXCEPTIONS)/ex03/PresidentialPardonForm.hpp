#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

	private:
		PresidentialPardonForm(void);

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);

		virtual void execute(Bureaucrat const & executor) const;

		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);

		~PresidentialPardonForm(void);
};

#endif
