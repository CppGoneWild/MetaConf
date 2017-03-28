#ifndef STATIC_POW_HH
#define STATIC_POW_HH


template <int A, unsigned int B>
struct StaticPow
{
	static const unsigned int result = A * StaticPow<A, B - 1>::result;
};


template <int A>
struct StaticPow<A, 0>
{
	static const unsigned int result = 1;
};


#endif // STATIC_POW_HH
