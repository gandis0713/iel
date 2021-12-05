#ifndef _IEL_COMPILER_H_
#define _IEL_COMPILER_H_

#if __has_cpp_attribute(nodiscard) && __cplusplus >= 201703L
# define NODISCARD [[nodiscard]]
#else
# define NODISCARD
#endif

#if __cplusplus >= 201703L
# define CONSTEXPR constexpr
#else
# define CONSTEXPR
#endif

#ifdef __PTRDIFF_TYPE__
# define PTRDIFF_TYPE __PTRDIFF_TYPE__
#else
# define PTRDIFF_TYPE long int
#endif

#endif // _IEL_COMPILER_H_