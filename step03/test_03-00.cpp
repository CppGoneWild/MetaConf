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

	std::cout << "v      " << v << std::endl;
  std::cout << "v + 42 " << v + 42 << std::endl;
  std::cout << "v - 42 " << v - 42 << std::endl;
  std::cout << "v * 42 " << v * 42 << std::endl;
  std::cout << "v / 3  " << v / 3 << std::endl;
//  std::cout << "v % 2  " << v % 2 << std::endl;

	Vector<double, 5> v2;
	v2.static_get<1>() = 1.42;
	v2.static_get<2>() = 2.42;
	v2.static_get<3>() = 3.42;
	v2.static_get<4>() = 4.42;
	v2.static_get<5>() = 5.42;

	std::cout << "v2     " << v2 << std::endl;
  std::cout << "v2 + v " << v2 + v << std::endl;
  std::cout << "v2 - v " << v2 - v << std::endl;
  std::cout << "v2 * v " << v2 * v << std::endl;
  std::cout << "v2 / v " << v2 / v << std::endl;
//  std::cout << "v2 % v " << v2 % v << std::endl;

	return (0);
}