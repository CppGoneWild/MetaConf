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

template<class T, std::size_t SIZE>
bool Vector<T, SIZE>::operator==(Vector<T, SIZE> const & other) const
{
	if (value != other.value)
		return (false);
	return (*(static_cast<Vector<T, SIZE - 1>*>(this)) == other);
}

template<class T, std::size_t SIZE>
bool Vector<T, SIZE>::operator!=(Vector<T, SIZE> const & other) const
{
	if (value != other.value)
		return (true);
	return (*(static_cast<Vector<T, SIZE - 1>*>(this)) != other);
}

template<class T, std::size_t SIZE>
void Vector<T, SIZE>::operator+=(T const & scalar)
{
	value += scalar;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) += scalar;
}

template<class T, std::size_t SIZE>
void Vector<T, SIZE>::operator-=(T const & scalar)
{
	value -= scalar;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) -= scalar;
}

template<class T, std::size_t SIZE>
void Vector<T, SIZE>::operator*=(T const & scalar)
{
	value *= scalar;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) *= scalar;
}

template<class T, std::size_t SIZE>
void Vector<T, SIZE>::operator/=(T const & scalar)
{
	value /= scalar;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) /= scalar;
}

template<class T, std::size_t SIZE>
void Vector<T, SIZE>::operator%=(T const & scalar)
{
	value = Modulo<T, T>::mod(value, scalar);
	*(static_cast<Vector<T, SIZE - 1>*>(this)) %= scalar;
}

template<class T, std::size_t SIZE>
template <class U>
void Vector<T, SIZE>::operator+=(Vector<U, SIZE> const & other)
{
	value += other.value;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) += other;
}

template<class T, std::size_t SIZE>
template <class U>
void Vector<T, SIZE>::operator-=(Vector<U, SIZE> const & other)
{
	value -= other.value;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) -= other;
}

template<class T, std::size_t SIZE>
template <class U>
void Vector<T, SIZE>::operator*=(Vector<U, SIZE> const & other)
{
	value *= other.value;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) *= other;
}

template<class T, std::size_t SIZE>
template <class U>
void Vector<T, SIZE>::operator/=(Vector<U, SIZE> const & other)
{
	value /= other.value;
	*(static_cast<Vector<T, SIZE - 1>*>(this)) /= other;
}

template<class T, std::size_t SIZE>
template <class U>
void Vector<T, SIZE>::operator%=(Vector<U, SIZE> const & other)
{
	value = Modulo<T, U>::mod(value, other.value);
	*(static_cast<Vector<T, SIZE - 1>*>(this)) %= other;
}

template<class T, std::size_t SIZE>
template <class U>
Vector<T, SIZE> Vector<T, SIZE>::operator+(U const & thing) const
{
	Vector<T, SIZE> res(*this);
	res += thing;
	return (res);
}

template<class T, std::size_t SIZE>
template <class U>
Vector<T, SIZE> Vector<T, SIZE>::operator-(U const & thing) const
{
	Vector<T, SIZE> res(*this);
	res -= thing;
	return (res);
}

template<class T, std::size_t SIZE>
template <class U>
Vector<T, SIZE> Vector<T, SIZE>::operator*(U const & thing) const
{
	Vector<T, SIZE> res(*this);
	res *= thing;
	return (res);
}

template<class T, std::size_t SIZE>
template <class U>
Vector<T, SIZE> Vector<T, SIZE>::operator/(U const & thing) const
{
	Vector<T, SIZE> res(*this);
	res /= thing;
	return (res);
}

template<class T, std::size_t SIZE>
template <class U>
Vector<T, SIZE> Vector<T, SIZE>::operator%(U const & thing) const
{
	Vector<T, SIZE> res(*this);
	res %= thing;
	return (res);
}

template<class T, std::size_t SIZE>
T Vector<T, SIZE>::getNormeSquared() const
{
	return (static_cast<Vector<T, SIZE - 1>const *>(this)->getNormeSquared() + value * value);
}

template<class T, std::size_t SIZE>
T Vector<T, SIZE>::getNorme() const
{
	return (std::sqrt(getNormeSquared()));
}

template<class T, std::size_t SIZE>
template <class U>
T Vector<T, SIZE>::dotProduct(Vector<U, SIZE> const & other) const
{
	return (static_cast<Vector<T, SIZE - 1>const *>(this)->dotProduct(other) + value * other.value);
}

template<class T, std::size_t SIZE>
Vector<T, SIZE> Vector<T, SIZE>::getNormed() const
{
	Vector<T, SIZE> res(*this);
	res /= this->getNorme();
	return (res);
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


template<class T>
bool Vector<T, 1>::operator==(Vector<T, 1> const & other) const
{
	return (value == other.value);
}

template<class T>
bool Vector<T, 1>::operator!=(Vector<T, 1> const & other) const
{
	return (value != other.value);
}

template<class T>
void Vector<T, 1>::operator+=(T const & scalar)
{
	value += scalar;
}

template<class T>
void Vector<T, 1>::operator-=(T const & scalar)
{
	value -= scalar;
}

template<class T>
void Vector<T, 1>::operator*=(T const & scalar)
{
	value *= scalar;
}

template<class T>
void Vector<T, 1>::operator/=(T const & scalar)
{
	value /= scalar;
}

template<class T>
void Vector<T, 1>::operator%=(T const & scalar)
{
	value = Modulo<T, T>::mod(value, scalar);
}


template<class T>
template <class U>
void Vector<T, 1>::operator+=(Vector<U, 1> const & other)
{
	value += other.value;
}

template<class T>
template <class U>
void Vector<T, 1>::operator-=(Vector<U, 1> const & other)
{
	value -= other.value;
}

template<class T>
template <class U>
void Vector<T, 1>::operator*=(Vector<U, 1> const & other)
{
	value *= other.value;
}

template<class T>
template <class U>
void Vector<T, 1>::operator/=(Vector<U, 1> const & other)
{
	value /= other.value;
}

template<class T>
template <class U>
void Vector<T, 1>::operator%=(Vector<U, 1> const & other)
{
	value = Modulo<T, U>::mod(value, other.value);
}


template<class T>
template <class U>
Vector<T, 1> Vector<T, 1>::operator+(U const & thing) const
{
	Vector<T, 1> res(*this);
	res += thing;
	return (res);
}

template<class T>
template <class U>
Vector<T, 1> Vector<T, 1>::operator-(U const & thing) const
{
	Vector<T, 1> res(*this);
	res -= thing;
	return (res);
}

template<class T>
template <class U>
Vector<T, 1> Vector<T, 1>::operator*(U const & thing) const
{
	Vector<T, 1> res(*this);
	res *= thing;
	return (res);
}

template<class T>
template <class U>
Vector<T, 1> Vector<T, 1>::operator/(U const & thing) const
{
	Vector<T, 1> res(*this);
	res /= thing;
	return (res);
}

template<class T>
template <class U>
Vector<T, 1> Vector<T, 1>::operator%(U const & thing) const
{
	Vector<T, 1> res(*this);
	res %= thing;
	return (res);
}

template<class T>
T Vector<T, 1>::getNormeSquared() const
{
	return (value * value);
}

template<class T>
T Vector<T, 1>::getNorme() const
{
	return (value);
}

template<class T>
template <class U>
T Vector<T, 1>::dotProduct(Vector<U, 1> const & other) const
{
	return (value * other.value);
}

template<class T>
Vector<T, 1> Vector<T, 1>::getNormed() const
{
	Vector<T, 1> res(*this);
	res /= value;
	return (res);
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
