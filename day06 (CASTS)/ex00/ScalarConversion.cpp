#include "ScalarConversion.hpp"

const char *ScalarConversion::ImpossibleException::what() const throw() {
	return ("impossible");
}

const char *ScalarConversion::NonDisplayableException::what() const throw() {
	return ("Non displayable");
}

std::string ScalarConversion::_padding() const {

	if (this->_value.rfind("nan", 0) == 0 || this->_value.rfind("-inf") == 0
		|| this->_value.rfind("+inf") == 0)
		return "";

	size_t find = this->_value.find('.');
	if (find == std::string::npos)
		return ".0";

	int count = 0;
	int excep = 0;
	while (this->_value[++find]) {

		if (this->_value[find] == '0')
			count++;
		else if (this->_value[find] == 'f' && !excep) {
			excep = 1;
		}
		else
			return "";
	}

	return ("." + std::string(count, '0'));

}

ScalarConversion::ScalarConversion(std::string input) {
	this->_value = input;
}

ScalarConversion::ScalarConversion(ScalarConversion const & src) {
	*this = src;
}

ScalarConversion::operator char(void) const {
	char value;

	try {
		value = std::stoi(this->_value);
	} catch (std::exception &e) {
		throw ScalarConversion::ImpossibleException();
	}

	if (value < 32 || value > 126)
		throw ScalarConversion::NonDisplayableException();
	else if (value > 127 || value < -128)
		throw ScalarConversion::ImpossibleException();

	return (static_cast<char>(value));
}

ScalarConversion::operator int(void) const {
	int value;

	try {
		value = std::stoi(this->_value);
	} catch(std::exception &e) {
		throw ScalarConversion::ImpossibleException();
	}

	return (value);
}

ScalarConversion::operator float(void) const {
	float value;

	try {
		value = std::stof(this->_value);
	} catch(std::exception &e) {
		throw ScalarConversion::ImpossibleException();
	}

	return (value);
}

ScalarConversion::operator double(void) const {
	double value;

	try {
		value = std::stod(this->_value);
	} catch(std::exception &e) {
		throw ScalarConversion::ImpossibleException();
	}

	return (value);
}

void ScalarConversion::printChar(void) const {
	char value;

	std::cout << "char: ";
	try {
		value = static_cast<char>(*this);
		std::cout << "'" << value << "'" << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void ScalarConversion::printInt(void) const {
	int value;

	std::cout << "int: ";
	try {
		value = static_cast<int>(*this);
		std::cout << value << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void ScalarConversion::printFloat(void) const {
	float value;

	std::cout << "float: ";
	try {
		value = static_cast<float>(*this);
		std::cout << value << this->_padding() << "f" << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void ScalarConversion::printDouble(void) const {
	double value;

	std::cout << "double: ";
	try {
		value = static_cast<double>(*this);
		std::cout << value << this->_padding() << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}


ScalarConversion & ScalarConversion::operator=(ScalarConversion const & src) {
	(void)src;
	return (*this);
}

ScalarConversion::~ScalarConversion(void) {return;}
