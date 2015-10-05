#ifndef IO_SCREEN_HPP
#define IO_SCREEN_HPP

#include "InputStream.hpp"
#include "OutputStream.hpp"

namespace IO {

struct Screen
{
   Screen(void);

   void Clear(void) const;
   void GetPosition(void) const;
   void SetPosition(void) const;
   void SavePosition(void) const;
   void RestorePosition(void) const;
   void SetBackground(void) const;
   void SetForeground(void) const;
   void MoveLeft(size_t columns) const;
   void MoveRight(size_t columns) const;
   void MoveUp(size_t rows) const;
   void MoveDown(size_t rows) const;
private:
   InputStream mIn;
   OutputStream mOut;
};

} // namespace IO

#endif

