#ifndef IO_INPUT_STREAM_HPP
#define IO_INPUT_STREAM_HPP

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

}

#endif

