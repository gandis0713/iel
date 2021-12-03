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
  mCapacity(this->mSize),
  mContent(std::make_unique<char[]>(this->mCapacity))
{
  std::memcpy(mContent.get(), str, this->mCapacity);
}

String::String(const String& str):
  mSize(str.mSize),
  mCapacity(str.mCapacity),
  mContent(std::make_unique<char[]>(this->mCapacity))
{
  std::memcpy(mContent.get(), str.mContent.get(), this->mCapacity);
}

String::String(String&& str) noexcept 
{

}

String::~String() 
{

}

String& String::operator=(const String& str) 
{
  if(this != &str) 
  {
    this->mSize = str.mSize;
    this->mCapacity = str.mCapacity;
    if(this->mContent != nullptr) this->mContent.reset();
    this->mContent = std::make_unique<char[]>(this->mCapacity);
    std::memcpy(mContent.get(), str.mContent.get(), this->mCapacity);
  }

  return *this;
}

String String::operator=(String&& str) noexcept
{
  return *this;
}

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
  strOut.mCapacity = this->mCapacity + strIn.mCapacity;

  strOut.mContent = std::make_unique<char[]>(strOut.mCapacity);

  size_t index = 0;
  while(index < this->mSize)
  {
    strOut.mContent[index] = this->mContent[index];
    ++index;
  }

  index = 0;
  while(index < strIn.mSize)
  {
    strOut.mContent[index + this->mSize] = strIn.mContent[index];
    ++index;
  }
  
  
  return strOut;
}
  
_IEL_NAMESPACE_END_