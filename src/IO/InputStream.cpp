#include "InputStream.hpp"

#include <errno.h>
#include <unistd.h> // read()

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
   auto count = read(mFileDesc, result.data(), result.size());
   if (count < 0) {
      if ((EAGAIN == errno) || (EWOULDBLOCK == errno)) {
         count = 0;
      } else {
         throw errno;
      }
   }
   // COUNT is not negative
   result.resize(static_cast<size_t>(count));
   return result;
}

} // namespace IO

