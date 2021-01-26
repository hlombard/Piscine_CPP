#include "AnnuaireZero.class.hpp"
#include "Contact.class.hpp"

#define F_NAME 0
#define L_NAME 1
#define NICKNAME 2

AnnuaireZero::AnnuaireZero(void) {
	this->_contacts_nb = 0;
	for (int i = 0; i < 8; i++) {
		this->_contacts[i].index = i;
	}
}

void AnnuaireZero::welcome(void) {
	std::cout << "/*** Welcome to AnnuaireZero ***\\" << std::endl << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "\t- SEARCH: find a user" << std::endl;
	std::cout << "\t- ADD: add a new user" << std::endl;
	std::cout << "\t- EXIT: quit" << std::endl;
}

void AnnuaireZero::badCmd(std::string command) {
	std::cout << command << " not recognized..." << std::endl;
}

void AnnuaireZero::_printHeader(void) {
	std::string tmp[3];

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < this->_contacts_nb; i++) {

		for (int j = 0; j < 3; j++) {
			if (this->_contacts[i].infos[j].find_first_not_of(' ') != std::string::npos)
				tmp[j] = this->_contacts[i].infos[j];
			else
				tmp[j] = "(NULL)";

			if (tmp[j].length() >= 10) {
				tmp[j].resize(10);
				tmp[j][9] = '.';
			}
		}

		std::cout << "|" << "         " << this->_contacts[i].index << "|";

		for (int i = tmp[0].length(); i < 10; i++) {
			std::cout << " ";
		}
		std::cout << tmp[0] << "|";


		for (int i = tmp[1].length(); i < 10; i++) {
			std::cout << " ";
		}
		std::cout << tmp[1] << "|";

		for (int i = tmp[2].length(); i < 10; i++) {
			std::cout << " ";
		}
		std::cout << tmp[2] << "|";

		std::cout << std::endl;
	}

	std::cout << "---------------------------------------------" << std::endl;
}

void AnnuaireZero::search(void) {

	int search_index;

	if (this->_contacts_nb == 0) {
		std::cout << "0 contacts in AnnuaireZero :[" << std::endl;
		return;
	}

	this->_printHeader();

	std::cout << "Enter contact Index: ";
	while (!(std::cin >> search_index) || (search_index < 0 || search_index >= this->_contacts_nb)) {
		std::cout << "#error on input: ";
		std::cout << "index availables: [ ";
		for (int i = 0; i < this->_contacts_nb; i++) {
			std::cout << i;
			if (i != this->_contacts_nb - 1)
				std::cout << ", ";
		}
		std::cout << " ]" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl << "Enter contact Index: ";

	}

	// Fix pour bug à la sortie: Enter a command:  not recognized, try again, permet de flush
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	this->_contacts[search_index].printInfo();
}

void AnnuaireZero::addContact(void) {
	if (this->_contacts_nb >= 8) {
		std::cout << "Maximum contacts limit reached ( 8 )" << std::endl;
		std::cout << "Adding another contact will delete the last one (index 7)" << std::endl;
		this->_contacts[7].setInfo();
		return;
	}
	this->_contacts[_contacts_nb].setInfo();
	this->_contacts_nb += 1;
}

AnnuaireZero::~AnnuaireZero(void) {
	return;
}
