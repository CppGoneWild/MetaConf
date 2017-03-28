template<class T, std::size_t SIZE, class FINAL>
Vector<T, SIZE, FINAL>::Vector(FINAL const & value)
: Vector<T, SIZE - 1, FINAL>(value),
  value(value)
{}

template<class T, std::size_t SIZE, class FINAL>
template<class U, class FINAL_U>
Vector<T, SIZE, FINAL>::Vector(Vector<U, SIZE, FINAL_U> const & other)
: Vector<T, SIZE - 1, FINAL>(other),
  value(other.value)
{}

template<class T, std::size_t SIZE, class FINAL>
template <std::size_t IDX>
T const & Vector<T, SIZE, FINAL>::static_get() const
{
	static_assert(IDX <= SIZE);
	if (IDX == SIZE - 1)
		return (value);
	else
		return (static_cast<Vector<T, IDX + 1, FINAL>*>(this)->value);
}

template<class T, std::size_t SIZE, class FINAL>
template <std::size_t IDX>
T & Vector<T, SIZE, FINAL>::static_get()
{
	static_assert(IDX <= SIZE);
	if (IDX == SIZE - 1)
		return (value);
	else
		return (static_cast<Vector<T, IDX + 1, FINAL>*>(this)->value);
}

template<class T, std::size_t SIZE, class FINAL>
bool Vector<T, SIZE, FINAL>::operator==(Vector<T, SIZE, FINAL> const & other) const
{
	if (value != other.value)
		return (false);
	return (*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) == other);
}

template<class T, std::size_t SIZE, class FINAL>
bool Vector<T, SIZE, FINAL>::operator!=(Vector<T, SIZE, FINAL> const & other) const
{
	if (value != other.value)
		return (true);
	return (*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) != other);
}

template<class T, std::size_t SIZE, class FINAL>
void Vector<T, SIZE, FINAL>::operator+=(FINAL const & scalar)
{
	value += scalar;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) += scalar;
}

template<class T, std::size_t SIZE, class FINAL>
void Vector<T, SIZE, FINAL>::operator-=(FINAL const & scalar)
{
	value -= scalar;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) -= scalar;
}

template<class T, std::size_t SIZE, class FINAL>
void Vector<T, SIZE, FINAL>::operator*=(FINAL const & scalar)
{
	value *= scalar;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) *= scalar;
}

template<class T, std::size_t SIZE, class FINAL>
void Vector<T, SIZE, FINAL>::operator/=(FINAL const & scalar)
{
	value /= scalar;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) /= scalar;
}

template<class T, std::size_t SIZE, class FINAL>
void Vector<T, SIZE, FINAL>::operator%=(FINAL const & scalar)
{
	value = Modulo<FINAL, FINAL>::mod(value, scalar);
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) %= scalar;
}

template<class T, std::size_t SIZE, class FINAL>
template <class U, class FINAL_U>
void Vector<T, SIZE, FINAL>::operator+=(Vector<U, SIZE, FINAL_U> const & other)
{
	value += other.value;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) += other;
}

template<class T, std::size_t SIZE, class FINAL>
template <class U, class FINAL_U>
void Vector<T, SIZE, FINAL>::operator-=(Vector<U, SIZE, FINAL_U> const & other)
{
	value -= other.value;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) -= other;
}

template<class T, std::size_t SIZE, class FINAL>
template <class U, class FINAL_U>
void Vector<T, SIZE, FINAL>::operator*=(Vector<U, SIZE, FINAL_U> const & other)
{
	value *= other.value;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) *= other;
}

template<class T, std::size_t SIZE, class FINAL>
template <class U, class FINAL_U>
void Vector<T, SIZE, FINAL>::operator/=(Vector<U, SIZE, FINAL_U> const & other)
{
	value /= other.value;
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) /= other;
}

template<class T, std::size_t SIZE, class FINAL>
template <class U, class FINAL_U>
void Vector<T, SIZE, FINAL>::operator%=(Vector<U, SIZE, FINAL_U> const & other)
{
	value = Modulo<FINAL, FINAL_U>::mod(value, other.value);
	*(static_cast<Vector<T, SIZE - 1, FINAL>*>(this)) %= other;
}

