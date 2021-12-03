#ifndef _IEL_COMPILER_H_
#define _IEL_COMPILER_H_

#define _IEL_NAMESPACE_BEGIN_ namespace _IEL_NAME_SPACE_ {
#define _IEL_NAMESPACE_END_   }

#if __has_cpp_attribute(nodiscard)
#define _NO_DISCARD [[nodiscard]]
#else
#define _NO_DISCARD
#endif


#endif // _IEL_COMPILER_H_