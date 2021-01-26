#ifndef BASE_A_B_C_HPP
# define BASE_A_B_C_HPP

class Base {
	public:
		virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
