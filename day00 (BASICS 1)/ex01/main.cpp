#include "AnnuaireZero.class.hpp"

int main(void)
{
	AnnuaireZero prog;
	std::string command;

	prog.welcome();
	while (true)
	{
		command.clear();
		std::cout << std::endl << "Enter a command: ";
		getline(std::cin, command);

		if (!command.compare("EXIT"))
			break;
		else if (!command.compare("ADD"))
			prog.addContact();
		else if (!command.compare("SEARCH"))
			prog.search();
		else
			prog.badCmd(command);
	}
	return (0);
}
