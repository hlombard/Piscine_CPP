#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <string>

/*
infos[0] : first name
infos[1] : last name
infos[2] : nickname
infos[3] : login
infos[4] : postal address
infos[5] : email address
infos[6] : phone number
infos[7] : birthday date
infos[8] : favorite meal
infos[9] : underwear color
infos[10] : darkest secret
*/

class Contact {
	private:
		const char *_fields[11] = {
		"First name",
		"Last name",
		"Nickname",
		"Login",
		"Postal address",
		"Email address",
		"Phone number",
		"Birthday date",
		"Favorite meal",
		"Underwear color",
		"Darkest secret"
	};

	public:
		int index;
		std::string infos[11];

		Contact(void);
		void setInfo(void);
		void printInfo(void);
		~Contact(void);
};

#endif
