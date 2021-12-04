#ifndef _IEL_STRING_H_
#define _IEL_STRING_H_

#include "../../Compiler.h"

#include <memory>


_IEL_NAMESPACE_BEGIN_

constexpr size_t strlen(const char* str) 
{
  size_t len = 0;

  while(str[len] != '\0')
  {
    ++len;
  }

  return len;
}

class _NO_DISCARD String {
public:
  String();
  String(const char* str);
  String(const String& str);
  // String(String&& str) noexcept;
  ~String();

  String& operator=(const String& str);
  // String operator=(String&& str) noexcept;
  bool operator==(const String& str) const;
  bool operator!=(const String& str) const;
  String operator+(const String& str);
public:
  static constexpr char null_content = '\0';

public:
  _NO_DISCARD constexpr size_t size() { return this->mSize; }
  _NO_DISCARD constexpr size_t capacity() { return this->mCapacity; }
  const char* c_str() { return this->mContent.get(); }

private:
  size_t mSize;
  size_t mCapacity;
  std::unique_ptr<char[]> mContent;

};

_IEL_NAMESPACE_END_

#endif // _IEL_STRING_H_