#ifndef IO_INPUT_STREAM_HPP
#define IO_INPUT_STREAM_HPP

#include <cstddef> // size_t
#include <cstdint> // uint8_t
#include <vector>

namespace IO {

struct InputStream
{
   InputStream(int fileDescriptor);

   int operator () (void) const;

   std::vector<uint8_t> Read(size_t maxBytes) const;

private:
   int mFileDesc;
};

} // namespace IO

#endif

