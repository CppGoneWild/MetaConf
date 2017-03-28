#include <iostream>

#include "Matrix.hpp"

int main(int, char **)
{
  Matrix<int, 2, 5> m(42);
  Matrix<int, 2, 5> m2(21);

	std::cout << "m      " << m << std::endl;
  std::cout << "m + 42 " << m + 42 << std::endl;
  std::cout << "m - 42 " << m - 42 << std::endl;
  std::cout << "m * 42 " << m * 42 << std::endl;
  std::cout << "m / 3  " << m / 3 << std::endl;

  std::cout << "m2     " << m2 << std::endl;
  std::cout << "m2 + m " << m2 + m << std::endl;
  std::cout << "m2 - m " << m2 - m << std::endl;
  std::cout << "m2 * m " << m2 * m << std::endl;
  std::cout << "m / m2 " << m / m2 << std::endl;
  std::cout << "m % m2 " << m % m2 << std::endl;

	return (0);
}
