#ifndef _IEL_STRING_H_
#define _IEL_STRING_H_

#include "../../Compiler.h"

#include <memory>
#include <iostream>

namespace IEL_NAME_SPACE {

CONSTEXPR size_t strlen(const char* str) 
{
  size_t len = 0;

  while(str[len] != '\0')
  {
    ++len;
  }

  return len;
}

class NODISCARD String {
public:
  using size_type = size_t;
  using value_type = char;
  using ptr_diff_type = PTRDIFF_TYPE;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;

public:
  String();
  String(const value_type* str);
  String(const String& str);
  String(String&& str) noexcept;
  ~String();

  void* operator new(size_type size);
  void operator delete(void* p);
  String& operator=(const String& str);
  String& operator=(String&& str) noexcept;
  bool operator==(const String& str) const;
  bool operator!=(const String& str) const;
  NODISCARD reference operator[](const ptr_diff_type diff) const { return *(this->mContent.get() + diff); }
  String operator+(const String& str);
public:
  static CONSTEXPR value_type kNullValue = '\0';

public:
  NODISCARD CONSTEXPR size_type size() const { return this->mSize; }
  NODISCARD CONSTEXPR size_type length() const { return this->mSize; }
  NODISCARD CONSTEXPR size_type capacity() const { return this->mCapacity; }
  NODISCARD const_pointer c_str() const { return this->mContent.get(); }

private:
  size_type mSize;
  size_type mCapacity;
  std::unique_ptr<value_type[]> mContent;

};

} // IEL_NAME_SPACE

#endif // _IEL_STRING_H_