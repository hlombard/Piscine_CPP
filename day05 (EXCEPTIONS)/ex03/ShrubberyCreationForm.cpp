#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137) {return;}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {
	*this = src;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	std::ofstream file;

	std::string namefmt = this->getName().append("_shrubbery");
	const char *filename = namefmt.c_str();

	Form::execute(executor);
	file.open(filename, std::ofstream::out | std::ofstream::trunc);
	if (file.is_open()) {
		file << "       ###" << std::endl;
		file << "      #o###" << std::endl;
		file << "    #####o###" << std::endl;
		file << "   #o#\\#|#/###" << std::endl;
		file << "    ###\\|/#o#" << std::endl;
		file << "     # }|{  #" << std::endl;
		file << "       }|{" << std::endl;
		file.close();
	}
	else {
		std::cerr << "Couldn't open file " << this->getName() + "_shrubbery" << std::endl;
	}
}


ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	(void)src;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {return;}
