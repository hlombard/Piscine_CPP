#include "Array_tpp.cpp"

template <typename T>
void printContent(Array<T> &arr, std::string name) {
	std::cout << "Array " << name << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << "\t index " << i << ": " << arr[i] << std::endl;
	}
}

int main(void) {

	// Init and print size and print content
	Array<int> integer(5);
	std::cout << "Created integer Array of size: " << integer.size() << std::endl;
	printContent(integer, "integer");
	std::cout << std::endl;

	// Set values and print content
	integer[0] = 1;
	integer[4] = 1;
	printContent(integer, "integer");
	std::cout << std::endl;

	// Access out ouf bound index
	try {
		integer[5] = 9;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Copy constructor and print content
	Array<int> integercpy(integer);
	printContent(integercpy, "integer copy");
	std::cout << std::endl;

	// Asignation and print content and size
	Array<int> integersame(42);
	std::cout << "Created integer Array of size: " << integersame.size() << std::endl;
	integersame = integercpy;
	std::cout << "Size modified to integer copy array: " << integersame.size() << std::endl;
	printContent(integersame, "Integer asignation");
	std::cout << std::endl;

	// Test with string array
	Array<std::string> str(5);
	std::cout << "Created std::string Array of size: " << str.size() << std::endl;
	printContent(str, "str array");
	std::cout << std::endl;

	// Set values and print content
	str[0] = "Hello world!";
	str[1] = "Hi mom";
	str[2] = "Hi dad";
	str[3] = "Foo";
	str[4] = "42";
	printContent(str, "str array");

	return (0);
}
