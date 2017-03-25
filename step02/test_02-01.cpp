#include <iostream>

#include "Vector.hpp"

int main(int, char **)
{
	Vector<int, 5> v;

	v.static_get<1>() = 1;
	v.static_get<2>() = 2;
	v.static_get<3>() = 3;
	v.static_get<4>() = 4;
	v.static_get<5>() = 5;

	Vector<double, 5> v2;
	v2.static_get<1>() = 1.42;
	v2.static_get<2>() = 2.42;
	v2.static_get<3>() = 3.42;
	v2.static_get<4>() = 4.42;
	v2.static_get<5>() = 5.42;

	std::cout << "v      " << v << std::endl;
	std::cout << "v2     " << v2 << std::endl;

	std::cout << "v.getNormeSquared()      " << v.getNormeSquared() << std::endl;
	std::cout << "v.getNorme()      " << v.getNorme() << std::endl;
	std::cout << "v.getNormed()      " << v.getNormed() << std::endl;

	std::cout << "v2.getNormeSquared()     " << v2.getNormeSquared() << std::endl;
	std::cout << "v2.getNorme()     " << v2.getNorme() << std::endl;
	std::cout << "v2.getNormed()     " << v2.getNormed() << std::endl;

	std::cout << "v.dotProduct(v2)      " << v.dotProduct(v2) << std::endl;
	return (0);
}