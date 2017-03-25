#include <iostream>

#include "StaticPow.hpp"

int main(int, char **)
{
	std::cout << "2^4 = " << StaticPow<2, 4>::result << std::endl;
	std::cout << "3^4 = " << StaticPow<3, 4>::result << std::endl;
	std::cout << "4^4 = " << StaticPow<4, 4>::result << std::endl;
	return (0);
}