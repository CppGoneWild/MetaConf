#include <iostream>

#include "Vector.hpp"

int main(int, char **)
{
	Vector<int, 5> v(42);
	Vector<int, 5> v2(v);

	std::cout << "v  ["
	<< static_cast<Vector<int, 1> * >(&v)->value << " , "
	<< static_cast<Vector<int, 2> * >(&v)->value << " , "
	<< static_cast<Vector<int, 3> * >(&v)->value << " , "
	<< static_cast<Vector<int, 4> * >(&v)->value << " , "
	<< static_cast<Vector<int, 5> * >(&v)->value
	<< "]" << std::endl;

	std::cout << "v2 ["
	<< static_cast<Vector<int, 1> * >(&v2)->value << " , "
	<< static_cast<Vector<int, 2> * >(&v2)->value << " , "
	<< static_cast<Vector<int, 3> * >(&v2)->value << " , "
	<< static_cast<Vector<int, 4> * >(&v2)->value << " , "
	<< static_cast<Vector<int, 5> * >(&v2)->value
	<< "]" << std::endl;

	return (0);
}