#include <iostream>

#include "Vector.hpp"

int main(int, char **)
{
	Vector<int, 5> v(42);
	Vector<double, 5> v2(v);

	v.static_get<2>() = -42;
	v2.static_get<2>() = -42.42;

	std::cout << "v  " << v << std::endl;
	std::cout << "v2 " << v2 << std::endl;

	return (0);
}