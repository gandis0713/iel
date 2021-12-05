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


#endif // _IEL_COMPILER_H_