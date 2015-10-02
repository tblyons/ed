#ifndef IO_TERMINAL_HPP
#define IO_TERMINAL_HPP

#include <termios.h>

namespace IO {

struct Terminal {
   Terminal(void);

   // Restores the original termios
   ~Terminal(void);

   void MakeRaw(void) const;

private:
   struct termios mOriginalTermios;
};

} // namespace IO

#endif

