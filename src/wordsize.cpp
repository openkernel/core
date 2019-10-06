#include<iostream>
class Object {

};

class Integer {
	int i;
	public:
	void display() {
		std::cout<<i<<std::endl;
	}
};

int main(int ac, char *av[]) {
	std::cout << "Size of bool		:" << sizeof(bool) << std::endl;
	std::cout << "Size of char		:" << sizeof(char) << std::endl;
	std::cout << "Size of short		:" << sizeof(short) << std::endl;
	std::cout << "Size of int		:" << sizeof(int) << std::endl;
	std::cout << "Size of long		:" << sizeof(long) << std::endl;
	std::cout << "Size of long long	:" << sizeof(long long) << std::endl;
	std::cout << "Size of float		:" << sizeof(float) << std::endl;
	std::cout << "Size of double	:" << sizeof(double) << std::endl;
	std::cout << "Size of long double:" << sizeof(long double) << std::endl;
	std::cout << "Size of Object	:" << sizeof(Object) << std::endl;
	std::cout << "Size of Integer	:" << sizeof(Integer) << std::endl;
}

