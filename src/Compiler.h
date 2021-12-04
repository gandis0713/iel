#ifndef _IEL_COMPILER_H_
#define _IEL_COMPILER_H_

#define _IEL_NAMESPACE_BEGIN_ namespace IEL_NAME_SPACE {
#define _IEL_NAMESPACE_END_   }

#if __has_cpp_attribute(nodiscard) && CPP_VERSION >= 17
#define NODISCARD [[nodiscard]]
#else
#define NODISCARD
#endif

#if CPP_VERSION >= 17
#define CONSTEXPR constexpr
#else
#define CONSTEXPR
#endif


#endif // _IEL_COMPILER_H_