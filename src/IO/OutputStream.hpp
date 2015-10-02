#ifndef IO_OUTPUT_STREAM_HPP
#define IO_OUTPUT_STREAM_HPP

#include <cstdint> // uint8_t
#include <vector>

#include <unistd.h> // write()

namespace IO {

struct OutputStream
{
   OutputStream(int fileDescriptor);

   int operator () (void) const;

   size_t Write(const std::vector<uint8_t> &data) const;

   template <size_t SIZE>
   size_t Write(const char (&data)[SIZE]) const
   {
      const auto COUNT = write(mFileDesc, data, SIZE);
      if (COUNT < 0)
      {
         throw COUNT;
      }
      // COUNT is not negative
      return static_cast<size_t>(COUNT);
   }
private:
   int mFileDesc;
};

} // namespace IO

#endif

