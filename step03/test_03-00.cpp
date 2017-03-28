#include <iostream>

#include "Vector.hpp"

int main(int, char **)
{
	Vector<Vector<int, 3>, 5, int> v(42);
	Vector<Vector<float, 3>, 5, float> v2(42.42);

	std::cout << "v      " << v << std::endl;
  std::cout << "v + 42 " << v + 42 << std::endl;
  std::cout << "v - 42 " << v - 42 << std::endl;
  std::cout << "v * 42 " << v * 42 << std::endl;
  std::cout << "v / 3  " << v / 3 << std::endl;

	std::cout << "v2     " << v2 << std::endl;
  std::cout << "v2 + v " << v2 + v << std::endl;
  std::cout << "v2 - v " << v2 - v << std::endl;
  std::cout << "v2 * v " << v2 * v << std::endl;
  std::cout << "v2 / v " << v2 / v << std::endl;

	return (0);
}
