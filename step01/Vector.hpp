#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <iostream>


template <class T, std::size_t SIZE>
struct Vector : public Vector<T, SIZE - 1>
{
	T value;

	explicit Vector(T const & value = T());
	template<class U> explicit Vector(Vector<U, SIZE> const & other);

	template <std::size_t IDX> T const & static_get() const;
	template <std::size_t IDX> T & static_get();
};

template <class T>
struct Vector<T, 1>
{
	T value;

	explicit Vector(T const & value = T());
	template<class U> explicit Vector(Vector<U, 1> const & other);

	template <std::size_t IDX> T const & static_get() const;
	template <std::size_t IDX> T & static_get();
};




template <class T, std::size_t SIZE>
struct Printer
{
	static void print(std::ostream &, Vector<T, SIZE> const &);
};

template <class T>
struct Printer<T, 1>
{
	static void print(std::ostream &, Vector<T, 1> const &);
};

template <class T, std::size_t SIZE>
std::ostream & operator<<(std::ostream & os, Vector<T, SIZE> const & v);


#include "Vector.ipp"


#endif // VECTOR_HPP