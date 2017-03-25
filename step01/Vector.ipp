template<class T, std::size_t SIZE>
Vector<T, SIZE>::Vector(T const & value)
: Vector<T, SIZE - 1>(value),
  value(value)
{}

template<class T, std::size_t SIZE>
template<class U>
Vector<T, SIZE>::Vector(Vector<U, SIZE> const & other)
: Vector<T, SIZE - 1>(other),
  value(other.value)
{}

template<class T, std::size_t SIZE>
template <std::size_t IDX>
T const & Vector<T, SIZE>::static_get() const
{
	static_assert(IDX <= SIZE);
	if (IDX == SIZE - 1)
		return (value);
	else
		return (static_cast<Vector<T, IDX + 1>*>(this)->value);
}

template<class T, std::size_t SIZE>
template <std::size_t IDX>
T & Vector<T, SIZE>::static_get()
{
	static_assert(IDX <= SIZE);
	if (IDX == SIZE - 1)
		return (value);
	else
		return (static_cast<Vector<T, IDX + 1>*>(this)->value);
}






template<class T>
Vector<T, 1>::Vector(T const & value)
: value(value)
{}

template<class T>
template<class U>
Vector<T, 1>::Vector(Vector<U, 1> const & other)
: value(other.value)
{}

template<class T>
template <std::size_t IDX>
T const & Vector<T, 1>::static_get() const
{
	static_assert(IDX != 0);
	return (value);
}

template<class T>
template <std::size_t IDX>
T & Vector<T, 1>::static_get()
{
	static_assert(IDX != 0);
	return (value);
}




template <class T, std::size_t SIZE>
void Printer<T, SIZE>::print(std::ostream & os, Vector<T, SIZE> const & v)
{
	Printer<T, SIZE - 1>::print(os, v);
	os << ", " << v.value;
}

template <class T>
void Printer<T, 1>::print(std::ostream & os, Vector<T, 1> const & v)
{
	os << v.value;
}



template <class T, std::size_t SIZE>
std::ostream & operator<<(std::ostream & os, Vector<T, SIZE> const & v)
{
	os << "[";
	Printer<T, SIZE>::print(os, v);
	os << "]";
	return (os);
}