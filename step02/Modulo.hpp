#ifndef   MPL_MODULO_HPP
# define  MPL_MODULO_HPP

# include <type_traits> // std::is_arithmetic
# include <limits>    // std::numeric_limits<T>::is_integer
# include <cmath>     // fmod

template<typename A, typename B,
         bool not_integer = std::is_arithmetic<A>::value && std::is_arithmetic<B>::value &&
                            (!std::numeric_limits<A>::is_integer || !std::numeric_limits<B>::is_integer)>
class Modulo
{
public:
  static auto mod(A a, B b) -> decltype(a % b)
  {
    return (a % b);
  }
};
  
template<typename A, typename B>
class Modulo<A, B, true>
{
public:
  static auto mod(A a, B b) -> decltype(std::fmod(a, a))
  {
    return (std::fmod(a, A(b)));
  }
};

#endif // MPL_MODULO_HPP
