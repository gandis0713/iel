#ifndef _IEL_STRING_H_
#define _IEL_STRING_H_

#include <memory>

#include "../../Compiler.h"

_IEL_NAMESPACE_BEGIN_

class String {
public:
  String();
  String(const String& str);
  String(String&& str) noexcept;
  ~String();

  String& operator=(const String& str);
  String operator=(String&& str) noexcept;
  String operator+(const String& str);

private:
  size_t mSize;
  size_t mCapacity;
  std::unique_ptr<char> mChar;

};

_IEL_NAMESPACE_END_

#endif // _IEL_STRING_H_