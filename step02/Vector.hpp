#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <iostream>

#include "Modulo.hpp"


template <class T, std::size_t SIZE>
struct Vector : public Vector<T, SIZE - 1>
{
	T value;

	explicit Vector(T const & value = T());
	template<class U> explicit Vector(Vector<U, SIZE> const & other);

	template <std::size_t IDX> T const & static_get() const;
	template <std::size_t IDX> T & static_get();

	bool operator==(Vector<T, SIZE> const &) const;
	bool operator!=(Vector<T, SIZE> const &) const;

	void operator+=(T const & scalar);
	void operator-=(T const & scalar);
	void operator*=(T const & scalar);
	void operator/=(T const & scalar);
	void operator%=(T const & scalar);

	template <class U> void operator+=(Vector<U, SIZE> const & other);
	template <class U> void operator-=(Vector<U, SIZE> const & other);
	template <class U> void operator*=(Vector<U, SIZE> const & other);
	template <class U> void operator/=(Vector<U, SIZE> const & other);
	template <class U> void operator%=(Vector<U, SIZE> const & other);

	template <class U> Vector<T, SIZE> operator+(U const & thing) const;
	template <class U> Vector<T, SIZE> operator-(U const & thing) const;
	template <class U> Vector<T, SIZE> operator*(U const & thing) const;
	template <class U> Vector<T, SIZE> operator/(U const & thing) const;
	template <class U> Vector<T, SIZE> operator%(U const & thing) const;

	T getNormeSquared() const;
	T getNorme() const;
	template <class U> T dotProduct(Vector<U, SIZE> const &) const;
	Vector<T, SIZE> getNormed() const;
};

template <class T>
struct Vector<T, 1>
{
	T value;

	explicit Vector(T const & value = T());
	template<class U> explicit Vector(Vector<U, 1> const & other);

	template <std::size_t IDX> T const & static_get() const;
	template <std::size_t IDX> T & static_get();

	bool operator==(Vector<T, 1> const &) const;
	bool operator!=(Vector<T, 1> const &) const;

	void operator+=(T const & scalar);
	void operator-=(T const & scalar);
	void operator*=(T const & scalar);
	void operator/=(T const & scalar);
	void operator%=(T const & scalar);

	template <class U> void operator+=(Vector<U, 1> const & scalar);
	template <class U> void operator-=(Vector<U, 1> const & scalar);
	template <class U> void operator*=(Vector<U, 1> const & scalar);
	template <class U> void operator/=(Vector<U, 1> const & scalar);
	template <class U> void operator%=(Vector<U, 1> const & scalar);

	template <class U> Vector<T, 1> operator+(U const & thing) const;
	template <class U> Vector<T, 1> operator-(U const & thing) const;
	template <class U> Vector<T, 1> operator*(U const & thing) const;
	template <class U> Vector<T, 1> operator/(U const & thing) const;
	template <class U> Vector<T, 1> operator%(U const & thing) const;

	T getNormeSquared() const;
	T getNorme() const;
	template <class U> T dotProduct(Vector<U, 1> const &) const;
	Vector<T, 1> getNormed() const;
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