template<class T, std::size_t SIZE, class FINAL>
template <class U>
Vector<T, SIZE, FINAL> Vector<T, SIZE, FINAL>::operator+(U const & thing) const
{
	Vector<T, SIZE, FINAL> res(*this);
	res += thing;
	return (res);
}

template<class T, std::size_t SIZE, class FINAL>
template <class U>
Vector<T, SIZE, FINAL> Vector<T, SIZE, FINAL>::operator-(U const & thing) const
{
	Vector<T, SIZE, FINAL> res(*this);
	res -= thing;
	return (res);
}

template<class T, std::size_t SIZE, class FINAL>
template <class U>
Vector<T, SIZE, FINAL> Vector<T, SIZE, FINAL>::operator*(U const & thing) const
{
	Vector<T, SIZE, FINAL> res(*this);
	res *= thing;
	return (res);
}

template<class T, std::size_t SIZE, class FINAL>
template <class U>
Vector<T, SIZE, FINAL> Vector<T, SIZE, FINAL>::operator/(U const & thing) const
{
	Vector<T, SIZE, FINAL> res(*this);
	res /= thing;
	return (res);
}

template<class T, std::size_t SIZE, class FINAL>
template <class U>
Vector<T, SIZE, FINAL> Vector<T, SIZE, FINAL>::operator%(U const & thing) const
{
	Vector<T, SIZE, FINAL> res(*this);
	res %= thing;
	return (res);
}

template<class T, std::size_t SIZE, class FINAL>
T Vector<T, SIZE, FINAL>::getNormeSquared() const
{
	return (static_cast<Vector<T, SIZE - 1, FINAL>const *>(this)->getNormeSquared() + value * value);
}

template<class T, std::size_t SIZE, class FINAL>
T Vector<T, SIZE, FINAL>::getNorme() const
{
	return (std::sqrt(getNormeSquared()));
}

template<class T, std::size_t SIZE, class FINAL>
template <class U, class FINAL_U>
T Vector<T, SIZE, FINAL>::dotProduct(Vector<U, SIZE, FINAL_U> const & other) const
{
	return (static_cast<Vector<T, SIZE - 1, FINAL>const *>(this)->dotProduct(other) + value * other.value);
}

template<class T, std::size_t SIZE, class FINAL>
Vector<T, SIZE, FINAL> Vector<T, SIZE, FINAL>::getNormed() const
{
	Vector<T, SIZE, FINAL> res(*this);
	res /= this->getNorme();
	return (res);
}







template<class T, class FINAL>
Vector<T, 1, FINAL>::Vector(FINAL const & value)
: value(value)
{}

template<class T, class FINAL>
template<class U, class FINAL_U>
Vector<T, 1, FINAL>::Vector(Vector<U, 1, FINAL_U> const & other)
: value(other.value)
{}

template<class T, class FINAL>
template <std::size_t IDX>
T const & Vector<T, 1, FINAL>::static_get() const
{
	static_assert(IDX != 0);
	return (value);
}

template<class T, class FINAL>
template <std::size_t IDX>
T & Vector<T, 1, FINAL>::static_get()
{
	static_assert(IDX != 0);
	return (value);
}


template<class T, class FINAL>
bool Vector<T, 1, FINAL>::operator==(Vector<T, 1, FINAL> const & other) const
{
	return (value == other.value);
}

template<class T, class FINAL>
bool Vector<T, 1, FINAL>::operator!=(Vector<T, 1, FINAL> const & other) const
{
	return (value != other.value);
}

template<class T, class FINAL>
void Vector<T, 1, FINAL>::operator+=(FINAL const & scalar)
{
	value += scalar;
}

template<class T, class FINAL>
void Vector<T, 1, FINAL>::operator-=(FINAL const & scalar)
{
	value -= scalar;
}

template<class T, class FINAL>
void Vector<T, 1, FINAL>::operator*=(FINAL const & scalar)
{
	value *= scalar;
}

