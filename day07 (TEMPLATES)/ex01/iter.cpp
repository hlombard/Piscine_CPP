#include <string>
#include <iostream>

template <typename T>
void iter(T *array, int length, void (*f)(T)) {
	if (!array)
		return;

	for (int i = 0; i < length; i++) {
		std::cout << "Elem " << i << ": ";
		f(array[i]);
	}
}

template <typename T>
void print_elem(T elem) {
	std::cout << elem << std::endl;
}

int main(void) {
	int array_int[6] = {5,4,3,2,1,0};
	std::string array_str[6] = {"toto", "titi", "tutu", "tata", "bobo", "baba"};

	iter(array_int, 6, print_elem);
	std::cout << std::endl;
	iter(array_str, 6, print_elem);

	return (0);
}
