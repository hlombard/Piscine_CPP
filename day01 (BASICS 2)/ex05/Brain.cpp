#include "Brain.hpp"

std::string Brain::identify(void) const {
	const long addr = (long)this;

	std::string ret = "0x";
	ret += std::to_string(addr);
	return (ret);
}
