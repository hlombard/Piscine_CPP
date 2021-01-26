#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Form* rrf;
    Bureaucrat joe("Joe", 1);

    /* RobotomyRequestForm */
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf;
    joe.signForm(*rrf);
    joe.executeForm(*rrf);
    std::cout << std::endl;

    /* PresidentialPardonForm */
    Form *ppf = someRandomIntern.makeForm("presidential pardon", "Pardon");
    joe.signForm(*ppf);
    std::cout << *ppf;
    joe.executeForm(*ppf);
    std::cout << std::endl;

    /* ShrubberyCreationForm */
    Form *scf = someRandomIntern.makeForm("shrubbery creation", "shrub");
    joe.signForm(*scf);
    std::cout << *scf;
    joe.executeForm(*scf);
    std::cout << std::endl;

    /* Unknown Form */
    try {
        Form *wtf = someRandomIntern.makeForm("blablabla", "wtf");
        std::cout << *wtf;
        joe.signForm(*wtf);
        joe.executeForm(*wtf);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete rrf;
    delete ppf;
    delete scf;

    return (0);
}
