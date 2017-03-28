#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "Vector.hpp"

template <class T, std::size_t SIZE, std::size_t... ARGS>
struct Matrix
{
	using ChildType = Matrix<T, ARGS...>;
	static constexpr std::size_t N = sizeof...(ARGS) + 1;

	Vector<ChildType, SIZE, T> row;

	Matrix(T const & value = T());
	template <class U> Matrix(Matrix<U, SIZE, ARGS...> const &);

	template <std::size_t IDX, std::size_t... IDXS> T const & static_get() const;
	template <std::size_t IDX, std::size_t... IDXS> T & static_get();

	void operator+=(T const &);
	void operator-=(T const &);
	void operator*=(T const &);
	void operator/=(T const &);
	void operator%=(T const &);

	template <class U> void operator+=(Matrix<U, SIZE, ARGS...> const &);
	template <class U> void operator-=(Matrix<U, SIZE, ARGS...> const &);
	template <class U> void operator*=(Matrix<U, SIZE, ARGS...> const &);
	template <class U> void operator/=(Matrix<U, SIZE, ARGS...> const &);
	template <class U> void operator%=(Matrix<U, SIZE, ARGS...> const &);

	template <class U> Matrix<T, SIZE, ARGS...> operator+(U const &) const;
	template <class U> Matrix<T, SIZE, ARGS...> operator-(U const &) const;
	template <class U> Matrix<T, SIZE, ARGS...> operator*(U const &) const;
	template <class U> Matrix<T, SIZE, ARGS...> operator/(U const &) const;
	template <class U> Matrix<T, SIZE, ARGS...> operator%(U const &) const;
};



template <class T, std::size_t SIZE>
struct Matrix<T, SIZE>
{
	using ChildType = T;
	static constexpr std::size_t N = 1;

	Vector<ChildType, SIZE, T> row;

	Matrix(T const & value = T());
	template <class U> Matrix(Matrix<U, SIZE> const &);

	template <std::size_t IDX> T const & static_get() const;
	template <std::size_t IDX> T & static_get();

	void operator+=(T const &);
	void operator-=(T const &);
	void operator*=(T const &);
	void operator/=(T const &);
	void operator%=(T const &);

	template <class U> void operator+=(Matrix<U, SIZE> const &);
	template <class U> void operator-=(Matrix<U, SIZE> const &);
	template <class U> void operator*=(Matrix<U, SIZE> const &);
	template <class U> void operator/=(Matrix<U, SIZE> const &);
	template <class U> void operator%=(Matrix<U, SIZE> const &);

	template <class U> Matrix<T, SIZE> operator+(U const &) const;
	template <class U> Matrix<T, SIZE> operator-(U const &) const;
	template <class U> Matrix<T, SIZE> operator*(U const &) const;
	template <class U> Matrix<T, SIZE> operator/(U const &) const;
	template <class U> Matrix<T, SIZE> operator%(U const &) const;
};





template <class T, std::size_t SIZE, std::size_t... ARGS>
std::ostream & operator<<(std::ostream & os, Matrix<T, SIZE, ARGS...> const & m);


#include "Matrix.ipp"


#endif // MATRIX_HPP
