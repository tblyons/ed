#include "IO/InputStream.hpp"
#include "IO/OutputStream.hpp"
#include "IO/Screen.hpp"
#include "IO/Terminal.hpp"

int main(int, const char*[])
{
   IO::Terminal term;
   term.MakeRaw();
   IO::OutputStream out(STDOUT_FILENO);
   IO::InputStream in(STDIN_FILENO);
   IO::Screen scr;
   scr.Clear();
   out.Write("Hello World!\n");
   in.Read(10);
   out.Write(in.Read(256));
   return 0;
}
