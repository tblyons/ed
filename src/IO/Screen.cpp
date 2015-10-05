#include "Screen.hpp"

namespace IO {

Screen::Screen(void)
   : mIn(STDIN_FILENO),
   mOut(STDOUT_FILENO)
{
}

void Screen::Clear(void) const
{
   mOut.Write("\x1B[2J");
}
void Screen::GetPosition(void) const
{
}
void Screen::SetPosition(void) const
{
   mOut.Write("\x1B[1;1H");
}
void Screen::SavePosition(void) const
{
   mOut.Write("\x1B[s");
}
void Screen::RestorePosition(void) const
{
   mOut.Write("\x1B[u");
}
void Screen::SetBackground(void) const
{
}
void Screen::SetForeground(void) const
{
}
void Screen::MoveLeft(size_t columns) const
{
   mOut.Write("\x1B[D");
}
void Screen::MoveRight(size_t columns) const
{
   mOut.Write("\x1B[C");
}
void Screen::MoveUp(size_t rows) const
{
   mOut.Write("\x1B[A");
}
void Screen::MoveDown(size_t rows) const
{
   mOut.Write("\x1B[B");
}

} // namespace IO
