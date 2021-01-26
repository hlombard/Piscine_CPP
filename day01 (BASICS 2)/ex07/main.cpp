#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int usage(char *name) {

	std::cerr	<< "usage: " << name
				<< " [file] [occurence_str] [replace_str]"
				<< std::endl;
	return (1);
}

int checkInput(char **argv) {

	for (int i = 1; i < 4; i++) {
		if (std::string(argv[i]).empty()) {
			std::cerr << "error: param " << i << " is empty" << std::endl;
			return (1);
		}
	}
	return (0);
}

/* s1 can take regex, but can also be escaped if needed */

void replace(char *fileName, char *s1, char *s2) {

	std::ifstream file (fileName);
	std::ofstream newfile;
	std::stringstream buffer;
	std::string content;

	if (!file.is_open()) {
		std::cerr << "error: can't open file " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}

	buffer << file.rdbuf();
	content = buffer.str();
	content = std::regex_replace(content, std::regex(s1), s2);


	newfile.open(std::string(fileName)+".replace");
	if (!newfile.is_open()) {
		std::cerr << "error: can't write file " << std::string(fileName)+".replace" << std::endl;
		file.close();
		exit(EXIT_FAILURE);
	}

	newfile << content;
	newfile.close();
}

int main(int argc, char **argv) {

	if (argc != 4)
		return (usage(argv[0]));
	else if (checkInput(argv))
		return (1);

	replace(argv[1], argv[2], argv[3]);
}
