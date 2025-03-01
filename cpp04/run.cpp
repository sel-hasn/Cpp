# include <iostream>

class A {
	int one;
	int two;
	public:
		void	print( void ) {
			std::cout << one << " : " << two << std::endl;
		}
};

class C {};

class B : public A {
	int last;
	public:
		void	print( void ) {
			std::cout << last << std::endl;
		}
};

int main() {
	B b;
	int*  o = (int *)&b;
	A *a = &b;
	*o = 42;
	*(o + 1) = 1337;
	*(o + 2) = 0;
	std::cout << 	*(o + 3) << std::endl;
	a->print();
	b.print();
	std::cout << sizeof(C) << std::endl;
}
