#include "OutputStream.hpp"

namespace IO {

OutputStream::OutputStream(int fileDescriptor)
   : mFileDesc(fileDescriptor)
{
   // Intentionally left blank
}

} // namespace IO
