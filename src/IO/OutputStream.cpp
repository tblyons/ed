#include "OutputStream.hpp"

namespace IO {

OutputStream::OutputStream(int fileDescriptor)
   : mFileDesc(fileDescriptor)
{
   // Intentionally left blank
}

int OutputStream::operator () (void) const
{
   return mFileDesc;
}

size_t OutputStream::Write(const std::vector<uint8_t> &data) const
{
   const ssize_t COUNT = write(mFileDesc, data.data(), data.size());
   if (COUNT < 0)
   {
      throw COUNT;
   }
   // COUNT is not negative
   return static_cast<size_t>(COUNT);
}

} // namespace IO