template<class T, class FINAL>
void Vector<T, 1, FINAL>::operator/=(FINAL const & scalar)
{
	value /= scalar;
}

template<class T, class FINAL>
void Vector<T, 1, FINAL>::operator%=(FINAL const & scalar)
{
	value = Modulo<FINAL, FINAL>::mod(value, scalar);
}


template<class T, class FINAL>
template <class U, class FINAL_U>
void Vector<T, 1, FINAL>::operator+=(Vector<U, 1, FINAL_U> const & other)
{
	value += other.value;
}

template<class T, class FINAL>
template <class U, class FINAL_U>
void Vector<T, 1, FINAL>::operator-=(Vector<U, 1, FINAL_U> const & other)
{
	value -= other.value;
}

template<class T, class FINAL>
template <class U, class FINAL_U>
void Vector<T, 1, FINAL>::operator*=(Vector<U, 1, FINAL_U> const & other)
{
	value *= other.value;
}

template<class T, class FINAL>
template <class U, class FINAL_U>
void Vector<T, 1, FINAL>::operator/=(Vector<U, 1, FINAL_U> const & other)
{
	value /= other.value;
}

template<class T, class FINAL>
template <class U, class FINAL_U>
void Vector<T, 1, FINAL>::operator%=(Vector<U, 1, FINAL_U> const & other)
{
	value = Modulo<FINAL, FINAL_U>::mod(value, other.value);
}


template<class T, class FINAL>
template <class U>
Vector<T, 1, FINAL> Vector<T, 1, FINAL>::operator+(U const & thing) const
{
	Vector<T, 1, FINAL> res(*this);
	res += thing;
	return (res);
}

template<class T, class FINAL>
template <class U>
Vector<T, 1, FINAL> Vector<T, 1, FINAL>::operator-(U const & thing) const
{
	Vector<T, 1, FINAL> res(*this);
	res -= thing;
	return (res);
}

template<class T, class FINAL>
template <class U>
Vector<T, 1, FINAL> Vector<T, 1, FINAL>::operator*(U const & thing) const
{
	Vector<T, 1, FINAL> res(*this);
	res *= thing;
	return (res);
}

template<class T, class FINAL>
template <class U>
Vector<T, 1, FINAL> Vector<T, 1, FINAL>::operator/(U const & thing) const
{
	Vector<T, 1, FINAL> res(*this);
	res /= thing;
	return (res);
}

template<class T, class FINAL>
template <class U>
Vector<T, 1, FINAL> Vector<T, 1, FINAL>::operator%(U const & thing) const
{
	Vector<T, 1, FINAL> res(*this);
	res %= thing;
	return (res);
}

template<class T, class FINAL>
T Vector<T, 1, FINAL>::getNormeSquared() const
{
	return (value * value);
}

template<class T, class FINAL>
T Vector<T, 1, FINAL>::getNorme() const
{
	return (value);
}

template<class T, class FINAL>
template <class U, class FINAL_U>
T Vector<T, 1, FINAL>::dotProduct(Vector<U, 1, FINAL_U> const & other) const
{
	return (value * other.value);
}

template<class T, class FINAL>
Vector<T, 1, FINAL> Vector<T, 1, FINAL>::getNormed() const
{
	Vector<T, 1, FINAL> res(*this);
	res /= value;
	return (res);
}










template <class T, std::size_t SIZE, class FINAL>
void Printer<T, SIZE, FINAL>::print(std::ostream & os, Vector<T, SIZE, FINAL> const & v)
{
	Printer<T, SIZE - 1, FINAL>::print(os, v);
	os << ", " << v.value;
}

template <class T, class FINAL>
void Printer<T, 1, FINAL>::print(std::ostream & os, Vector<T, 1, FINAL> const & v)
{
	os << v.value;
}



template <class T, std::size_t SIZE, class FINAL>
std::ostream & operator<<(std::ostream & os, Vector<T, SIZE, FINAL> const & v)
{
	os << "[";
	Printer<T, SIZE, FINAL>::print(os, v);
	os << "]";
	return (os);
}
