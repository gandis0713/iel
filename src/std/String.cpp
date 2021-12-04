#include "../inc/std/String.h"
#include <cstring>
#include <limits>
#include <iostream>

_IEL_NAMESPACE_BEGIN_

String::String():
  mSize(0),
  mCapacity(0)
{

}

String::String(const char* str):
  mSize(_IEL_NAME_SPACE_::strlen(str)),
  mCapacity(this->mSize + 1),
  mContent(std::make_unique<char[]>(this->mCapacity))
{
  std::memcpy(mContent.get(), str, this->mCapacity);
  mContent[this->mSize] = String::null_content;
}

String::String(const String& str):
  mSize(str.mSize),
  mCapacity(str.mCapacity),
  mContent(std::make_unique<char[]>(this->mCapacity))
{
  std::memcpy(mContent.get(), str.mContent.get(), this->mCapacity);
}

// String::String(String&& str) noexcept 
// {

// }

String::~String() 
{
  
}

String& String::operator=(const String& str) 
{
  if(this != &str) 
  {
    this->mSize = str.mSize;
    this->mCapacity = str.mCapacity;
    std::unique_ptr<char[]> content(new (std::nothrow) char[this->mCapacity]);
    if(content == nullptr) 
    {
      std::cerr << "Failed to allocate memory string copy assignment." << std::endl;
      return *this;
    }

    if(this->mContent != nullptr) this->mContent.reset();
    this->mContent = std::move(content);

    memcpy(mContent.get(), str.mContent.get(), this->mCapacity);
  }

  return *this;
}

// String String::operator=(String&& str) noexcept
// {
//   return *this;
// }

bool String::operator==(const String& str) const
{
  if(this == &str) return true;

  if(this->mSize != str.mSize) return false;

  size_t index = 0;
  while(index < this->mSize)
  {
    if(this->mContent[index] != str.mContent[index])
    {
      return false;
    }
    ++index;
  }

  return true;
}

bool String::operator!=(const String& str) const
{
  if(this->mSize != str.mSize) return true;

  size_t index = 0;
  while(index < this->mSize)
  {
    if(this->mContent[index] != str.mContent[index])
    {
      return true;
    }
    ++index;
  }

  return false;
}

String String::operator+(const String& strIn)
{
  if(this->mSize > SIZE_MAX - strIn.mSize)
  {
    std::cerr << "The size of string overflows." << std::endl;
    return *this;
  }

  if(this->mCapacity > SIZE_MAX - strIn.mCapacity)
  {
    std::cerr << "The capacity of string overflows." << std::endl;
    return *this;
  }

  String strOut;
  strOut.mSize = this->mSize + strIn.mSize;
  strOut.mCapacity = strOut.mSize + 1;

  strOut.mContent = std::unique_ptr<char[]>(new (std::nothrow) char[strOut.mCapacity]);
  if(strOut.mContent == nullptr) 
  {
    std::cerr << "Failed to allocate memory for string content +." << std::endl;
    return *this;
  }

  size_t index = 0;
  while(index < this->mSize)
  {
    strOut.mContent[index] = this->mContent[index];
    ++index;
  }

  while(index < strOut.mSize)
  {
    strOut.mContent[index] = strIn.mContent[index - this->mSize];
    ++index;
  }

  strOut.mContent[strOut.mSize] = String::null_content;
  
  return strOut;
}
  
_IEL_NAMESPACE_END_