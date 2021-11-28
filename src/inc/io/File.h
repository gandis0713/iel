#ifndef _IEL_IO_FILE_H_
#define _IEL_IO_FILE_H_

#include <string>
#include <fstream>
#include <memory>

#include "../Compiler.h"

_IEL_BEGIN_

class File {
  public:
    enum class Result {
      NoError,
      EmptyFilePath,
      CannotOpen,
      AlreadyOpen
    };

    enum class Type {
      R, // read
      W, // write
      RW // read/write
    };

  public:
    File(const std::string& path, const Type type);
    File(const File& file) = delete;
    virtual ~File();

    Result open();
    void close();
  public:
    File& operator=(const File&) = delete;

  private:
    std::string mFilePath;
    Type mType;

    std::unique_ptr<std::fstream> mStream;
};

_IEL_END

#endif // _IEL_IO_FILE_H_