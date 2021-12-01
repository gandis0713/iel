#include "../inc/std/String.h"

_IEL_NAMESPACE_BEGIN_

String::String() 
{

}

String::String(const String& str)
{

}

String::String(String&& str) noexcept 
{

}

String::~String() 
{

}

String& String::operator=(const String& str) 
{
  return *this;
}

String String::operator=(String&& str) noexcept
{
  return *this;
}

String String::operator+(const String& str)
{
  String strR;
  return strR;
}
  
_IEL_NAMESPACE_END_