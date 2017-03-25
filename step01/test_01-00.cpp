#include <iostream>

#include "Vector.hpp"

int main(int, char **)
{
	Vector<int, 5> v;

	static_cast<Vector<int, 1> * >(&v)->value = 1;
	static_cast<Vector<int, 2> * >(&v)->value = 2;
	static_cast<Vector<int, 3> * >(&v)->value = 3;
	static_cast<Vector<int, 4> * >(&v)->value = 4;
	static_cast<Vector<int, 5> * >(&v)->value = 5;

	std::cout << "["
	<< static_cast<Vector<int, 1> * >(&v)->value << " , "
	<< static_cast<Vector<int, 2> * >(&v)->value << " , "
	<< static_cast<Vector<int, 3> * >(&v)->value << " , "
	<< static_cast<Vector<int, 4> * >(&v)->value << " , "
	<< static_cast<Vector<int, 5> * >(&v)->value
	<< "]" << std::endl;

	return (0);
}