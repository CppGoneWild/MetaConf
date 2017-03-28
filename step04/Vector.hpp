#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <iostream>

#include "Modulo.hpp"


template <class T, std::size_t SIZE, class FINAL = T>
struct Vector : public Vector<T, SIZE - 1, FINAL>
{
	T value;

	explicit Vector(FINAL const & value = FINAL());
	template<class U, class FINAL_U> explicit Vector(Vector<U, SIZE, FINAL_U> const & other);

	template <std::size_t IDX> T const & static_get() const;
	template <std::size_t IDX> T & static_get();

	bool operator==(Vector<T, SIZE, FINAL> const &) const;
	bool operator!=(Vector<T, SIZE, FINAL> const &) const;

	void operator+=(FINAL const & scalar);
	void operator-=(FINAL const & scalar);
	void operator*=(FINAL const & scalar);
	void operator/=(FINAL const & scalar);
	void operator%=(FINAL const & scalar);

	template <class U, class FINAL_U> void operator+=(Vector<U, SIZE, FINAL_U> const & other);
	template <class U, class FINAL_U> void operator-=(Vector<U, SIZE, FINAL_U> const & other);
	template <class U, class FINAL_U> void operator*=(Vector<U, SIZE, FINAL_U> const & other);
	template <class U, class FINAL_U> void operator/=(Vector<U, SIZE, FINAL_U> const & other);
	template <class U, class FINAL_U> void operator%=(Vector<U, SIZE, FINAL_U> const & other);

	template <class U> Vector<T, SIZE, FINAL> operator+(U const & thing) const;
	template <class U> Vector<T, SIZE, FINAL> operator-(U const & thing) const;
	template <class U> Vector<T, SIZE, FINAL> operator*(U const & thing) const;
	template <class U> Vector<T, SIZE, FINAL> operator/(U const & thing) const;
	template <class U> Vector<T, SIZE, FINAL> operator%(U const & thing) const;

	T getNormeSquared() const;
	T getNorme() const;
	template <class U, class FINAL_U> T dotProduct(Vector<U, SIZE, FINAL_U> const &) const;
	Vector<T, SIZE, FINAL> getNormed() const;
};


template <class T, class FINAL>
struct Vector<T, 1, FINAL>
{
	T value;

	explicit Vector(FINAL const & value = FINAL());
	template<class U,class FINAL_U> explicit Vector(Vector<U, 1, FINAL_U> const & other);

	template <std::size_t IDX> T const & static_get() const;
	template <std::size_t IDX> T & static_get();

	bool operator==(Vector<T, 1, FINAL> const &) const;
	bool operator!=(Vector<T, 1, FINAL> const &) const;

	void operator+=(FINAL const & scalar);
	void operator-=(FINAL const & scalar);
	void operator*=(FINAL const & scalar);
	void operator/=(FINAL const & scalar);
	void operator%=(FINAL const & scalar);

	template <class U, class FINAL_U> void operator+=(Vector<U, 1, FINAL_U> const & scalar);
	template <class U, class FINAL_U> void operator-=(Vector<U, 1, FINAL_U> const & scalar);
	template <class U, class FINAL_U> void operator*=(Vector<U, 1, FINAL_U> const & scalar);
	template <class U, class FINAL_U> void operator/=(Vector<U, 1, FINAL_U> const & scalar);
	template <class U, class FINAL_U> void operator%=(Vector<U, 1, FINAL_U> const & scalar);

	template <class U> Vector<T, 1, FINAL> operator+(U const & thing) const;
	template <class U> Vector<T, 1, FINAL> operator-(U const & thing) const;
	template <class U> Vector<T, 1, FINAL> operator*(U const & thing) const;
	template <class U> Vector<T, 1, FINAL> operator/(U const & thing) const;
	template <class U> Vector<T, 1, FINAL> operator%(U const & thing) const;

	T getNormeSquared() const;
	T getNorme() const;
	template <class U, class FINAL_U> T dotProduct(Vector<U, 1, FINAL_U> const &) const;
	Vector<T, 1, FINAL> getNormed() const;
};


template <class T, std::size_t SIZE, class FINAL = T>
struct Printer
{
	static void print(std::ostream &, Vector<T, SIZE, FINAL> const &);
};


template <class T, class FINAL>
struct Printer<T, 1, FINAL>
{
	static void print(std::ostream &, Vector<T, 1, FINAL> const &);
};


template <class T, std::size_t SIZE, class FINAL>
std::ostream & operator<<(std::ostream & os, Vector<T, SIZE, FINAL> const & v);


#include "Vector.ipp"


#endif // VECTOR_HPP
