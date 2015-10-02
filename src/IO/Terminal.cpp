#include "Terminal.hpp"

#include <errno.h>
#include <unistd.h>

namespace IO {

   Terminal::Terminal(void)
   : mOriginalTermios()
   {
      if (tcgetattr(STDIN_FILENO, &mOriginalTermios))
      {
         throw errno;
      }
   }

   Terminal::~Terminal(void)
   {
      if (tcsetattr(STDIN_FILENO, TCSANOW, &mOriginalTermios))
      {
         // Failed to restore the original termios.
         // Do nothing, this is the destructor
      }
   }

   void Terminal::MakeRaw(void) const
   {
      struct termios new_termios = mOriginalTermios;
      cfmakeraw(&new_termios);
      if (tcsetattr(STDIN_FILENO, TCSANOW, &new_termios))
      {
         throw errno;
      }
   }

} // namespace IO

