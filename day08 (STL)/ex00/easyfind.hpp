#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <list>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception
{
	const char *what() const throw() {
		return "Not Found Exception: couldn't find required value";
	}
};

template <typename T>
int easyfind(T & container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == std::end(container))
		throw NotFoundException();
	return *it;
}

#endif
