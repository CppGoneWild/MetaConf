template <class T, std::size_t SIZE, std::size_t... ARGS>
Matrix<T, SIZE, ARGS...>::Matrix(T const & value)
	: row(value)
{}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
Matrix<T, SIZE, ARGS...>::Matrix(Matrix<U, SIZE, ARGS...> const & other)
	: row(other.row)
{}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <std::size_t IDX, std::size_t... IDXS>
T const & Matrix<T, SIZE, ARGS...>::static_get() const
{
	return row. template static_get<IDX>(). template static_get<IDXS...>();
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <std::size_t IDX, std::size_t... IDXS>
T & Matrix<T, SIZE, ARGS...>::static_get()
{
	return row. template static_get<IDX>(). template static_get<IDXS...>();
}


template <class T, std::size_t SIZE, std::size_t... ARGS>
void Matrix<T, SIZE, ARGS...>::operator+=(T const & scalar)
{
	row += scalar;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
void Matrix<T, SIZE, ARGS...>::operator-=(T const & scalar)
{
	row -= scalar;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
void Matrix<T, SIZE, ARGS...>::operator*=(T const & scalar)
{
	row *= scalar;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
void Matrix<T, SIZE, ARGS...>::operator/=(T const & scalar)
{
	row /= scalar;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
void Matrix<T, SIZE, ARGS...>::operator%=(T const & scalar)
{
	row %= scalar;
}


template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
void Matrix<T, SIZE, ARGS...>::operator+=(Matrix<U, SIZE, ARGS...> const & other)
{
	row += other.row;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
void Matrix<T, SIZE, ARGS...>::operator-=(Matrix<U, SIZE, ARGS...> const & other)
{
	row -= other.row;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
void Matrix<T, SIZE, ARGS...>::operator*=(Matrix<U, SIZE, ARGS...> const & other)
{
	row *= other.row;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
void Matrix<T, SIZE, ARGS...>::operator/=(Matrix<U, SIZE, ARGS...> const & other)
{
	row /= other.row;
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
void Matrix<T, SIZE, ARGS...>::operator%=(Matrix<U, SIZE, ARGS...> const & other)
{
	row %= other.row;
}


template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
Matrix<T, SIZE, ARGS...> Matrix<T, SIZE, ARGS...>::operator+(U const & things) const
{
	Matrix<T, SIZE, ARGS...> tmp(*this);
	tmp += things;
	return (tmp);
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
Matrix<T, SIZE, ARGS...> Matrix<T, SIZE, ARGS...>::operator-(U const & things) const
{
	Matrix<T, SIZE, ARGS...> tmp(*this);
	tmp -= things;
	return (tmp);
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
Matrix<T, SIZE, ARGS...> Matrix<T, SIZE, ARGS...>::operator*(U const & things) const
{
	Matrix<T, SIZE, ARGS...> tmp(*this);
	tmp *= things;
	return (tmp);
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
Matrix<T, SIZE, ARGS...> Matrix<T, SIZE, ARGS...>::operator/(U const & things) const
{
	Matrix<T, SIZE, ARGS...> tmp(*this);
	tmp /= things;
	return (tmp);
}

template <class T, std::size_t SIZE, std::size_t... ARGS>
template <class U>
Matrix<T, SIZE, ARGS...> Matrix<T, SIZE, ARGS...>::operator%(U const & things) const
{
	Matrix<T, SIZE, ARGS...> tmp(*this);
	tmp %= things;
	return (tmp);
}








template <class T, std::size_t SIZE>
Matrix<T, SIZE>::Matrix(T const & value)
	: row(value)
{}

template <class T, std::size_t SIZE>
template <class U>
Matrix<T, SIZE>::Matrix(Matrix<U, SIZE> const & other)
	: row(other.row)
{}

template <class T, std::size_t SIZE>
template <std::size_t IDX>
T const & Matrix<T, SIZE>::static_get() const
{
	return row. template static_get<IDX>();
}

template <class T, std::size_t SIZE>
template <std::size_t IDX>
T & Matrix<T, SIZE>::static_get()
{
	return row. template static_get<IDX>();
}






template <class T, std::size_t SIZE>
void Matrix<T, SIZE>::operator+=(T const & scalar)
{
	row += scalar;
}

template <class T, std::size_t SIZE>
void Matrix<T, SIZE>::operator-=(T const & scalar)
{
	row -= scalar;
}

template <class T, std::size_t SIZE>
void Matrix<T, SIZE>::operator*=(T const & scalar)
{
	row *= scalar;
}

template <class T, std::size_t SIZE>
void Matrix<T, SIZE>::operator/=(T const & scalar)
{
	row /= scalar;
}

template <class T, std::size_t SIZE>
void Matrix<T, SIZE>::operator%=(T const & scalar)
{
	row %= scalar;
}


template <class T, std::size_t SIZE>
template <class U>
void Matrix<T, SIZE>::operator+=(Matrix<U, SIZE> const & other)
{
	row += other.row;
}

template <class T, std::size_t SIZE>
template <class U>
void Matrix<T, SIZE>::operator-=(Matrix<U, SIZE> const & other)
{
	row -= other.row;
}

template <class T, std::size_t SIZE>
template <class U>
void Matrix<T, SIZE>::operator*=(Matrix<U, SIZE> const & other)
{
	row *= other.row;
}

template <class T, std::size_t SIZE>
template <class U>
void Matrix<T, SIZE>::operator/=(Matrix<U, SIZE> const & other)
{
	row /= other.row;
}

template <class T, std::size_t SIZE>
template <class U>
void Matrix<T, SIZE>::operator%=(Matrix<U, SIZE> const & other)
{
	row %= other.row;
}


template <class T, std::size_t SIZE>
template <class U>
Matrix<T, SIZE> Matrix<T, SIZE>::operator+(U const & things) const
{
	Matrix<T, SIZE> tmp(*this);
	tmp += things;
	return (tmp);
}

template <class T, std::size_t SIZE>
template <class U>
Matrix<T, SIZE> Matrix<T, SIZE>::operator-(U const & things) const
{
	Matrix<T, SIZE> tmp(*this);
	tmp -= things;
	return (tmp);
}

template <class T, std::size_t SIZE>
template <class U>
Matrix<T, SIZE> Matrix<T, SIZE>::operator*(U const & things) const
{
	Matrix<T, SIZE> tmp(*this);
	tmp *= things;
	return (tmp);
}

template <class T, std::size_t SIZE>
template <class U>
Matrix<T, SIZE> Matrix<T, SIZE>::operator/(U const & things) const
{
	Matrix<T, SIZE> tmp(*this);
	tmp /= things;
	return (tmp);
}

template <class T, std::size_t SIZE>
template <class U>
Matrix<T, SIZE> Matrix<T, SIZE>::operator%(U const & things) const
{
	Matrix<T, SIZE> tmp(*this);
	tmp %= things;
	return (tmp);
}













template <class T, std::size_t SIZE, std::size_t... ARGS>
std::ostream & operator<<(std::ostream & os, Matrix<T, SIZE, ARGS...> const & m)
{
	os << m.row;
	return (os);
}
