#include "InputStream.hpp"

namespace IO {

InputStream::InputStream(int fileDescriptor)
   : mFileDesc(fileDescriptor)
{
   // Intentionally left blank
}

int InputStream::operator () (void) const
{
   return mFileDesc;
}

std::vector<uint8_t> InputStream::Read(size_t maxBytes) const
{
   std::vector<uint8_t> result(maxBytes);
   const ssize_t COUNT = read(mFileDesc, result.data(), result.size());
   if (COUNT < 0)
   {
      throw COUNT;
   }
   // COUNT is 0 or greater
   result.resize(static_cast<size_t>(COUNT));
   return std::move(result);
}

}

