#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

int main( void ) {
	int a = 2;
	int b = 3;

	// INT Swap
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;
	std::cout << "SWAP INT" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;

	// INT Min / Max
	std::cout << "MIN / MAX INT" << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl << std::endl;

	// STR SWAP
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;
	std::cout << "SWAP STR" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	// STR Min / Max
	std::cout << "MIN / MAX STR" << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d  ) = " << ::max( c, d ) << std::endl << std::endl;

	// FLOAT Swap
	float e = 93.04;
	float f = 93.006;
	std::cout << "e = " << e << ", f = " << f << std::endl << std::endl;
	std::cout << "SWAP FLOAT" << std::endl;
	::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;

	// FLOAT Min / Max
	std::cout << "MIN / MAX FLOAT" << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::cout << std::endl << std::endl;

	return 0;
}
