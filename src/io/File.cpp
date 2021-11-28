#include "../inc/io/File.h"

_IEL_NAMESPACE_BEGIN_

File::File(const std::string& path, const Type type): 
  mFilePath(path), 
  mType(type) {

  this->open();
}

File::~File() {
  this->close();
}

File::Result File::open() {
  if(mFilePath.empty()) 
    return Result::EmptyFilePath;

  if(mStream != nullptr) {
    if(mStream->is_open()) 
      return Result::AlreadyOpen;

    mStream.reset();
  }

  switch(mType) {
    case Type::R:
    mStream = std::make_unique<std::fstream>(mFilePath, std::ios::in);
    break;
    case Type::W:
    mStream = std::make_unique<std::fstream>(mFilePath, std::ios::in);
    break;
    case Type::RW:
    mStream = std::make_unique<std::fstream>(mFilePath, std::ios::in | std::ios::out);
    default:
    break;
  }

  return File::Result::NoError;
}

void File::close() {
  if(mStream != nullptr) {
    mStream->close();
  }
}


_IEL_NAMESPACE_END_